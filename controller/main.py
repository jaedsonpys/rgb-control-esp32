import tkinter as tk
from tkinter import ttk
from tkinter.colorchooser import askcolor

from controller import Controller

root = tk.Tk()
root.title('RGB Controller ESP32')
root.geometry('300x300')

ct = Controller('192.168.0.108', 80)


def rgb_selector():
    colors = askcolor(title='RGB Color')
    rgb = colors[0]
    ct.rgb(int(rgb[0]), int(rgb[1]), int(rgb[2]))


ttk.Button(root, text='RED', command=ct.on_red).grid(column=0, row=3)
ttk.Button(root, text='GREEN', command=ct.on_green).grid(column=0, row=4)
ttk.Button(root, text='BLUE', command=ct.on_blue).grid(column=0, row=5)
ttk.Button(root, text='RGB', command=rgb_selector).grid(column=0, row=6)

root.mainloop()
