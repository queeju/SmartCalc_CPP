#include <QApplication>
#include <QDebug>
#include <QFontDatabase>

#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QFontDatabase::addApplicationFont(":/resources/fonts/Quicksand-Bold.ttf");
  QFontDatabase::addApplicationFont(":/resources/fonts/Quicksand-Regular.ttf");
  QFontDatabase::addApplicationFont(":/resources/fonts/Quicksand-Medium.ttf");
  MainWindow mainWindow;
  mainWindow.show();
  return a.exec();
}
