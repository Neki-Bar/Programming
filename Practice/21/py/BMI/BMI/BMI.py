def bmi(weight: float, height: float) -> float:
    return weight/height/height

def print_bmi(BMI: float) -> float:
    if(BMI < 18.5):  print("Underweight")
    if (18.5 <= BMI and BMI< 25.0):  print("Normal weight")
    if (25.0 <= BMI and BMI < 30.0):  print("Overweight")
    if (30.0 <= BMI):  print("Obesity")


weight,height = input("Введите свой вес в килограммах и рост в метрах.(через пробел)\n").split(" ")
print_bmi(bmi(float(weight),float(height)))