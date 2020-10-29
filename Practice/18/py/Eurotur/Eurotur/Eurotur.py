know = "halloklempnerdasistfantastischfluggegecheimen"
probability = 1
size = len(know)
stop = input("Введите стоп-слово\n")
for temp in stop:
    probability *= know.count(temp)/size
print(probability)


