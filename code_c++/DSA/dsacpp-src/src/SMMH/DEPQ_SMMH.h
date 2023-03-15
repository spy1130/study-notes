/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "Vector/Vector.h" //借助多重继承机制，基于向量
#include "DEPQ/DEPQ.h" //按照优先级队列ADT实现的

template <typename T> class SMMH : public DEPQ<T>, public Vector<T> { //Symmetric Min-Max Heap
   /*DSA*/friend class UniPrint; //For test. Just remove this line for real applications
protected:
   //void heapify ( Rank n ); //Floyd's heapification
public:
   SMMH() { insert((T) -1); } //initialized with a dummy root
   void insert( T ); //insert an element (duplicates accepted)
   T getMin() { return _elem[1]; }
   T getMax() { return _size < 3 ? _elem[1] : _elem[2]; }
   T delMin();
   T delMax();
}; //SMMH

/*DSA*/#include "DEPQ_SMMH_macro.h"
/*DSA*/#include "DEPQ_SMMH_implementation.h"
