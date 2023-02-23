#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> //COORD
#define WIDE 60
#define HIGH 30
// 1 设置地图范围（边界） 宽 高
// 2 初始化蛇，食物
typedef struct _body
{
    int x;
    int y;
} BODY;
typedef struct snake
{
    BODY list[WIDE * HIGH]; // 身体,身体的每一节坐标都是BODY类型
    int size;               // 蛇的身体大小
    BODY food;              // 食物的坐标
    COORD coord;            // 光标的位置信息
    int dy;                 // 蛇y轴移动的方向
    int dx;                 // 蛇x轴移动的方向
    int score;              // 分数
    BODY tail;              // 尾巴
} SNAKE;
void game_end(SNAKE *snake);
void init_food(SNAKE *snake)
{
    srand(time(NULL)); // 设置随机数种子
    snake->food.x = rand() % WIDE;
    snake->food.y = rand() % HIGH;
    // 防止生成在蛇身上
    for (int i = 1; i < snake->size; i++)
    {
        if (snake->food.x == snake->list[i].x &&
            snake->food.y == snake->list[i].y)
        {
            init_food(snake);
        }
    }
}
void init_snake(SNAKE *snake) // 初始化
{
    // 蛇头
    snake->list[0].x = WIDE / 2;
    snake->list[0].y = HIGH / 2;
    // 蛇尾
    snake->list[1].x = WIDE / 2 - 1;
    snake->list[1].y = HIGH / 2;
    // 身体大小
    snake->size = 2;
    // 食物
    init_food(snake);
    // 蛇的移动方向
    snake->dx = 1;
    snake->dy = 0;
    // 初始化分数
    snake->score = 0;
}
// 3 将蛇，食物显示在屏幕上
void show_ui(SNAKE *snake)
{
    // 显示蛇 注意：每次显示蛇或食物，都要设置显示的位置（光标的位置）
    for (int i = 0; i < snake->size; i++) // 这里的size也决定了显示*的次数
    {
        snake->coord.X = snake->list[i].x;
        snake->coord.Y = snake->list[i].y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord); // 设置字符光标的位置
        if (0 == i)
        {
            printf("@");
        }
        else
        {
            printf("*");
        }
    }
    // 显示食物
    snake->coord.X = snake->food.x;
    snake->coord.Y = snake->food.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord); // 设置字符光标的位置
    printf("#");
    // 将原来尾巴的位置显示为空格
    snake->coord.X = snake->tail.x;
    snake->coord.Y = snake->tail.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord); // 设置字符光标的位置
    printf(" ");
}
// 4蛇的移动（通过wasd）
/*
    a>蛇碰墙
    b>身体
    c>障碍物
    d>食物（身体+1，原食物消失，生成新的食物，加分）
*/
void move_snake(SNAKE *snake)
{ // 记录尾巴坐标
    snake->tail.x = snake->list[snake->size - 1].x;
    snake->tail.y = snake->list[snake->size - 1].y;
    // 更新蛇的身体坐标，除蛇头
    for (int i = snake->size - 1; i > 0; i--)
    {
        snake->list[i] = snake->list[i - 1]; // 将数组前一个身体的坐标赋给后一个，这里新增也有了坐标
    }
    // 更新蛇头
    snake->list[0].x += snake->dx;
    snake->list[0].y += snake->dy;
}
void control_snake(SNAKE *snake)
{
    char key = 0;
    while (_kbhit()) // 判断是否按下按键，按下不等于0
    {
        key = _getch();
    }
    switch (key)
    {
    case 'a':
        snake->dx = -1;
        snake->dy = 0;
        break;
    case 's':
        snake->dx = 0;
        snake->dy = 1;
        break;
    case 'w':
        snake->dx = 0;
        snake->dy = -1; //-1往上走原点在左上角
        break;
    case 'd':
        snake->dx = 1;
        snake->dy = 0;
        break;
    }
}
// 吃自己
void snake_eat_body(SNAKE *snake)
{
    // 如果蛇头和身体的任意一节身体坐标相同，则吃到自己身体
    for (int i = 1; i < snake->size; i++)
    {
        if (snake->list[0].x == snake->list[i].x &&
            snake->list[0].y == snake->list[i].y)
        {
            game_end(snake);
        }
    }
}
// 吃食物
void snake_eat_food(SNAKE *snake)
{
    // 如果蛇头和食物的坐标重合则吃到了食物
    if (snake->list[0].x == snake->food.x &&
        snake->list[0].y == snake->food.y)
    {
        // 原食物消失（蛇头会覆盖）,生成新的食物
        init_food(snake);
        // 身体+1
        snake->size++;
        // 分数增加
        if (0 <= snake->size && snake->size < 10)
        {
            snake->score += 10;
        }
        else if (10 <= snake->size && snake->size < 100)
        {
            snake->score += 20;
        }
        else if (100 <= snake->size && snake->size < 250)
        {
            snake->score += 30;
        }
        else if (250 <= snake->size && snake->size < 500)
        {
            snake->score += 40;
        }
        else if (500 <= snake->size && snake->size < 1000)
        {
            snake->score += 50;
        }
        else if (1000 <= snake->size && snake->size < 1800)
        {
            snake->score += 60;
        }
    }
}
void start_game(SNAKE *snake)
{
    while (snake->list[0].x < 60 && snake->list[0].x >= 0 && snake->list[0].y < 30 && snake->list[0].y >= 0) // 蛇碰墙
    {                                                                                                        // 控制蛇的方向
        control_snake(snake);
        // 更新蛇的坐标
        move_snake(snake);
        // 蛇移动
        show_ui(snake); // 显示
        // 吃身体
        snake_eat_body(snake);
        // 食物（身体+1，原食物消失，生成新的食物，加分）
        snake_eat_food(snake);
        Sleep(200); // 延时0.2s
    }
    game_end(snake);
}
// 死亡 积分
void game_end(SNAKE *snake)
{
    snake->coord.X = 25;
    snake->coord.Y = 25;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord); // 设置字符光标的位置
    printf("game over score:%d", snake->score);
    Sleep(3000);
    exit(0); // 退出进程
}
// 墙
void init_wall()
{
    for (int i = 0; i <= HIGH; i++)
    {
        for (int j = 0; j <= WIDE; j++)
        {
            if (i == HIGH || j == WIDE)
            {
                printf("+");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void hide_cur()
{
    // 隐藏光标
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = sizeof(cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
int main()
{
    hide_cur(); // 隐藏光标
    init_wall();
    // 申请蛇的结构体
    SNAKE *snake = (SNAKE *)malloc(sizeof(SNAKE)); //=两边类型得一致
    init_snake(snake);                             // 初始化蛇，食物
    show_ui(snake);
    start_game(snake); // 开始游戏

    system("pause");
    return 0;
}