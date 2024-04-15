#ifndef INFO_H
#define INFO_H

#include <QDesktopServices>
#include <QDialog>
#include <QLabel>
#include <QMovie>

namespace Ui {
class info;
}

class info : public QDialog {
  Q_OBJECT

 public:
  explicit info(QWidget *parent = nullptr);
  ~info();

 private:
  Ui::info *ui;
  QMovie *gifMovie;
  QLabel *gifLabel;
};

#endif  // INFO_H
