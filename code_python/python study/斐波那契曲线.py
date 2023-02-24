
import numpy as np
import pylab as plt

# 产生菲波那切数列
def fibo(n):
    f_0 = 0
    f_1 = 1
    fibo_list = np.array([f_0,f_1])
    for i in np.arange(n-2):
        fibo_num = f_0 + f_1
        fibo_list = np.append(fibo_list,fibo_num)
        f_0, f_1 = f_1, fibo_num
    return fibo_list

#找出各个圆心
def find_o_xy(f_list):
    x_n, y_n = 0, 0         #起始圆心坐标
    o_x_array, o_y_array = np.array([x_n]), np.array([y_n])
    for n in np.arange(1,len(f_list)):
        #需要注意pyhton中数组计数是从0开始
        #第一项作为起始点已经给出
        y_n=y_n+np.mod(n+1,2)*f_list[n]*(-1)**(1+(np.mod(n+1,2)+n+1)/2)
        x_n=x_n+np.mod(n,2)*f_list[n]*(-1)**(1+(np.mod(n+1,2)+n+1)/2)
        o_x_array = np.append(o_x_array, x_n)
        o_y_array = np.append(o_y_array, y_n)
    return o_x_array, o_y_array

#现一并画出曲线与方格。
count = 7
f_list = fibo(count)
x0_array,y0_array = find_o_xy(f_list)

f_list_r = fibo(count+2)[2::]        #各个正方形对应的边长
square_list = np.zeros([1,2,5])
start_angle, end_angle = np.pi, 1.5*np.pi
for n in np.arange(len(f_list_r)):
    #圆心坐标
    x0 = x0_array[n]
    y0 = y0_array[n]
    
    #得到对角顶点坐标
    x2 = x0+f_list_r[n]*(-1)**((np.mod(n+1,2)+n+1)/2)
    if n == 0:
        y2 = -1         #起始点特殊目前只想到这么整了
    else:
        y2 = y0+f_list_r[n]*(-1)**(1+(np.mod(n,2)+n)/2)

    #其余两点坐标
    x1, x3 = x0, x2
    y1, y3 = y2, y0
    
    #整合一下,画正方形需要回到原点，因此5个点
    pp = np.array([[[x0,x1,x2,x3,x0],[y0,y1,y2,y3,y0]]])
    
    #画出圆弧
    t=np.arange(start_angle,end_angle,0.001)
    circle_x = (f_list_r[n])*(np.sin(t))+x0_array[n]
    circle_y = (f_list_r[n])*(np.cos(t))+y0_array[n]
    start_angle += 0.5*np.pi
    end_angle += 0.5*np.pi
    
    plt.plot(pp[0][0][::],pp[0][1][::],color = 'b')
    plt.plot(circle_x,circle_y,color='b')

#设置图片保存为png格式，有背景
plt.savefig('sdf.png',format = 'png',dpi=300)

