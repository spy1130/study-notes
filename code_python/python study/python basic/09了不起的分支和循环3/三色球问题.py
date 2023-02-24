print('red\tyellow\tblue') 
for red in range(0, 4):
    for yellow in range(0, 4):
        for green in range(2, 7):
            if red + yellow + green == 8: 
                # 注意，下边不是字符串拼接，因此不用 ?+?哦~ 
                print(red, '\t', yellow, '\t', green) 
