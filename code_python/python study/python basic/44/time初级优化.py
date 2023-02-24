import time as t

class Timer:
    def __init__(self):
        self.unit = ['年','月','日','时','分','秒']
        self.prompt = '没开始计时！'
        self.borrow = [0,12,31,24,60,60]#这里默认一月有31天了
        self.lasted= []
        self.begin = 0
        self.end = 0

    def __str__(self):
        return self.prompt
    #时间相加
    def __add__(self,other):
        prompt = '总共运行了'
        result =[]
        for index in range(6):
            result.append(self.lasted[index] + other.lasted[index])
            if result[index]:
                prompt += (str(result[index] + self.unit[index]) 
        return prompt

    __repr__ = __str__ #方法赋值相同
    # 开始计时
    def start(self):
        self.begin = t.localtime()
        self.prompt = '请先调用 stop() 停止计时！'
        print("计时开始...")

    #停止计时
    def stop(self):
        if not self.begin:
            print('请先调用 start() 方法')
        else:
            self.end = t.localtime()
            self._calc()
            print("计时结束...")

    #内部方法 ：计算时间
    def _calc(self):
        self.lasted = []
        self.prompt = "总共运行了"
        for index in range(6):
            temp = self.end[index] - self.begin[index]

            #低位不够减，需向高位借
            if temp < 0:
                # 测试高位是否有得‘借’，没得借的花再向高位借
                i = 1
                while self.lasted[index-i] < 1:
                    self.lasted[index-i] += self.borrow[index-i] -1
                    self.lasted[index-i-1] -= 1
                    i += 1

                self.lasted.append(self.borrow[index]+ temp)
                self.lasted[index - 1] - = 1
            else:
                self.lasted.append(temp)

            #由于高位随时会被借位，所以打印要放在最后
            for index in range(6):
                if self.lasted[index]:#是0不循环，非0才循环
                    self.prompt += str(self.lasted[index])+ self.unit[index]
        #初始化
        self.begin = 0
        self.end = 0
#运行模块
t1 = Timer()
print(t1)
secs = int(input("输入你想要的时间："))
t1.start()
t.sleep(secs)
t1.stop()
print(t1)