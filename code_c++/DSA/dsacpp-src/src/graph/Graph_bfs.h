/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> //广度优先搜索BFS算法（全图）
void Graph<Tv, Te>::bfs( Rank s ) { // s < n
   reset(); Rank dClock = 0; //全图复位
   for ( Rank v = s; v < s + n; v++ ) //从s起顺次检查所有顶点
      if ( UNDISCOVERED == status( v % n ) ) //一旦遇到尚未发现者
         BFS( v % n, dClock ); //即从它出发启动一次BFS
} //如此可完整覆盖全图，且总体复杂度依然保持为O(n+e)

template <typename Tv, typename Te> //广度优先搜索BFS算法（单个连通域）
void Graph<Tv, Te>::BFS( Rank v, Rank& dClock ) { // v < n
   Queue<Rank> Q; status( v ) = DISCOVERED; Q.enqueue( v ); dTime( v ) = dClock++; //起点入队
   for ( Rank fClock = 0; !Q.empty(); ) { //在Q变空之前，反复地
      if ( dTime( v ) < dTime( Q.front() ) ) //dTime的增加，意味着开启新的一代，因此
         dClock++, fClock = 0; //dTime递增，fTime复位
      v = Q.dequeue(); //取出首顶点v，并
      for ( Rank u = firstNbr( v ); -1 != u; u = nextNbr( v, u ) ) //考查v的每一个邻居u
         if ( UNDISCOVERED == status( u ) ) { //若u尚未被发现，则发现之
            status( u ) = DISCOVERED; Q.enqueue( u ); dTime( u ) = dClock;
            type( v, u ) = TREE; parent( u ) = v; //引入树边，拓展BFS树
         } else //若u已被发现，或者甚至已访问完毕，则
            type( v, u ) = CROSS; //将(v, u)归类于跨边
      status( v ) = VISITED; fTime( v ) = fClock++; //至此，v访问完毕
   } //for
} //BFS
