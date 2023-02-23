#1.将小甲鱼修改为小鱿鱼
list1 = [1, [1, 2, [' 小甲鱼 ']], 3, 5, 8, 13, 18]
print(list1)
list1[1][2][0]='小鱿鱼'
print(list1)
#2. 要对一个列表进行顺序排序，请问使用什么方法？
list3 = [1,2,3,4,5,6,7,8]
list3.sort()
#3. 要对一个列表进行逆序排序，请问使用什么方法？
list3.sort(reverse=True)
#--------------------------------------------
list3.sort()
list3.reverse()
#4.copy() 方法跟使用切片拷贝是一样的：
list2 = list1.copy() 
print(list2)
#clear() 方法用于清空列表的元素，但要注意，清空完后列表仍然还在哦，只是变成一个空列表。
list2.clear()
print(list2)
#5. 问题：请先在 IDLE 中获得下边列表的结果，并按照上方例子把列表推导式还原 出来。
list1 = [(x, y) for x in range(10) for y in range(10) if x%2==0 if y%2!=0]
print(list1)
print('------------------------------------------------------------------')
list2 =[]
for x in range(10):
    for y in range(10):
        if x%2 == 0:
            if y%2 != 0:
                list2.append((x,y))
print(list2)
