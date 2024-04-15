#include "info.h"

#include "ui_info.h"

info::info(QWidget *parent) : QDialog(parent), ui(new Ui::info) {
  ui->setupUi(this);
  setFixedSize(512, 178);
  this->setWindowTitle("Info");
  gifMovie = new QMovie(":/resources/icons/info.gif");

  gifLabel = new QLabel(this);
  gifLabel->move(200, 0);
  gifLabel->setMovie(gifMovie);
  gifMovie->start();
  ui->textBrowser->setOpenLinks(true);
  ui->textBrowser->setOpenExternalLinks(true);
}

info::~info() {
  gifMovie->stop();
  delete gifMovie;
  delete ui;
}
