/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "stack/stack.h" //借助栈结构，计算直方图H[]中的最大矩形（并列时取最靠左者）

__int64 mr_STACK( int H[], Rank n, Rank& mr_r, Rank& mr_s, Rank& mr_t ) { //H[]皆非负
   Stack<Rank> SR; //次栈顶、栈顶总是s[r]-1与r，当前的t = t[r]
   __int64 maxRect = 0;
   for (Rank t = 0; t <= n; t++ ) { //逐个尝试以t为右边界的
      while ( !SR.empty() && ( t == n || H[SR.top()] > H[t] ) ) { //每一个极大矩形
         Rank r = SR.pop(), s = SR.empty() ? 0 : SR.top() + 1;
         __int64 mR = H[r] * ( t - s );
         if ( maxRect < mR )
            { maxRect = mR; mr_r = r; mr_s = s; mr_t = t; }
      }
      if ( t < n ) SR.push( t ); //栈中只记录所有的H[s] = min{ H[k] | s <= k <= t }
   } //assert: SR is empty at exit
   return maxRect;
} //每项进栈、出栈不过常数次，累计成本O(n)
