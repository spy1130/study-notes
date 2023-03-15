/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> template <typename PU> //优先级搜索（全图）
void Graph<Tv, Te>::pfs( Rank s, PU prioUpdater ) { // s < n
   reset(); //全图复位
   for ( Rank v = s; v < s + n; v++ ) //从s起顺次检查所有顶点
      if ( UNDISCOVERED == status( v % n ) ) //一旦遇到尚未发现者
         PFS( v % n, prioUpdater ); //即从它出发启动一次PFS
} //如此可完整覆盖全图，且总体复杂度依然保持为O(n+e)

template <typename Tv, typename Te> template <typename PU> //顶点类型、边类型、优先级更新器
void Graph<Tv, Te>::PFS( Rank v, PU prioUpdater ) { //优先级搜索（单个连通域）
   priority( v ) = 0; status( v ) = VISITED; //初始化，起点v加至PFS树中
   while ( 1 ) { //将下一顶点和边加至PFS树中
      for ( Rank u = firstNbr( v ); - 1 != u; u = nextNbr( v, u ) ) //对v的每一个邻居u
         prioUpdater( this, v, u ); //更新其优先级及其父亲
      int shortest = INT_MAX;
      for ( Rank u = 0; u < n; u++ ) //从尚未加入遍历树的顶点中，选出下一个优先级
         if ( ( UNDISCOVERED == status( u ) ) && ( shortest > priority( u ) ) ) //最高的
            { shortest = priority( u ), v = u; } //顶点v
      if ( shortest == INT_MAX ) break; //直至所有顶点均已加入
      status( v ) = VISITED; type( parent( v ), v ) = TREE; //将v加入遍历树
   }
} //通过定义具体的优先级更新策略prioUpdater，即可实现不同的算法功能
