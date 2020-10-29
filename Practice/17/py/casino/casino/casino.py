i = 1
max = 0
red = 0
black = 0
noms= []
for temp in range(0,37):
    noms.append(0)
ends = []
for temp in range(0,37):
    ends.append(0)
count = 0
while (i):
    nom = int(input("Введите последний результат\n"))
    if(nom == -1): break
    if (nom >= 0 and nom < 37):
        noms[nom]+=1
        ends[nom] = 1 + count%12
        if (nom % 2 == 0 and nom != 0): black+=1
        if (nom % 2 == 1 and nom != 0): red+=1
        for temp in range(0,37):
            if (noms[temp] > max): max = noms[temp]
        print("Выпадали чаще всего:", end = " ")
        for temp in range(0,37):
            if (noms[temp] == max): print(temp, end = " ")
        print("\n Не выпадали за последние 12 игр:", end = " ")
        for temp in range(0,37):
            if(ends[temp] == 0): print(temp, end = " ")
            if(ends[temp] != 0 and temp != nom and count > 10):
                ends[temp] -= 1
        print("\nКрасное/черное", end = " ")
        print(red, black)
        count+=1
    
