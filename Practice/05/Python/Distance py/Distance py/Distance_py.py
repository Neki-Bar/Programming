x = int(input("Введите начальную координату (м)"))
v = int(input("Введите начальную скорость (м/с)"))
t = int(input("Введите время падения (с)"))
distance = v * t + 9.8 * t * t / 2
print("Пройденное расстояние = " + str(round(distance)))