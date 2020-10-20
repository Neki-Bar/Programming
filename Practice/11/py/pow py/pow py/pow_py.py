print("Форма ввода:\nОснование степени\nПоказатель степени")
i = 1
while(i):
    osn = int(input())
    poc = int(input())
    st = 1
    for j in range(0, poc):
        st *= osn
    print(osn,"^",poc,"=",st)
    i = int(input("\nДля продолжения введите 1\nЧтобы выйти введите 0\n"))

