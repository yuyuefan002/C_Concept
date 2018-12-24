#ifndef __EXPR_H__
#define __EXPR_H__
#include <iostream>
#include <sstream>
#include <string>
class Expression
{
 protected:
  std::string expr;
  long num;

 public:
  Expression() {}
  //long getNum() { return num; }
  virtual std::string toString() const = 0;
  virtual long evaluate() const = 0;
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
    num = n;
  }
  virtual long evaluate() const { return num; }
  virtual std::string toString() const { return expr; }
};
class opExpression : public Expression
{
 protected:
  std::string lexpr;
  std::string rexpr;
  long lnum;
  long rnum;

 public:
  opExpression(Expression * lhs, Expression * rhs) {
    std::stringstream ss;
    ss << "(" << lhs->toString();
    lexpr = ss.str();
    std::stringstream ss1;
    ss1 << rhs->toString() << ")";
    rexpr = ss1.str();
    lnum = lhs->evaluate();
    rnum = rhs->evaluate();
    delete lhs;
    delete rhs;
  }
  virtual long evaluate() const { return num; };
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
    num = lnum + rnum;
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
    num = lnum - rnum;
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
    num = lnum * rnum;
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
    num = lnum / rnum;
  }
  //virtual std::string toString() const { return expr; }
};
#endif
