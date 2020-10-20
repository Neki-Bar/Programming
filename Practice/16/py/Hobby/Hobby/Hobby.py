i = 1
while (i):
    n = int(input("В первой строке введите количество билетов а во второй все номера билетов.\n"))
    out = []
    j=0
    while(j<n):
        bilet = input()
        if (bilet[0] == 'a' and bilet[4] == '5' and bilet[5] == '5' and bilet[6] == '6' and bilet[7] == '6' and bilet[8] == '1'):
            out.append(bilet);
        print("Билеты Суслика:", sep = " ")
        for temp in range(0,len(out)):
            print(out[temp], sep = " ")
        i = int(input("Для продолжения введите 1\nЧтобы выйти введите 0\n"))
