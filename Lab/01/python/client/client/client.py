from tkinter import *
import json
import requests




def click(event):
    res = requests.get("http://localhost:3000/raw")
    info = res.json()
    desc.config(text=str(info["description"].encode('l1').decode()))
    main.config(text=str(info["temperature"]) + "°C")

root = Tk()

root.bind("<Button-3>", click)

root.geometry('130x190')
root.title("Погода")

head = Label(root, text = "Симферополь", bg = "yellow", width = 20, height = 1, font = ("bold", 10))
desc = Label(root, bg = "yellow", width = 30, height = 1, font = ("default" ,7))
main = Label(root, bg = "white",  width = 10, height = 2, font = ("bold" ,30))
footer = Label(root, height = 3, width = 20 ,bg = "yellow" )

head.pack(side = TOP)
desc.pack(side = TOP)
main.pack(side = TOP)
footer.pack(side = BOTTOM)


click()

root.mainloop()
