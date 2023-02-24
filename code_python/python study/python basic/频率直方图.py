import matplotlib.pyplot as plt
a =[57,61,57,57,58,57,61,54,68,51,49,64,50,48,65,52,56,46,54,49,51,47,55,55,54,42,51,56,55,51,54,51,60,62,43,55,56,61,52,69,64,46,54,48]
plt.rcParams['font.sans-serif'] = ['SimHei']				# 解决中文无法显示的问题
plt.rcParams['axes.unicode_minus'] = False			# 用来正常显示负号
plt.subplot(211)														# 2行2列第二幅图
plt.hist(sorted(a),density=True,bins=5)					# density为True表示频率，否则是频数，可根据需求修改
plt.xlabel('年龄')
plt.ylabel('频率/组距')
plt.show()