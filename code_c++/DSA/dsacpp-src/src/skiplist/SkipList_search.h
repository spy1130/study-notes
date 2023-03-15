/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * Skiplist词条查找算法（供内部调用）
 * 返回关键码不大于k的最后一个词条（所对应塔的基座）
 ******************************************************************************************/
template <typename K, typename V> QNodePosi<Entry<K, V>> Skiplist<K, V>::search( K k ) {
   for ( QNodePosi<Entry<K, V>> p = first()->data->header; ; ) //从顶层Quadlist的首节点p出发
      if ( ( p->succ->succ ) && ( p->succ->entry.key <= k ) ) p = p->succ; //尽可能右移
      else if ( p->below ) p = p->below; //水平越界时，下移
      else return p; //验证：此时的p符合输出约定（可能是最底层列表的header）
} //体会：得益于哨兵的设置，哪些环节被简化了？
