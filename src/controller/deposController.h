#ifndef DEPOS_CONTROLLER_H
#define DEPOS_CONTROLLER_H
#include "../model/deposModel.h"

namespace s21 {
class deposController {
 public:
  deposController(double init_investment, double contribution, double term,
                  double rate)
      : depos_calc_(init_investment, contribution, term, rate){};
  ~deposController() = default;

  // getters
  double end_balance() const { return depos_calc_.end_balance(); }
  double total_contribs() const { return depos_calc_.total_contribs(); }
  double total_interest() const { return depos_calc_.total_interest(); }

  void calculateDeposit(bool compound) {
    depos_calc_.calculateDeposit(compound);
  }

 private:
  DeposCalc depos_calc_;
};

}  // namespace s21
#endif  // DEPOS_CONTROLLER_H