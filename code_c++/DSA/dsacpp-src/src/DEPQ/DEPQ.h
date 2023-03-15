/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> struct DEPQ : public PQ<T> { //Double-Ended Priority Queue
   virtual T getMin() = 0; //get the element with the lowest priority
   virtual T delMin() = 0; //remove the element with the lowest priority
}; //DEPQ
