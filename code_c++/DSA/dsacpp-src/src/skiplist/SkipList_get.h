/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> V* Skiplist<K, V>::get( K k ) { //跳转表词条查找算法
   QNode< Entry<K, V> >* p = search(k); //无论是否命中，search()都不会返回NULL
   return (p->pred && p->entry.key == k) ? &(p->entry.value) : NULL; //故须再做判断
} //有多个命中时靠后者优先