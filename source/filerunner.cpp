// filerunner.cpp
// code to run or debug a program

#include <iostream>

#include <QDir>
#include <QFileInfo>
#include <QInputDialog>
#include <QMutex>

#include "console.h"
#include "filerunner.h"

// create the FileRunner and save the window it's associated with
FileRunner::FileRunner(MainWindow* mainWindow) {
    // output
    connect(this, SIGNAL(output(QString)), mainWindow,
            SLOT(receiveOutput(QString)));

    // errors
    connect(this, SIGNAL(errorSeen(QString, int)), mainWindow,
            SLOT(reportError(QString, int)));
    
    // save main window ref
    this->mainWindow = mainWindow;
    interrupted = false;
}

// run or debug file
void FileRunner::runFile() {
    // start timer
    programTimer.start();
    
    // get the current file name
    QFileInfo file(mainWindow->getOpenFile());

    // launch javac to compile
    proc = new QProcess(this);
    proc->setWorkingDirectory(file.path());
    proc->start("/usr/bin/javac", {file.fileName()});
    proc->waitForFinished(-1);
    
    // list any compiler errors
    QByteArray err = proc->readAllStandardError();
    emit output(QString::fromStdString(err.toStdString()));
    QThread::currentThread()->quit();

    // if there were any errors, we're done
    if (proc->exitCode() != QProcess::NormalExit) {
        delete proc;
        proc = NULL;
        emit finished();
        return;
    } else {
        delete proc;
        proc = NULL;
    }

    // now we launch java to run
    proc = new QProcess(this);
    proc->setWorkingDirectory(file.path());
    proc->start("/usr/bin/java", {file.baseName()});
    proc->waitForStarted();
    
    // keep going until the process is done
    while (proc->state() == QProcess::Running) {
        input_mux.lock();
        if (input_available) {
            proc->write(input.toStdString().c_str());
            proc->write("\n");
            input_available = false;
        }
        input_mux.unlock();

        if (proc->waitForReadyRead(50)) {
            QByteArray stuff = proc->readAllStandardOutput();
            emit output(QString::fromStdString(stuff.toStdString()));
        }
    }

    // wait for it to finish the rest of the way
    proc->waitForFinished(-1);

    // now we are done
    QThread::currentThread()->quit();
    delete proc;
    proc = NULL;

    if (!interrupted) {
        // calculate elapsed running time
        double seconds = programTimer.elapsed() / 1000.0;
        emit output("Program finished in " + QString::number(seconds, 'f', 2) + " seconds.");
    }
    emit finished();
}

void FileRunner::receiveInput(QString in) {
    input_mux.lock();
    input = in;
    input_available = true;
    input_mux.unlock();
}

// stop the running program in its tracks
void FileRunner::halt() {
    interrupted = true;
    proc->terminate();
    double seconds = programTimer.elapsed() / 1000.0;
    emit output("Program halted after " + QString::number(seconds, 'f', 2) + " seconds.");
}
