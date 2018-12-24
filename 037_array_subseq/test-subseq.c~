#include "stdio.h"
#include "stdlib.h"
size_t maxSeq(int * array, size_t n);
void check_maxSeq(int * array, size_t n, size_t expected_answer, int i) {
  printf("maxSeq(int * array, size_t,n)= %ld, expected_answer = %ld\n",
         maxSeq(array, n),
         expected_answer);
  if (maxSeq(array, n) != expected_answer) {
    printf("fail to pass the test %d!\n", i);
    exit(EXIT_FAILURE);
  }
}
int main() {
  int array[7][10] = {{1, 10, 3, 8, 5, 6, 7, 4, 9, 2},
                      {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
                      {1, 2, 1, 3, 5, 8, 2, 4, 6, 9},
                      {0, 1, -1, 3, 4, 5, 6, 7, 8, 9},
                      {1, 1, 1, 1, 1, 1, 1, 1, 1, 2147483647},
                      {1, 4, 9, 16, 25, 36, 49, 64, 81, 100},
                      {1, -2, 3, -4, 5, -6, 7, -8, 9, -10}};
  int array2[] = {};
  size_t expected_answer[] = {3, 1, 4, 8, 2, 10, 2};
  for (int i = 0; i < 7; i++) {
    size_t n = 10;
    printf("size_t n=%ld\n", n);
    check_maxSeq(array[i], n, expected_answer[i], i);
  }
  check_maxSeq(array2, 0, 0, 7);
  printf("pass all tests\n");
  return EXIT_SUCCESS;
}
