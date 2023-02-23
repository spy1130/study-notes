#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define max 51
void help()
{
    printf("请照着打,按任意键开始,输入首字母将会开始计时,错误则显示为_");
}
void rom(char *str);
void game(char *str);
int main()
{
    char str[max] = {0};
    while (1)
    {
        help();
        rom(str);
        _getch();
        game(str);
        char ch=_getch();
        if(ch==27){
            break;
        }
        system("cls");
    }
    return 0;
}
void rom(char *str)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < max - 1; i++)
    {
        str[i] = rand() % 26 + 'a';
    }
    str[max - 1] = '\0';
}

void game(char *str)
{
    char ch;
    int count = 0, time_strat, time_end;
    system("cls");
    printf("\n%s\n", str);
    for (int i = 0; i < max - 1; i++)
    {   ch=_getch();
        if (i == 0)
        {   
            time_strat=time(NULL);
        }
        if (ch ==str[i])
        {
            printf("%c",ch);
            count++;
        }
        else{
            printf("_");
        }
    }
    time_end=time(NULL);
    printf("\n完成输入!\n用时%d s\n", time_end-time_strat);
    printf("正确率%lf %% \n", (count*1.0/(max -1))*100);
    printf("按下Esc退出,任意健继续! \n\n" );

}