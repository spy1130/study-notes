#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string>

unsigned int lcsIteration(char const * A, int n, char const * B, int m);
unsigned int lcsMemoization(char const * A, int n, char const * B, int m);
unsigned int lcsRecursion(char const * A, int n, char const * B, int m);

/******************************************************************************************
 * 最长公共子串
 * Example test cases:
 *    HNAJBJDJU   LDVFGDKD
 *    ZEIEZCCTPZ   WPUZALLPBXL
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   srand((unsigned int)time(NULL));
   int errors = 0, tests = 100;
   for (int k = 0; k < tests; k++) {
      printf("\n%d\n", k);
      char* A; int n; char* B; int m;
      if (2 < argc) {
         m = strlen(argv[2]); B = argv[2];
      }
      else {
         m = 9 + rand() % 9; B = new char[m + 1];
         for (int j = 0; j < m; j++)
            B[j] = 'A' + (rand() % 26);
         B[m] = 0;
      }
      if (1 < argc) {
         n = strlen(argv[1]); A = argv[1];
      }
      else {
         n = 9 + rand() % 9; A = new char[n + 1];
         for (int i = 0; i < n; i++)
            A[i] = 'A' + (rand() % 26);
         A[n] = 0;
      }
      unsigned int lcsI = lcsIteration(A, n, B, m);
      unsigned int lcsM = lcsMemoization(A, n, B, m);
      unsigned int lcsR = lcsRecursion(A, n, B, m);
      errors += lcsI != lcsM || lcsM != lcsR;
      if ( lcsI == lcsM )
         printf("%2u == %2u", lcsI, lcsM);
      else
         printf("%2u <> %2u", lcsI, lcsM);
      if ( lcsM == lcsR )
         printf(" == %2u", lcsR);
      else
         printf(" <> %2u", lcsR);
      printf(" : %18s [%2d] ~ %18s [%2d]\n", A, n, B, m);
      if (argc < 3) delete[] B;
      if (argc < 2) delete[] A;
   }
   printf("\n%d / %d\n", tests - errors, tests);
   return 0;
}
