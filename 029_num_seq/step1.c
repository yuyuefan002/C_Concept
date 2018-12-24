// This file is for Step 1.
// You should do
//  Step 1 (A): write seq1
//  Step 1 (B): write main to test seq1
//  Step 1 (C): write printSeq1Range
//  Step 1 (D): add test cases to main to test printSeq1Range
//
// Be sure to #include any header files you need!
#include "stdio.h"
#include "stdlib.h"
//calculate seq1
int seq1(int x) {
  return 1 + (x - 1) * 4;
}
//check seq1
int check_printf(int x, int expected_ans) {
  int res = seq1(x);
  if (res != expected_ans) {
    printf("fail the test %d, expected result should be %d, but the result is %d\n",
           x,
           expected_ans,
           res);
    exit(EXIT_FAILURE);
  }
  return res;
}
//printf seq1 in sequence
void printSeq1Range(int low, int high) {
  for (int i = low; i < high; i++) {
    printf("%d", seq1(i));
    if (i != high - 1)
      printf(", ");
  }
  printf("\n");
}
int main() {
  //initialize test cases
  int test_case[] = {1, 0, -4, 10, 100, -100, 10000, -10000};
  int expected_ans[] = {1, -3, -19, 37, 397, -403, 39997, -40003};
  int size_tc1 = sizeof(test_case) / sizeof(test_case[0]);
  int test_case2[][2] = {{7, 3}, {0, 4}, {-2, 6}, {1, 2}, {-2, -2}};
  int size_tc2 = sizeof(test_case2) / sizeof(test_case2[0]);
  for (int i = 0; i < size_tc1; i++) {
    printf("seq1(%d) = %d\n", test_case[i], check_printf(test_case[i], expected_ans[i]));
    //    check_printf(test_case[i], expected_ans[i]);
  }
  printf("pass all the tests!!!\n");
  for (int i = 0; i < size_tc2; i++) {
    printf("printSeq1Range(%d, %d)\n", test_case2[i][0], test_case2[i][1]);
    printSeq1Range(test_case2[i][0], test_case2[i][1]);
  }
  printf("pass all the tests!!!\n");
  return EXIT_SUCCESS;
}
