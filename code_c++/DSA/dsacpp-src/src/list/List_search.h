/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //在有序列表内节点p（可能是trailer）的n个（真）前驱中，找到不大于e的最后者
ListNodePosi<T> List<T>::search( T const& e, Rank n, ListNodePosi<T> p ) const {
   do { // 0 <= n <= Rank(p) < _size
      p = p->pred; n--;  //从右向左  /*DSA*/ ( -1 == n ) ? printf( " -->header" ) : printf( " -->%4d", p->data );
   } while ( ( -1 != n ) && ( e < p->data ) ); //逐个比较，直至命中或越界  /*DSA*/  printf ( "\n" );
   return p; //返回查找终止的位置
} //失败时，返回区间左边界的前驱（可能是header）——调用者可通过valid()判断成功与否