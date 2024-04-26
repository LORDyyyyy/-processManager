import ttkbootstrap as tb
from app import ProcessManager

if __name__ == "__main__":
    root = tb.Window(themename="pulse")
    app = ProcessManager(root)
    root.mainloop()
