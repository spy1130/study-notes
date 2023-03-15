/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "rpn.h"

void append ( char* rpn, double opnd ) { //将操作数接至RPN末尾
   char buf[64];
   if ( ( int ) opnd < opnd ) sprintf ( buf, "%6.2f \0", opnd ); //浮点格式，或
   else                       sprintf ( buf, "%d \0", ( int ) opnd ); //整数格式
   strcat ( rpn, buf ); //RPN加长
}

void append ( char* rpn, char optr ) { //将运算符接至RPN末尾
   int n = strlen ( rpn ); //RPN当前长度（以'\0'结尾，长度n + 1）
   sprintf ( rpn + n, "%c \0", optr ); //接入指定的运算符
}