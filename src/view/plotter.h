#ifndef PLOTTER_H
#define PLOTTER_H

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QVector>

#include "../controller/calcController.h"
// #include "../view/qcustomplot.h"

namespace Ui {
class Plotter;
}

class Plotter : public QDialog {
  Q_OBJECT

 public:
  explicit Plotter(QWidget *parent = nullptr);
  ~Plotter();

 public slots:
  void plot_slot(std::string str);

 private slots:

 private:
  Ui::Plotter *ui;
  s21::CalcController calc_control;
};

#endif  // PLOTTER_H
