i = 1
max = 0
red = 0
black = 0
noms= []
for temp in range(0,36):
    noms.append(0)
ends = []
for temp in range(0,12):
    ends.append(0)
count = 0
while (i):
    nom = int(input("Введите последний результат\n"))
    if (nom > 0 and nom < 37):
        noms[nom]+=1
        ends[count%12] = nom
    if (nom % 2 == 0): black+=1
    if (nom % 2 == 1): red+=1
    for temp in range(0,36):
        if (noms[temp] > max): max = noms[temp]
    print("Выпадали чаще всего:", end = " ")
    for temp in range(0,36):
        if (noms[temp] == max): print(temp, end = " ")
    print("\nВыпадали за последние 12 игр:", end = " ")
    for temp in range(0,12):
        if(ends[temp] != 0): print(ends[temp], end = " ")
    print("\nКрасное/черное", end = " ")
    print(red, black)
    count+=1
