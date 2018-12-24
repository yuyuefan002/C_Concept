#include <math.h>

#include <iostream>

#include "function.h"
#include "search.cpp"
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

//int binarySearchForZero(Function<int, int> * f, int low, int high);
int binarySearchForZero2(Function<int, int> * f, int low, int high) {
  int l = low;
  int h = high;
  int x, result;
  if (l == h) {
    result = f->invoke(l);
    if (result > 0)
      return h - 1;
    else
      return l;
  }

  while (true) {
    x = (l + h) / 2;
    result = f->invoke(x);
    if (result > 0)
      h = x;
    else if (result < 0)
      l = x;
    else
      return x;
    if (h - l <= 1)
      return l;
    if (x == high || x == low)
      return x;
  }
}

class SinFunction : public Function<int, int>
{
 public:
  virtual int invoke(int arg) { return 10000000 * (sin(arg / 100000.0) - 0.5); }
};

class constFunction : public Function<int, int>
{
 public:
  virtual int invoke(int arg) { return -10 + arg / 100000; }
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
  // std::cout << test_ans << std::endl;
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
  low = 1000;
  high = 1500000;
  expected_ans = 1031562;
  check(fn, low, high, expected_ans, "test5");
  std::cout << "pass all test" << std::endl;
  return 0;
}
