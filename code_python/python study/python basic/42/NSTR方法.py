class Nstr(str):
    def __sub__(self,others):
        return self.replace(others,'') #replace(self, old, new, count=-1, /)，这个就是replace的基本用法，old就是指要替换的字符串，，new就
a = Nstr('SSPYY22222')
B = Nstr('2')
D = a - B
print(D)