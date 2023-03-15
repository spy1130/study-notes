/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //ÏòÁ¿Ï£¶ûÅÅÐò
void Vector<T>::shellSort( Rank lo, Rank hi ) { // 0 <= lo < hi <= size <= 2^31
   /*DSA*/ printf( "Shellsort [%3d, %3d)\n", lo, hi );
   for ( Rank d = 0x7FFFFFFF; 0 < d; d >>= 1 ) // PS Sequence: { 1, 3, 7, 15, 31, ... }
      for ( Rank j = lo + d; j < hi; j++ ) { // for each j in [lo+d, hi)
         T x = _elem[j]; Rank i = j; // within the prefix of the subsequence of [j]
         while ( ( lo + d <= i ) && ( x < _elem[i - d] ) ) // find the appropriate
            _elem[i] = _elem[i - d], i -= d; // predecessor [i]
         _elem[i] = x; // where to insert [j]
      }
}
