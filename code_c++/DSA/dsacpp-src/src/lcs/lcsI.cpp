#include <algorithm>
using namespace std;

unsigned int lcsIteration(char const * A, int n, char const * B, int m) {
   if (n < m) { swap(A, B); swap(n, m); } //make sure m <= n
   unsigned int* lcs1 = new unsigned int[m+1]; //the current two rows are
   unsigned int* lcs2 = new unsigned int[m+1]; //buffered alternatively
   memset(lcs1, 0x00, sizeof(unsigned int) * (m+1));
   memset(lcs2, 0x00, sizeof(unsigned int) * (m+1));
   for (int i = 0; i < n; swap(lcs1, lcs2), i++)
      for (int j = 0; j < m; j++)
         lcs2[j + 1] = (A[i] == B[j]) ? 1 + lcs1[j] : max(lcs2[j], lcs1[j+1]);
   unsigned int solu = lcs1[m];
   delete[] lcs1;
   delete[] lcs2;
   return solu;
}
