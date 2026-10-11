# flowlite.py - hold F9, speak, release: the text is pasted into the focused app.
# Small copy of the Wispr Flow pipeline: hotkey -> 16 kHz mic -> ASR -> clipboard + paste keys -> restore.
# Paste rules follow the Ghidra pass on Wispr Flow Helper.exe (see wispr-flow-teardown.html, section 7).
#   python flowlite.py              run (Ctrl+C to quit)
#   python flowlite.py --test a.wav transcribe one 16 kHz mono WAV and print it (no paste)
#   python flowlite.py --selftest   check the paste rules (no mic, no model)
import sys, time, wave, ctypes, threading
from ctypes import wintypes
import numpy as np, sounddevice as sd, keyboard, pyperclip

RATE, KEY = 16000, "f9"
# Wispr helper: Shift+Insert only for these process names (and only when its "shift-insert" flag is on).
SHIFT_INSERT_APPS = {"code", "cursor", "windsurf"}
# Wispr helper: restore delay by process-name prefix, case-insensitive. Remote desktops 5000 ms, Office/WhatsApp 3000 ms, else 500 ms.
SLOW_RESTORE = ((5.0, ("vncviewer", "tvnviewer", "mstsc", "msrdc", "wfica32", "vmware-view", "rdcman", "anydesk", "teamviewer")),
                (3.0, ("outlook", "olk", "winword", "whatsapp")))
MODIFIERS = ("ctrl", "shift", "alt", "left windows", "right windows")


def load_model():
    from faster_whisper import WhisperModel
    try:
        return WhisperModel("base.en", device="cuda", compute_type="float16")
    except Exception as e:  # ponytail: CPU fallback, slower but works without CUDA/cuDNN
        print(f"CUDA failed ({e}); using CPU", flush=True)
        return WhisperModel("base.en", device="cpu", compute_type="int8")


def transcribe(model, audio):
    segs, _ = model.transcribe(audio, vad_filter=True)
    return " ".join(s.text.strip() for s in segs).strip()


def record():
    chunks = []
    with sd.InputStream(samplerate=RATE, channels=1, dtype="float32",
                        callback=lambda d, *_: chunks.append(d.copy())):
        while keyboard.is_pressed(KEY):
            time.sleep(0.02)
    return np.concatenate(chunks)[:, 0] if chunks else np.zeros(0, np.float32)


def foreground_process():
    """Process name of the focused window without '.exe', e.g. 'Code'."""
    u32, k32 = ctypes.windll.user32, ctypes.windll.kernel32
    pid = wintypes.DWORD()
    u32.GetWindowThreadProcessId(u32.GetForegroundWindow(), ctypes.byref(pid))
    h = k32.OpenProcess(0x1000, False, pid.value)  # PROCESS_QUERY_LIMITED_INFORMATION
    if not h:
        return "unknown"
    buf, n = ctypes.create_unicode_buffer(260), wintypes.DWORD(260)
    ok = k32.QueryFullProcessImageNameW(h, 0, buf, ctypes.byref(n))
    k32.CloseHandle(h)
    return buf.value.rsplit("\\", 1)[-1].rsplit(".", 1)[0] if ok else "unknown"


def pick_keys(proc):
    return ("shift", "insert") if proc.lower() in SHIFT_INSERT_APPS else ("ctrl", "v")


def restore_delay(proc):
    p = proc.lower()
    return next((d for d, names in SLOW_RESTORE if p.startswith(names)), 0.5)


def paste(text):
    proc = foreground_process()
    keys, delay = pick_keys(proc), restore_delay(proc)
    for _ in range(100):  # Wispr refuses to paste while a modifier is held; we wait up to 2 s
        if not any(keyboard.is_pressed(m) for m in MODIFIERS):
            break
        time.sleep(0.02)
    old = pyperclip.paste()
    pyperclip.copy(text)  # ponytail: plain text only; Wispr also writes "HTML Format" and uses delayed rendering
    for k in keys:
        keyboard.press(k)
    time.sleep(0.05)      # Wispr: all key-downs, Sleep(50), all key-ups
    for k in reversed(keys):
        keyboard.release(k)
    time.sleep(0.05)      # Wispr: "sleeping for 50 ms for paste to complete"
    # Restore later, and skip it if something else changed the clipboard meanwhile (Wispr does the same).
    # ponytail: restores text only; Wispr snapshots every format in its FormatsToRestore list.
    threading.Timer(delay, lambda: pyperclip.paste() == text and pyperclip.copy(old)).start()
    return proc, "+".join(keys), delay


def selftest():
    assert pick_keys("Code") == ("shift", "insert") and pick_keys("Cursor") == ("shift", "insert")
    assert pick_keys("python") == ("ctrl", "v") and pick_keys("chrome") == ("ctrl", "v")
    assert restore_delay("mstsc") == 5.0 and restore_delay("AnyDesk") == 5.0
    assert restore_delay("WINWORD") == 3.0 and restore_delay("olk") == 3.0
    assert restore_delay("notepad") == 0.5 and restore_delay("unknown") == 0.5
    print("selftest ok")


def main():
    if sys.argv[1:] == ["--selftest"]:
        return selftest()
    model = load_model()
    if len(sys.argv) == 3 and sys.argv[1] == "--test":
        with wave.open(sys.argv[2]) as w:
            assert w.getframerate() == RATE and w.getnchannels() == 1 and w.getsampwidth() == 2, "need 16 kHz mono 16-bit WAV"
            audio = np.frombuffer(w.readframes(w.getnframes()), np.int16).astype(np.float32) / 32768
        print(transcribe(model, audio))
        return
    print(f"Ready. Hold {KEY.upper()} and speak. Ctrl+C to quit.", flush=True)
    while True:
        keyboard.wait(KEY)
        audio = record()
        if len(audio) < RATE // 4:
            continue  # under 0.25 s: ignore taps
        t1 = time.perf_counter()
        text = transcribe(model, audio)
        asr = time.perf_counter() - t1
        if text:
            proc, keys, delay = paste(text + " ")
            print(f"{len(audio)/RATE:.1f}s audio, {asr:.2f}s ASR, {proc} -> {keys}, restore {delay}s: {text!r}", flush=True)
        else:
            print(f"{len(audio)/RATE:.1f}s audio, {asr:.2f}s ASR: no text", flush=True)


if __name__ == "__main__":
    main()
