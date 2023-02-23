def  gcd(x, y):
    if  y == 0:
        return 0
    return x if ( y % x == 0 ) else gcd(y % x, x)
print(gcd(2,3))