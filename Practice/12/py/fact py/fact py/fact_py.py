print("Введите число для вычисления факториала(1<=n<=12)")
j = 1
while(j):
    n = int(input())
    fact = 1
    if(1 <= n <= 12):
        for i in range(1,n+1):
            fact *= i
        print(n,"! = ",fact, sep = "")
    else:
        print("неправильный ввод")
    j = int(input("Для продолжения введите 1\nЧтобы выйти введите 0\n"))




