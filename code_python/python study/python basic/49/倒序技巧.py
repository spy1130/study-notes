def myRev(date):
    #这里用range 生成 date 的倒序索引
    #注意，range 的结束位置是不包含的
    for index in range(len(date)-1,-1,-1):#（len-1，-1（不包含））以-1为跨度
        yield date[index]
