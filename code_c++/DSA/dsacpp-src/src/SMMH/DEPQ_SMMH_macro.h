/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#define sib(i) ( 1 + ( ( (i) - 1 ) ^ 0x01 ) ) // ( (i) & 1 ? (i) + 1 : (i) - 1 ) //sibling
#define lc(i)  ( 1 + ( ( i ) << 1 ) ) //left child
#define rc(i)  ( ( 1 + ( i ) ) << 1 ) //right child
#define ln(i)  ( lc( sib( i ) ) ) //left nephew
#define rn(i)  ( rc( sib( i ) ) ) //right nephew
#define isLC(i)   ( ( 0 < (i) ) && (     1 & (i)   ) ) //left child
#define isRC(i)   ( ( 0 < (i) ) && ( ! ( 1 & (i) ) ) ) //right child
#define hasGP(i)  ( 2 < (i) ) //having grandparent
#define gp(i)  ( ( (i) - 3 ) >> 2 ) //grandparent
#define lp(i)  ( lc( gp( i ) ) ) //left parent = the left child of grandparent
#define rp(i)  ( rc( gp( i ) ) ) //right parent = the right child of grandparent
