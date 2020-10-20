
import random

i = 1
randnum
usernum
j
print("Компьютер загадал случайное целое число  в диапазоне 0<=n<=100. Вам даётся 5 попыток угадать это число.")
while (i == 1):
    randnum = random.randint(0, 100)
    j = 0
    while(j < 5):
        usernum = int(input())
        if (0 <= usernum and usernum <= 100):
            if (usernum == randnum or j != 4):
                if (usernum < randnum): print("Загаданное число больше")
                if (usernum > randnum): print("Загаданное число меньше")
                if (usernum == randnum):
                    cout << "Поздравляю! Вы угадали\n";
                    break;
            else: print("Неправильный ввод")
        if (j == 5): 
            print("Вы проиграли. Было загадано: {" << randnum << "}")
        i = int(input("Хотите начать сначала? (1 - ДА )\n")
		



