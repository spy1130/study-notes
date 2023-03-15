/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> bool Skiplist<K, V>::remove( K k ) { //跳转表词条删除算法
   QNodePosi< Entry<K, V> > p = search ( k ); //查找目标词条
   if ( !p->pred || (k != p->entry.key) )  return false; //若不存在，直接返回
   ListNodePosi< Quadlist< Entry<K, V> >* > qlist = last(); //从底层Quadlist开始
   while ( p->above ) { qlist = qlist->pred; p = p->above; } //升至塔顶
   do { //逐层拆塔
      QNodePosi< Entry<K, V> > lower = p->below; //记住下一层节点，并
      qlist->data->remove( p ); //删除当前层节点，再
      p = lower; qlist = qlist->succ; //转入下一层
   } while ( qlist->succ ); //直到塔基
   while ( (1 < height()) && (first()->data->_size < 1) ) { //逐层清除
      List::remove( first() ); 
      first()->data->header->above = NULL;
   } //已不含词条的Quadlist（至少保留最底层空表）
   return true; //删除成功
} //体会：得益于哨兵的设置，哪些环节被简化了？
