/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <assert.h>
#include "_share/util.h"
#include "UniPrint/print.h"

using Rank = unsigned int; //秩
#define DEFAULT_CAPACITY  3 //默认的初始容量（实际应用中可设置为更大）

template <typename T> class CursorList { //游标式列表
protected:
   Rank _size; Rank _capacity; //规模、容量
   Rank* _link; T* _elem; //游标指针、数据区
   Rank _data, _free; //数据链表和空闲链表的起点
public:
   CursorList ( Rank c = DEFAULT_CAPACITY ) { //容量为c
      _link = new Rank[_capacity = c]; //游标指针向量
      _elem = new T[_capacity = c]; memset ( _elem, 0, c * sizeof ( T ) ); //数据向量
      _data = _capacity; _size = 0; //数据链表初始为空
      _free = 0; //空闲链表由所有单元依次串接而成
      for ( Rank i = 0; i + 1 < _capacity; i++ ) _link[i] = i + 1;
      _link[_capacity - 1] = _capacity;
   }
   ~CursorList() { delete [] _link; delete [] _elem; } //释放内部空间
   Rank size() const { return _size; } //规模
   bool empty() const { return !_size; } //判空
   Rank find ( T const& e ) const { //查找
      Rank i = _data; //从数据链表起点出发
      while ( ( _capacity != i ) && ( e != _elem[i] ) ) i = _link[i]; //依次比对
      return i;
   }
   Rank insert ( T const& e ) { //插入元素
      assert ( _free < _capacity );
      if ( _size >= _capacity ) return _capacity; //full & insert fails
      Rank k = _free; _free = _link[k]; _elem[k] = e;
      _link[k] = _data; _data = k;
      _size++; return k;
   }
   Rank remove ( Rank k ) { //删除秩为k的元素
      assert ( k < _capacity ); //此前经查找并确认k合法
      if ( _data == k ) { //若[k]为首节点
         _data = _link[k];
      } else { //否则
         Rank i = _data; while ( k != _link[i] ) i = _link[i]; //find i = pred(k)
         _link[i] = _link[k];
      }
      _link[k] = _free; _free = k; _elem[k] = 0;
      _size--; return k;
   }
   void print() {
      printf ( "size = %4d : ", _size );
      for ( Rank i = _data; _capacity != i; i = _link[i] )
      {  printf("   "); UniPrint::p ( _elem[i] ); }
      printf ( "\n" );
      printf ( "\tRank: " ); for ( Rank i = 0; i < _capacity; i++ ) UniPrint::p ( i ); printf ( "\n" );
      printf ( "\tLink: " ); for ( Rank i = 0; i < _capacity; i++ ) UniPrint::p ( _link[i] ); printf ( "\n" );
      printf ( "\tFree: " ); for ( Rank i = _free; i < _capacity; i = _link[i] ) UniPrint::p ( i ); printf ( "\n" );
      printf ( "\tData: " ); for ( Rank i = _data; i < _capacity; i = _link[i] ) UniPrint::p ( i ); printf ( "\n" );
      printf ( "\n\n" );
   }
};

#include "cursor_list_implementation.h"