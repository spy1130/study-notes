import datetime as dt
class leapYears:
    def __init__(self):
        self.now = dt.date.today().year#date.today()返回一个当前本地日期的year
    def __iter__(self):
        return self
    def laeps(self,year):
        if (year%4 == 0 and year%100 !=0)or(year%400 == 0):
            return True
        else:
            return False
    def __next__(self):
        while not self.laeps(self.now):
            self.now -=1
        temp = self.now
        self.now -= 1
        return temp
leap = leapYears()
for i in leap:
    if i >= 0:
        print(i)
    else:
        break
