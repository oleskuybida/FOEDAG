#include "location_form.h"

#include <QFileDialog>

#include "ui_location_form.h"

using namespace FOEDAG;

locationForm::locationForm(QWidget *parent)
    : QWidget(parent), ui(new Ui::locationForm) {
  ui->setupUi(this);
  ui->m_labelTitle->setText(tr("Project Location"));
  ui->m_labelCont->setText(
      tr("This wizard will guide you through the creation of a new project."));
  ui->m_labelTail->setText(
      tr("To create a project you will need to provide a name and a location "
         "for your project files. "
         "Next,you will specify the type of flow you'll be working with. "
         "Finally,you will specify your project sources and choose a default "
         "part."));
  ui->m_labelPname->setText(tr("Project name:"));
  ui->m_labelPpath->setText(tr("Project location:"));
  ui->m_checkBox->setText(tr("Create project subdirectory"));
  ui->m_labelPath0->setText(tr("Project will be created at:"));
  ui->m_btnBrowse->setText(tr("Browse..."));
  ui->m_lineEditPname->setText("project_1");
  ui->m_lineEditPpath->setText(QDir::homePath());
  ui->m_labelPath1->setText(ui->m_lineEditPpath->text());
  ui->m_checkBox->setCheckState(Qt::CheckState::Checked);
}

locationForm::~locationForm() { delete ui; }
QString locationForm::getProjectName() { return ui->m_lineEditPname->text(); }
QString locationForm::getProjectPath() { return ui->m_labelPath1->text(); }
bool locationForm::IsCreateDir() {
  return ui->m_checkBox->checkState() == Qt::CheckState::Checked ? true : false;
}

bool locationForm::IsProjectNameExit() {
  QString pname = ui->m_lineEditPname->text();
  QString ppath = ui->m_labelPath1->text();
  if ("" == pname || "" == ppath) return false;
  if (Qt::CheckState::Checked == ui->m_checkBox->checkState()) {
    QStringList dirlist;  // = getallChildDir(ppath);
    foreach (QString str, dirlist) {
      if (!pname.compare(str, Qt::CaseInsensitive)) {
        return true;
      }
    }
  }
  return false;
}

void locationForm::on_m_btnBrowse_clicked() {
  QString pathName = QFileDialog::getExistingDirectory(
      this, tr("Select Directory"),
      ui->m_lineEditPpath->text() == "" ? QDir::homePath()
                                        : ui->m_lineEditPpath->text(),
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  if ("" == pathName) {
    return;
  }
  ui->m_lineEditPpath->setText(pathName);

  QString name = ui->m_lineEditPname->text();
  Qt::CheckState state = ui->m_checkBox->checkState();
  if (Qt::CheckState::Checked == state && "" != pathName && "" != name) {
    ui->m_labelPath1->setText(pathName + "/" + name);
  } else {
    ui->m_labelPath1->setText(pathName);
  }
}

void locationForm::on_m_checkBox_stateChanged(int arg1) {
  QString name = ui->m_lineEditPname->text();
  QString path = ui->m_lineEditPpath->text();
  if (Qt::CheckState::Checked == arg1 && "" != name && "" != path) {
    ui->m_labelPath1->setText(path + "/" + name);
  } else {
    ui->m_labelPath1->setText(path);
  }
}

void locationForm::on_m_lineEditPname_textChanged(const QString &arg1) {
  QString path = ui->m_lineEditPpath->text();
  Qt::CheckState state = ui->m_checkBox->checkState();
  if (Qt::CheckState::Checked == state && "" != arg1 && "" != path) {
    ui->m_labelPath1->setText(path + "/" + arg1);
  } else {
    ui->m_labelPath1->setText(path);
  }
}
