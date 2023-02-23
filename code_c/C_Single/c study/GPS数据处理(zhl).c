#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*输入多个GPS数据,经处理后格式化输出最后一个指定数据的时间*/
int main()
{
    char string[100],str1[100],*str2,*symbol;
    int temp,num1,num2,i,time,result = 0;
    while(1)
    {
        memset(string,'\0',sizeof(string)); // 清空字符串
        memset(str1,'\0',sizeof(str1));
        scanf("%s",string);
        if(string[0] == 'E') break; // 判断是否结束
        sscanf(string,"$%[^*]*%x",str1,&num1); // 分割成 从$到*间的一段字符串 和 末尾的校验值 两部分
        str2 = strtok(string,","); // 分割第一段前缀
        time = atoi(strtok(NULL,",")); // 分割第二段时间
        symbol = strtok(NULL,","); // 分割第三段字符
        if(strcmp(str2,"$GPRMC") || symbol[0] != 'A') continue; // 判断是否符合条件
        else temp = num2 = i = 0; // 第二遍一定要记得重置！！！
        do // 计算异或值
        {
            num2 ^= str1[i];
            i++;
        } while(str1[i] != '\0');
        if(num1 == num2) // 与校验值比对
        {
            time += 80000; // 换算成北京时间
            temp = time/10000 - 24;
            if(temp >= 0) time += temp - 24; // 判断是否超过24小时
            result = time;
        }
    }
    if(result) printf("%02d:%02d:%02d\n",result/10000,(result-result/10000*10000)/100,result-result/10000*10000-((result-result/10000*10000)/100)*100); // 格式化输出
    else printf("No vaild data\n");
    return 0;   
}

/*
  input sample:
  $GPRMC,014600.00,A,2237.496474,N,11356.089515,E,0.0,225.5,310518,2.3,W,A*23
  $GPRMC,010101.130,A,3606.6834,N,12021.7778,E,0.0,238.3,010807,,,A*6C
  END
  output sample:
  09:01:01
*/