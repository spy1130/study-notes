/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> Rank Vector<T>::deduplicate() { //删除无序向量中重复元素（高效版）
   Rank oldSize = _size; //记录原规模
   for ( Rank i = 1; i < _size; ) //自前向后逐个考查_elem[1,_size)
      if ( -1 == find(_elem[i], 0, i) ) //在前缀[0,i)中寻找与[i]雷同者（至多一个），O(i)
         i++; //若无雷同，则继续考查其后继
      else
         remove(i); //否则删除[i]，O(_size-i)
   return oldSize - _size; //被删除元素总数
}