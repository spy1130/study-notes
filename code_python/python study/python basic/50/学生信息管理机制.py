import pickle
from os.path import isfile
from os import remove


def main():
    running = True
    while running:
        menu()
        code = '9'
        count = 0
        while code not in [str(i) for i in range(8)]:
            if count == 0:
                code = input("请输入：")
            else:
                code = input("输入有误！请重新输入：")
            count += 1
        if code == '0':
            running = False
        elif code == '1':
            insert()
        elif code == '2':
            search()
        elif code == '3':
            delete()
        elif code == '4':
            modify()
        elif code == '5':
            sort()
        elif code == '6':
            total()
        elif code == '7':
            show()
    else:
        input("感谢您使用学生信息查询系统程序，请按 <Enter> 键退出程序！")


def menu():
    print('''
    ╔———————学生信息管理系统————————╗
    │                                              │
    │   =============== 功能菜单 ===============   │
    │                                              │
    │   1 录入学生信息                             │
    │   2 查找学生信息                             │
    │   3 删除学生信息                             │
    │   4 修改学生信息                             │
    │   5 排序                                     │
    │   6 统计学生总人数                           │
    │   7 显示所有学生信息                         │
    │   0 退出系统                                 │
    │  ==========================================  │
    │  说明：通过数字选择菜单                      │
    ╚———————————————————————╝
        ''')


def insert():
    continue_ = 'y'
    while continue_ == 'y':
        ID = input("请输入 ID（如 1001）：")
        name = input("请输入名字：")
        chinese = input("请输入语文成绩：")
        while not is_float(chinese):
            chinese = input("输入无效！请重新输入语文成绩：")
        chinese = float(chinese)
        math = input("请输入数学成绩：")
        while not is_float(math):
            math = input("输入无效！请重新输入数学成绩：")
        math = float(math)
        english = input("请输入英语成绩：")
        while not is_float(english):
            english = input("输入无效！请重新输入英语成绩：")
        english = float(english)

        score = [{'id': ID, 'name': name,
                  'chinese': chinese, 'math': math, 'english': english}]

        if not isfile("students.pkl"):
            file = open("students.pkl", "ab")
            pickle.dump(score, file)
            file.close()
        else:
            file = open("students.pkl", "rb+")
            score_list = pickle.load(file)
            score_list.extend(score)
            file.close()
            file = open("students.pkl", "wb")
            pickle.dump(score_list, file)
            file.close()

        continue_ = input("是否继续添加？（y/n）")
        while continue_ not in ['y', 'n']:
            continue_ = input("输入无效！是否继续添加？（y/n）")

    else:
        print("学生信息录入完毕！")


def search():
    continue_ = 'y'
    while continue_ == 'y':
        if not isfile("students.pkl"):
            print("没有任何数据！")
            return
        way = input("按ID查输入1；按姓名查输入2：")
        while way not in ['1', '2']:
            way = input("输入无效！按ID查输入1；按姓名查输入2：")
        if way == '1':
            students = pickle.load(open("students.pkl", "rb"))
            ID = input("请输入学生 ID：")
            result = []
            for each in students:
                if each['id'] == ID:
                    result.append(each)
        else:
            students = pickle.load(open("students.pkl", "rb"))
            name = input("请输入学生姓名：")
            result = []
            for each in students:
                if each['name'] == name:
                    result.append(each)
        result_str = ''
        result_str += 'ID'.center(6)
        result_str += '姓名'.center(12)
        result_str += '语文'.center(10)
        result_str += '数学'.center(10)
        result_str += '英语'.center(10)
        result_str += '总成绩'.center(11)
        for i in result:
            result_str += "\n"
            result_str += i['id'].center(6)
            result_str += i['name'].center(12)
            result_str += str(i['chinese']).center(12)
            result_str += str(i['math']).center(12)
            result_str += str(i['english']).center(12)
            result_str += str(i['chinese'] + i['math'] +
                              i['english']).center(13)
        print(result_str)
        continue_ = input("是否继续查询 (y/n)？")
        while continue_ not in ['y', 'n']:
            continue_ = input("输入无效！是否继续查询 (y/n)？")


def delete():
    if not isfile("students.pkl"):
        print("没有学生信息！@_@")
        return
    continue_ = 'y'
    while continue_ == 'y':
        show()
        ID = input("请输入要删除的学生ID：")
        students = pickle.load(open("students.pkl", "rb"))
        result = []
        for each in students:
            if each['id'] == ID:
                result.append(each)
        if not result:
            print(f"没有找到ID为 {ID} 的学生信息...")
            show()
        else:
            for i in result:
                students.remove(i)
            if not students:
                remove("students.pkl")
                print(f"ID 为 {ID} 的学生已成功删除！不可继续删除！")
                return
            else:
                pickle.dump(students, open("students.pkl", "wb"))
                print(f"ID 为 {ID} 的学生已成功删除！")
        continue_ = input("是否继续删除 (y/n)？")
        while continue_ not in ['y', 'n']:
            continue_ = input("输入无效！是否继续删除 (y/n)？")


def modify():
    if not isfile("students.pkl"):
        print("没有学生信息！")
        return
    show()
    continue_ = 'y'
    while continue_ == 'y':
        ID = input("请输入要修改的学生ID：")
        students = pickle.load(open("students.pkl", "rb"))
        result = []
        for each in students:
            if each['id'] == ID:
                result.append(each)
        if not result:
            print(f"没有找到ID为 {ID} 的学生信息...")
            show()
        elif len(result) != 1:
            print("ID 有相同的情况！")
        else:
            students.remove(result[0])
            name = input("请输入名字：")
            chinese = input("请输入语文成绩：")
            while not is_float(chinese):
                chinese = input("输入无效！请重新输入语文成绩：")
            chinese = float(chinese)
            math = input("请输入数学成绩：")
            while not is_float(math):
                math = input("输入无效！请重新输入数学成绩：")
            math = float(math)
            english = input("请输入英语成绩：")
            while not is_float(english):
                english = input("输入无效！请重新输入英语成绩：")
            english = float(english)

            score = {'id': ID, 'name': name,
                     'chinese': chinese, 'math': math, 'english': english}
            students.append(score)
            pickle.dump(students, open("students.pkl", "wb"))
        continue_ = input("是否继续修改 (y/n)？")
        while continue_ not in ['y', 'n']:
            continue_ = input("输入无效！是否继续修改 (y/n)？")


def sort():
    if not isfile("students.pkl"):
        print("没有学生信息！")
        return
    show()
    reverse = input("请选择（0升序；1降序）：")
    while reverse not in ['0', '1']:
        reverse = input("输入无效！请选择（0升序；1降序）：")
    reverse = bool(int(reverse))
    students = pickle.load(open("students.pkl", "rb"))
    way = input("请选择排序方式"
                "（1按语文成绩排序；"
                "2按数学成绩排序；"
                "3按英语成绩排序；"
                "0按总成绩排序）：")
    while way not in ['0', '1', '2', '3']:
        way = input("输入无效！请选择排序方式"
                    "（1按语文成绩排序；"
                    "2按数学成绩排序；"
                    "3按英语成绩排序；"
                    "0按总成绩排序）：")
    if way == '0':
        def condition(x):
            return x['chinese'] + x['math'] + x['english']
    elif way == '1':
        def condition(x):
            return x['chinese']
    elif way == '2':
        def condition(x):
            return x['math']
    else:
        def condition(x):
            return x['english']
    result = sorted(students, key=condition, reverse=reverse)
    result_str = ''
    result_str += 'ID'.center(6)
    result_str += '姓名'.center(12)
    result_str += '语文'.center(10)
    result_str += '数学'.center(10)
    result_str += '英语'.center(10)
    result_str += '总成绩'.center(11)
    for i in result:
        result_str += "\n"
        result_str += i['id'].center(6)
        result_str += i['name'].center(12)
        result_str += str(i['chinese']).center(12)
        result_str += str(i['math']).center(12)
        result_str += str(i['english']).center(12)
        result_str += str(i['chinese'] + i['math'] +
                          i['english']).center(13)
    print(result_str)


def total():
    try:
        print("一共有",
              str(len(pickle.load(open("students.pkl", "rb")))), "名学生！")
    except FileNotFoundError:
        print("没有学生信息！")


def show():
    if not isfile("students.pkl"):
        print("没有学生信息！@_@")
        return
    result = pickle.load(open("students.pkl", "rb"))
    result_str = ''
    result_str += 'ID'.center(6)
    result_str += '姓名'.center(12)
    result_str += '语文'.center(10)
    result_str += '数学'.center(10)
    result_str += '英语'.center(10)
    result_str += '总成绩'.center(11)
    for i in result:
        result_str += "\n"
        result_str += i['id'].center(6)
        result_str += i['name'].center(12)
        result_str += str(i['chinese']).center(12)
        result_str += str(i['math']).center(12)
        result_str += str(i['english']).center(12)
        result_str += str(i['chinese'] + i['math'] +
                          i['english']).center(13)
    print(result_str)


def is_float(number):
    try:
        float(number)
    except ValueError:
        return False
    else:
        return True


if __name__ == '__main__':
    try:
        main()
    except BaseException as e:
        print("啊哦，出错了 O_O")
        print(e)
        input("请按 <Enter> 键退出程序！")