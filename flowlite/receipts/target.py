# Test target app: a text box that grabs focus and mirrors its contents to a file every 0.3 s.
import sys, tkinter as tk
out = sys.argv[1]
root = tk.Tk(); root.title("flowlite-e2e-target"); root.geometry("700x200+200+200"); root.attributes("-topmost", True)
t = tk.Text(root, font=("Segoe UI", 14)); t.pack(fill="both", expand=True)
def dump():
    open(out, "w", encoding="utf-8").write(t.get("1.0", "end-1c")); root.after(300, dump)
root.after(200, lambda: (root.focus_force(), t.focus_set())); dump(); root.mainloop()
