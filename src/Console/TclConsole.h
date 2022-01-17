#pragma once

#include <QThread>

#include "ConsoleInterface.h"
#include "TclWorker.h"

namespace FOEDAG {
class TclInterpreter;
}

class TclConsole : public ConsoleInterface {
  Q_OBJECT
 public:
  TclConsole(FOEDAG::TclInterpreter *interpreter, std::ostream &out,
             QObject *parent = nullptr);
  void registerInterpreter(FOEDAG::TclInterpreter *interpreter);
  ~TclConsole();
  void run(const QString &command) override;
  QString startWith() const override;

 public slots:
  void abort();

 private slots:
  void tclFinished();

 signals:
  void sendCommand(QString);
  void abort_();

 private:
  TclWorker *m_tclWorker;
  std::vector<TclWorker *> m_tclWorkers;
  std::ostream &m_out;
};