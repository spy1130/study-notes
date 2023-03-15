/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> Rank percolateUp( T* A, Rank i ) { //对词条A[i]做上滤，0 <= i < _size
   while ( 0 < i ) { //在抵达堆顶之前，反复地
      Rank j = Parent( i ); //考查[i]之父亲[j]
      if ( lt( A[i], A[j] ) ) break; //一旦父子顺序，上滤旋即完成；否则
      swap( A[i], A[j] ); i = j; //父子换位，并继续考查上一层
   } //while
   return i; //返回上滤最终抵达的位置
}
