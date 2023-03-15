/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> struct DijkPU { //针对Dijkstra算法的顶点优先级更新器
   virtual void operator()( Graph<Tv, Te>* g, Rank v, Rank u ) {
      if ( UNDISCOVERED == g->status( u ) ) //对于v每一尚未被发现的邻接顶点u，按Dijkstra策略
         if ( g->priority( u ) > g->priority( v ) + g->weight( v, u ) ) { //做松弛
            g->priority( u ) = g->priority( v ) + g->weight( v, u ); //更新优先级（数）
            g->parent( u ) = v; //并同时更新父节点
         }
   }
};
