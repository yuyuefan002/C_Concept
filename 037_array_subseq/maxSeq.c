#include "stdio.h"
#include "stdlib.h"

size_t max(size_t x, size_t y) {
  if (x >= y)
    return x;
  return y;
}

size_t maxSeq(int * array, size_t n) {
  if (n < 1)
    return n;
  size_t maxCount = 1;
  size_t count = 1;
  for (size_t i = 1; i < n; i++) {
    if (array[i] > array[i - 1]) {
      count++;
    }
    else
      count = 1;
    maxCount = max(maxCount, count);
  }
  return maxCount;
}
