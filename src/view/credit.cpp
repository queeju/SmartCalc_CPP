#include "credit.h"

#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QDialog(parent), ui(new Ui::Credit) {
  ui->setupUi(this);

  termButtons = new QButtonGroup(this);
  termButtons->addButton(ui->buttonMonths);
  termButtons->addButton(ui->buttonYears);

  typeButtons = new QButtonGroup(this);
  typeButtons->addButton(ui->buttonAnnuity);
  typeButtons->addButton(ui->buttonDiff);

  ui->buttonAnnuity->setChecked(true);
  ui->buttonMonths->setChecked(true);
}

Credit::~Credit() { delete ui; }

void Credit::on_buttonCalculate_clicked() {
  // input
  bool flagDiff = ui->buttonDiff->isChecked();

  bool val1, val2, val3;
  double amount = ui->inpLoanAmount->text().toDouble(&val1);
  double term = ui->inpTerm->text().toDouble(&val2);
  double interest = ui->inpInterest->text().toDouble(&val3);
  int valid = val1 + val2 + val3;
  if (amount > 0 && term > 0 && interest > 0) {
    valid++;
  }
  if (valid != 4) {
    QMessageBox::critical(this, "Error", "Enter valid values");
  }
  if (ui->buttonYears->isChecked()) {
    term *= 12;
  }

  s21::credController cred_controller(amount, interest, term);
  cred_controller.calculateCredit(flagDiff);

  // output
  double monthly = cred_controller.monthly();
  double overpayment = cred_controller.overpayment();
  double total = cred_controller.total();

  QString strMonthly = "";
  if (flagDiff) strMonthly += "≈";
  strMonthly += QString::number(monthly, 'f', 2);
  ui->outMonthly->setText(strMonthly);

  QString strOver = QString::number(overpayment, 'f', 2);
  ui->outOverpayment->setText(strOver);

  QString strTotal = QString::number(total, 'f', 2);
  ui->outTotal->setText(strTotal);
}

void Credit::on_buttonClear_clicked() {
  ui->inpLoanAmount->setText("");
  ui->inpInterest->setText("");
  ui->inpTerm->setText("");
  ui->outTotal->setText("0.00");
  ui->outMonthly->setText("0.00");
  ui->outOverpayment->setText("0.00");
  ui->buttonAnnuity->setChecked(true);
  ui->buttonMonths->setChecked(true);
}
