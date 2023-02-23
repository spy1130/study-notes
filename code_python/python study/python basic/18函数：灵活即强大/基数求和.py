def fmun(*param,base=3):
    result=0
    for i in param:
        result +=i
    result *=base
    print('结果是：',result)
fmun(1,2,3,4,5,base=5)