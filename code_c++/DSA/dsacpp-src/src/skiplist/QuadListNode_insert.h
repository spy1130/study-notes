/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> QNodePosi<T> //将e作为当前节点的后继、b的上邻插入Quadlist
QNode<T>::insert( T const& e, QNodePosi<T> b ) {
   QNodePosi<T> x = new QNode<T>( e, this, succ, NULL, b ); //创建新节点
   succ->pred = x; succ = x; //设置水平逆向链接
   if ( b ) b->above = x; //设置垂直逆向链接
   return x; //返回新节点的位置
}