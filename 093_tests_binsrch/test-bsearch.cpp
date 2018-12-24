#include <math.h>

#include <iostream>

#include "function.h"

class CountedIntFn : public Function<int, int>
{
 protected:
  unsigned remaining;
  Function<int, int> * f;
  const char * mesg;

 public:
  CountedIntFn(unsigned n, Function<int, int> * fn, const char * m) :
      remaining(n),
      f(fn),
      mesg(m) {}

  virtual int invoke(int arg) {
    if (remaining == 0) {
      fprintf(stderr, "Too many function invocations in %s\n", mesg);
      exit(EXIT_FAILURE);
    }
    remaining--;
    return f->invoke(arg);
  }
};

int binarySearchForZero(Function<int, int> * f, int low, int high);
class SinFunction : public Function<int, int>
{
 public:
  virtual int invoke(int arg) { return 10000000 * (sin(arg / 100000.0) - 0.5); }
};

class constFunction : public Function<int, int>
{
 public:
  virtual int invoke(int arg) { return arg; }
};

void check(Function<int, int> * f, int low, int high, int expected_ans, const char * mesg) {
  unsigned limit;
  if (low == high) {
    limit = 1;
  }
  else {
    limit = log2(high - low) + 1;
  }

  Function<int, int> * cf = new CountedIntFn(limit, f, mesg);
  int test_ans = binarySearchForZero(cf, low, high);
  if (expected_ans != test_ans) {
    fprintf(stderr, "Wrong answer! \n");
    exit(EXIT_FAILURE);
  }
}

int main()

{
  int low = 0;
  int high = 150000;
  int expected_ans = 52359;
  Function<int, int> * fn = new SinFunction();
  check(fn, low, high, expected_ans, "test1");

  low = 52359;
  high = 52359;
  expected_ans = 52359;
  check(fn, low, high, expected_ans, "test2");

  low = 52360;
  high = 150000;
  expected_ans = 52360;
  check(fn, low, high, expected_ans, "test3");

  low = 0;
  high = 52359;
  expected_ans = 52358;
  check(fn, low, high, expected_ans, "test4");

  fn = new constFunction();
  low = -2;
  high = 5;
  expected_ans = 0;
  check(fn, low, high, expected_ans, "test5");
  std::cout << "pass all test" << std::endl;
  return 0;
}
