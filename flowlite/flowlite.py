# flowlite.py - hold F9, speak, release: the text is pasted into the focused app.
# Small copy of the Wispr Flow pipeline: hotkey -> 16 kHz mic -> ASR -> clipboard + Ctrl+V -> restore.
#   python flowlite.py              run (Ctrl+C to quit)
#   python flowlite.py --test a.wav transcribe one 16 kHz mono WAV and print it (no paste)
import sys, time, wave
import numpy as np, sounddevice as sd, keyboard, pyperclip
from faster_whisper import WhisperModel

RATE, KEY = 16000, "f9"


def load_model():
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


def paste(text):
    old = pyperclip.paste()
    pyperclip.copy(text)
    keyboard.send("ctrl+v")
    time.sleep(0.15)     # ponytail: fixed delay; a slow app may paste the old clipboard
    pyperclip.copy(old)  # ponytail: restores text only; images/HTML on the clipboard are lost


def main():
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
        print(f"{len(audio)/RATE:.1f}s audio, {time.perf_counter()-t1:.2f}s ASR: {text!r}", flush=True)
        if text:
            paste(text + " ")


if __name__ == "__main__":
    main()
