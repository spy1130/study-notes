/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "QuadListNode.h" //引入Quadlist节点类

template <typename T> struct Quadlist { //四联列表
   Rank _size; //规模
   QNodePosi<T> header, trailer; //头哨兵、尾哨兵
   void init(); //初始化
   int clear(); //清除所有节点
   Quadlist() { init(); } //构造
   ~Quadlist() { clear(); delete header; delete trailer; } //析构
   T remove( QNodePosi<T> p ); //删除（合法）位置p处的节点，返回被删除节点的数值
   QNodePosi<T> insert( T const& e, QNodePosi<T> p, QNodePosi<T> b = NULL ); //将e作为p的后继、b的上邻插入
   void traverse( void (* ) ( T& ) ); //遍历各节点，依次实施指定操作（函数指针，只读或局部修改）
   template <typename VST> void traverse ( VST& ); //遍历
}; //Quadlist

#include "Quadlist_implementation.h"