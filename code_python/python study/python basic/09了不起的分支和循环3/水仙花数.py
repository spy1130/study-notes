for i in range(100, 1000):
    sum = 0 
    temp = i 
    while temp: 
        sum = sum + (temp%10) ** 3 
        temp //= 10         # 注意这里要使用地板除哦 ~ 
    if sum == i: 
        print(i) 
