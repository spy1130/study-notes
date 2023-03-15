/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include<iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "UniPrint/print.h"

#include "stack/stack.h"

bool paren ( const char exp[], Rank lo, Rank hi );
void displaySubstring ( const char exp[], Rank lo, Rank hi );
void displayProgress ( const char exp[], Rank i, Stack<char> S );
