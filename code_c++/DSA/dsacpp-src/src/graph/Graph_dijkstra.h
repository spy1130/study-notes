/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> //���·��Dijkstra�㷨��������һ�������ͼ
void Graph<Tv, Te>::dijkstra( Rank s ) { // s < n
   reset(); priority( s ) = 0;
   for ( Rank i = 0; i < n; i++ ) { //��������n�������n-1����
      status( s ) = VISITED;
      if ( -1 != parent( s ) ) type( parent( s ), s ) = TREE; //���뵱ǰ��s
      for ( Rank j = firstNbr( s ); - 1 != j; j = nextNbr( s, j ) ) //ö��s�������ھ�j
         if ( ( status( j ) == UNDISCOVERED ) && ( priority( j ) > priority( s ) + weight( s, j ) ) ) //���ڽӶ���j���ɳ�
            { priority( j ) = priority( s ) + weight( s, j ); parent( j ) = s; } //��Prim�㷨Ψһ�Ĳ�֮ͬ��
      int shortest = INT_MAX;
      for ( Rank j = 0; j < n; j++ ) //ѡ����һ�������
         if ( ( status( j ) == UNDISCOVERED ) && ( shortest > priority( j ) ) )
            { shortest = priority( j ); s = j; }
   }
} //����������ͨͼ������ÿһ���߱�ʾΪ�����桢Ȩ����ȵ�һ�Ա�