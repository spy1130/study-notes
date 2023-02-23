import time as t

class MyTimer:
    def __init__(self, func, number=1000000):
        self.prompt = "未开始计时！"
        self.lasted = 0.0
        self.default_timer = t.perf_counter
        self.func = func
        self.number = number
    
    def __str__(self):
        return self.prompt

    __repr__ = __str__

    def __add__(self, other):
        result = self.lasted + other.lasted
        prompt = "总共运行了 %0.2f 秒" % result
        return prompt

    # 内部方法，计算运行时间
    def timing(self):
        self.begin = self.default_timer()
        for i in range(self.number):
            self.func()
        self.end = self.default_timer()
        self.lasted = self.end - self.begin
        self.prompt = "总共运行了 %0.2f 秒" % self.lasted
        
    # 设置计时器(time.perf_counter() 或 time.process_time())
    def set_timer(self, timer):
        if timer == 'process_time':
            self.default_timer = t.process_time
        elif timer == 'perf_counter':
            self.default_timer = t.perf_counter
        else:
            print("输入无效，请输入 perf_counter 或 process_time")
#运行模块
def test():
        text = "I love FishC.com!"
        char = 'o'
        if char in text:
                pass
                   
t1 = MyTimer(test)
t1.timing()
print(t1)
t2 = MyTimer(test, 100000000)
t2.timing()
print(t2)
print(t1 + t2)
