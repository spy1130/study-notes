import pandas as pd
from pulp import *

# 读取Excel文件
data = pd.read_excel('通信课表.xlsx')

# 获取各列数据
course_number = data.iloc[:, 0].astype(int)
course_name = data.iloc[:, 1].astype(str)
credit = data.iloc[:, 2].astype(float)
is_required = data.iloc[:, 3].astype(int)

# 逗号分隔的数列转换为列表
prerequisite = data.iloc[:, 4].apply(lambda x: [int(i) for i in str(x).split(',') if i.strip()])  
course_type = data.iloc[:, 5].apply(lambda x: [int(i) for i in str(x).split(',') if i.strip()])  

"""# 打印课程信息
for i in range(len(data)):
    print("课程序号:", course_number[i])
    print("课程名称:", course_name[i])
    print("学分:", credit[i])
    print("是否必修:", "是" if is_required[i] == 1 else "否")
    print("先修课要求:", prerequisite[i])
    print("属于类型:", course_type[i])
    print("---------------------")
    """

# 创建线性规划问题
prob1 = LpProblem("目标一模型", LpMaximize)
prob2 = LpProblem("目标二模型", LpMinimize)
prob3 = LpProblem("目标三模型", LpMinimize)
prob4 = LpProblem("目标四模型", LpMaximize)

# 创建决策变量
x1 = [LpVariable(f"x1_{i}", cat=LpBinary) for i in range(len(data))]
x2 = [LpVariable(f"x2_{i}", cat=LpBinary) for i in range(len(data))]
x3 = [LpVariable(f"x3_{i}", cat=LpBinary) for i in range(len(data))]
x4 = [LpVariable(f"x4_{i}", cat=LpBinary) for i in range(len(data))]

# 添加目标函数
prob1 += lpSum(x1)
prob2 += lpSum(x2)
prob3 += 0.3 * lpSum([credit[i] * x3[i] for i in range(len(data))]) + 0.7 * lpSum(x3)
prob4 += 0.7 * lpSum([credit[i] * x4[i] for i in range(len(data))]) + 0.3 * lpSum(x4)

# 添加约束条件函数
def add_constraints(prob, x, course_type):
    for i in range(len(data)):
        # 必修课程必须选择
        if is_required[i] == 1:
            prob += x[i] == 1
        # 先修课程要求
        for pre in prerequisite[i]:
            prob += x[i] <= x[int(pre)]
        # 属于类型的约束
        for t in course_type[i]:
            prob += x[i] <= lpSum([x[j] for j in range(len(data)) if t in course_type[j]])

# 添加约束条件
add_constraints(prob1, x1, course_type)
add_constraints(prob2, x2, course_type)
add_constraints(prob3, x3, course_type)
add_constraints(prob4, x4, course_type)

# 解决四个模型
prob1.solve()
prob2.solve()
prob3.solve()
prob4.solve()

# 计算学分总和
total_credits = [value(lpSum([credit[i] * x[j] for j in range(len(data))])) for i, x in enumerate([x1, x2, x3, x4])]

# 打印结果
print("目标一模型 - 只考虑尽可能多的学分")
print(f"学分总和: {total_credits[0]}")
for i in range(len(data)):
    if value(x1[i]) == 1:
        print(f"选修课程：{course_name[i]}")

print("\n目标二模型 - 选修课程最少")
print(f"学分总和: {total_credits[1]}")
for i in range(len(data)):
    if value(x2[i]) == 1:
        print(f"选修课程：{course_name[i]}")

print("\n目标三模型 - 同时考虑学分最多和选修科最少")
print(f"学分总和: {total_credits[2]}")
for i in range(len(data)):
    if value(x3[i]) == 1:
        print(f"选修课程：{course_name[i]}")

print("\n目标四模型 - 同时考虑课程最少和所获得的学分最多")
print(f"学分总和: {total_credits[3]}")
for i in range(len(data)):
    if value(x4[i]) == 1:
        print(f"选修课程：{course_name[i]}")
