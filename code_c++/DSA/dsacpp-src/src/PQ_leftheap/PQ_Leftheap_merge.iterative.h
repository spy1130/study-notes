/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //合并以a和b为根节点的两个左式堆（迭代版）
BinNodePosi<T> merge( BinNodePosi<T> a, BinNodePosi<T> b ) {
   if ( !a ) return b; //退化情况
   if ( !b ) return a; //退化情况
   if ( lt( a->data, b->data ) ) swap( a, b ); //确保a>=b
   for ( ; a->rc; a = a->rc ) //沿右侧链做二路归并，直至堆a->rc先于b变空
      if ( lt( a->rc->data, b->data ) ) //只有在a->rc < b时才需做实质的操作
         { b->parent = a; swap( a->rc, b ); } //接入b的根节点（及其左子堆）
   ( a->rc = b )->parent = a; //直接接入b的残余部分（必然非空）
   for ( ; a; b = a, a = a->parent ) { //从a出发沿右侧链逐层回溯（b == a->rc）
      if ( !a->lc || ( a->lc->npl < a->rc->npl ) ) //若有必要
         swap( a->lc, a->rc ); //通过交换确保右子堆的npl不大
      a->npl = a->rc ? a->rc->npl + 1 : 1; //更新npl
   }
   return b; //返回合并后的堆顶
} //本算法只实现结构上的合并，堆的规模须由上层调用者负责更新
