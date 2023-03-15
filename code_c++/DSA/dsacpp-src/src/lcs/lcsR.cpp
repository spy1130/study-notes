#include <algorithm>
using namespace std;

unsigned int lcsRecursion(char const * A, int n, char const * B, int m) {
   if (n < 1 || m < 1) //trivial cases
      return 0;
   else if (A[n-1] == B[m-1]) //decrease & conquer
      return 1 + lcsRecursion(A, n-1, B, m-1);
   else //divide & conquer
      return max(lcsRecursion(A, n-1, B, m), lcsRecursion(A, n, B, m-1));
}
