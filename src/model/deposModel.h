#ifndef DEPOS_MODEL_H
#define DEPOS_MODEL_H

namespace s21 {
class DeposCalc {
 public:
  DeposCalc() = default;
  DeposCalc(double init_investment, double contribution, double term,
            double rate)
      : init_investment_(init_investment),
        contribution_(contribution),
        term_(term),
        rate_(rate) {}
  ~DeposCalc() = default;

  // getters
  double end_balance() const { return end_balance_; }
  double total_contribs() const { return total_contribs_; }
  double total_interest() const { return total_interest_; }

  void calculateDeposit(bool compound);

 private:
  double init_investment_;
  double contribution_;
  double term_;
  double rate_;
  double end_balance_;
  double total_contribs_;
  double total_interest_;
};

void DeposCalc::calculateDeposit(bool compound) {
  rate_ /= 100;
  if (!compound && !contribution_) {
    total_interest_ = init_investment_ * rate_ / 12 * term_;
    end_balance_ = total_interest_ + init_investment_;
  } else if (!compound && contribution_) {
    for (int i = 0; i < term_; i++) {
      init_investment_ += contribution_;
      total_interest_ += init_investment_ * rate_ / 12;
    }
    total_contribs_ = contribution_ * term_;
    end_balance_ = total_interest_ + init_investment_;
  } else if (compound) {
    double curr_interest = 0;
    end_balance_ = init_investment_;
    for (int i = 0; i < term_; i++) {
      end_balance_ += contribution_;
      curr_interest = end_balance_ * rate_ / 12;
      end_balance_ += curr_interest;
      total_interest_ += curr_interest;
    }
    total_contribs_ = contribution_ * term_;
  }
}
}  // namespace s21
#endif  // DEPOS_MODEL_H
