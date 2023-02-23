result = []
def get(n):
    if n > 0 :
        result.insert(0,n%10)
        get(n//10)

get(123456789)
print(result)
