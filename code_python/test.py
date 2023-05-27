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

# 定义约束条件函数
def add_constraints(prob, x, course_type):
    # 数学课程至少选择5门
    prob += lpSum([x[i] for i in range(len(data)) if 1 in course_type[i]]) >= 5
    # 物理课程至少选择2门
    prob += lpSum([x[i] for i in range(len(data)) if 2 in course_type[i]]) >= 2
    # 专业课程至少选择3门
    prob += lpSum([x[i] for i in range(len(data)) if 4 in course_type[i]]) >= 3
    # 就业课程至少选择4门
    prob += lpSum([x[i] for i in range(len(data)) if 5 in course_type[i]]) >= 4
    # 思政课程至少选择1门
    prob += lpSum([x[i] for i in range(len(data)) if 3 in course_type[i]]) >= 1
    # 每门先修课程必须在所选课程中
    for i in range(len(data)):
        for j in prerequisite[i]:
            prob += x[j] >= x[i]

# 建立目标一模型：只考虑尽可能多的学分
prob1 = LpProblem("Model1", LpMaximize)
x1 = []
for i in range(len(data)):
    x1.append(LpVariable(f"x1_{i}", cat=LpBinary))
prob1 += lpSum([credit[i] * x1[i] for i in range(len(data))])

# 添加约束条件
add_constraints(prob1, x1, course_type)

# 解决目标一模型
prob1.solve()

# 建立目标二模型：选修课程最少
prob2 = LpProblem("Model2", LpMinimize)
x2 = []
for i in range(len(data)):
    x2.append(LpVariable(f"x2_{i}", cat=LpBinary))
prob2 += lpSum(x2)

# 添加约束条件
add_constraints(prob2, x2, course_type)

# 解决目标二模型
prob2.solve()

# 建立目标三模型：同时考虑学分最多和选修科最少（假设所占比例三七分）
prob3 = LpProblem("Model3", LpMaximize)
x3 = []
for i in range(len(data)):
    x3.append(LpVariable(f"x3_{i}", cat=LpBinary))
prob3 += 0.3 * lpSum([credit[i] * x3[i] for i in range(len(data))]) + 0.7 * lpSum(x3)

# 添加约束条件
add_constraints(prob3, x3, course_type)

# 解决目标三模型
prob3.solve()

# 建立目标四模型：同时考虑课程最少和所获得的学分最多（按3:7的重要性）
prob4 = LpProblem("Model4", LpMinimize)
x4 = []
for i in range(len(data)):
    x4.append(LpVariable(f"x4_{i}", cat=LpBinary))
prob4 += 0.7 * lpSum([credit[i] * x4[i] for i in range(len(data))]) + 0.3 * lpSum(x4)

# 添加约束条件
add_constraints(prob4, x4, course_type)

# 解决目标四模型
prob4.solve()

# 打印结果
print("目标一模型 - 只考虑尽可能多的学分")
for i in range(len(data)):
    if value(x1[i]) == 1:
        print(f"课程编号: {course_number[i]}, 课程名称: {course_name[i]}")

print("\n目标二模型 - 选修课程最少")
for i in range(len(data)):
    if value(x2[i]) == 1:
        print(f"课程编号: {course_number[i]}, 课程名称: {course_name[i]}")

print("\n目标三模型 - 同时考虑学分最多和选修科最少")
for i in range(len(data)):
    if value(x3[i]) == 1:
        print(f"课程编号: {course_number[i]}, 课程名称: {course_name[i]}")

print("\n目标四模型 - 同时考虑课程最少和所获得的学分最多")
for i in range(len(data)):
    if value(x4[i]) == 1:
        print(f"课程编号: {course_number[i]}, 课程名称: {course_name[i]}")
