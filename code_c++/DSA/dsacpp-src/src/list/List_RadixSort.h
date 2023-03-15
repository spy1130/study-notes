/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

using U = unsigned int; //约定：类型T或就是U；或可转换为U，并依此定序

template <typename T> //对列表中起始于位置p、宽度为n的区间做基数排序
void List<T>::radixSort( ListNodePosi<T> p, Rank n ) { // valid(p) && Rank(p) + n <= size
   /*DSA*///printf ( "RadixSort ...\n" );
   ListNodePosi<T> head = p->pred; //待排序区间为(head, tail)
   ListNodePosi<T> tail = p; for ( Rank i = 0; i < n; i++ ) tail = tail->succ;
   for ( U radixBit = 0x1; radixBit && (p = head); radixBit <<= 1 ) //以下反复地
      for ( Rank i = 0; i < n; i++ ) //根据当前基数位，将所有节点
         radixBit & U (p->succ->data) ? //分拣为后缀（1）与前缀（0）
            insert( remove( p->succ ), tail ) : p = p->succ;
}
