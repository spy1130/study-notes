// 2、利用sleep函数(Linux平台)结合结构体，编写一个模拟时钟
#include <stdio.h>
#include <windows.h>

typedef struct Time
{ // 表示时间的数据类型
    int hour;
    int minute;
    int second;
} Time;

int main(){
    Time data[1]={
        {10,00,00}
    };
    printf("当前时间为：");
    while (1)
    {Sleep(1000);
        data[0].second++;
        if(data[0].second >= 60){
            data[0].second=0;
            data[0].minute++;
            if(data[0].minute >=60){
                data[0].minute=0;
                data[0].hour++;
                if(data[0].hour >=24){
                    data[0].hour =0;
                }
            }
        }

    }
    printf("\r%02d:%02d:%02d",data[0].hour,data[0].minute,data[0].second);
    fflush(stdout);
}
/*提示：
1)#include <unistd.h>
  sleep(1);  //以秒为单位

2) fflush(stdout); //人为刷新打印缓冲区
   "\r"，转义字符，跳到句首打印*/
