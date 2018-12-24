#ifndef __EXPR_H__
#define __EXPR_H__
#include <iostream>
#include <sstream>
#include <string>
class Expression
{
 protected:
  std::string expr;

 public:
  Expression() {}
  //long getNum() { return num; }
  virtual std::string toString() const = 0;
  virtual ~Expression() {}
};
class NumExpression : public Expression
{
 private:
 public:
  NumExpression() {}
  NumExpression(long n) {
    std::stringstream ss;
    ss << n;
    expr = ss.str();
  }
  virtual std::string toString() const { return expr; }
};
class PlusExpression : public Expression
{
 private:
 public:
  PlusExpression(Expression * lhs, Expression * rhs) {
    std::stringstream ss;
    ss << "(" << lhs->toString() << " + " << rhs->toString() << ")";
    expr = ss.str();
    delete lhs;
    delete rhs;
  }
  virtual std::string toString() const { return expr; }
};
#endif
