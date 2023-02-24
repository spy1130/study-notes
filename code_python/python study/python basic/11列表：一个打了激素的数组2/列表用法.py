member=[1,2,3,4,5,6,7,8]
print(member)
member.remove(1)#删除指定参数
print(member)
del member[3]#删除第四个参数（从0数起）
print(member)
member0=member.pop()#取出最后一个参数，并返回/pop(参数所在序数)，去出在这一序数的参数，并返回
print(member0)
member2=member[1:3]#分片列表[序数：序数2：跨步（兔子数列)]从序数到序数的参数的新列表(从0开始）
print(member2)
member3=member[:3]#[默认0:序数2]
print(member3)
member4=member[1:]#[序数：默认到尾]
print(member4)
member.append(8)#将参数作为一个元素增加到列表的末尾
print(member)      
member.extend([9,10])#将参数作为一个列表去扩展列表的末尾
print(member)      
member.insert(0,1)#在指定序数添加参数{用法（序数[从0开始]，函数}
print(member)
member.insert(4,5)
print(member)
print('--------------------------------------------------')
list1 = [123]
list2 = [234]
list1 > list2#列表也可以比较
list1 = [123,456]
list2 = [234,123]
list1 > list2#比较只比较列表第一个数
list3 = [123,456]
(list1 < list2) and (list1 == list3)#当and两边都为True的时候才返回True，一个不成立，则返回False
list4 =list1 +list2#加号合并两列表，相当于extend方法，但不能实现添加新元素
print(list3,'           ',list4)
list3 * 3#列表打印3遍，并包含在一个列表，也可以list3 *=3
123 in list3#成员关系操作符，检测列表是否包含这参数个
'spy' not in list3#参数没在
list5 = [123,[1,2],456]
1 in list5[1]#1在list5列表的第二个位置的列表里（从0开始）
list5[1][1]#访问2的值，和二维数组相似，访问list5列表里第二个位置的列表里的第二个位置
#dir(list)访问list列表函数
list3.count(123)#计算参数在列表中出现的次数,123在list3列表中出现的次数
list3.index(123)#返回参数在列表中的位置
list3 *=5
list3.index(123,3,7)#后边两个数是规定搜寻参数的范围
list3.reverse()#倒序（乾坤大转移）
print(list3)
list6 = [4,3,5,2,1]
list6.sort()#从小到大排队
print(list6)
list6.sort(reverse=True)#sort(func[指定排序的算法],key[跟这个算法搭配的关键字]，reverse[默认=False]从大到小排)
print('----------------------------------\n补：\n',list6)
list7 = list6[:]#list7拷贝list6，list7独立
print(list7)
list8 =list6#list8随list6的改变而改变
print(list8)
list6.sort()
print(list6,'      ',list7,'      ',list8)
list9=list6.copy()#copy() 方法跟使用切片拷贝是一样的
print(list9)
list9.clear()#clear() 方法用于清空列表的元素，但要注意，清空完后列表仍然还在哦，只是变成一 个空列表。
print(list9)




