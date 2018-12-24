#include <iostream>

#include "function.h"

/*int binarySearchForZero(Function<int, int> * f, int low, int high) {
  while (low < high) {
    int mid = low + (high - low) / 2;
    int result = f->invoke(mid);
    if (result > 0) {
      high = mid;
    }
    else if (result < 0) {
      low = mid;
    }
    else {
      return mid;
    }
    if (high - low <= 1) {
      return low;
    }
  }
  return low;
  }*/

int binarySearchForZero(Function<int, int> * f, int low, int high) {
  if (high - low <= 1) {
    return low;
  }
  int mid = low + (high - low) / 2;
  int result = f->invoke(mid);
  if (result > 0) {
    return binarySearchForZero(f, low, mid);
  }
  else if (result < 0) {
    return binarySearchForZero(f, mid, high);
  }
  else {
    return mid;
  }
}
