
def create(size, first=0, step=0):
    return [first + item * step for item in range(size)]

_print = print
def print(mas):
    for i in range(len(mas)):
        print(mas[i])
    return mas

def sort(mas):
    for i in range(len(mas)):
        key = mas[i]
        j = i - 1
        while (j >= 0 and mas[j] > key):
            mas[j + 1] = mas[j]
            j = j - 1
        mas[j + 1] = key
    return mas

size = int(input("Введите размер массива "))
first = int(input("Введите начальный элемент "))
step = int(input("Введите шаг прогрессии "))
print(sort(create(size,first,step)))