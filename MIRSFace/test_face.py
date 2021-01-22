import time
import py_recv_2
import tkinter as tk
from PIL import Image, ImageTk

mode = 0

root = tk.Tk()
img = ImageTk.PhotoImage(Image.open('/home/pi/MIRS2004/MIRSFace/smile.png'))
panel = tk.Label(root, image=img)
panel.pack(side="bottom", fill="both", expand="yes")
root.attributes('-fullscreen', True)

def change():
    mode = py_recv_2.py_recv()
    print("mode:" + str(mode))
    if(mode == 1):
        img = ImageTk.PhotoImage(Image.open('/home/pi/MIRS2004/MIRSFace/smile.png'))
        panel.configure(image=img)
        panel.image = img
        mode = 0

    elif(mode == 2):
        img2 = ImageTk.PhotoImage(Image.open('/home/pi/MIRS2004/MIRSFace/warning.png'))
        panel.configure(image=img2)
        panel.image = img2
        mode = 0


    #root.after_idle(main)
    #root.bind("<Return>", callback)
    #mode = int(input())
    root.after(1000, change)

root.after(0, change)
root.mainloop()
