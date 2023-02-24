member = [' 小甲鱼 ', 88, ' 黑夜', 90, ' 迷途', 85, ' 怡静', 90, ' 秋舞斜阳 ', 88]
count = 0 
length = len(member) 
while count < length: 
    print(member[count], member[count+1]) 
    count += 2
print("--------------------------------")
member = [' 小甲鱼 ', 88, ' 黑夜', 90, ' 迷途', 85, ' 怡静', 90, ' 秋舞斜阳 ', 88]
for each in range(len(member)): 
    if each%2 == 0: 
        print(member[each], member[each+1]) 
