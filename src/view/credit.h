#ifndef CREDIT_H
#define CREDIT_H

#include <QButtonGroup>
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>

//#include "../model/model.h"
#include "../controller/credController.h"

namespace Ui {
class Credit;
}

class Credit : public QDialog {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private:
  Ui::Credit *ui;
  QButtonGroup *termButtons;
  QButtonGroup *typeButtons;
  //  s21::credController cred_controller;

 private slots:

  void on_buttonCalculate_clicked();

  void on_buttonClear_clicked();
};

#endif  // CREDIT_H
