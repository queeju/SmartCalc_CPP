#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  //    int i = 1;
  //    std::cout << "test " << i++ << "\n";
  ui->setupUi(this);
  setFixedSize(458, 430);
  //  std::cout << "test " << i++ << "\n";
  this->setWindowTitle("Greaterm Calculator");
  //  std::cout << "test " << i++ << "\n";
  set_icons();
  //  std::cout << "test " << i++ << "\n";
  connect_slots();
  //  std::cout << "test " << i++ << "\n";
  ui->graph->setChecked(false);
  ui->credit->setChecked(false);
  ui->deposit->setChecked(false);
  ui->info->setChecked(false);
  //  std::cout << "test " << i++ << "\n";
  myPlot = new Plotter(this);
  myPlot->setWindowFlag(Qt::WindowType::FramelessWindowHint);
  credWindow = new Credit(this);
  credWindow->setWindowFlag(Qt::WindowType::FramelessWindowHint);
  depositWindow = new Deposit(this);
  depositWindow->setWindowFlag(Qt::WindowType::FramelessWindowHint);
  infoWindow = new info(this);
  connect_windows();
  //  std::cout << "test " << i++ << "\n";
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::set_icons() {
  QIcon icon_deposit(":/resources/icons/piggy1.png");
  ui->deposit->setIcon(icon_deposit);
  QIcon icon_credit(":/resources/icons/credit1.png");
  ui->credit->setIcon(icon_credit);
  QIcon icon_graph(":/resources/icons/graph1.png");
  ui->graph->setIcon(icon_graph);
}

void MainWindow::connect_slots() {
  connect(ui->num0, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->num1, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->num2, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->num3, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->num4, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->num5, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->num6, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->num7, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->num8, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->num9, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->plus, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->minus, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->mult, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->divide, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->dot, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->open_br, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->close_br, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->mod, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->ex, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->sin, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->asin, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->cos, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->acos, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->tan, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->atan, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->ln, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->log, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->pow, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->sqrt, SIGNAL(clicked()), this, SLOT(input_button_clicked()));
  connect(ui->delete_2, SIGNAL(clicked()), this, SLOT(delete_button_clicked()));
  connect(ui->all_clear, SIGNAL(clicked()), this, SLOT(on_all_clear_clicked()));
  connect(ui->graph, SIGNAL(clicked()), this, SLOT(on_graph_clicked()));
  connect(ui->credit, SIGNAL(clicked()), this, SLOT(on_credit_clicked()));
  connect(ui->deposit, SIGNAL(clicked()), this, SLOT(on_deposit_clicked()));
  connect(ui->info, SIGNAL(clicked()), this, SLOT(on_info_clicked()));
  connect(ui->equal, SIGNAL(clicked()), this,
          SLOT(on_key_input_returnPressed()));
  connect(ui->key_input, SIGNAL(returnPressed()), this,
          SLOT(on_key_input_returnPressed()));
}

void MainWindow::moveEvent(QMoveEvent *event) {
  QMainWindow::moveEvent(event);
  updateDialogPositions();
}

void MainWindow::updateDialogPositions() {
  if (depositWindow) {
    depositWindow->move(this->pos() + dialog_window_position);
  }
  if (credWindow) {
    credWindow->move(this->pos() + dialog_window_position);
  }
  if (myPlot) {
    myPlot->move(this->pos() + dialog_window_position);
  }
}

void MainWindow::connect_windows() {
  connect(this, &MainWindow::plot_signal, myPlot, &Plotter::plot_slot);
}

void MainWindow::close_credit() {
  credWindow->close();
  ui->credit->setChecked(false);
  QIcon icon_credit(":/resources/icons/credit1.png");
  ui->credit->setIcon(icon_credit);
}

void MainWindow::close_deposit() {
  depositWindow->close();
  ui->deposit->setChecked(false);
  QIcon icon_deposit(":/resources/icons/piggy1.png");
  ui->deposit->setIcon(icon_deposit);
}

void MainWindow::close_plot() {
  myPlot->close();
  ui->graph->setChecked(false);
  ui->equal->setText("=");
  QIcon icon_graph(":/resources/icons/graph1.png");
  ui->graph->setIcon(icon_graph);
}

void MainWindow::close_info() {
  infoWindow->close();
  ui->info->setChecked(false);
}

void MainWindow::on_key_input_returnPressed() {
  QString new_label = ui->key_input->text();
  std::string str = new_label.toStdString();
  bool is_numeric;
  double x_val = ui->x_value->text().toDouble(&is_numeric);
  if (!is_numeric) {
    QMessageBox::critical(this, "Error", "Enter valid x value");
  }
  if (!str.length()) {
    QMessageBox::critical(this, "Error", "Enter valid equation");
  }

  if (ui->graph->isChecked()) {
    emit plot_signal(str);
  } else {
    calc_control.reset_err();
    calc_control.HandleInput(str);
    calc_control.set_x(x_val);
    calc_control.Calculate();
    if (!calc_control.error()) {
      double res = calc_control.result();
      QString resString = QString::number(res, 'f', 7);
      while (resString.back() == '0') {
        resString.chop(1);
      }
      if (resString.back() == '.') {
        resString.chop(1);
      }
      ui->display->setText(resString);
    } else {
      QMessageBox::critical(this, "Error", "Enter valid equation");
    }
  }
}

void MainWindow::input_button_clicked() {
  QPushButton *button = (QPushButton *)sender();
  QByteArray btn_text = button->text().toLocal8Bit();
  const char *c_str = btn_text.data();

  if (strpbrk(c_str, "0123456789x+-()^.*")) {
    ui->key_input->setText(ui->key_input->text() + button->text());
  } else if (strpbrk(c_str, "√")) {
    ui->key_input->setText(ui->key_input->text() + "sqrt(");
  } else if (strpbrk(c_str, "÷")) {
    ui->key_input->setText(ui->key_input->text() + "/");
  } else if (strpbrk(c_str, "%")) {
    ui->key_input->setText(ui->key_input->text() + " mod ");
  } else {
    ui->key_input->setText(ui->key_input->text() + button->text() + "(");
  }
}

void MainWindow::on_all_clear_clicked() { ui->key_input->setText(""); }

void MainWindow::delete_button_clicked() {
  QString txt = ui->key_input->text();
  if (!txt.isEmpty()) {
    txt = txt.chopped(1);
    ui->key_input->setText(txt);
  }
}

void MainWindow::on_info_clicked() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  if (button->isChecked()) {
    if (infoWindow == nullptr) {
      infoWindow = new info(this);
    }
    infoWindow->show();
  } else {
    if (infoWindow != nullptr) {
      close_info();
    }
  }
}

void MainWindow::on_credit_clicked() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());

  if (button->isChecked()) {
    if (credWindow == nullptr) {
      credWindow = new Credit(this);
    }
    if (myPlot != nullptr) {
      close_plot();
    }
    //    if (depositWindow != nullptr) {
    //      close_deposit();
    //    }
    QIcon icon_credit(":/resources/icons/credit2.png");
    ui->credit->setIcon(icon_credit);
    credWindow->show();
    credWindow->move(this->pos() + dialog_window_position);
  } else {
    if (credWindow != nullptr) {
      close_credit();
    }
  }
}

void MainWindow::on_deposit_clicked() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());

  if (button->isChecked()) {
    if (depositWindow == nullptr) {
      depositWindow = new Deposit(this);
    }
    if (myPlot != nullptr) {
      close_plot();
    }
    if (credWindow != nullptr) {
      close_credit();
    }
    QIcon icon_deposit(":/resources/icons/piggy2.png");
    ui->deposit->setIcon(icon_deposit);
    depositWindow->show();
    depositWindow->move(this->pos() + dialog_window_position);
  } else {
    if (depositWindow != nullptr) {
      close_deposit();
    }
  }
}

void MainWindow::on_graph_clicked() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());

  if (button->isChecked()) {
    if (myPlot == nullptr) {
      myPlot = new Plotter(this);
    }
    if (credWindow != nullptr) {
      close_credit();
    }
    if (depositWindow != nullptr) {
      close_deposit();
    }
    QIcon icon_graph(":/resources/icons/graph2.png");
    ui->graph->setIcon(icon_graph);
    myPlot->move(this->pos() + dialog_window_position);
    myPlot->show();
    ui->equal->setText("plot");
  } else {
    if (myPlot != nullptr) {
      close_plot();
    }
  }
}
