# coding: utf-8
import pygame,sys,time,random
from pygame.locals import *
# 定义颜色变量
redColour = pygame.Color(255,0,0)
blackColour = pygame.Color(0,0,0)
whiteColour = pygame.Color(255,255,255)
greenColour = pygame.Color(0,255,0)
headColour = pygame.Color(0,119,255)

#注意：在下面所有的除法中，为了防止pygame输出偏差，必须取除数(//)而不是单纯除法(/)

# 蛇运动的场地长宽，因为第0行，HEIGHT行，第0列，WIDTH列为围墙，所以实际是13*13
HEIGHT = 15
WIDTH = 15
FIELD_SIZE = HEIGHT * WIDTH
# 蛇头位于snake数组的第一个元素
HEAD = 0

# 用数字代表不同的对象，由于运动时矩阵上每个格子会处理成到达食物的路径长度，
# 因此这三个变量间需要有足够大的间隔(>HEIGHT*WIDTH)来互相区分
# 小写一般是坐标，大写代表常量
FOOD = 0
UNDEFINED = (HEIGHT + 1) * (WIDTH + 1)
SNAKE = 2 * UNDEFINED

# 由于snake是一维数组，所以对应元素直接加上以下值就表示向四个方向移动
LEFT = -1
RIGHT = 1
UP = -WIDTH#一维数组，所以需要整个宽度都加上才能表示上下移动
DOWN = WIDTH 

# 错误码
ERR = -2333

# 用一维数组来表示二维的东西
# board表示蛇运动的矩形场地
# 初始化蛇头在(1,1)的地方
# 初始蛇长度为1
board = [0] * FIELD_SIZE #[0,0,0,……]
snake = [0] * (FIELD_SIZE+1)
snake[HEAD] = 1*WIDTH+1
snake_size = 1
# 与上面变量对应的临时变量，蛇试探性地移动时使用
tmpboard = [0] * FIELD_SIZE
tmpsnake = [0] * (FIELD_SIZE+1)
tmpsnake[HEAD] = 1*WIDTH+1
tmpsnake_size = 1

# food:食物位置初始在(4, 7)
# best_move: 运动方向
food = 4 * WIDTH + 7
best_move = ERR

# 运动方向数组，游戏分数(蛇长)
mov = [LEFT, RIGHT, UP, DOWN]                                           
score = 1 

# 检查一个cell有没有被蛇身覆盖，没有覆盖则为free，返回true
def is_cell_free(idx, psize, psnake):
    return not (idx in psnake[:psize]) 

# 检查某个位置idx是否可向move方向运动
def is_move_possible(idx, move):
    flag = False
    if move == LEFT:
        #因为实际范围是13*13,[1,13]*[1,13],所以idx为1时不能往左跑，此时取余为1所以>1
        flag = True if idx%WIDTH > 1 else False
    elif move == RIGHT:
        #这里的<WIDTH-2跟上面是一样的道理
        flag = True if idx%WIDTH < (WIDTH-2) else False
    elif move == UP:
        #这里向上的判断画图很好理解，因为在[1,13]*[1,13]的实际运动范围外，还有个
        #大框是围墙，就是之前说的那几个行列，下面判断向下运动的条件也是类似的
        flag = True if idx > (2*WIDTH-1) else False
    elif move == DOWN:
        flag = True if idx < (FIELD_SIZE-2*WIDTH) else False
    return flag
# 重置board
# board_BFS后，UNDEFINED值都变为了到达食物的路径长度
# 如需要还原，则要重置它
def board_reset(psnake, psize, pboard):
    for i in range(FIELD_SIZE):
        if i == food:
            pboard[i] = FOOD
        elif is_cell_free(i, psize, psnake): # 该位置为空
            pboard[i] = UNDEFINED
        else: # 该位置为蛇身
            pboard[i] = SNAKE
    
# 广度优先搜索遍历整个board，
# 计算出board中每个非SNAKE元素到达食物的路径长度
def board_BFS(pfood, psnake, pboard):
    queue = []
    queue.append(pfood)
    inqueue = [0] * FIELD_SIZE
    found = False
    # while循环结束后，除了蛇的身体，
    # 其它每个方格中的数字为从它到食物的曼哈顿间距
    while len(queue)!=0: 
        idx = queue.pop(0)#初始时idx是食物的坐标 
        if inqueue[idx] == 1: continue
        inqueue[idx] = 1
        for i in range(4):#左右上下
            if is_move_possible(idx, mov[i]):
                if idx + mov[i] == psnake[HEAD]:
                    found = True
                if pboard[idx+mov[i]] < SNAKE: # 如果该点不是蛇的身体
                    if pboard[idx+mov[i]] > pboard[idx]+1:#小于的时候不管，不然会覆盖已有的路径数据
                        pboard[idx+mov[i]] = pboard[idx] + 1
                    if inqueue[idx+mov[i]] == 0:
                        queue.append(idx+mov[i])
    return found

# 从蛇头开始，根据board中元素值，
# 从蛇头周围4个领域点中选择最短路径
def choose_shortest_safe_move(psnake, pboard):
    best_move = ERR
    min = SNAKE
    for i in range(4):
        if is_move_possible(psnake[HEAD], mov[i]) and pboard[psnake[HEAD]+mov[i]]<min:
        	#这里判断最小和下面的函数判断最大，都是先赋值，再循环互相比较
            min = pboard[psnake[HEAD]+mov[i]]
            best_move = mov[i]
    return best_move

# 从蛇头开始，根据board中元素值，
# 从蛇头周围4个领域点中选择最远路径
def choose_longest_safe_move(psnake, pboard):
    best_move = ERR
    max = -1
    for i in range(4):
        if is_move_possible(psnake[HEAD], mov[i]) and pboard[psnake[HEAD]+mov[i]]<UNDEFINED and pboard[psnake[HEAD]+mov[i]]>max:
            max = pboard[psnake[HEAD]+mov[i]]
            best_move = mov[i]
    return best_move

# 检查是否可以追着蛇尾运动，即蛇头和蛇尾间是有路径的
# 为的是避免蛇头陷入死路
# 虚拟操作，在tmpboard,tmpsnake中进行
def is_tail_inside():
    global tmpboard, tmpsnake, food, tmpsnake_size
    tmpboard[tmpsnake[tmpsnake_size-1]] = 0 # 虚拟地将蛇尾变为食物(因为是虚拟的，所以在tmpsnake,tmpboard中进行)
    tmpboard[food] = SNAKE # 放置食物的地方，看成蛇身
    result = board_BFS(tmpsnake[tmpsnake_size-1], tmpsnake, tmpboard) # 求得每个位置到蛇尾的路径长度
    for i in range(4): # 如果蛇头和蛇尾紧挨着，则返回False。即不能follow_tail，追着蛇尾运动了
        if is_move_possible(tmpsnake[HEAD], mov[i]) and tmpsnake[HEAD]+mov[i]==tmpsnake[tmpsnake_size-1] and tmpsnake_size>3:
            result = False
    return result

# 让蛇头朝着蛇尾运行一步
# 不管蛇身阻挡，朝蛇尾方向运行
def follow_tail():
    global tmpboard, tmpsnake, food, tmpsnake_size
    tmpsnake_size = snake_size
    tmpsnake = snake[:]
    board_reset(tmpsnake, tmpsnake_size, tmpboard) # 重置虚拟board
    tmpboard[tmpsnake[tmpsnake_size-1]] = FOOD # 让蛇尾成为食物
    tmpboard[food] = SNAKE # 让食物的地方变成蛇身
    board_BFS(tmpsnake[tmpsnake_size-1], tmpsnake, tmpboard) # 求得各个位置到达蛇尾的路径长度
    tmpboard[tmpsnake[tmpsnake_size-1]] = SNAKE # 还原蛇尾
    return choose_longest_safe_move(tmpsnake, tmpboard) # 返回运行方向(让蛇头运动1步)

# 在各种方案都不行时，随便找一个可行的方向来走(1步),
def any_possible_move():
    global food , snake, snake_size, board
    best_move = ERR
    board_reset(snake, snake_size, board)
    board_BFS(food, snake, board)
    min = SNAKE

    for i in range(4):
        if is_move_possible(snake[HEAD], mov[i]) and board[snake[HEAD]+mov[i]]<min:
            min = board[snake[HEAD]+mov[i]]
            best_move = mov[i]
    return best_move
    
#转换数组函数
def shift_array(arr, size):
    for i in range(size, 0, -1):
        arr[i] = arr[i-1]

def new_food():#随机函数生成新的食物
    global food, snake_size
    cell_free = False
    while not cell_free:
        w = random.randint(1, WIDTH-2)
        h = random.randint(1, HEIGHT-2)
        food = WIDTH*h + w
        cell_free = is_cell_free(food, snake_size, snake)
    pygame.draw.rect(playSurface,redColour,Rect(18*(food//WIDTH), 18*(food%WIDTH),18,18))

# 真正的蛇在这个函数中，朝pbest_move走1步
def make_move(pbest_move):
    global snake, board, snake_size, score
    shift_array(snake, snake_size)
    snake[HEAD] += pbest_move
    p = snake[HEAD]
    for body in snake:#画蛇，身体，头，尾
    	pygame.draw.rect(playSurface,whiteColour,Rect(18*(body//WIDTH), 18*(body%WIDTH),18,18))
    pygame.draw.rect(playSurface,greenColour,Rect(18*(snake[snake_size-1]//WIDTH),18*(snake[snake_size-1]%WIDTH),18,18))
    pygame.draw.rect(playSurface,headColour,Rect(18*(p//WIDTH), 18*(p%WIDTH),18,18))
    #下面一行是把初始情况会出现的第一个白块bug填掉
    pygame.draw.rect(playSurface,(255,255,0),Rect(0,0,18,18))
    # 刷新pygame显示层
    pygame.display.flip() 
    
    # 如果新加入的蛇头就是食物的位置
    # 蛇长加1，产生新的食物，重置board(因为原来那些路径长度已经用不上了)
    if snake[HEAD] == food:
        board[snake[HEAD]] = SNAKE # 新的蛇头
        snake_size += 1
        score += 1
        if snake_size < FIELD_SIZE: new_food()
    else: # 如果新加入的蛇头不是食物的位置
        board[snake[HEAD]] = SNAKE # 新的蛇头
        board[snake[snake_size]] = UNDEFINED # 蛇尾变为UNDEFINED，黑色
        pygame.draw.rect(playSurface,blackColour,Rect(18*(snake[snake_size]//WIDTH),18*(snake[snake_size]%WIDTH),18,18))
        # 刷新pygame显示层
        pygame.display.flip() 

# 虚拟地运行一次，然后在调用处检查这次运行可否可行
# 可行才真实运行。
# 虚拟运行吃到食物后，得到虚拟下蛇在board的位置
def virtual_shortest_move():
    global snake, board, snake_size, tmpsnake, tmpboard, tmpsnake_size, food
    tmpsnake_size = snake_size
    tmpsnake = snake[:] # 如果直接tmpsnake=snake，则两者指向同一处内存
    tmpboard = board[:] # board中已经是各位置到达食物的路径长度了，不用再计算
    board_reset(tmpsnake, tmpsnake_size, tmpboard)
    
    food_eated = False
    while not food_eated:
        board_BFS(food, tmpsnake, tmpboard)    
        move = choose_shortest_safe_move(tmpsnake, tmpboard)
        shift_array(tmpsnake, tmpsnake_size)
        tmpsnake[HEAD] += move # 在蛇头前加入一个新的位置
        # 如果新加入的蛇头的位置正好是食物的位置
        # 则长度加1，重置board，食物那个位置变为蛇的一部分(SNAKE)
        if tmpsnake[HEAD] == food:
            tmpsnake_size += 1
            board_reset(tmpsnake, tmpsnake_size, tmpboard) # 虚拟运行后，蛇在board的位置
            tmpboard[food] = SNAKE
            food_eated = True
        else: # 如果蛇头不是食物的位置，则新加入的位置为蛇头，最后一个变为空格
            tmpboard[tmpsnake[HEAD]] = SNAKE
            tmpboard[tmpsnake[tmpsnake_size]] = UNDEFINED

# 如果蛇与食物间有路径，则调用本函数
def find_safe_way():
    global snake, board
    safe_move = ERR
    # 虚拟地运行一次，因为已经确保蛇与食物间有路径，所以执行有效
    # 运行后得到虚拟下蛇在board中的位置，即tmpboard
    virtual_shortest_move() # 该函数唯一调用处
    if is_tail_inside(): # 如果虚拟运行后，蛇头蛇尾间有通路，则选最短路运行(1步)
        return choose_shortest_safe_move(snake, board)
    safe_move = follow_tail() # 否则虚拟地follow_tail 1步，如果可以做到，返回true
    return safe_move


#初始化pygame
pygame.init()
#定义一个变量用来控制游戏速度
fpsClock = pygame.time.Clock()
# 创建pygame显示层
playSurface = pygame.display.set_mode((270,270))
pygame.display.set_caption('贪吃蛇')
# 绘制pygame显示层
playSurface.fill(blackColour)
#初始化食物
pygame.draw.rect(playSurface,redColour,Rect(18*(food//WIDTH), 18*(food%WIDTH),18,18))

while True:
    for event in pygame.event.get():#循环监听键盘和退出事件
        if event.type == QUIT:#如果点了关闭
            print(score)#游戏结束后打印分数
            pygame.quit()
            sys.exit()
        elif event.type == KEYDOWN:#如果esc键被按下
            if event.key==K_ESCAPE:
                print(score)#游戏结束后打印分数
                pygame.quit()
                sys.exit()
    # 刷新pygame显示层
    pygame.display.flip()  
    #画围墙，255,255,0是黄色，边框是36是因为，pygame矩形是以边为初始，向四周填充边框
    pygame.draw.rect(playSurface,(255,255,0),Rect(0,0,270,270),36)
    # 重置距离
    board_reset(snake, snake_size, board)
    # 如果蛇可以吃到食物，board_BFS返回true
    # 并且board中除了蛇身(=SNAKE)，其它的元素值表示从该点运动到食物的最短路径长
    if board_BFS(food, snake, board):
        best_move  = find_safe_way() # find_safe_way的唯一调用处
    else:
        best_move = follow_tail()
    if best_move == ERR:
        best_move = any_possible_move()
    # 上面一次思考，只得出一个方向，运行一步
    if best_move != ERR: make_move(best_move)
    else:
        print(score)#游戏结束后打印分数
        break
    # 控制游戏速度
    fpsClock.tick(60)#20看上去速度正好

