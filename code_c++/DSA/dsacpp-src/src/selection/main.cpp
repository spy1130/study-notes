/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "_share/util.h"
#include "UniPrint/print.h"
#include "vector/vector.h"
#include "quickSelect.h"

int main( int argc, char* argv[] ) { //基于快速划分的k选取算法测试
   if ( 2 > argc ) { printf ( "Usage: %s <n>\a\a\n", argv[0] ); return 1; }
   Rank n = atoi( argv[1] );
   if ( n < 1 ) { printf ( "Invalid arguments\a\a\n" ); return 1; }
   srand((unsigned int)time(NULL)); //随机种子
   //srand( 31415926 ); //固定种子（假种子，调试用）
   for ( Rank k = 0; k < n; k++ ) {
      Vector<int> A;
      while ( A.size() < n ) // create a random vector
         A.insert( rand() % n );
      /*DSA*///PRINT( A );
      quickSelect( A, k ); // find k-th element
      /*DSA*///PRINT( A ); for ( int i = 0; i < n; i++ ) printf( (i == k) ? " ||||" : " ...." ); printf("\n");
      Vector<int> B( A ); B.sort(); //compared with the sorted copy /*DSA*///PRINT( B );
      printf( ( A[k] == B[k] ) ? " k =%4d OK\n" : " k =%4d Failed\n\n\n", k );
   }
   return 0;
}