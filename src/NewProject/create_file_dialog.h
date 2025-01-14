#ifndef CREATEFILEDIALOG_H
#define CREATEFILEDIALOG_H

#include <QDialog>

#include "source_grid.h"

namespace Ui {
class createFileDialog;
}

namespace FOEDAG {

class createFileDialog : public QDialog {
  Q_OBJECT

 public:
  explicit createFileDialog(QWidget *parent = nullptr);
  ~createFileDialog();

  void initialDialog(int type);
 signals:
  void sig_updateGrid(filedata fdata);

 private slots:
  void on_m_pushBtnOK_clicked();
  void on_m_pushBtnCancel_clicked();
  void on_m_comboxFileLocation_currentIndexChanged(int index);

 private:
  Ui::createFileDialog *ui;

  int m_type;
};
}  // namespace FOEDAG
#endif  // CREATEFILEDIALOG_H
