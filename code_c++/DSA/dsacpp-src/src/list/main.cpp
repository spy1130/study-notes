/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

/******************************************************************************************
 * Test of list
 ******************************************************************************************/
#include "list_test.h"

Rank testID = 0; //测试编号

/******************************************************************************************
 * 随机生成长度为n的列表（其中可能包含重复节点）
 ******************************************************************************************/
template <typename T> //元素类型
void randomList ( List<T> & list, Rank n ) { //创建长度为n的列表，其元素随机取自[0, 4n)
   ListNodePosi<T> p =
      ( rand() % 2 )
         ? list.insertAsLast  ( rand() % ( T ) ( n * 4 ) )
         : list.insertAsFirst ( rand() % ( T ) ( n * 4 ) );
   for ( Rank i = 1; i < n; i++ )
      p = rand() % 2
         ? list.insert ( rand() % ( T ) ( n * 4 ), p )
         : list.insert ( p, rand() % ( T ) ( n * 4 ) );
}

/******************************************************************************************
 * 测试列表
 ******************************************************************************************/
#define PRINT(x)  { print(x); crc(x); checkOrder(x); }
template <typename T> void testList( Rank testSize ) {
   printf("\n  ==== Test %2d. Generate a random list with %d elements\n", testID++, testSize);
   List<T> L; randomList(L, testSize); PRINT(L);
   printf("\n  ==== Test %2d. Sort it\n", testID++);
   L.sort(); PRINT(L);

   printf("\n  ==== Test %2d. Generate two sorted lists each with %d random elements\n", testID++, testSize);
   List<T> Lx; randomList(Lx, testSize); PRINT(Lx); Lx.sort(); PRINT(Lx);
   List<T> Ly; randomList(Ly, testSize); PRINT(Ly); Ly.sort(); PRINT(Ly);

   printf("\n  ==== Test %2d. Merge them into a single sorted list\n", testID++);
   Lx.merge(Ly); PRINT(Lx); PRINT(Ly);
//
   printf ( "\n  ==== Test %2d. Generate two lists each of size %d by random insertions\n", testID++, testSize );
   List<T> La; randomList ( La, testSize ); PRINT ( La );
   List<T> Lb; randomList ( Lb, testSize ); PRINT ( Lb );
//
   printf ( "\n  ==== Test %2d. Call list members by Rank (with high complexity)\n", testID++ );
   for ( Rank i = 0; i < La.size(); i++ ) print ( La[i]->data ); printf ( "\n" );
   for ( Rank i = 0; i < Lb.size(); i++ ) print ( Lb[i]->data ); printf ( "\n" );
   printf ( "\n  ==== Test %2d. Concatenation\n", testID++ ); PRINT ( La ); PRINT ( Lb );
   while ( 0 < Lb.size() ) La.insertAsLast ( Lb.remove ( Lb.first() ) ); PRINT ( La ); PRINT ( Lb );
   printf ( "\n  ==== Test %2d. Increase\n", testID++ ); PRINT ( La );
   increase ( La ); PRINT ( La );
   printf ( "\n  ==== Test %2d. Lowpass (with high complexity) on\n", testID++ ); PRINT ( La );
   Rank i = La.size(); while ( 0 < --i ) { La[i-1]->data += La[i]->data; La[i-1]->data >>= 1; } PRINT ( La ); //call-by-rank, clear but slow
   printf ( "\n  ==== Test %2d. reverse\n", testID++ );
   La.reverse(); PRINT ( La );
   printf ( "\n  ==== Test %2d. Copy all\n", testID++ ); PRINT ( La );
   List<T> Le ( La ); PRINT ( Le );
   Rank r = dice( La.size() / 4 ), n = dice( La.size() * 3 / 4, La.size() ) - r;
   printf( "\n  ==== Test %2d. Copy [%d, %d)\n", testID++, r, r + n );
   List<T> Ld( La, r, n ); PRINT( Ld );
   printf ( "\n  ==== Test %2d. Trim by random deletions\n", testID++ ); PRINT ( Ld );
   while ( testSize / 4 < Ld.size() ) {
      Rank N = dice( Ld.size() ); printf ( "removing L[%d]=", N );
      ListNodePosi<T> p = Ld[N]; print ( p->data ); printf ( " ...\n" ); //call-by-rank, clear but slow
      Ld.remove ( p ); PRINT ( Ld );
   }
   printf ( "\n  ==== Test %2d. Copy\n", testID++ ); PRINT ( La );
   List<T> Lf ( La ); PRINT ( Lf );
   printf ( "\n  ==== Test %2d. FIND in\n", testID++ ); PRINT ( Lf );
   for ( Rank i = 0; i <= testSize * 2; i++ ) { //逐一测试[0, 2n]中的所有可能
      ListNodePosi<T> p = Lf.find ( ( T ) i ); printf ( "Looking for " ); print ( ( T ) i ); printf ( ": " );
      if ( p ) { printf ( "found with" ); print ( p->data ); }
      else printf ( "not found" );
      printf ( "\n" );
   } //正确的结构应该是大致（n+1次）失败、（n次）成功相间
   printf ( "\n  ==== Test %2d. Sort\n", testID++ ); PRINT ( La );
   La.sort(); PRINT ( La );
   printf ( "\n  ==== Test %2d. SEARCH in\n", testID++ ); PRINT ( La );
   for ( Rank i = 0; i <= testSize * 2; i++ ) { //逐一测试[0, 2n]中的所有可能
      ListNodePosi<T> p = La.search ( ( T ) i ); printf ( "Looking for " ); print ( ( T ) i ); printf ( ": " );
      printf( ( La.valid( p ) && ( (T)i == p->data ) ) ? "found at" : "failed at" );
      La.valid( p ) ? print( p->data ) : print( "header" );
      printf ( "\n" );
   } //正确的结构应该是大致（n+1次）失败、（n次）成功相间
   printf ( "\n  ==== Test %2d. Remove redundancy in\n", testID++ ); PRINT ( La );
   printf ( "%d node(s) removed\n", La.uniquify() ); PRINT ( La ); La.reverse(); PRINT ( La );
   printf ( "\n  ==== Test %2d. Remove redundancy in\n", testID++ ); PRINT ( Le );
   printf ( "%d node(s) removed\n", Le.deduplicate() ); PRINT ( Le );
   printf ( "\n  ==== Test %2d. Sort\n", testID++ ); PRINT ( Le );
   Le.sort(); PRINT ( Le );
   return;
}

/******************************************************************************************
 * 测试列表
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand( (unsigned int)time( NULL ) ); //随机种子
   //srand( 31415926 ); //固定种子（假种子，调试用）
   testList<int>( atoi( argv[1] ) ); //元素类型可以在这里任意选择
   return 0;
}