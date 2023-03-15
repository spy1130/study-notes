/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "Vector/Vector.h" //引入向量
#include "Graph/Graph.h" //引入图ADT

template <typename Tv> struct Vertex { //顶点对象（为简化起见，并未严格封装）
   Tv data; int inDegree, outDegree; VStatus status; //数据、出入度数、状态
   Rank dTime, fTime; //时间标签
   Rank parent; int priority; //在遍历树中的父节点、优先级数
   Vertex( Tv const& d = (Tv)0 ) : //构造新顶点
      data( d ), inDegree( 0 ), outDegree( 0 ), status( UNDISCOVERED ), dTime( -1 ),
      fTime( -1 ), parent( -1 ), priority( INT_MAX ) {} //暂不考虑权重溢出
};

template <typename Te> struct Edge { //边对象（为简化起见，并未严格封装）
   Te data; int weight;
   EType type; //数据、权重、类型
   Edge( Te const& d, int w ) : data( d ), weight( w ), type( UNDETERMINED ) {} //构造
};

template <typename Tv, typename Te> //顶点类型、边类型
class GraphMatrix : public Graph<Tv, Te> { //基于向量，以邻接矩阵形式实现的图
private:
   Vector<Vertex<Tv>> V; //顶点集（向量）
   Vector<Vector<Edge<Te>*>> E; //边集（邻接矩阵）
public:
   GraphMatrix() { n = e = 0; } //构造
   ~GraphMatrix() { //析构
      for ( Rank v = 0; v < n; v++ ) //所有动态创建的
         for ( Rank u = 0; u < n; u++ ) //边记录
            delete E[v][u]; //逐条清除
   }
// 顶点的基本操作：查询第v个顶点（0 <= v < n）
   virtual Tv& vertex( Rank v ) { return V[v].data; } //数据
   virtual Rank inDegree( Rank v ) { return V[v].inDegree; } //入度
   virtual Rank outDegree( Rank v ) { return V[v].outDegree; } //出度
   virtual Rank firstNbr( Rank v ) { return nextNbr( v, n ); } //首个邻接顶点
   virtual Rank nextNbr( Rank v, Rank u ) //相对于顶点u的下一邻接顶点（改用邻接表效率更高）
      { while ( ( -1 != --u ) && !exists( v, u ) ); return u; } //逆向线性试探
   virtual VStatus& status( Rank v ) { return V[v].status; } //状态
   virtual Rank& dTime( Rank v ) { return V[v].dTime; } //时间标签dTime
   virtual Rank& fTime( Rank v ) { return V[v].fTime; } //时间标签fTime
   virtual Rank& parent( Rank v ) { return V[v].parent; } //在遍历树中的父亲
   virtual int& priority( Rank v ) { return V[v].priority; } //在遍历树中的优先级数
// 顶点的动态操作
   virtual Rank insert( Tv const& vertex ) { //插入顶点，返回编号
      for ( Rank u = 0; u < n; u++ ) E[u].insert( NULL ); n++; //各顶点预留一条潜在的关联边
      E.insert( Vector<Edge<Te>*>( n, n, (Edge<Te>*)NULL ) ); //创建新顶点对应的边向量
      return V.insert( Vertex<Tv>( vertex ) ); //顶点向量增加一个顶点
   }
   virtual Tv remove( Rank v ) { //删除第v个顶点及其关联边（0 <= v < n）
      for ( Rank u = 0; u < n; u++ ) //所有
         if ( exists( v, u ) ) //出边
            { delete E[v][u]; V[u].inDegree--; e--; } //逐条删除
      E.remove( v ); n--; //删除第v行
      Tv vBak = vertex( v ); V.remove( v ); //删除顶点v
      for ( Rank u = 0; u < n; u++ ) //所有
         if ( Edge<Te>* x = E[u].remove( v ) ) //入边
            { delete x; V[u].outDegree--; e--; } //逐条删除
      return vBak; //返回被删除顶点的信息
   }
// 边的确认操作
   virtual bool exists( Rank v, Rank u ) //边(v, u)是否存在
      { return ( v < n ) && ( u < n ) && ( E[v][u] != NULL ); }
// 边的基本操作：查询顶点v与u之间的联边（0 <= v, u < n且exists(v, u)）
   virtual EType& type( Rank v, Rank u ) { return E[v][u]->type; } //边(v, u)的类型
   virtual Te& edge( Rank v, Rank u ) { return E[v][u]->data; } //边(v, u)的数据
   virtual int& weight( Rank v, Rank u ) { return E[v][u]->weight; } //边(v, u)的权重
// 边的动态操作
   virtual void insert( Te const& edge, int w, Rank v, Rank u ) { //插入权重为w的边(v, u)
      if ( exists( v, u ) ) return; //确保该边尚不存在
      E[v][u] = new Edge<Te>( edge, w ); //创建新边
      e++; V[v].outDegree++; V[u].inDegree++; //更新边计数与关联顶点的度数
   }
   virtual Te remove( Rank v, Rank u ) { //删除顶点v和u之间的联边（exists(v, u)）
      Te eBak = edge( v, u ); delete E[v][u];
      E[v][u] = NULL; //备份后删除边记录
      e--; V[v].outDegree--; V[u].inDegree--; //更新边计数与关联顶点的度数
      return eBak; //返回被删除边的信息
   }
}; //Graph