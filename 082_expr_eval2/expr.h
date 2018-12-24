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
class opExpression : public Expression
{
 protected:
  std::string lexpr;
  std::string rexpr;

 public:
  opExpression(Expression * lhs, Expression * rhs) {
    std::stringstream ss;
    ss << "(" << lhs->toString();
    lexpr = ss.str();
    std::stringstream ss1;
    ss1 << rhs->toString() << ")";
    rexpr = ss1.str();
    delete lhs;
    delete rhs;
  }
  virtual std::string toString() const { return expr; }
};
class PlusExpression : public opExpression
{
 private:
 public:
  PlusExpression(Expression * lhs, Expression * rhs) : opExpression(lhs, rhs) {
    std::stringstream ss;
    ss << lexpr << " + " << rexpr;
    expr = ss.str();
  }
  // virtual std::string toString() const { return expr; }
};
class MinusExpression : public opExpression
{
 private:
 public:
  MinusExpression(Expression * lhs, Expression * rhs) : opExpression(lhs, rhs) {
    std::stringstream ss;
    ss << lexpr << " - " << rexpr;
    expr = ss.str();
  }
  //virtual std::string toString() const { return expr; }
};
class TimesExpression : public opExpression
{
 private:
 public:
  TimesExpression(Expression * lhs, Expression * rhs) : opExpression(lhs, rhs) {
    std::stringstream ss;
    ss << lexpr << " * " << rexpr;
    expr = ss.str();
  }
  // virtual std::string toString() const { return expr; }
};
class DivExpression : public opExpression
{
 private:
 public:
  DivExpression(Expression * lhs, Expression * rhs) : opExpression(lhs, rhs) {
    std::stringstream ss;
    ss << lexpr << " / " << rexpr;
    expr = ss.str();
  }
  //virtual std::string toString() const { return expr; }
};
#endif
