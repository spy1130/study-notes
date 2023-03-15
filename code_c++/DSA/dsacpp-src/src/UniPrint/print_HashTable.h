/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * Hashtable
 ******************************************************************************************/

template <typename K, typename V> //e、value
void UniPrint::p ( Hashtable<K, V>& HT ) { //引用
   printf( "%s[%d]*(%d + %d)/%d:\n", typeid( HT ).name(), (int)&HT, HT.N, HT.removed->size(), HT.M ); //基本信息
   for ( Rank i = 0; i < HT.M; i++ ) //输出桶编号
      printf ( "  %4d  ", i );
   printf ( "\n" );
   for ( Rank i = 0; i < HT.M; i++ ) //输出所有元素
      if ( HT.ht[i] ) printf ( "-<%04d>-", HT.ht[i]->key ); //演示用，仅适用于int
      else if ( HT.removed->test(i) ) printf ( "-<****>-" );
      else printf ( "--------" );
   printf ( "\n" );
   for ( Rank i = 0; i < HT.M; i++ ) //输出所有元素
      if ( HT.ht[i] ) printf ( "    %c   ", HT.ht[i]->value ); //演示用，仅适用于char
//      if (ht.ht[i]) printf("%8s", ht.ht[i]->value); //针对Huffman编码中使用的散列表
      else if ( HT.removed->test(i) ) printf ( "    *   " );
      else printf ( "        " );
   printf ( "\n" );
}
