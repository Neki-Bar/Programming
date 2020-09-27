def area(x,y,z):
    if(x+y>z and x+z>y and y+z>x):
        p = (x + y + z) / 2
        print("S = ",(p * (p - x) * (p - y) * (p - z))**0.5)
    else:
        print("Такой треугольник не существует")
i = 1
while(i):
    choose = int(input("Выберите способ ввода:\n1 - через дины сторон;\n2 - через координаты вершин\n"))
    if (choose == 1):
        a = int(input("Введите длину стороны a "))
        b = int(input("Введите длину стороны b "))
        c = int(input("Введите длину стороны c "))
        area(a,b,c)
    elif (choose == 2):
        ax,ay = input("Введите координаты вершины A через пробел ").split(" ")
        ax = int(ax)
        ay = int(ay)
        bx,by = input("Введите координаты вершины B через пробел ").split(" ")
        bx = int(bx)
        by = int(by)
        cx,cy = input("Введите координаты вершины C через пробел ").split(" ")
        cx = int(cx)
        cy = int(cy)
        a = ((bx - ax)**2 + (by - ay)**2)**0.5
        b = ((cx - bx)**2 + (cy - by)**2)**0.5
        c = ((ax - cx)**2 + (ay - cy)**2)**0.5
        area(a,b,c)
    else:
        print("Вы неправильно указали способ ввода")
    i = input("Для продолжения введите 1\nЧтобы выйти введите 0\n")