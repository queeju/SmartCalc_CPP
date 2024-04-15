#include "credModel.h"
using namespace s21;

void CredCalc::calculateCredit(bool flagDiff) {
  if (!flagDiff) {
    monthly_ = annuityCalc();
    total_ = monthly_ * term_;
  } else {
    monthly_ = diffCalc();
  }
  overpayment_ = total_ - amount_;
}

double CredCalc::annuityCalc() const {
  double res = 0;
  double rate = interest_ / 1200.0;
  res = amount_ * rate / (1 - std::pow(1 + rate, 0 - term_));
  res = round(res * 100) / 100;
  return res;
}

double CredCalc::diffCalc() {
  double res = 0;
  double remainder = amount_;
  double loanPart = amount_ / term_;
  int i = 0;
  double first = 0, last = 0;
  double days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  while (remainder > 0.001) {
    last = loanPart + (remainder * (interest_ / 100.0) * days[i]) / 365.0;
    last = round(last * 100) / 100;
    if (!i) first = last;
    if (i == 11)
      i = 0;
    else
      i++;
    remainder -= loanPart;
    total_ += last;
  }
  res = (first + last) / 2;
  return res;
}
