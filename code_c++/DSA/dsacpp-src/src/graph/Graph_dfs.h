/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> //深度优先搜索DFS算法（全图）
void Graph<Tv, Te>::dfs( Rank s ) { // s < n
   reset(); Rank clock = 0; //全图复位
   for ( Rank v = s; v < s + n; v++ ) //从s起顺次检查所有顶点
      if ( UNDISCOVERED == status( v % n ) ) //一旦遇到尚未发现者
         DFS( v % n, clock ); //即从它出发启动一次DFS
} //如此可完整覆盖全图，且总体复杂度依然保持为O(n+e)

template <typename Tv, typename Te> //深度优先搜索DFS算法（单个连通域）
void Graph<Tv, Te>::DFS( Rank v, Rank& clock ) { // v < n
   dTime( v ) = clock++; status( v ) = DISCOVERED; //发现当前顶点v
   for ( Rank u = firstNbr( v ); - 1 != u; u = nextNbr( v, u ) ) //考查v的每一个邻居u
      switch ( status( u ) ) { //并视其状态分别处理
         case UNDISCOVERED : // u尚未发现，意味着支撑树可在此拓展
            type( v, u ) = TREE; parent( u ) = v; DFS( u, clock ); break;
         case DISCOVERED : // u已被发现但尚未访问完毕，应属被后代指向的祖先
            type( v, u ) = BACKWARD; break;
         default : // u已访问完毕（VISITED，有向图），则视承袭关系分为前向边或跨边
            type( v, u ) = ( dTime( v ) < dTime( u ) ) ? FORWARD : CROSS; break;
      }
   status( v ) = VISITED; fTime( v ) = clock++; //至此，当前顶点v方告访问完毕
}
