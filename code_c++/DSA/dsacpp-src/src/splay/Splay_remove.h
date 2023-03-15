/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool Splay<T>::remove( const T& e ) { //从伸展树中删除关键码e
   if ( !_root || ( e != search( e )->data ) ) return false; //若目标存在，则伸展至根
   BinNodePosi<T> L = _root->lc, R = _root->rc; release( _root ); //记下左、右子树L、R后，释放之
   if ( !R ) { //若R空，则
      if ( L ) L->parent = NULL; _root = L; //L即是余树
   } else { //否则
      _root = R; R->parent = NULL; search( e ); //在R中再次查找e：注定失败，但其中的最小节点必
      if (L) L->parent = _root; _root->lc = L; //伸展至根（且无左孩子），故可令其以L作为左子树
   }
   if ( --_size ) updateHeight( _root ); return true; //更新规模及树高，报告删除成功
}
