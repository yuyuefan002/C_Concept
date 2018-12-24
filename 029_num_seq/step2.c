// This file is for Step 2.
// You should do
//  Step 2 (A): write seq2
//  Step 2 (B): write main to test seq2
//  Step 2 (C): write sumSeq2
//  Step 2 (D): add test cases to main to test sumSeq2
//
// Be sure to #include any header files you need!
#include "stdio.h"
#include "stdlib.h"
//return num in seq
int seq2(int x) {
  //old method, recursion,too complicated
  //  if (x == 0)
  // return 1;
  //if (x >= 0)
  //  return seq2(x - 1) + (x + 1) * 2;
  //else
  //  return seq2(x + 1) - (x + 2) * 2;
  //easy way to find the num
  return 1 + x * (x + 3);
}
//check seq2
int run_check_seq2(int x, int expected_ans) {
  int num = seq2(x);
  if (num != expected_ans) {
    printf(
        "\nfail the test %d,the result should be %d, but the result is %d\n", x, expected_ans, num);
    exit(EXIT_FAILURE);
  }
  return num;
}
//sum the num in seq2
int sumSeq2(int low, int high) {
  int sum = 0;
  for (int i = low; i < high; i++) {
    sum += seq2(i);
  }
  return sum;
}
//check sumSeq2
int run_check_sumSeq2(int * test_case, int expected_ans) {
  int res = sumSeq2(test_case[0], test_case[1]);
  if (res != expected_ans) {
    printf("fail the test (%d, %d),the result should be %d, but the result is %d\n",
           test_case[0],
           test_case[1],
           expected_ans,
           res);
    exit(EXIT_FAILURE);
  }
  return res;
}
int main() {
  //initialize the test cases;
  int test_case[] = {0, -1, 14, -2, -4, 500, 5000, 10000};
  int expected_ans[] = {1, -1, 239, -1, 5, 251501, 25015001, 100030001};
  int size_tc1 = sizeof(test_case) / sizeof(test_case[0]);
  int test_case2[][2] = {{0, 2}, {3, 6}, {9, 7}, {9, 9}, {-3, -0}};
  int expected_ans2[] = {6, 89, 0, 0, -1};
  int size_tc2 = sizeof(test_case2) / sizeof(test_case2[0]);
  for (int i = 0; i < size_tc1; i++) {
    printf("seq2(%d) = %d\n", test_case[i], run_check_seq2(test_case[i], expected_ans[i]));
    //run_check_seq2(test_case[i], expected_ans[i]);
  }
  printf("pass all test case for seq2!!\n");
  for (int i = 0; i < size_tc2; i++) {
    printf("sumSeq2(%d, %d) = %d\n",
           test_case2[i][0],
           test_case2[i][1],
           run_check_sumSeq2(test_case2[i], expected_ans2[i]));
    //    run_check_sumSeq2(test_case2[i], expected_ans2[i]);
  }
  printf("pass all test case for sumSeq2!!\n");
  return EXIT_SUCCESS;
}
