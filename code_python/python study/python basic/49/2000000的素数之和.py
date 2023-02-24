import math

def isprime (num) :
    if num > 1 :
        if num == 2 :
            return True
        if num %2 == 0:
            return False
        for currect in range (3,int(math.sqrt(num)+1),2):
            if num % currect == 0:
                return False
        return True

def getprime (num) :
    while True:
        if isprime(num) :
            yield num
        num += 1

def slove () :
    total = 2
    for nextprime in getprime(3) :
        if nextprime < 2000000 :
            total += nextprime
        else :
            print (total)
            return

slove()