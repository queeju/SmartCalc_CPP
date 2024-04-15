#include "model.h"

void s21::Parser::ParseInput() {
  Substitute();

  for (size_t i = 0; i < input_str_.size() && !error_; ++i) {
    char ch = input_str_[i];
    if (std::isdigit(ch)) {
      flags.digit = 1;
      flags.binary_op = 1;
      queue_ += ch;
    } else if (ch == 'x') {
      if (flags.digit) {
        HandleOperator('*');
      }
      HandleX();
      flags.binary_op = 1;
    } else if (ch == '.') {
      HandleDot();
    } else {
      flags.dot = 0;
      flags.digit = 0;
      if (ch == ' ') {
        queue_ += ' ';
      } else if (ch == '(') {
        LeftBracket(i);
      } else if (ch == ')') {
        RightBracket();
      } else if (ch == '-' && !flags.binary_op) {
        UnaryMinus(i);
      } else if (ch == '+' && !flags.binary_op) {
        continue;
      } else if (IsOperator(i)) {
        HandleOperator(ch);
        flags.binary_op = 0;
      } else {
        error_ = 1;
      }
    }
  }
  EmptyStack();
}

void s21::Parser::EmptyStack() {
  while (!stack_.empty()) {
    queue_ += " ";
    queue_ += stack_.top();
    stack_.pop();
  }
}

bool s21::Parser::IsOperator(int i) {
  return std::string("%-+*/^").find(input_str_[i]) != std::string::npos ||
         (std::string("sctukgqnl").find(input_str_[i]) != std::string::npos &&
          input_str_[i + 1] == '(');
}

void s21::Parser::UnaryMinus(int i) {
  if (size_t(i + 1) < input_str_.size()) {
    char next_ch = input_str_[i + 1];
    if (next_ch == '(') {
      flags.special_case = 1;
      stack_.push('(');
    } else if (next_ch > 'a' && next_ch < 'z') {
      queue_ += "-1 ";
      stack_.push('*');
    } else {
      queue_ += input_str_[i];
    }
  } else {
    error_ = 1;
  }
}

void s21::Parser::RightBracket() {
  if (flags.open_bracket) {
    flags.binary_op = 1;

    while (stack_.top() != '(') {
      queue_ += ' ';
      queue_ += stack_.top();
      queue_ += ' ';
      stack_.pop();
    }
    if (flags.special_case) {
      queue_ += "-1 * ";
      flags.special_case = 0;
      stack_.pop();
    }
    stack_.pop();
    flags.open_bracket -= 1;
  } else {
    error_ = 1;
  }
}

void s21::Parser::LeftBracket(int i) {
  if (size_t(i + 1) < input_str_.size() && (input_str_[i + 1] == ')')) {
    error_ = 1;
  } else {
    flags.open_bracket += 1;
    flags.binary_op = 0;
    stack_.push('(');
  }
}

void s21::Parser::HandleDot() {
  if (flags.digit && !flags.dot) {
    queue_ += '.';
    flags.dot = 1;
    flags.digit = 0;
  } else {
    error_ = 1;
  }
}

void s21::Parser::HandleX() {
  queue_ += '@';
  flags.x = 1;
  flags.digit = 1;
}

void s21::Parser::HandleOperator(char oper) {
  if (stack_.empty() || (Priority(oper) > Priority(stack_.top()))) {
    queue_ += ' ';
    stack_.push(oper);
  } else {
    while (!stack_.empty() && Priority(oper) <= Priority(stack_.top())) {
      queue_ += ' ';
      queue_ += stack_.top();
      stack_.pop();
      queue_ += ' ';
    }
    stack_.push(oper);
  }
}

int s21::Parser::Priority(char a) {
  int res = 0;
  if (a == '+' || a == '-')
    res = 1;
  else if (a == '*' || a == '/' || a == '%')
    res = 2;
  else if (a == '^')
    res = 3;
  else if (a > 'a' && a < 'z')
    res = 4;
  return res;
}

void s21::Parser::Substitute() {
  std::array<std::pair<std::string, std::string>, 10> substitutions = {
      std::make_pair("acos", "k"), std::make_pair("asin", "u"),
      std::make_pair("atan", "g"), std::make_pair("cos", "c"),
      std::make_pair("sin", "s"),  std::make_pair("tan", "t"),
      std::make_pair("sqrt", "q"), std::make_pair("ln", "n"),
      std::make_pair("log", "l"),  std::make_pair("mod", "%")};

  for (const auto& sub : substitutions) {
    size_t pos = 0;
    // Find and replace all occurrences of the target substring
    while ((pos = input_str_.find(sub.first, pos)) != std::string::npos) {
      input_str_.replace(pos, sub.first.length(), sub.second);
      pos++;  // Move past the replaced substring
    }
  }
}

void s21::Evaluator::Evaluate() {
  std::string rpn = rpn_;
  char delim[] = " ";
  char* token = strtok(&rpn[0], delim);

  if (token[0] == '@') {
    numbers_.push(x_value_);
  } else {
    numbers_.push(atof(token));
  }

  token = strtok(nullptr, delim);
  double num1 = 0, num2 = 0;
  while (token != nullptr && !numbers_.empty() && !error_) {
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
      numbers_.push(atof(token));
    } else if (token[0] == '@') {
      numbers_.push(x_value_);
    } else {
      char ch = token[0];
      num1 = numbers_.top();
      numbers_.pop();
      if (ch > 'a' && ch < 'z') {
        UnaryOperation(ch, num1);
      } else if (!numbers_.empty()) {
        num2 = numbers_.top();
        numbers_.pop();
        BinaryOperation(ch, num1, num2);
      } else {
        error_ = 3;
      }
      numbers_.push(result_);
    }
    token = strtok(nullptr, delim);
  }
  result_ = numbers_.top();
  numbers_.pop();
  if (!numbers_.empty()) error_ = 4;
}

void s21::Evaluator::Restore() {
  while (!numbers_.empty()) {
    numbers_.pop();
  }
  reset_err();
  result_ = 0;
}

void s21::Evaluator::BinaryOperation(char ch, double num1, double num2) {
  if (ch == '+') {
    result_ = num2 + num1;
  } else if (ch == '-') {
    result_ = num2 - num1;
  } else if (ch == '*') {
    result_ = num1 * num2;
  } else if (ch == '/') {
    if (num1) {
      result_ = num2 / num1;
    } else {
      error_ = 1;
    }
  } else if (ch == '^') {
    result_ = pow(num2, num1);
  } else if (ch == '%') {
    if (num1) {
      result_ = fmod(num2, num1);
    } else {
      error_ = 2;
    }
  }
}

void s21::Evaluator::UnaryOperation(char ch, double num1) {
  if (ch == 'c') {
    result_ = cos(num1);
  } else if (ch == 's') {
    result_ = sin(num1);
  } else if (ch == 't') {
    result_ = tan(num1);
  } else if (ch == 'u') {
    result_ = asin(num1);
  } else if (ch == 'k') {
    result_ = acos(num1);
  } else if (ch == 'g') {
    result_ = atan(num1);
  } else if (ch == 'q') {
    result_ = sqrt(num1);
  } else if (ch == 'n') {
    result_ = log(num1);
  } else if (ch == 'l') {
    result_ = log10(num1);
  }
  if (std::isnan(result_)) {
    error_ = true;
  }
}

void s21::ResultFinder::Calculate(double x) {
  error_ = false;
  Evaluator eval(rpn_, x);
  eval.Evaluate();
  if (!eval.error()) {
    result_ = eval.result();
  } else {
    error_ = true;
  }
}

void s21::ResultFinder::PlotGraph(double x_min, double x_max) {
  x_coords_ = new double[DOTS]{0};
  y_coords_ = new double[DOTS]{0};
  double step = (x_max - x_min) / DOTS;
  double i = x_min;
  Evaluator eval(rpn_);
  for (int j = 0; j < DOTS; j++) {
    x_coords_[j] = i;
    eval.Restore();
    eval.set_x(i);
    eval.Evaluate();

    if (eval.error()) {
      y_coords_[j] = NAN;
    } else {
      y_coords_[j] = eval.result();
    }
    i += step;
  }
}
