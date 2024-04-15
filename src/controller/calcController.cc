#include "calcController.h"

void s21::CalcController::HandleInput(std::string input) {
  if (input == "") {
    error_ = true;
  } else {
    Parser p(input);
    p.ParseInput();
    if (!p.error()) {
      res_finder_.set_rpn(p.get_rpn());
    } else {
      error_ = true;
    }
  }
}

void s21::CalcController::Calculate() {
  if (!error_) {
    res_finder_.Calculate(x_value_);
    error_ = res_finder_.error();
    result_ = res_finder_.result();
  }
}

void s21::CalcController::PlotGraph(double x_max, double x_min) {
  if (!error_) {
    res_finder_.PlotGraph(x_max, x_min);
  }
}
