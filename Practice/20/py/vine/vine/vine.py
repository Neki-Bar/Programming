class Drink:
    def __init__(self, name, price, volume):
        self.name = name
        self.price = price
        self.volume = volume
        self.perv = price/volume
        self.k = 0

    def getPrice(self):
        return self.price

    def getK(self):
        return self.k

    def getName(self):
        return self.name

    def getVolume(self):
        return self.volume
    
    def addK(self, a):
        self.k = a

buget = int(input("Введите количество денег\n"))
assorti = int(input("Введите количество разновидностей напитков\n"))
print("Введите наименование напитка, его цену и его объем через пробел, причем каждый новый напиток с новой строки.\n")
drinks = []
minprice = 1000000001
sumvol = 0
for i in range (assorti):
    name, price, volume= input().split(" ")
    price = int(price)
    volume = int(volume)
    drinks.append(Drink(name, price, volume))
    if(minprice > price): minprice = price
if(minprice > buget): print(-1)
else:
    sorted(drinks, key = lambda drink: drink.perv)
    for i in range (assorti):
        drinks[i].addK(buget // drinks[i].getPrice())
        buget %= drinks[i].getPrice();
    print("<Название напитка> <количество бутылок>:\n")
    for i in range (assorti):
        temp = drinks[i].getK()
        if (temp):
            print(str(drinks[i].getName()) + " " + str(temp) + "\n")
            sumvol += drinks[i].getVolume() * temp
    print("Суммарный объем: " + str(sumvol) + "\n")
    print("Остаток денег: " + str(buget))