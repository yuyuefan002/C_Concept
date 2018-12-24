// This file is for Step 3.
// You should do
//  Step 3 (A): write seq3
//  Step 3 (B): write main to test seq3
//  Step 3 (C): write countEvenInSeq3Range
//  Step 3 (D): add test cases to main to test countEvenInSeq3Range
//
// Be sure to #include any header files you need!
#include "stdio.h"
#include "stdlib.h"
int seq3(int x, int y) {
  return y * 2 + x * (y - 3);
}
int run_check_seq3(int x, int y, int expected_ans) {
  int res = seq3(x, y);
  if (res != expected_ans) {
    printf("\nfail the test (%d, %d)\n", x, y);
    exit(EXIT_FAILURE);
  }
  return res;
}
int countEvenInSeq3Range(int xLow, int xHi, int yLow, int yHi) {
  int ans = 0;
  for (int i = xLow; i < xHi; i++) {
    for (int j = yLow; j < yHi; j++) {
      if (seq3(i, j) % 2 == 0) {
        ans++;
      }
    }
  }
  return ans;
}
int run_check_count(int * tc, int expected_ans) {
  int ans = countEvenInSeq3Range(tc[0], tc[1], tc[2], tc[3]);
  if (ans != expected_ans) {
    printf("\nfail the test\n");
    exit(EXIT_FAILURE);
  }
  return ans;
}
int main() {
  int test_case[][2] = {{0, 0}, {5, 5}, {3, -2}, {-4, 5}, {-2, -5}, {10000, 10000}};
  int test_case2[][4] = {{0, 2, 0, 3}, {-3, 2, -3, 3}, {0, 0, 0, 0}, {1, 0, -5, 0}, {0, 1, 0, 1}};
  int expected_ans[] = {0, 20, -19, 2, 6, 99990000};
  int expected_ans2[] = {4, 21, 0, 0, 1};
  int size_tc1 = sizeof(test_case) / sizeof(test_case[0]);
  int size_tc2 = sizeof(test_case2) / sizeof(test_case2[0]);
  for (int i = 0; i < size_tc1; i++) {
    printf("seq3(%d, %d) = %d\n",
           test_case[i][0],
           test_case[i][1],
           run_check_seq3(test_case[i][0], test_case[i][1], expected_ans[i]));
    //    run_check_seq3(test_case[i][0], test_case[i][1], expected_ans[i]);
  }
  printf("pass all tests!!!\n");
  for (int i = 0; i < size_tc2; i++) {
    printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n",
           test_case2[i][0],
           test_case2[i][1],
           test_case2[i][2],
           test_case2[i][3],
           run_check_count(test_case2[i], expected_ans2[i]));
    // run_check_count(test_case2[i], expected_ans2[i]);
  }
  printf("pass all tests!!!\n");
  return EXIT_SUCCESS;
}
