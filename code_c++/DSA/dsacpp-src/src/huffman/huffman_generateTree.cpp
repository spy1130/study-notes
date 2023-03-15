/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "huffman_PQ.h"

HuffTree* minHChar ( HuffForest* forest ) { //在Huffman森林中找出权重最小的超字符
   ListNodePosi<HuffTree*> m = forest->first(); //从首节点出发，遍历所有节点
   for ( ListNodePosi<HuffTree*> p = m->succ; forest->valid( p ); p = p->succ )
      if ( m->data->root()->data.weight > p->data->root()->data.weight ) //不断更新
         m = p; //找到最小节点（所对应的Huffman子树）
   return forest->remove( m ); //从森林中取出该子树，并返回
}

HuffTree* generateTree ( HuffForest* forest ) { //Huffman编码算法
   while ( 1 < forest->size() ) {
      HuffTree* T1 = minHChar ( forest ); HuffTree* T2 = minHChar ( forest );
      HuffTree* S = new HuffTree(); /*DSA*/printf ( "\n################\nMerging " ); print ( T1->root()->data ); printf ( " with " ); print ( T2->root()->data ); printf ( " ...\n" );
      S->insert ( HuffChar ( '^', T1->root()->data.weight + T2->root()->data.weight ) );
      S->attach ( T1, S->root() ); S->attach ( S->root(), T2 );
      forest->insertAsLast ( S ); /*DSA*/ //print(forest);
   } //assert: 循环结束时，森林中唯一（列表首节点中）的那棵树即Huffman编码树
   return forest->first()->data;
}