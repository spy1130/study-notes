/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "stack/stack.h" //借助栈结构，计算直方图H[]中的最大矩形（并列时取最靠左者）

__int64 mr_STACKS( int H[], Rank n, Rank& mr_r, Rank& mr_s, Rank& mr_t ) { //除末项-1哨兵，H[]皆非负
   Rank* s = new Rank[n]; Stack<Rank> S; //自右可见项的秩
   for( Rank r = 0; r < n; r++ ) { //依次计算出
      while ( !S.empty() && ( H[S.top()] >= H[r] ) ) S.pop(); //每一个s(r)
      s[r] = S.empty() ? 0 : 1 + S.top();
      S.push(r);
   }
   while( !S.empty() ) S.pop();

   Rank* t = new Rank[n]; Stack<Rank> T; //自左可见项的秩
   for( Rank r = n-1; -1 != r; r-- ) { //依次计算出
      while ( !T.empty() && H[r] <= H[T.top()] ) T.pop(); //每一个t(r)
      t[r] = T.empty() ? n : T.top();
      T.push(r);
   }
   while( !T.empty() ) T.pop();

   __int64 maxRect = 0;
   for( Rank r = 0; r < n; r++ ) {
      __int64 mR = H[r] * (t[r] - s[r]);
      if ( maxRect < mR )
         { maxRect = mR; mr_r = r; mr_s = s[r]; mr_t = t[r]; }
   }
   delete [] s; delete [] t;
   return maxRect;
} //每项进栈、出栈不过常数次，累计成本O(n)
