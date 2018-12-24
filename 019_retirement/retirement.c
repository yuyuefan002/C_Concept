#include <stdio.h>
#include <stdlib.h>
struct retire_info_tag {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct retire_info_tag retire_info_t;
double update_balance(double balance, double rate, double contribution) {
  balance += balance * rate;
  balance += contribution;
  return balance;
}
void retirement(int startAge, double initial, retire_info_t working, retire_info_t retired) {
  double balance = initial;
  for (int i = 0; i < working.months; i++) {
    int age = (startAge + i) / 12;
    int month = (startAge + i) % 12;
    printf("Age %3d month %2d you have $%.2lf\n", age, month, balance);
    balance = update_balance(balance, working.rate_of_return, working.contribution);
  }
  for (int i = 0; i < retired.months; i++) {
    int age = (startAge + working.months + i) / 12;
    int month = (startAge + working.months + i) % 12;
    printf("Age %3d month %2d you have $%.2lf\n", age, month, balance);
    balance = update_balance(balance, retired.rate_of_return, retired.contribution);
  }
}

int main() {
  retire_info_t working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12;
  retire_info_t retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12;
  retirement(327, 21345, working, retired);
  return EXIT_SUCCESS;
}
