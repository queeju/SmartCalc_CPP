#include "deposit.h"

#include "../controller/deposController.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) : QDialog(parent), ui(new Ui::Deposit) {
  ui->setupUi(this);
  term_buttons = new QButtonGroup(this);
  term_buttons->addButton(ui->rb_months);
  term_buttons->addButton(ui->rb_years);

  interest_buttons = new QButtonGroup(this);
  interest_buttons->addButton(ui->rb_compound);
  interest_buttons->addButton(ui->rb_simple);

  ui->rb_months->setChecked(true);
  ui->rb_simple->setChecked(true);
}

Deposit::~Deposit() { delete ui; }

void Deposit::on_pb_calculate_clicked() {
  // input
  int flag_compound = ui->rb_compound->isChecked();
  bool val1, val2, val3, val4;
  double init_investment = ui->init_invest->text().toDouble(&val1);
  double term = ui->term->text().toDouble(&val2);
  double interest = ui->interest_rate->text().toDouble(&val3);
  double contribution = ui->monthly_contrib->text().toDouble(&val4);
  int valid = val1 + val2 + val3 + val4;
  if (init_investment > 0 && term > 0 && interest > 0 && contribution >= 0) {
    valid++;
  }
  if (valid != 5) {
    QMessageBox::critical(this, "Error", "Enter valid values");
  }
  if (ui->rb_years->isChecked()) {
    term *= 12;
  }

  s21::deposController depos_controller(init_investment, contribution, term,
                                        interest);
  depos_controller.calculateDeposit(flag_compound);

  // output
  double end_balance = depos_controller.end_balance();
  double total_contribs = depos_controller.total_contribs();
  double total_interest = depos_controller.total_interest();

  QString str_end_balance = QString::number(end_balance, 'f', 2);
  ui->res_end_balance->setText(str_end_balance);

  QString str_total_contribs = QString::number(total_contribs, 'f', 2);
  ui->res_total_contribs->setText(str_total_contribs);

  QString str_total_interest = QString::number(total_interest, 'f', 2);
  ui->res_total_interest->setText(str_total_interest);
}

void Deposit::on_pb_clear_clicked() {
  ui->res_end_balance->setText("0");
  ui->res_total_contribs->setText("0");
  ui->res_total_interest->setText("0");
  ui->init_invest->setText("");
  ui->term->setText("");
  ui->interest_rate->setText("");
  ui->monthly_contrib->setText("");
  ui->rb_months->setChecked(true);
  ui->rb_simple->setChecked(true);
}
