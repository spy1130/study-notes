def libs():
    a = 0
    b = 1
    while True:
        a , b = b , a+b
        yield a
libs = libs()
for i in libs:
    if i >1000:
        break
    else:    
        print(i,end=" ")




a = [i for i in range(100) if not(i % 2) and i % 3]
print(a)
b ={i:i%2 == 0 for i in range(100)}#i%2 ==0,判断i是否为2的倍数
print(b)
v= {i for i in [1,2,23,443,4,54,5,56,3,3,3,3,44,4,5,6,6,788,44,44,44,44]}#集合
print(v)
e = (i for i in range(10))
for each in e:
    print(each)
sum(i for i in range(100))
