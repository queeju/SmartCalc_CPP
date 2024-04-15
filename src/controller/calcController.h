#ifndef CALC_CONTROLLER_H
#define CALC_CONTROLLER_H

#include <string>

#include "../model/model.h"

namespace s21 {
class CalcController {
 public:
  CalcController() : result_(0), error_(false), x_value_(0) {}
  ~CalcController() = default;
  void HandleInput(std::string input);
  void Calculate();
  void PlotGraph(double x_max, double x_min);

  bool error() const { return error_; }
  double result() const { return result_; }
  const double* x_coords() const { return res_finder_.x_coords(); }
  const double* y_coords() const { return res_finder_.y_coords(); }

  void set_x(const double x) { x_value_ = x; }
  void reset_err() { error_ = false; }

 private:
  double result_;
  bool error_;
  double x_value_;
  ResultFinder res_finder_;
};

}  // namespace s21
#endif  // CALC_CONTROLLER_H