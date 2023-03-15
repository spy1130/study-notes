#include <algorithm>
using namespace std;

unsigned int lcsM(char const * A, int n, char const * B, int m, unsigned int * const lcs, int const M) {
   if (n < 1 || m < 1) return 0;
   if (UINT_MAX != lcs[(n-1)*M + m-1])
      return lcs[(n-1)*M + m-1]; //recursion stops here
   else
      return lcs[(n-1)*M + m-1] = (A[n-1] == B[m-1]) ?
               1 + lcsM(A, n-1, B, m-1, lcs, M) :
               max( lcsM(A, n-1, B, m, lcs, M), lcsM(A, n, B, m-1, lcs, M) );
}

unsigned int lcsMemoization(char const* A, int n, char const* B, int m) {
   unsigned int * lcs = new unsigned int[n*m]; //a lookup-table of all sub-solutions
   memset(lcs, 0xFF, sizeof(unsigned int)*n*m); //initialized with n*m UINT_MAX's
   unsigned int solu = lcsM(A, n, B, m, lcs, m);
   delete[] lcs;
   return solu;
}
