print("Калькулятор\nФормат ввода:\nЧерез пробел: 1-й операнд, оператор(+-*/), 2-й операнд")
i = 1
while(i):
    a,oper,b = input().split(" ")
    a = int(a)
    b = int(b)
    if(oper == "+"): print(a + b)
    elif(oper == "-"): print(a - b)
    elif(oper == "*"): print(a * b)
    elif(oper == "/"): print(a / b)
    else: print("Вы не правильно ввели оператор")
    i = int(input("Для продолжения введите 1\nЧтобы выйти введите 0\n"))

       