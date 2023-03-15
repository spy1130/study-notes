/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //在无序向量中顺序查找e：成功则返回最靠后的出现位置，否则返回lo-1
Rank Vector<T>::find ( T const& e, Rank lo, Rank hi ) const { //0 <= lo < hi <= _size
   while ( ( lo < hi-- ) && ( e != _elem[hi] ) ); //从后向前，顺序查找
   return hi; //若hi < lo，则意味着失败；否则hi即命中元素的秩
}
