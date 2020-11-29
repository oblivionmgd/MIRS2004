import tkinter as tk

root = tk.Tk()
photo = tk.PhotoImage(file="cat.gif")
gif_index = 0

def next_frame():
    global gif_index
    try:
        photo.configure(format="gif -index {}".format(gif_index))

        gif_index += 1
    except tk.TclError:
        gif_index = 0
        return next_frame()
    else:
        root.after(100, next_frame)

label = tk.Label(root, image=photo)
label.pack()

root.after_idle(next_frame)
root.attributes("-fullscreen", True)
root.mainloop()
