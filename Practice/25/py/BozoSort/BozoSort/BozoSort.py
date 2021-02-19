import random

def BozoSort(vec: list, comp: bool)->list:
    check = True
    while(check):
        check = False
        for i in range(0, len(vec)-1):
            if(comp):
                if (vec[i] > vec[i+1]): check = True
                if (check): break
            else:
                if (vec[i] < vec[i+1]): check = True
                if (check): break
        if (check):
            first = random.randint(0, len(vec))
            second = random.randint(0, len(vec))
            temp = vec[first]
            vec[first] = vec[second]
            vec[second] = temp
    return vec

def BozoSort(vec: list, comp: bool)->list:
