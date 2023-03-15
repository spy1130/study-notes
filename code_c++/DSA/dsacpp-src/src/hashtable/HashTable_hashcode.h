/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

static Rank hashCode( char c ) { return (Rank)c; } //字符
static Rank hashCode( int k ) { return (Rank)k; } //整数以及长长整数
static Rank hashCode( long long i ) { return (Rank)( ( i >> 32 ) + (int)i ); }
static Rank hashCode( char s[] ) { //生成字符串的循环移位散列码（cyclic shift hash code）
   Rank n = strlen( s ); Rank h = 0; //散列码
   for ( Rank i = 0; i < n; i++ ) { //自左向右，逐个处理每一字符
      h = ( h << 5 ) | ( h >> 27 ); //左移5位即乘以32；右移27位作为扰动（通常与最高位有关）
      h += s[i]; //累计上当前字符的贡献
   }
   return h; //如此所得的散列码，实际上可理解为近似的“多项式散列码”
} //32接近于26，故此方法针对于英文字符串；对于中文等其他字符串，需做相应的调整
