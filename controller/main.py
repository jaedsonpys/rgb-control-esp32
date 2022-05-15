import tkinter as tk
from tkinter import ttk
from tkinter.colorchooser import Chooser

from controller import Controller

root = tk.Tk()
root.title('RGB Controller ESP32')
root.geometry('300x300')

ct = None


def initialize():
    host = host_entry.get()
    port = int(port_entry.get())

    ct = Controller(host, port)


ttk.Label(root, text='Host: ').grid(column=0, row=0)
host_entry = ttk.Entry(root)
host_entry.grid(column=1, row=0)

ttk.Label(root, text='Port: ').grid(column=0, row=1)
port_entry = ttk.Entry(root)
port_entry.grid(column=1, row=1)

ttk.Button(root, text='Connect', command=initialize).grid(column=0, row=2)

ttk.Button(root, text='RED').grid(column=0, row=3)
ttk.Button(root, text='GREEN').grid(column=0, row=4)
ttk.Button(root, text='BLUE').grid(column=0, row=5)

root.mainloop()
