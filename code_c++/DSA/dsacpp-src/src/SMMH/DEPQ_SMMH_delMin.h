/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T SMMH<T>::delMin() { //delMin from a non-empty SMMH
   T minElem = _elem[1]; Rank k = 1; _elem[k] = _elem[--_size]; //initialization
   while (1) { //percolate down
      Rank x = k;
      Rank i = lc(k); if ( (i < _size) && (_elem[i] < _elem[x]) ) x = i;
      Rank j = ln(k); if ( (j < _size) && (_elem[j] < _elem[x]) ) x = j;
      if ( x == k ) break;
      swap(_elem[k], _elem[x]); k = x; //Property #1
      if ( (k+1 < _size) && (_elem[k] > _elem[k+1]) ) swap( _elem[k], _elem[k+1]); //Property #0
   }
   return minElem;
} //delMin
