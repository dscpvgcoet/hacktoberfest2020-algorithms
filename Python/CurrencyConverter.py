from tkinter import *


window = Tk()
window.title=("Currency Converter")
window.geometry('500x150')

def currency():

    Dollar = float(e2_value.get()) * 0.014


    Dinar = float(e2_value.get()) * 16.20


    Yen = float(e2_value.get()) * 1.44


    Peso= float(e2_value.get()) * 0.29


    Euro= float(e2_value.get()) * 0.012


    Yuan = float(e2_value.get()) * 0.091

    #This currency values are taken on 18/10/2020


    t1.delete("1.0", END)
    t1.insert(END, Dollar)

    t2.delete("1.0", END)
    t2.insert(END, Dinar)

    t3.delete("1.0", END)
    t3.insert(END, Yen)

    t4.delete("1.0", END)
    t4.insert(END, Peso)

    t5.delete("1.0", END)
    t5.insert(END, Euro)

    t6.delete("1.0", END)
    t6.insert(END, Yuan)



e1 = Label(window, text="Enter the Value in Rupees")
e2_value = StringVar()
e2 = Entry(window, textvariable=e2_value)
e3 = Label(window, text='United States Dollar')
e4 = Label(window, text='Iraqi Dinar')
e5 = Label(window, text='Japanese Yen')
e6 = Label(window, text='Mexican Peso')
e7 = Label(window, text='Euro')
e8 = Label(window, text='Chinese Yuan')


t1 = Text(window, height=1, width=10)
t2 = Text(window, height=1, width=10)
t3 = Text(window, height=1, width=10)
t4 = Text(window, height=1, width=10)
t5 = Text(window, height=1, width=10)
t6 = Text(window, height=1, width=10)


b1 = Button(window, text="Convert", command=currency)


e1.grid(row=0, column=0)
e2.grid(row=0, column=1)
e3.grid(row=1, column=0)
e4.grid(row=1, column=1)
e5.grid(row=1, column=2)
e6.grid(row=4, column=0)
e7.grid(row=4, column=1)
e8.grid(row=4, column=2)
t1.grid(row=2, column=0)
t2.grid(row=2, column=1)
t3.grid(row=2, column=2)
t4.grid(row=5, column=0)
t5.grid(row=5, column=1)
t6.grid(row=5, column=2)

b1.grid(row=0, column=2)


window.mainloop()