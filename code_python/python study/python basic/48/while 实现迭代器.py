list = range(5)
i = 0
while True:
    try:
        each = list[i]
        print(each)
        i += 1
    except:
        break




a = range(5)
it = iter(a)

while True:
    try:
        print(next(it))
    except StopIteration:
        break
