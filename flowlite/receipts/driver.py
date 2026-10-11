# End-to-end driver: focus target, set clipboard sentinel, hold F9 while playing speech to the speakers.
import sys, time, wave, subprocess, ctypes, json, numpy as np, sounddevice as sd, keyboard, pyperclip
from ctypes import wintypes
d = sys.argv[1]; u32 = ctypes.windll.user32
def fg_pid():
    pid = wintypes.DWORD(); u32.GetWindowThreadProcessId(u32.GetForegroundWindow(), ctypes.byref(pid)); return pid.value
def fg_title():
    b = ctypes.create_unicode_buffer(256); u32.GetWindowTextW(u32.GetForegroundWindow(), b, 256); return b.value
r = {}
INJECT = len(sys.argv) > 2 and sys.argv[2] == "inject"
if INJECT:
    fl = subprocess.Popen([sys.executable, "-u", f"{d}/flowlite_injected.py", sys.argv[3], f"{d}/../test.wav"], stdout=open(f"{d}/flowlite_injected.log", "w"), stderr=subprocess.STDOUT); r["flowlite_pid"] = fl.pid
    while "Ready." not in open(f"{d}/flowlite_injected.log").read(): time.sleep(0.5)
sentinel = f"CLIPBOARD-SENTINEL-{int(time.time())}"; pyperclip.copy(sentinel); r["clipboard_before"] = pyperclip.paste()
tgt = subprocess.Popen([sys.executable, f"{d}/target.py", f"{d}/target_text.txt"]); r["target_pid"] = tgt.pid
for _ in range(50):
    time.sleep(0.2)
    if fg_title() == "flowlite-e2e-target": break
    hwnd = u32.FindWindowW(None, "flowlite-e2e-target")
    if hwnd: keyboard.press_and_release("alt"); u32.SetForegroundWindow(hwnd)
r["foreground_title"] = fg_title(); r["foreground_is_target"] = r["foreground_title"] == "flowlite-e2e-target"
if not r["foreground_is_target"]:
    tgt.kill(); INJECT and fl.kill(); r["aborted"] = "target not foreground; did not press F9"; print(json.dumps(r, indent=1)); sys.exit(1)
w = wave.open(f"{d}/../test.wav"); audio = np.frombuffer(w.readframes(w.getnframes()), np.int16).astype(np.float32) / 32768
OUT = next(i for i, x in enumerate(sd.query_devices()) if x["name"].startswith("Speaker (3- Realtek") and x["max_output_channels"] and sd.query_hostapis(x["hostapi"])["name"] == "MME"); r["output_device"] = sd.query_devices(OUT)["name"]
keyboard.press("f9"); time.sleep(0.3)
time.sleep(len(audio) / 16000 + 0.4) if INJECT else (sd.play(audio * 0.9, 16000, device=OUT), sd.wait(), time.sleep(0.4))
keyboard.release("f9"); r["f9_held_s"] = round(0.7 + len(audio) / 16000, 2)
time.sleep(6)
r["foreground_after"] = fg_title()
try:
    from PIL import ImageGrab
    hwnd = u32.FindWindowW(None, "flowlite-e2e-target"); rc = wintypes.RECT(); u32.GetWindowRect(hwnd, ctypes.byref(rc))
    ImageGrab.grab((rc.left, rc.top, rc.right, rc.bottom)).save(f"{d}/target.png"); r["screenshot"] = f"{d}/target.png"
except Exception as e: r["screenshot"] = f"failed: {e}"
r["target_text"] = open(f"{d}/target_text.txt", encoding="utf-8").read()
r["clipboard_after"] = pyperclip.paste(); r["clipboard_restored"] = r["clipboard_after"] == sentinel
tgt.kill()
if INJECT: fl.kill(); r["flowlite_log"] = open(f"{d}/flowlite_injected.log").read().splitlines()[-1]
print(json.dumps(r, indent=1))
