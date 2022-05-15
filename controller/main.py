import tkinter as tk
from tkinter import ttk
from tkinter.colorchooser import Chooser

from controller import Controller

root = tk.Tk()
root.title('RGB Controller ESP32')
root.geometry('300x300')

ct = Controller('192.168.0.108', 80)

ttk.Button(root, text='RED', command=ct.on_red).grid(column=0, row=3)
ttk.Button(root, text='GREEN', command=ct.on_green).grid(column=0, row=4)
ttk.Button(root, text='BLUE', command=ct.on_blue).grid(column=0, row=5)

root.mainloop()
