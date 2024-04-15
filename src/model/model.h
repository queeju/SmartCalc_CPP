#ifndef S21_MODEL_H
#define S21_MODEL_H

#include <array>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <utility>

#define DOTS 5000

namespace s21 {
class Parser {
 public:
  Parser(const std::string& input)
      : input_str_(input), flags{0, 0, 0, 0, 0, 0}, error_(0) {}
  ~Parser() = default;
  void ParseInput();
  bool error() { return error_; }
  std::string get_rpn() { return queue_; }

 private:
  void EmptyStack();
  bool IsOperator(int i);
  void UnaryMinus(int i);
  void RightBracket();
  void LeftBracket(int i);
  void HandleDot();
  void HandleX();
  void HandleOperator(char oper);
  int Priority(char a);
  void Substitute();

  std::string input_str_;
  std::stack<char> stack_;
  std::string queue_;
  struct flags {
    int dot, open_bracket, digit, binary_op, special_case, x;
  } flags;
  bool error_;
};

class Evaluator {
 public:
  Evaluator(std::string& rpn, double x_val = 0)
      : rpn_(rpn), error_(0), x_value_(x_val), result_(0) {}
  ~Evaluator() = default;
  void Evaluate();
  double result() { return result_; }
  bool error() { return error_; }
  void set_x(double x_value) { x_value_ = x_value; }
  void reset_err() { error_ = false; }
  void Restore();

 private:
  void BinaryOperation(char ch, double num1, double num2);
  void UnaryOperation(char ch, double num1);

  std::string rpn_;
  std::stack<double> numbers_;
  int error_;
  double x_value_;
  double result_;
};

class ResultFinder {
 public:
  ResultFinder()
      : result_(0),
        error_(false),
        rpn_(""),
        x_value_(0),
        x_coords_(nullptr),
        y_coords_(nullptr) {}
  ~ResultFinder() {
    if (x_coords_) {
      delete x_coords_;
    }
    if (y_coords_) {
      delete y_coords_;
    }
  }
  void Calculate(double x);
  void PlotGraph(double x_min, double x_max);

  // getters
  bool error() const { return error_; }
  double result() const { return result_; }
  const double* x_coords() const { return x_coords_; }
  const double* y_coords() const { return y_coords_; }

  // setters
  void set_rpn(const std::string& rpn) { rpn_ = rpn; }
  void set_x(double x) { x_value_ = x; }

 private:
  double result_;
  bool error_;
  std::string rpn_;
  double x_value_;
  double* x_coords_;
  double* y_coords_;
};

}  // namespace s21

#endif  // S21_MODEL_H