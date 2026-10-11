# Runs the real flowlite.main() with ONE swap: sd.InputStream feeds a WAV in real time instead of the mic.
# Hotkey hook, ASR, clipboard, Ctrl+V and restore are the unmodified flowlite code.
import sys, threading, time, wave, numpy as np
sys.path.insert(0, sys.argv[1]); import flowlite
w = wave.open(sys.argv[2]); WAV = np.frombuffer(w.readframes(w.getnframes()), np.int16).astype(np.float32) / 32768
class FakeStream:
    def __init__(self, samplerate, channels, dtype, callback): self.cb, self.run = callback, True
    def _feed(self):
        i = 0
        while self.run:
            blk = WAV[i:i + 640] if i < len(WAV) else np.zeros(0, np.float32)
            blk = np.pad(blk, (0, 640 - len(blk)))[:, None]; i += 640
            self.cb(blk, 640, None, None); time.sleep(0.04)  # 640 samples = 40 ms at 16 kHz
    def __enter__(self): self.t = threading.Thread(target=self._feed, daemon=True); self.t.start(); return self
    def __exit__(self, *a): self.run = False; self.t.join()
flowlite.sd.InputStream = FakeStream
flowlite.main()
