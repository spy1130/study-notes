#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*输入多个GPS数据,经处理后格式化输出最后一个指定数据的时间*/
char a[100]; // 喂入的数据数组
char *time;  // 储存时间
int h, m, s, flag = 0;
char *check(char *a);
int main()
{
    while (1)
    {
        memset(a, 0, sizeof(a));
        scanf("%s", a);
        if (a[0] == 'E')
            break;
        time = check(a);
        if (time == NULL)
        {
            continue;
        }
        else
        {
            sscanf(time, "%02d%02d%02d.", &h, &m, &s);
            h = h + 8; // 换算北京时间
            h = h > 24 ? h - 24 : h;
            flag = 1;
        } // 检查返回值
    }
    if (flag)
        printf("%02d:%02d:%02d\n", h, m, s);
    else
        printf("No vaild data\n");
    return 0;
}
char *check(char *a)
{
    char *c = a;
    char *p[20] = {NULL};
    char j[100];                        // 前检测数组
    int answer;                         // 校验值
    int cal = 0;                        // 计算值
    sscanf(c, "$%[^*]*%x", j, &answer); // 拆封
    // printf("%s %x",j,answer);
    for (int s = 0; j[s] != 0; s++)
    {
        cal ^= j[s];
    }
    if (cal % 65536 == answer)
    {
        int i = 0;
        do
        {
            p[i] = i == 0 ? strtok(c, ",") : strtok(NULL, ",");
        } while (p[i++] != NULL); 
        if (strcmp(p[0], "$GPRMC") == 0 && *(p[2] + 0) == 'A')
        {
            return p[1];
        }
    }
    return NULL;
}

/*
  input sample:
$GPRMC,014600.00,V,2237.496474,N,11356.089515,E,0.0,225.5,310518,2.3,W,A*23
$GPRMC,010101.130,A,3606.6834,N,12021.7778,E,0.0,238.3,010807,,,A*6C
END
  output sample:
  09:01:01
*/