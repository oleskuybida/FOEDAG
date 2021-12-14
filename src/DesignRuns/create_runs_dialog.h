#ifndef CREATE_RUNS_DIALOG_H
#define CREATE_RUNS_DIALOG_H

#include <QDialog>

#include "create_runs_form.h"

namespace Ui {
class CreateRunsDialog;
}

namespace FOEDAG {

class CreateRunsDialog : public QDialog {
  Q_OBJECT

 public:
  explicit CreateRunsDialog(QWidget *parent = nullptr);
  ~CreateRunsDialog();

  void InitDialog(int itype);

 public:
  CreateRunsForm *m_createRunsForm;

 private:
  Ui::CreateRunsDialog *ui;
};
}  // namespace FOEDAG
#endif  // CREATE_RUNS_DIALOG_H
