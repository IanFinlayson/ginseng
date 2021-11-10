// filerunner.h
// code to run or debug a program */

#ifndef FILERUNNER_H
#define FILERUNNER_H

#include <sys/types.h>
#include <QElapsedTimer>
#include <QMutex>
#include <QObject>
#include <QProcess>
#include <QWaitCondition>

#include "mainwindow.h"

class MainWindow;
class FileRunner : public QObject {
    Q_OBJECT
  public:
    FileRunner(MainWindow* mainWindow);

    // halt the running program in its tracks */
    void halt();

    // get input from console */
    void receiveInput(QString input);

  signals:
    void finished();
    void output(QString text);
    void needInput();
    void errorSeen(QString message, int line);

  public slots:
    void runFile(bool debug);

  private:
    // pointer to the main window */
    MainWindow* mainWindow;

    // pointer to a process for compilation/execution */
    QProcess* proc;

    // the string when there is one */
    QMutex input_mux;
    QString input;
    bool input_available;

    // keep track of the elapsed running time */
    QElapsedTimer programTimer;
    bool interrupted;
};

#endif
