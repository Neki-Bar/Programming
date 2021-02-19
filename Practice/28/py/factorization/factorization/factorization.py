
def print_factorization(n: int) -> None:
    print("Множители: ", end= "")
    divisor = 2
    divisors = list()
    while(n != 1):
        if (n % divisor == 0):
            divisors.append(divisor)
            n /= divisor
        else:
            divisor += 1
    divisors.append(0)
    count = 1
    lastitem = divisors[0]
    for i in range(1, len(divisors)):
        if(lastitem == divisors[i]):
            count+=1
        else:
            print(lastitem,end= "")
            lastitem = divisors[i]
            if(count > 1):
                print("^"+str(count), end= "")
                count = 1
                if(i < len(divisors)-1):print("*",end = "")
            else:
                if(i < len(divisors)-1):print("*",end = "")

x = int(input("Введите число для факторизации.\n"))
print_factorization(x)