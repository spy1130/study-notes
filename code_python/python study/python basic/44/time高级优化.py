import time as t

class MyTimer:
    def __init__(self):
        self.prompt = "未开始计时！"
        self.lasted = 0.0
        self.begin = 0
        self.end = 0
        self.default_timer = t.perf_counter #time.perf_counter()
        #返回计时器的精准时间
        #（系统的运行时间），包含整个系统的睡眠时间。
        # 由于返回值的基准点是未定义的，
        # 所以，只有连续调用的结果之间的差才是有效的。
    
    def __str__(self):
        return self.prompt

    __repr__ = __str__

    def __add__(self, other):
        result = self.lasted + other.lasted
        prompt = "总共运行了 %0.2f 秒" % result
        return prompt
    
    # 开始计时
    def start(self):
        self.begin = self.default_timer()
        self.prompt = "提示：请先调用 stop() 停止计时！"
        print("计时开始...")

    # 停止计时
    def stop(self):
        if not self.begin:#是0不循环，非0才循环
            print("提示：请先调用 start() 进行计时！")
        else:
            self.end = self.default_timer()
            self._calc()
            print("计时结束！")

    # 内部方法，计算运行时间
    def _calc(self):
        self.lasted = self.end - self.begin
        self.prompt = "总共运行了 %0.2f 秒" % self.lasted
        
        # 为下一轮计时初始化变量
        self.begin = 0
        self.end = 0

    # 设置计时器(time.perf_counter() 或 time.process_time())
    def set_timer(self, timer):
        if timer == 'process_time':
            self.default_timer = t.process_time
        elif timer == 'perf_counter':
            self.default_timer = t.perf_counter
        else:
            print("输入无效，请输入 perf_counter 或 process_time")
#运行模块
t1 = MyTimer()
print(t1)
secs = int(input("输入你想要的时间："))
t1.start()
t.sleep(secs)
t1.stop()
print(t1)