/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //通过调整元素位置，构造出区间[lo, hi)内的一个轴点
Rank Vector<T>::partition( Rank lo, Rank hi ) { // DUP版：可优化处理多个关键码雷同的退化情况
   swap( _elem[lo], _elem[lo + rand() % ( hi - lo )] ); //任选一个元素与首元素交换
   T pivot = _elem[lo]; //经以上交换，等效于随机选取候选轴点
   while ( lo < hi ) { //从两端交替扫描，直至相遇
      do hi--; while ( ( lo < hi ) && ( pivot < _elem[hi] ) ); //向左拓展后缀G
      if ( lo < hi ) _elem[lo] = _elem[hi]; //阻挡者归入前缀L
      do lo++; while ( ( lo < hi ) && ( _elem[lo] < pivot ) ); //向右拓展前缀L
      if ( lo < hi ) _elem[hi] = _elem[lo]; //阻挡者归入后缀G
   } // assert: quit with lo == hi or hi + 1
   _elem[hi] = pivot; //候选轴点置于前缀、后缀之间，它便名副其实
   return hi; //返回轴点的秩
}
