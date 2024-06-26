import math

def fibonacci(n):
    five=5**0.5
    a=(1+five)/2
    b=(1-five)/2
    return int((a**n-b**n)//five)

for i in range(1,100):
    print(fibonacci(i))


# 0 1 2 3 5 8 13 21