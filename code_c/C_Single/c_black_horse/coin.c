#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int money;
    scanf("%d", &money);

    // 币值为 0 的情况特殊处理
    if (money == 0) {
        printf("a");
        return 0;
    }

    /*
     * 获取 money 的各位数字并依次存进 digits 数组中，
     * 如 money = 813227345 八亿一千三百二十二万七千三百四十五，则 digits[10] = {5, 4, 3, 7, 2, 2, 3, 1, 8}
     */
    int len = 0;
    int digits[9] = {0};
    while (money) {
        digits[len++] = money % 10;
        money /= 10;
    }

    /*
     * 币值单位：S、B、Q、W、Y 分别代表拾、百、仟、万、亿，
     * 巧妙设计其与 digits 数组的关系，不难看出当逆序遍历 digits 数组时，digits 数组的下标恰与 currencyUnit 单位符合
     *  digits[10]    =     {5,   4,   3,   7,   2,   2,   3,   1,   8}  | 813227345
     *  currencyUnit[9] = {'\0', 'S', 'B', 'Q', 'W', 'S', 'B', 'Q', 'Y'} | 八亿一千三百二十二万七千三百四十五
     */
    char currencyUnit[9] = {'\0', 'S', 'B', 'Q', 'W', 'S', 'B', 'Q', 'Y'};

    // 从 digits 数组尾往头遍历，输出对应的人民币值
    for (int i = len - 1; i >= 0; i--) {
        if (digits[i]) {
            // 字母 a-j 对应数字 0-9，此处输出 money 值及单位，巧用下标 i 与币值单位数组 currencyUnit 的对应关系
            printf("%c%c", digits[i] + 'a', currencyUnit[i]);
        } else if (i == 4) {
            // 判断是否需要输出币值单位万，当且仅当 i == 4 并且存在十万 | 百万 | 千万时才输出 W
            if (digits[5] || digits[6] || digits[7]) {
                printf("W");
            }
        } else if (i - 1 >= 0 && digits[i - 1]) {
            /*
             * 题目要求：“零” 的用法必须符合中文习惯，
             * 向前看一位判断是否输出当前 0 对应的 a，当且仅当当前 0 不是 money 的末位数字且 0 的前一个数字不为 0 时才输出 a，
             * 如 6900（六千九百 gQjB digits = {0, 0, 9, 6, 0...}） 不需要输出 0，
             * 而 6090（六千零九十 gQajS digits = {0, 9, 0, 6, 0...}）仅需要输出 6 和 9 中间的 0
             */
            printf("a");
        }
    }

    return 0;
}

