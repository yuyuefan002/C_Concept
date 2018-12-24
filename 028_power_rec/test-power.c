#include "stdio.h"
#include "stdlib.h"
#define size 6
unsigned power(unsigned x, unsigned y);
void run_check(unsigned x, unsigned y, unsigned expected_ans) {
  if (power(x, y) != expected_ans || x == (unsigned)'a') {
    printf("the code is broken!");
    exit(EXIT_FAILURE);
  }
}

int main() {
  unsigned x[size] = {1, -1, 5, 2, 0, -2};
  unsigned y[size] = {0, 2, 2, 5, 0, 5};
  unsigned expected_ans[size] = {1, 1, 25, 32, 1, -32};
  for (int i = 0; i < size; i++) {
    run_check(x[i], y[i], expected_ans[i]);
  }
  printf("all cases are passed");
  return EXIT_SUCCESS;
}
