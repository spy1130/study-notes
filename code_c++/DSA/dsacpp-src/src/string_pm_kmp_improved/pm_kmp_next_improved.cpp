/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "string_pm/string_pm_test.h"

int* buildNext ( char* P ) { //构造模式串P的next表（改进版本）
   size_t m = strlen ( P ), j = 0; //“主”串指针
   int* next = new int[m]; int t = next[0] = -1; //next表，首项必为-1
   while ( j < m - 1 )
      if ( 0 > t || P[t] == P[j] ) { //匹配
         if ( P[++t] != P[++j] ) //附加条件判断
            next[j] = t; //唯当新的一对字符也匹配时，方照原方法赋值
         else
            next[j] = next[t]; //否则，改用next[t]（此时必有：P[next[t]] != P[t] == P[j]）
      } else //失配
         t = next[t]; //继续尝试下一值得尝试的位置
   /*DSA*/printString ( P ); printf ( "\n" );
   /*DSA*/printNext ( next, 0, m );
   return next;
}
