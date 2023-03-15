/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

/******************************************************************************************
 * Test of Vector
 ******************************************************************************************/
#include "cursor_list.h"

/******************************************************************************************
 * 测试游标式列表
 ******************************************************************************************/
int testCursor ( Rank testSize ) {
   CursorList<char> CL ( testSize ); CL.print(); 
   //CL.insert('A'); CL.insert('B'); CL.insert('C'); CL.insert('D'); CL.insert('E'); CL.print();
   //CL.remove(CL.find('A')); CL.remove(CL.find('B')); CL.remove(CL.find('C')); CL.remove(CL.find('D')); CL.remove(CL.find('E')); CL.print();
   //CL.insert('A'); CL.insert('B'); CL.insert('C'); CL.insert('D'); CL.insert('E'); CL.print();
   for ( Rank i = 0; i < 2*testSize ; i++ ) {
      char x = 'A' + ( rand() % 26 );
      if ( 30 < ( rand() % 100 ) ) {
         Rank r = CL.insert ( x );
         if ( r < testSize )
            printf ( "%c inserted at %d\n", x, r );
         else
            printf ( "failed to insert %c into full CL\n", x );
      } else {
         if ( testSize == CL.find ( x ) )
            printf ( "%c not found\n", x );
         else
            printf ( "%c removed at %d\n", x, CL.remove ( CL.find ( x ) ) );
      }
      CL.print();
   }
   for ( char x = 'A'; x <= 'Z'; x++ ) {
      while ( testSize != CL.find ( x ) )
         printf ( "%c removed at %d\n", x, CL.remove ( CL.find ( x ) ) );
      CL.print();
   }
   return 0;
}

/******************************************************************************************
 * 测试向量
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand ( ( unsigned int ) time ( NULL ) ); //设置随机种子
   testCursor ( atoi ( argv[1] ) ); //元素类型可以在这里任意选择
   return 0;
}