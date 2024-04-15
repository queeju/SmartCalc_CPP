#include "plotter.h"

#include "ui_plotter.h"

Plotter::Plotter(QWidget *parent) : QDialog(parent), ui(new Ui::Plotter) {
  ui->setupUi(this);
  this->setWindowTitle("Graph");
  ui->myGraph->addGraph();
  // make zoom
  ui->myGraph->setInteraction(QCP::iRangeZoom, true);
  ui->myGraph->setInteraction(QCP::iRangeDrag, true);
  ui->myGraph->replot();
}

Plotter::~Plotter() { delete ui; }

void Plotter::plot_slot(std::string str) {
  QVector<double> x(DOTS), y(DOTS);
  bool val1, val2, val3, val4;
  double x_min = ui->x_min->text().toDouble(&val1);
  double y_min = ui->y_min->text().toDouble(&val2);
  double x_max = ui->x_max->text().toDouble(&val3);
  double y_max = ui->y_max->text().toDouble(&val4);
  int valid = val1 + val2 + val3 + val4;
  if (valid != 4) {
    QMessageBox::critical(this, "Error",
                          "Enter valid domain and codomain values");
  }
  ui->myGraph->yAxis->setRange(x_min, x_max);
  ui->myGraph->xAxis->setRange(y_min, y_max);
  calc_control.HandleInput(str);
  if (calc_control.error()) {
    QMessageBox::critical(this, "Error",
                          "Enter valid domain and codomain values");
  }
  calc_control.PlotGraph(x_min, x_max);
  const double *x_coords = calc_control.x_coords();
  const double *y_coords = calc_control.y_coords();
  for (int i = 0; i < DOTS; i++) {
    x[i] = x_coords[i];
    y[i] = y_coords[i];
  }

  ui->myGraph->clearGraphs();
  ui->myGraph->addGraph();
  QPen my_pen;
  my_pen.setColor(QColor(53, 121, 78, 255));
  my_pen.setWidthF(1.5);
  ui->myGraph->graph(0)->setPen(my_pen);
  ui->myGraph->graph(0)->setData(x, y);
  ui->myGraph->xAxis->setRange(x_min, x_max);
  ui->myGraph->yAxis->setRange(y_min, y_max);
  ui->myGraph->replot();
}
