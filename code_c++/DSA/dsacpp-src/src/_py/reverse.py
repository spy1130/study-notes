from random import randrange
from timeit import Timer
from sys import stdout

###############################################################################
def show(L): print( str(sum(L)) + '/' + str(len(L)) + ':' + str(L) ); return

###############################################################################
def reverse_1(L): # reverse a list in manner of CALL-BY-RANK
   lo, hi = 0, len(L)-1 # starting from the first and the last element
   while lo < hi: # for each pair of symmetric elements
      L[lo], L[hi] = L[hi], L[lo] # swap them and
      lo, hi = lo+1, hi-1 # consider the next pair
   return L

def reverse_1_test(n): reverse_1([ randrange(n) for i in range(n) ]); return

###############################################################################
def reverse_2(L): # reverse a list in manner of CALL-BY-POSITION
   for i in range( len(L) ): # for each i in [0, n)
      L.insert(i, L.pop()) # move the last element to position i
   return L

def reverse_2_test(n): reverse_2([ randrange(n) for i in range(n) ]); return

###############################################################################
if __name__ == '__main__':
   n = 13
   L = [ randrange(n) for i in range(n) ]; show(L) # create a random list of size n
   L = reverse_1(L); show(L) # reverse it using algorithm #1
   L = reverse_2(L); show(L) # reverse it using algorithm #2
   L.sort(); show(L) # and sort it for verification
   print('\n\t   i        n :       T1     T1/n  |     T2    T2/n/n')
   print(22*'-' + '+' + 20*'-' + '+' + 26*'-' )
   for i in range(18): # for each i in [0, 18) (it slows down on typical PC for i more than 18)
      n = 2**i; # test the two algorithms with a list of size n = 2^i
      t1 = 1000*Timer('__main__.reverse_1_test(__main__.n)', 'import __main__').timeit(1);
      t2 = 1000*Timer('__main__.reverse_2_test(__main__.n)', 'import __main__').timeit(1);
      print('\t2^%2d = %6d : %8.2f %8.5f  | %8.2f %8.5f' %(i, n, t1, t1/n, t2, t2/n/n*1000));
      stdout.flush()
