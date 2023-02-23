#0
def func():
    pass

print('0:',type(func()))
#4
class A:
    def __init__(self, x):
        x = x + 1
        self.v1 = x

class B(A):
    def __init__(self, x):
        x = x + 1
        self.v2 = x
try:
    b = B(8)
    print("%d %d" % b.v1, b.v2)
except :
    print('4:IndentationError')
#6
values = [1, 1, 2, 3, 5]
nums = set(values)

def checkit(num):
    if num in nums:
        return True
    else:
        return False
print('\n6:',end='')
for i in filter(checkit, values):
    print(i, end=' ')
#7
values = [1, 1, 2, 3, 5]
def transform(num):
    return num ** 2
print('\n7:',end='')
for i in map(transform, values):
    print(i, end=' ')
#8
class A:
    def __init__(self, x):
        self.x = x

a = A(100)
a.__dict__['y'] = 50
print('\n8:',end='')
print(a.y + len(a.__dict__))
#9?
class A:
    def __init__(self):
        pass
    def get(self):
        print(__name__)
a = A()
print('9:',end='')
print(a.get())
#11
dict1 = {}
dict1[1] = 1
dict1['1'] = 2
dict1[1.0] = 3

result = 0
for each in dict1:
    result += dict1[each]

print('11:',result)
#14
list1 = [1, 2]
list2 = [3, 4]

dict1 = {'1':list1, '2':list2}
dict2 = dict1.copy()

dict1['1'][0] = 5

result = dict1['1'][0] + dict2['1'][0]
print('14:',result)
#15
import copy

list1 = [1, 2]
list2 = [3, 4]

dict1 = {'1':list1, '2':list2}
dict2 = copy.deepcopy(dict1)

dict1['1'][0] = 5

result = dict1['1'][0] + dict2['1'][0]
print('15:',result)