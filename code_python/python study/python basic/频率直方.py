#-*- encoding=utf-8 -*-
import datetime
import numpy as np
import matplotlib.pyplot as plt
import matplotlib
plt.rcParams['font.sans-serif'] = ['SimHei']

# 按照固定区间长度绘制频率分布直方图
# bins_interval 区间的长度
# margin        设定的左边和右边空留的大小
def probability_distribution(data, bins_interval=1, margin=1):
    bins = range(min(data), max(data) +1, 5)
    print(len(bins))
    for i in range(0, len(bins)):
        print(bins[i])
    plt.xlim(min(data) - margin, max(data) + margin)
    plt.title("Probability-distribution")
    plt.xlabel('重量')
    plt.ylabel('频率/组距')
    # 频率分布normed=True,频次分布normed=False
    prob,left,rectangle = plt.hist(x=data, bins=bins, normed=True, histtype='bar', color=['r'])
    for x, y in zip(left, prob):
        # 字体上边文字
        # 频率分布数据 normed=True
        plt.text(x + bins_interval / 2, y + 0.003, '%.2f' % y, ha='center', va='top')
        # 频次分布数据 normed=False
        plt.text(x + bins_interval / 2, y + 0.25, '%.2f' % y, ha='center', va='top')
    plt.show()

if __name__ == '__main__':
    data =[61,76,70,56,81,91,92,91,75,81,88,67,101,103,95,91,77,86,81,83,82,82,64,79,86,85,75,71,49,45]
    probability_distribution(data=data)