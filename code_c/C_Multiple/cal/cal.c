#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

void Print_Factorial(const int N);

int main()
{
    int N;
    LARGE_INTEGER lpPerformanceCount; // 测时间用的
    QueryPerformanceFrequency(&lpPerformanceCount);
    int c1, c2;

    scanf("%d", &N);
    QueryPerformanceCounter(&lpPerformanceCount); // 获得当前时间，单位是微秒
    c1 = lpPerformanceCount.QuadPart;
    Print_Factorial(N);
    QueryPerformanceCounter(&lpPerformanceCount);
    c2 = lpPerformanceCount.QuadPart;
    printf("\n%ld us\n", c2-c1);
    return 0;
}
void Print_Factorial(const int N)
{
    int num[10000] = {0};
    int ans = 1, list_max = 0, carry = 0;
    if (N < 0) // 当小于0时
        printf("Invalid input\n");
    else if (N == 0) // 等于0时
        printf("1\n");
    else if (N > 0 && N <= 12) // 小于12时
    {
        for (int m = 1; m <= 12; m++)
        {
            ans *= m;
        }
        printf("%d", ans);
    }
    else // 介于12至1000之间
    {
        num[0] = 1;
        for (int i = 2; i <= N; i++) // 乘的数
        {
            for (int n = 0; n <= list_max; n++)
            {
                ans = num[n] * i + carry; // 单位乘i后加上进位的临时值
                num[n] = ans % 10;
                carry = ans / 10; // 记录进位
            }
            while (carry > 0) // 当有进位时前面没有位数,开阔位数，循环也也考虑进位数可能会出现超过个位的现象
            {
                list_max++;
                num[list_max] = carry % 10;
                carry /= 10;
            }
        }
        for (int k = list_max; k >= 0; k--) // 打印
        {
            printf("%d", num[k]);
        }
    }
}