import os
import tkinter as tk

root = tk.Tk()
label = tk.Label(root, text="Hello World")
label.pack()

def goodbye_world(event):
    global label
    label.config(text="Goodbye World :<")
root.bind("<space>", goodbye_world)

root.mainloop()
