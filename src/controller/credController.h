#ifndef CRED_CONTROLLER_H
#define CRED_CONTROLLER_H
#include "../model/credModel.h"

namespace s21 {
class credController {
 public:
  credController(double amount, double interest, double term)
      : cred_calc_(amount, interest, term){};
  ~credController() = default;

  double monthly() { return cred_calc_.monthly(); }
  double overpayment() { return cred_calc_.overpayment(); }
  double total() { return cred_calc_.total(); }
  void calculateCredit(bool flagDiff) { cred_calc_.calculateCredit(flagDiff); }

 private:
  CredCalc cred_calc_;
};

}  // namespace s21
#endif  // CRED_CONTROLLER_H
