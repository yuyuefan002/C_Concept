#include "IntMatrix.h"

#include <cstdio>
IntMatrix ::IntMatrix() : numRows(0), numColumns(0), rows(NULL) {}
IntMatrix::IntMatrix(int r, int c) : numRows(r), numColumns(c), rows(new IntArray *[r]) {
  for (int i = 0; i < r; i++) {
    rows[i] = new IntArray(c);
  }
}
IntMatrix::IntMatrix(const IntMatrix & rhs) {
  numRows = rhs.getRows();
  numColumns = rhs.getColumns();
  rows = new IntArray *[numRows];
  for (int i = 0; i < numRows; i++) {
    rows[i] = new IntArray(rhs[i]);
  }
}
IntMatrix::~IntMatrix() {
  for (int i = 0; i < numRows; i++) {
    delete rows[i];
  }
  delete[] rows;
}
IntMatrix & IntMatrix::operator=(const IntMatrix & rhs) {
  if (this != &rhs) {
    IntArray ** temp = new IntArray *[rhs.getRows()];
    for (int i = 0; i < rhs.getRows(); i++) {
      temp[i] = new IntArray(rhs[i]);
    }
    for (int i = 0; i < numRows; i++) {
      delete rows[i];
    }
    delete[] rows;
    numRows = rhs.getRows();
    numColumns = rhs.getColumns();
    rows = temp;
  }
  return *this;
}
int IntMatrix::getRows() const {
  return numRows;
}
int IntMatrix::getColumns() const {
  return numColumns;
}
const IntArray & IntMatrix::operator[](int index) const {
  //printf("%d and %d\n", index, numRows);
  assert(index < numRows);
  return *rows[index];
}
IntArray & IntMatrix::operator[](int index) {
  //  printf("%d and %d\n", index, numRows);
  assert(index < numRows);
  return *rows[index];
}

bool IntMatrix::operator==(const IntMatrix & rhs) const {
  if (numRows != rhs.getRows() || numColumns != rhs.getColumns()) {
    return false;
  }
  for (int i = 0; i < numRows; i++) {
    if (*rows[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

IntMatrix IntMatrix::operator+(const IntMatrix & rhs) const {
  assert(numRows == rhs.getRows() && numColumns == rhs.getColumns());
  IntMatrix temp = IntMatrix(*this);
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      (*temp.rows[i])[j] += (*rhs.rows[i])[j];
    }
  }
  return temp;
}

std::ostream & operator<<(std::ostream & s, const IntMatrix & rhs) {
  s << "[ ";
  for (int i = 0; i < rhs.getRows(); i++) {
    s << rhs[i];
    if (i != rhs.getRows() - 1) {
      s << ",\n";
    }
  }
  s << " ]";
  return s;
}
