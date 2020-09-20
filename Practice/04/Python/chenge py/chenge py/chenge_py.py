print("С помощью переменной")
a = input("Введите число a")
b = input("Введите число b")
c = a
a = b
b = c
print("Число a = " + str(a))
print("Число b = " + str(b))

print("Без помощи переменной")
c = int(input("Введите число c"))
d = int(input("Введите число d"))
d = c * d
c = d / c
d = d / c
print("Число c = " + str(round(c)))
print("Число d = " + str(round(d)))