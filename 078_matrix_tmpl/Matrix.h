#ifndef __T_MATRIX_H___
#define __T_MATRIX_H___

#include <assert.h>

#include <cstdlib>
#include <iostream>
#include <vector>

//YOUR CODE GOES HERE!

template<typename T>
class Matrix
{
 private:
  int numRows;
  int numColumns;
  std::vector<T> ** rows;

 public:
  Matrix() : numRows(0), numColumns(0), rows(NULL) {}
  Matrix(int r, int c) : numRows(r), numColumns(c), rows(new std::vector<T> *[r]) {
    for (int i = 0; i < r; i++) {
      rows[i] = new std::vector<T>(c);
    }
  }
  Matrix(const Matrix & rhs) :
      numRows(rhs.getRows()),
      numColumns(rhs.getColumns()),
      rows(new std::vector<T> *[numRows]) {
    for (int i = 0; i < numRows; i++) {
      rows[i] = new std::vector<T>(rhs[i]);
    }
  }
  ~Matrix() {
    for (int i = 0; i < numRows; i++) {
      delete rows[i];
    }
    delete[] rows;
  }
  Matrix & operator=(const Matrix & rhs) {
    if (this != &rhs) {
      std::vector<T> ** temp = new std::vector<T> *[rhs.getRows()];
      for (int i = 0; i < rhs.getRows(); i++) {
        temp[i] = new std::vector<T>(rhs[i]);
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
  int getRows() const { return numRows; }
  int getColumns() const { return numColumns; }
  const std::vector<T> & operator[](int index) const {
    assert(index < numRows && index >= 0);
    return *rows[index];
  }
  std::vector<T> & operator[](int index) {
    assert(index < numRows && index >= 0);
    return *rows[index];
  }
  bool operator==(const Matrix & rhs) const {
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
  Matrix operator+(const Matrix & rhs) const {
    assert(numRows == rhs.getRows() && numColumns == rhs.getColumns());
    Matrix temp = Matrix(*this);
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numColumns; j++) {
        (*temp.rows[i])[j] += (*rhs.rows[i])[j];
      }
    }
    return temp;
  }
};
template<typename T>
std::ostream & operator<<(std::ostream & s, const Matrix<T> & rhs) {
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
template<typename T>
std::ostream & operator<<(std::ostream & s, const std::vector<T> & rhs) {
  s << "{";
  for (size_t i = 0; i < rhs.size(); i++) {
    s << rhs[i];
    if (i != rhs.size() - 1) {
      s << ", ";
    }
  }
  s << "}";
  return s;
}

#endif
