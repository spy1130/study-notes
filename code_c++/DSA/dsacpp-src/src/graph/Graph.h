/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

using VStatus = enum { UNDISCOVERED, DISCOVERED, VISITED }; //顶点状态
using EType = enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD }; //边在遍历树中所属的类型

template <typename Tv, typename Te> //顶点类型、边类型
class Graph { //图Graph模板类
private:
   void reset() { //所有顶点、边的辅助信息复位
      for ( Rank v = 0; v < n; v++ ) { //所有顶点的
         status( v ) = UNDISCOVERED; dTime( v ) = fTime( v ) = -1; //状态，时间标签
         parent( v ) = -1; priority( v ) = INT_MAX; //（在遍历树中的）父节点，优先级数
         for ( Rank u = 0; u < n; u++ ) //所有边的
            if ( exists( v, u ) ) type( v, u ) = UNDETERMINED; //类型
      }
   }
   void BFS( Rank, Rank& ); //（连通域）广度优先搜索算法
   void DFS( Rank, Rank& ); //（连通域）深度优先搜索算法
   void BCC( Rank, Rank&, Stack<Rank>& ); //（连通域）基于DFS的双连通分量分解算法
   bool TSort( Rank, Rank&, Stack<Tv>* ); //（连通域）基于DFS的拓扑排序算法
   template <typename PU> void PFS( Rank, PU ); //（连通域）优先级搜索框架
public:
// 顶点
   Rank n; //顶点总数
   virtual Rank insert( Tv const& ) = 0; //插入顶点，返回编号
   virtual Tv remove( Rank ) = 0; //删除顶点及其关联边，返回该顶点信息
   virtual Tv& vertex( Rank ) = 0; //顶点的数据（该顶点的确存在）
   virtual Rank inDegree( Rank ) = 0; //顶点的入度（该顶点的确存在）
   virtual Rank outDegree( Rank ) = 0; //顶点的出度（该顶点的确存在）
   virtual Rank firstNbr( Rank ) = 0; //顶点的首个邻接顶点
   virtual Rank nextNbr( Rank, Rank ) = 0; //顶点（相对当前邻居的）下一邻居
   virtual VStatus& status( Rank ) = 0; //顶点的状态
   virtual Rank& dTime( Rank ) = 0; //顶点的时间标签dTime
   virtual Rank& fTime( Rank ) = 0; //顶点的时间标签fTime
   virtual Rank& parent( Rank ) = 0; //顶点在遍历树中的父亲
   virtual int& priority( Rank ) = 0; //顶点在遍历树中的优先级数
// 边：这里约定，无向边均统一转化为方向互逆的一对有向边，从而将无向图视作有向图的特例
   Rank e; //边总数
   virtual bool exists( Rank, Rank ) = 0; //边(v, u)是否存在
   virtual void insert( Te const&, int, Rank, Rank ) = 0; //在两个顶点之间插入指定权重的边
   virtual Te remove( Rank, Rank ) = 0; //删除一对顶点之间的边，返回该边信息
   virtual EType& type( Rank, Rank ) = 0; //边的类型
   virtual Te& edge( Rank, Rank ) = 0; //边的数据（该边的确存在）
   virtual int& weight( Rank, Rank ) = 0; //边(v, u)的权重
// 算法
   void bfs( Rank ); //广度优先搜索算法
   void dfs( Rank ); //深度优先搜索算法
   void bcc( Rank ); //基于DFS的双连通分量分解算法
   Stack<Tv>* tSort( Rank ); //基于DFS的拓扑排序算法
   void prim( Rank ); //最小支撑树Prim算法
   void dijkstra( Rank ); //最短路径Dijkstra算法
   template <typename PU> void pfs( Rank, PU ); //优先级搜索框架
};

#include "Graph_implementation.h"
