name = input(' 请输入待查找的用户名： ') 
score =[['迷途', 85], ['黑夜', 80], ['小布丁', 65], ['福禄娃娃', 95], ['怡静', 90]] 
 

for each in score: 
    if name in each: 
        print(name + ' 的得分是： ', each[1]) 
        
        break 
    else:
        print(' 查找的数据不存在！ ')
        break 
