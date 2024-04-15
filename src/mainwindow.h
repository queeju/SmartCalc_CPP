#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFont>
#include <QFontDatabase>
#include <QGuiApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QScreen>
#include <string>

#include "../controller/calcController.h"
#include "../model/model.h"
#include "credit.h"
#include "deposit.h"
#include "info.h"
#include "plotter.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Plotter *myPlot;
  Credit *credWindow;
  info *infoWindow;
  Deposit *depositWindow;
  s21::CalcController calc_control;
  void connect_windows();
  void connect_slots();
  void set_icons();
  void close_credit();
  void close_plot();
  void close_info();
  void close_deposit();
  void moveEvent(QMoveEvent *event);
  void updateDialogPositions();
  QPoint dialog_window_position{459, 29};

 signals:
  void plot_signal(std::string);

 private slots:

  void on_key_input_returnPressed();
  void input_button_clicked();
  void on_all_clear_clicked();
  void delete_button_clicked();
  void on_deposit_clicked();
  void on_credit_clicked();
  void on_graph_clicked();
  void on_info_clicked();
};
#endif  // MAINWINDOW_H
