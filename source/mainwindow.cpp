// mainwindow.cpp
// code for the main application window, actions, etc.

#include <QDesktopServices>
#include <QFileDialog>
#include <QInputDialog>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>
#include <QScrollBar>
#include <QSignalMapper>
#include <QSize>
#include <QTabWidget>
#include <QThread>
#include <QtCore>

#include "editor.h"
#include "mainwindow.h"
#include "replacedialog.h"
#include "settingsdialog.h"
#include "settingsmanager.h"
#include "ui_about.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), replaceDialog(this) {
    // set the menu bar to work natively for systems with global bars
    menuBar()->setNativeMenuBar(true);

    // set up the ui elements for the window
    ui->setupUi(this);

    // set the title and icon
    setWindowTitle(tr("Ginseng [*]"));
    setWindowIcon(QIcon(":/icons/resources/icons/logo.svg"));

    // set up the key shortcuts for the program
    setupShortcuts();

    // set up the thread and file runner for running programs
    progThread = NULL;
    fileRunner = NULL;

    // set up the status bar
    statusBar()->showMessage("Ready.");
    coords = new QLabel("");
    statusBar()->addPermanentWidget(coords);
    updateCoordinates();

    // set the tab bar in "document mode" and give the tab no name
    ui->tabBar->setDocumentMode(true);
    ui->tabBar->setTabText(0, "Unsaved");

    // set these as disabled (they are enabled dynamically)
    ui->actionCut->setEnabled(false);
    ui->actionCopy->setEnabled(false);
    ui->actionRedo->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionStop->setVisible(false);

    // set up connections of signals with the current editor
    currentEditor()->setUpConnections(this);

    // connect tab changes so we can update buttons
    connect(ui->tabBar, SIGNAL(currentChanged(int)), this,
            SLOT(onTabChange(int)));

    // set up connections with the console
    ui->console->setUpConnections(this);

    // hide the search area by default
    hideSearch();

    // hide the console by default
    ui->dock->hide();

    // set up the search box signals
    connect(ui->findClose, SIGNAL(pressed()), this, SLOT(hideSearch()));
    connect(ui->findNext, SIGNAL(pressed()), this, SLOT(searchNext()));
    connect(ui->findPrev, SIGNAL(pressed()), this, SLOT(searchPrev()));
    connect(ui->searchBox, SIGNAL(returnPressed()), this, SLOT(searchNext()));
    connect(ui->searchBox, SIGNAL(textChanged(QString)), this,
            SLOT(clearSearchColor(QString)));
    connect(ui->searchBox, SIGNAL(closeSearch()), this, SLOT(hideSearch()));
    connect(ui->matchCase, SIGNAL(stateChanged(int)), this,
            SLOT(saveMatchCase(int)));

    // TODO enable debugging when it is working
    ui->actionDebug->setVisible(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupShortcuts() {
    ui->actionNew->setShortcuts(QKeySequence::New);
    ui->actionOpen->setShortcuts(QKeySequence::Open);
    ui->actionSave->setShortcuts(QKeySequence::Save);
    ui->actionSave_As->setShortcuts(QKeySequence::SaveAs);
    ui->actionPrint->setShortcuts(QKeySequence::Print);
    ui->actionClose->setShortcuts(QKeySequence::Close);
    ui->actionQuit->setShortcuts(QKeySequence::Quit);

    ui->actionFind->setShortcuts(QKeySequence::Find);
    ui->actionReplace->setShortcuts(QKeySequence::Replace);
    ui->actionCut->setShortcuts(QKeySequence::Cut);
    ui->actionCopy->setShortcuts(QKeySequence::Copy);
    ui->actionPaste->setShortcuts(QKeySequence::Paste);
    ui->actionRedo->setShortcuts(QKeySequence::Redo);
    ui->actionUndo->setShortcuts(QKeySequence::Undo);

    ui->actionDocumentation->setShortcuts(QKeySequence::HelpContents);

    ui->actionRun->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_R));
    ui->actionDebug->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_R));
}

void MainWindow::closeEvent(QCloseEvent* event) {
    event->ignore();
    on_actionQuit_triggered();
}

QString MainWindow::getOpenFile() {
    return currentEditor()->getOpenFile();
}

// gives stripped name of file (removes file path)
QString MainWindow::strippedName(const QString& fullFileName) {
    return QFileInfo(fullFileName).fileName();
}

void MainWindow::onTabChange(int) {
    // update button states
    if (currentEditor()) {
        ui->actionCopy->setEnabled(currentEditor()->canCopy());
        ui->actionCut->setEnabled(currentEditor()->canCopy());
        ui->actionUndo->setEnabled(currentEditor()->canUndo());
        ui->actionRedo->setEnabled(currentEditor()->canRedo());
    }
}

// load an initial file e.g. as an open file
void MainWindow::doOpen(QString fname) {
    Editor* newEditor = new Editor;
    newEditor->setUpConnections(this);
    if (newEditor->open(fname)) {
        // if there is one tab which is empty and not modified, close it first
        if (ui->tabBar->count() == 1 && currentEditor()->isEmpty()) {
            currentEditor()->close();
            ui->tabBar->removeTab(ui->tabBar->currentIndex());
        }

        QFileInfo info(fname);
        ui->tabBar->addTab(newEditor, info.fileName());
        ui->tabBar->setCurrentWidget(newEditor);
        updateTitle();
    } else {
        QMessageBox warning;
        warning.setText("Could not open file '" + fname + "'");
        warning.setIconPixmap(
            QPixmap(":/icons/resources/icons/dialog-warning.svg"));
        warning.exec();
    }
}

void MainWindow::documentWasModified() {
    if (ui->tabBar->count() == 1) {
        setWindowModified(currentEditor()->document()->isModified());
    } else {
        updateTitle();
    }
}

void MainWindow::updateCoordinates() {
    coords->setText(currentEditor()->getCoordinates());
    currentEditor()->ensureCursorVisible();
}

void MainWindow::on_actionNew_triggered() {
    Editor* newEditor = new Editor;
    newEditor->setUpConnections(this);
    ui->tabBar->addTab(newEditor, "Unsaved");
    ui->tabBar->setCurrentWidget(newEditor);
    updateTitle();
}

void MainWindow::on_actionClose_triggered() {
    if (currentEditor()->document()->isModified()) {
        QMessageBox messageBox;
        messageBox.setText("The file has been modified.");
        messageBox.setInformativeText("Do you want to save your changes?");
        messageBox.setIconPixmap(
            QPixmap(":/icons/resources/icons/dialog-question.svg"));
        messageBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard |
                                      QMessageBox::Cancel);
        messageBox.setDefaultButton(QMessageBox::Save);
        switch (messageBox.exec()) {
            case QMessageBox::Save:
                // try to save, if something goes wrong, bail
                if (!currentEditor()->save()) {
                    return;
                }
                break;
            case QMessageBox::Discard:
                // don't save!
                break;
            case QMessageBox::Cancel:
                // bail!
                return;
        }
    }

    // actually close the editor and tab
    currentEditor()->close();
    ui->tabBar->removeTab(ui->tabBar->currentIndex());

    // if that was the last tab, time to leave
    if (ui->tabBar->count() == 0) {
        QApplication::quit();
    } else {
        updateTitle();
    }
}

void MainWindow::updateTitle() {
    QString full = currentEditor()->getOpenFile();
    QFileInfo info(full);

    if (full != "") {
        QString name = info.fileName();
        if (currentEditor()->document()->isModified()) {
            name += "*";
        }
        ui->tabBar->setTabText(ui->tabBar->currentIndex(), name);
    }

    if (ui->tabBar->count() == 1) {
        if (full != "") {
            setWindowTitle(info.fileName() + " [*]");
        } else {
            setWindowTitle("Ginseng [*]");
        }
        setWindowModified(currentEditor()->document()->isModified());
    } else {
        setWindowTitle("Ginseng [*]");
    }
}

void MainWindow::on_actionSave_triggered() {
    if (currentEditor()->save()) {
        updateTitle();
    }
}

void MainWindow::on_actionSave_As_triggered() {
    if (currentEditor()->saveas()) {
        updateTitle();
    }
}

void MainWindow::on_actionOpen_triggered() {
    QString fname =
        QFileDialog::getOpenFileName(this, tr("Open File"), "", "Java (*.java)");
    if (fname == "") {
        return;
    }

    doOpen(fname);
}

int MainWindow::on_actionPrint_triggered() {
    QPrinter printer;

    QPrintDialog* dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");

    if (dialog->exec() != QDialog::Accepted) {
        return -1;
    }

    QPainter painter;
    painter.begin(&printer);
    QFont f = SettingsManager::font();
    painter.setFont(f);
    painter.drawText(100, 100, 500, 500, Qt::AlignLeft | Qt::AlignTop,
                     currentEditor()->toPlainText());

    painter.end();
    return 0;
}

Editor* MainWindow::currentEditor() {
    return (Editor*)ui->tabBar->currentWidget();
}

void MainWindow::on_actionCut_triggered() {
    currentEditor()->cut();
}
void MainWindow::on_actionUndo_triggered() {
    currentEditor()->undo();
}
void MainWindow::on_actionQuit_triggered() {
    // if there is one tab only, do a close
    if (ui->tabBar->count() == 1) {
        on_actionClose_triggered();
    }

    // check if there are unsaved tabs
    int mod_count = 0;
    Editor* unsaved = NULL;
    for (int i = 0; i < ui->tabBar->count(); i++) {
        Editor* ed = (Editor*)ui->tabBar->widget(i);
        if (ed->document()->isModified()) {
            unsaved = ed;
            mod_count++;
        }
    }

    if (mod_count == 1) {
        QMessageBox messageBox;
        messageBox.setText("The file has been modified.");
        messageBox.setInformativeText("Do you want to save your changes?");
        messageBox.setIconPixmap(
            QPixmap(":/icons/resources/icons/dialog-question.svg"));
        messageBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard |
                                      QMessageBox::Cancel);
        messageBox.setDefaultButton(QMessageBox::Save);
        switch (messageBox.exec()) {
            case QMessageBox::Save:
                // try to save, if something goes wrong, bail
                if (!unsaved->save()) {
                    return;
                }
                break;
            case QMessageBox::Discard:
                // don't save!
                break;
            case QMessageBox::Cancel:
                // bail!
                return;
        }
    } else if (mod_count > 1) {
        QMessageBox messageBox;
        messageBox.setText("Files have been modified.");
        messageBox.setInformativeText("Do you want to save all changes?");
        messageBox.setIconPixmap(
            QPixmap(":/icons/resources/icons/dialog-question.svg"));
        messageBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard |
                                      QMessageBox::Cancel);
        messageBox.setDefaultButton(QMessageBox::Save);
        switch (messageBox.exec()) {
            case QMessageBox::Save:
                for (int i = 0; i < ui->tabBar->count(); i++) {
                    Editor* ed = (Editor*)ui->tabBar->widget(i);
                    if (!ed->save()) {
                        return;
                    }
                    break;
                }
            case QMessageBox::Discard:
                // don't save!
                break;
            case QMessageBox::Cancel:
                // bail!
                return;
        }
    }

    QApplication::quit();
}

void MainWindow::on_actionRedo_triggered() {
    currentEditor()->redo();
}
void MainWindow::on_actionCopy_triggered() {
    currentEditor()->copy();
}
void MainWindow::on_actionPaste_triggered() {
    currentEditor()->paste();
}

void MainWindow::on_actionFind_triggered() {
    showSearch();
}

// help and about functions
void MainWindow::on_actionAbout_Ginseng_triggered() {
    QDialog* about = new QDialog();
    Ui_About about_ui;
    about_ui.setupUi(about);
    about->show();
}

void MainWindow::on_actionSettings_triggered() {
    SettingsDialog* prefs = new SettingsDialog(this);
    prefs->exec();

    // update the settings of all open editors
    for (int i = 0; i < ui->tabBar->count(); i++) {
        Editor* ed = (Editor*)ui->tabBar->widget(i);
        ed->updateSettings();
    }

    // update the settings for the console
    ui->console->updateSettings();
}

void MainWindow::on_actionDocumentation_triggered() {
    QDesktopServices::openUrl(QUrl("http://tetra-lang.org/ide-reference"));
}

void MainWindow::receiveOutput(QString text) {
    ui->console->write(text);
}

void MainWindow::on_actionRun_triggered() {
    qDebug() << "A???\n";
    // if it's not saved, we can't run
    if (currentEditor()->save()) {
        updateTitle();
    } else {
        return;
    }

    // start a thread
    progThread = new QThread;
    fileRunner = new FileRunner(this);

    // set up running so we know when we are done
    connect(fileRunner, SIGNAL(finished()), this, SLOT(exitRunMode()));

    // make sure the bottom dock is shown
    ui->dock->show();
    ui->console->document()->setPlainText("");
    ui->console->setEnabled(true);
    ui->console->setFocus(Qt::OtherFocusReason);
    ui->console->setReadOnly(false);
    ui->console->clear();

    // disable run again
    ui->actionRun->setDisabled(true);
    ui->actionDebug->setDisabled(true);
    ui->actionStop->setVisible(true);
    statusBar()->showMessage("Running.");

    // start the worker thread which runs the programs
    fileRunner->moveToThread(progThread);
    progThread->start();
    qDebug() << "STARTING???\n";
    QMetaObject::invokeMethod(fileRunner, "runFile", Qt::QueuedConnection);
}

// when the console has input for us to pass to program
void MainWindow::receiveInput(QString text) {
    // just pass it to the file runner
    fileRunner->receiveInput(text);
}

// called when the program has some type of error
void MainWindow::reportError(QString mesg, int line) {
    QString full = "Error on line " + QString::number(line) + ": " + mesg;
    ui->console->write(full);

    currentEditor()->moveCursor(line);
    currentEditor()->errorHighlight();
}

// finish running this
void MainWindow::exitRunMode() {
    // get rid of the running thread
    delete progThread;
    delete fileRunner;
    progThread = NULL;
    fileRunner = NULL;

    // go back to editing mode
    ui->actionRun->setEnabled(true);
    ui->actionDebug->setEnabled(true);
    ui->actionStop->setVisible(false);
    ui->console->setReadOnly(true);
    statusBar()->showMessage("Ready.");
}

void MainWindow::on_actionStop_triggered() {
    // tell the running thread to stop whatever it's doing
    fileRunner->halt();
}

// show and hide all components of the search window
void MainWindow::hideSearch() {
    ui->matchCase->setVisible(false);
    ui->findClose->setVisible(false);
    ui->findNext->setVisible(false);
    ui->findPrev->setVisible(false);
    ui->searchBox->setVisible(false);
    currentEditor()->unhighlightLine();
    ui->searchBox->setStyleSheet("");
}
void MainWindow::showSearch() {
    // set the checked ness of this based on settings
    ui->matchCase->setCheckState(SettingsManager::matchCase() ? Qt::Checked
                                                              : Qt::Unchecked);

    ui->matchCase->setVisible(true);
    ui->findClose->setVisible(true);
    ui->findNext->setVisible(true);
    ui->findPrev->setVisible(true);
    ui->searchBox->setVisible(true);
    ui->searchBox->setFocus(Qt::OtherFocusReason);
    ui->searchBox->setStyleSheet("");
    ui->searchBox->setSelection(0, ui->searchBox->text().size());
}

void MainWindow::saveMatchCase(int) {
    // save checked ness into settings
    SettingsManager::setMatchCase(ui->matchCase->checkState() == Qt::Checked);
}

// actually execute the searches
void MainWindow::doSearch(bool next) {
    // only search for non empty strings
    if (ui->searchBox->text().size() == 0) {
        return;
    }

    // search and check if found
    if (currentEditor()->searchDir(ui->searchBox->text(), next,
                                   ui->matchCase->checkState() == Qt::Checked,
                                   true)) {
        ui->searchBox->setStyleSheet("");
        currentEditor()->setFocus(Qt::OtherFocusReason);
    } else {
        ui->searchBox->setStyleSheet("background-color: " +
                                     SettingsManager::error().name() + ";");
    }
}

void MainWindow::searchNext() {
    doSearch(true);
}
void MainWindow::searchPrev() {
    doSearch(false);
}

// called also when the text is changed
void MainWindow::clearSearchColor(QString) {
    ui->searchBox->setStyleSheet("");
}

// launch the replace dialog
void MainWindow::on_actionReplace_triggered() {
    replaceDialog.updateSettings();
    replaceDialog.show();
}

// TODO debugger functions
void MainWindow::on_actionDebug_triggered() {
}

void MainWindow::on_actionStep_triggered() {
}

void MainWindow::on_actionContinue_triggered() {
}

void MainWindow::on_actionNext_triggered() {
}
