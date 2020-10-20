i = 1
while(i):
    s,l1,r1,l2,r2 = input("Введите через пробел значения s, l1, r1, l2, r2\n").split(" ")
    s = int(s)
    l1 = int(l1)
    r1 = int(r1)
    l2 = int(l2)
    r2 = int(r2)
    if ((s >= l1 + l2) and (s <= r1 + r2)):
        if (l1 + r2 - s == 0): print("x1 =", l1," x2 =",r2)
        if (l1 + r2 - s < 0): print("x1 =",l1 - (l1 + r2 - s), " x2 =", r2)
        if (l1 + r2 - s > 0): print("x1 =",l1," x2 =",r2 - (l1 + r2 - s))
    else: cout << -1;
    i = int(input("Для продолжения введите 1\nЧтобы выйти введите 0\n"))
