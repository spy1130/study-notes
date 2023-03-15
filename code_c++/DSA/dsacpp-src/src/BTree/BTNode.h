/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "vector/vector.h"
template <typename T> struct BTNode;
template <typename T> using BTNodePosi = BTNode<T>*; //B-树节点位置

template <typename T> struct BTNode { //B-树节点模板类
// 成员（为简化描述起见统一开放，读者可根据需要进一步封装）
   BTNodePosi<T> parent; //父节点
   Vector<T> key; //关键码向量
   Vector<BTNodePosi<T>> child; //孩子向量（总比关键码多一个）
// 构造函数
   BTNode() { parent = NULL; child.insert( NULL ); } //无关键码节点
   BTNode( T e, BTNodePosi<T> lc = NULL, BTNodePosi<T> rc = NULL ) {
      parent = NULL; key.insert( e ); //作为根节点只有一个关键码，以及
      child.insert( lc ); if ( lc ) lc->parent = this; //左孩子
      child.insert( rc ); if ( rc ) rc->parent = this; //右孩子
   }
};