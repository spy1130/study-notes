/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void quickSelect( Vector<T>& A, Rank k ) { //基于快速划分的k选取算法
   for ( Rank lo = 0, hi = A.size(); lo < hi; ) {
      Rank i = lo, j = hi; T pivot = A[lo]; //大胆猜测
      while ( i < j ) { //小心求证：O(hi - lo + 1) = O(n)
         do j--; while ( ( i < j ) && ( pivot <= A[j] ) );
         if ( i < j ) A[i] = A[j];
         do i++; while ( ( i < j ) && ( A[i] <= pivot ) );
         if ( i < j ) A[j] = A[i];
      } // assert: quit with i == j or j+1
      A[j] = pivot; // A[0,j) <= A[j] <= A(j, n)
      if ( k <= j ) hi = j; //suffix trimmed
      if ( i <= k ) lo = i; //prefix trimmed
      /*DSA*///print ( A ); for ( int i = 0; i < lo; i++ ) printf ( "     " ); for ( int i = lo; i < hi; i++ ) printf ( "-----" ); printf ( "\n" );
   } //A[k] is now a pivot
}
