def indOfMax(lis:list)->int:
    ind = 0
    for i in range(1,len(lis)):
        if(lis[i] > lis[ind]): ind = i
    return ind

n = int(input("Введите количество сигналов.\n"))
print("Введите сигналы через пробел.")
if(n >= 1 and n <= 100000):
    top = list()
    top = [1000001,1000001,1000001,1000001,1000001]
    maxind = 0
    out = list()
    inp = list()
    inp = input().split(" ")
    for i in range(0, n):
        a = int(inp[i])
        if(a >= -1000000 and a <= 1000000):
            maxind = indOfMax(top)
            if(a < top[maxind]):
                top[maxind] = a
                top.sort(reverse = True)
                out.append(top.copy())
            else:
                out.append(top)
for i in range(0, len(out)):
    for j in range(0,len(out[i])):
        if(out[i][j] >= -1000000 and out[i][j] <= 1000000):
            print(out[i][j], end = " ")
    print()

