#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QButtonGroup>
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Deposit;
}

class Deposit : public QDialog {
  Q_OBJECT

 public:
  explicit Deposit(QWidget *parent = nullptr);
  ~Deposit();

 private slots:
  void on_pb_calculate_clicked();

  void on_pb_clear_clicked();

 private:
  Ui::Deposit *ui;
  QButtonGroup *term_buttons;
  QButtonGroup *interest_buttons;
};

#endif  // DEPOSIT_H
