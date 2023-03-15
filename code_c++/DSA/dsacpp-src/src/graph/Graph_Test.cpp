/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

/******************************************************************************************
 * Test of Graph
 ******************************************************************************************/
#include "Graph_test.h"

/******************************************************************************************
 * 生成由v个顶点、e条边构成的随机图
 ******************************************************************************************/
template <typename Tv, typename Te> //顶点类型、边类型
void randomGraph ( GraphMatrix<Tv, Te> & g, Rank n, Rank e ) { //assert: 0 < e(e-1) <= v
   while ( ( g.n < n ) || ( g.e < e ) ) { //随机测试
      if ( g.n < n ) { //顶点
         if ( dice ( 100 ) < 65 ) { //65%概率插入顶点
            Tv vertex = ( Tv ) ( 'A' + dice ( 26 ) );      /*DSA*/printf ( "Inserting vertex" ); print ( vertex ); printf ( " ..." );
            g.insert ( vertex );               /*DSA*/printf ( "done\n" );
         } else { //35%概率删除顶点
            if ( 1 > g.n ) continue;
            int v = dice ( g.n );       /*DSA*/printf ( "Removing vertex %d ...", v );
            Tv x = g.remove ( v );        /*DSA*/printf ( "done with" ); print ( x ); printf ( "\n" );
         }
         /*DSA*/print ( g );
      }
      if ( ( 1 < g.n ) && ( g.e < e ) ) { //边
         if ( dice ( 100 ) < 65 ) { //65%概率插入边
            int v = dice ( g.n ), j = dice ( g.n ); Te e = dice ( ( Te ) 3 * n );
            /*DSA*/printf ( "Inserting edge (%d, %d) = ", v, j ); print ( e ); printf ( " ..." );
            if ( g.exists ( v, j ) ) {
               /*DSA*/printf ( "already exists\n" );
            } else {
               g.insert ( e, e, v, j );      /*DSA*/printf ( "done\n" );
            }
         } else { //35%概率删除边
            int v = dice ( g.n ), j = dice ( g.n );
            /*DSA*/printf ( "Removing edge (%d, %d) ...", v, j );
            if ( g.exists ( v, j ) ) {
               Te e = g.remove ( v, j );  /*DSA*/printf ( "done with" ); print ( e ); printf ( "\n" );
            } else {
               /*DSA*/printf ( "not exists\n" );
            }
         }
         /*DSA*/print ( g );
      }
   }
   for ( Rank v = 0; v < n; v++ ) g.vertex ( v ) = 'A' + (Tv) v;
   /*DSA*/print ( g );
}

/******************************************************************************************
 * 从命令行（文件重定向）中导入图
 ******************************************************************************************/
void importGraph ( GraphMatrix<char, int> & g ) {
   int n; scanf ( "%d\n", &n ); /*DSA*/printf ( "%d vertices\n", n );
   for ( int v = 0; v < n; v++ ) { //插入v个顶点
      char vertex; scanf ( "%c", &vertex );  /*DSA*/printf ( "Inserting vertex" ); print ( vertex ); printf ( " ..." );
      g.insert ( vertex );                  /*DSA*/printf ( "done\n" ); print ( g );
   }
   for ( int v = 0; v < n; v++ )
      for ( int j = 0; j < n; j++ ) { //插入边
         int edge; scanf ( "%d", &edge );
         if ( 0 > edge ) continue;             /*DSA*/printf ( "Inserting edge (%d, %d) = ", v, j ); print ( edge ); printf ( " ..." );
         g.insert ( edge, edge, v, j );        /*DSA*/printf ( "done\n" );
      }
}

/******************************************************************************************
 * 图结构的统一测试
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s -random <n> <e> | -import <n> <e> < <path>\a\a\n", argv[0] ); return -1; }
   // -import < ..\..\_input\graph.prim.0009+0028.txt  ..\..\_output\Graph_Matrix\graph.prim.0009+0028.txt
   // -random 67 543 > ..\..\_output\Graph_Matrix\graph.random.0067+0543.txt
   srand((unsigned int)time(NULL)); //随机种子
   //srand( 31415926 ); //固定种子（假种子，调试用）
   GraphMatrix<char, int> g;
   if ( !strcmp ( "-random", argv[1] ) )
      randomGraph<char, int> ( g, atoi ( argv[2] ), atoi ( argv[3] ) ); //顶点以字符编号，边为整数权重
   else if ( !strcmp ( "-import", argv[1] ) )
      importGraph ( g ); //从命令行（文件重定向）中导入图
   else return -1;
   /*DSA*/printf ( "\n" ); print ( g );
   /*DSA*/printf ( "=== BFS\n" );
   g.bfs ( 0 ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== BFS (PFS)\n" );
   g.pfs ( 0, BfsPU<char, int>() ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== DFS\n" );
   g.dfs ( 0 ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== DFS (PFS)\n" );
   g.pfs ( 0, DfsPU<char, int>() ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== TopoSort\n" );
   Stack<char>* ts = g.tSort ( 0 ); /*DSA*/ print ( ts ); print ( g ); release ( ts );
   /*DSA*/printf ( "=== BCC\n" );
   g.bcc ( 0 ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== Prim\n" );
   g.prim ( 0 ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== Prim (PFS)\n" );
   g.pfs ( 0, PrimPU<char, int>() ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== Dijkstra\n" );
   g.dijkstra ( 0 ); /*DSA*/print ( g );
   /*DSA*/printf ( "=== Dijkstra (PFS)\n" );
   g.pfs ( 0, DijkPU<char, int>() ); /*DSA*/print ( g );
   return 0;
}