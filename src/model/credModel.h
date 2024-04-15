#ifndef CRED_MODEL_H
#define CRED_MODEL_H

#include <cmath>

namespace s21 {
class CredCalc {
 public:
  CredCalc() = default;
  CredCalc(double amount, double interest, double term)
      : amount_(amount), interest_(interest), term_(term) {}
  ~CredCalc() = default;

  // getters
  double monthly() { return monthly_; }
  double overpayment() { return overpayment_; }
  double total() { return total_; }

  void calculateCredit(bool flagDiff);

 private:
  double annuityCalc() const;
  double diffCalc();

  double amount_;
  double interest_;
  double term_;
  double monthly_;
  double overpayment_;
  double total_;
};

}  // namespace s21
#endif  // CRED_MODEL_H
