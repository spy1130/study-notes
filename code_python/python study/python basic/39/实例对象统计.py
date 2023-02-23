class C:
    count = 0

    def __init__(self):
        C.count += 1

    def __del__(self):
        C.count -= 1

a = C()
b = C()
c = C()
w = C.count
print(w)
del a
v = C.count
print(v)