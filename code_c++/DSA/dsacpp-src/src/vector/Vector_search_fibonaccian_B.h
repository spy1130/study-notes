/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "fibonacci/Fib.h" //引入Fib数列类
//Fibonacci查找算法（版本B）：在有序向量的区间[lo, hi)内查找元素e，0 <= lo <= hi <= _size
template <typename T> static Rank fibSearch( T* S, T const& e, Rank lo, Rank hi ) {
   /*DSA*/printf ( "FIB search (B)\n" );
   for ( Fib fib( hi - lo ); lo < hi; ) { //Fib制表备查；此后每步迭代仅一次比较、两个分支
      /*DSA*/ //for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); else printf ( "<<<<|" ); printf ( "\n" );
      while ( hi - lo < fib.get() ) fib.prev(); //自后向前顺序查找（分摊O(1)）
      Rank mi = lo + fib.get() - 1; //确定形如Fib(k) - 1的轴点
      ( e < S[mi] ) ? hi = mi : lo = mi + 1; //比较后确定深入前半段[lo, mi)或后半段(mi, hi)
   } //即便已经找到，也不能提前终止
   /*DSA*/ //for( int i = 0; i < lo - 1; i++ ) printf ( "     " ); if ( lo > 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" );
   return lo - 1; //至此，[lo]为大于e的最小者，故[lo-1]即为不大于e的最大者
} //有多个命中元素时，返回最靠后者；查找失败时，返回失败的位置
