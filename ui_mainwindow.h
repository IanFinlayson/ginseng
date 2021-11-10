/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "console.h"
#include "editor.h"
#include "searchbox.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionPrint;
    QAction *actionAbout_Ginseng;
    QAction *actionDocumentation;
    QAction *actionCut;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSave_As;
    QAction *actionRun;
    QAction *actionDebug;
    QAction *actionStop;
    QAction *actionFind;
    QAction *actionContinue;
    QAction *actionStep;
    QAction *actionInterrupt;
    QAction *actionNext;
    QAction *actionQuit;
    QAction *actionReplace;
    QAction *actionSettings;
    QAction *actionClose;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *findClose;
    SearchBox *searchBox;
    QCheckBox *matchCase;
    QPushButton *findPrev;
    QPushButton *findNext;
    QSplitter *mainSplitter;
    QTabWidget *tabBar;
    Editor *initial_input;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuDebug;
    QDockWidget *dock;
    Console *console;
    QVBoxLayout *verticalLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(756, 548);
        QFont font;
        font.setPointSize(11);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/resources/icons/logo_squares.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/resources/icons/file-save.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/icons/resources/icons/file-save.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon1);
        actionSave->setIconVisibleInMenu(true);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/resources/icons/file-new.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon2);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/resources/icons/file-open.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon3);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/resources/icons/file-print.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon4);
        actionPrint->setIconVisibleInMenu(true);
        actionAbout_Ginseng = new QAction(MainWindow);
        actionAbout_Ginseng->setObjectName(QString::fromUtf8("actionAbout_Ginseng"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/resources/icons/help-about.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Ginseng->setIcon(icon5);
        actionDocumentation = new QAction(MainWindow);
        actionDocumentation->setObjectName(QString::fromUtf8("actionDocumentation"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/resources/icons/help-contents.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionDocumentation->setIcon(icon6);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/resources/icons/edit-cut.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon7);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/resources/icons/edit-undo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon8);
        actionUndo->setIconVisibleInMenu(true);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/resources/icons/edit-redo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon9);
        actionRedo->setIconVisibleInMenu(true);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/resources/icons/edit-copy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon10);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/resources/icons/edit-paste.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon11);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/resources/icons/file-saveas.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon12);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionRun->setCheckable(false);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/resources/icons/debug-run.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon13);
        actionRun->setIconVisibleInMenu(true);
        actionDebug = new QAction(MainWindow);
        actionDebug->setObjectName(QString::fromUtf8("actionDebug"));
        actionDebug->setCheckable(false);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/resources/icons/debug-debug.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionDebug->setIcon(icon14);
        actionDebug->setIconVisibleInMenu(true);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/resources/icons/debug-stop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon15);
        actionStop->setIconVisibleInMenu(false);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/resources/icons/edit-find.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon16);
        actionContinue = new QAction(MainWindow);
        actionContinue->setObjectName(QString::fromUtf8("actionContinue"));
        actionContinue->setEnabled(false);
        actionContinue->setIcon(icon14);
        actionStep = new QAction(MainWindow);
        actionStep->setObjectName(QString::fromUtf8("actionStep"));
        actionStep->setEnabled(false);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/resources/icons/debug-step.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionStep->setIcon(icon17);
        actionInterrupt = new QAction(MainWindow);
        actionInterrupt->setObjectName(QString::fromUtf8("actionInterrupt"));
        actionInterrupt->setEnabled(false);
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icons/resources/icons/debug-pause.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionInterrupt->setIcon(icon18);
        actionNext = new QAction(MainWindow);
        actionNext->setObjectName(QString::fromUtf8("actionNext"));
        actionNext->setEnabled(false);
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icons/resources/icons/debug-next.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionNext->setIcon(icon19);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/icons/resources/icons/file-quit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon20);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/icons/resources/icons/edit-replace.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionReplace->setIcon(icon21);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/icons/resources/icons/file-settings.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon22);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/icons/resources/icons/window-close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon23);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        findClose = new QPushButton(centralWidget);
        findClose->setObjectName(QString::fromUtf8("findClose"));
        findClose->setIcon(icon23);
        findClose->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(findClose);

        searchBox = new SearchBox(centralWidget);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));

        horizontalLayout->addWidget(searchBox);

        matchCase = new QCheckBox(centralWidget);
        matchCase->setObjectName(QString::fromUtf8("matchCase"));

        horizontalLayout->addWidget(matchCase);

        findPrev = new QPushButton(centralWidget);
        findPrev->setObjectName(QString::fromUtf8("findPrev"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/icons/resources/icons/debug-up.svg"), QSize(), QIcon::Normal, QIcon::Off);
        findPrev->setIcon(icon24);
        findPrev->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(findPrev);

        findNext = new QPushButton(centralWidget);
        findNext->setObjectName(QString::fromUtf8("findNext"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/icons/resources/icons/debug-down.svg"), QSize(), QIcon::Normal, QIcon::Off);
        findNext->setIcon(icon25);
        findNext->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(findNext);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        mainSplitter = new QSplitter(centralWidget);
        mainSplitter->setObjectName(QString::fromUtf8("mainSplitter"));
        mainSplitter->setOrientation(Qt::Vertical);
        tabBar = new QTabWidget(mainSplitter);
        tabBar->setObjectName(QString::fromUtf8("tabBar"));
        tabBar->setStyleSheet(QString::fromUtf8("QTabBar::close-button {\n"
"    image: url(:/icons/resources/icons/window-close.svg);\n"
"}"));
        tabBar->setTabsClosable(false);
        tabBar->setMovable(true);
        tabBar->setTabBarAutoHide(true);
        initial_input = new Editor();
        initial_input->setObjectName(QString::fromUtf8("initial_input"));
        tabBar->addTab(initial_input, QString());
        mainSplitter->addWidget(tabBar);

        gridLayout_3->addWidget(mainSplitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setAutoFillBackground(true);
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(32, 32));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 756, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QString::fromUtf8("menuDebug"));
        MainWindow->setMenuBar(menuBar);
        dock = new QDockWidget(MainWindow);
        dock->setObjectName(QString::fromUtf8("dock"));
        dock->setStyleSheet(QString::fromUtf8(""));
        dock->setFloating(false);
        console = new Console();
        console->setObjectName(QString::fromUtf8("console"));
        verticalLayout = new QVBoxLayout(console);
        verticalLayout->setSpacing(16);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(16, 16, 16, 16);
        dock->setWidget(console);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, dock);

        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionCut);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addSeparator();
        toolBar->addAction(actionRun);
        toolBar->addAction(actionDebug);
        toolBar->addAction(actionStop);
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionDocumentation);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_Ginseng);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionReplace);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSettings);
        menuDebug->addAction(actionRun);
        menuDebug->addAction(actionDebug);

        retranslateUi(MainWindow);

        tabBar->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Ginseng IDE", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "&New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "&Open", nullptr));
        actionPrint->setText(QCoreApplication::translate("MainWindow", "&Print...", nullptr));
#if QT_CONFIG(tooltip)
        actionPrint->setToolTip(QCoreApplication::translate("MainWindow", "Print this file", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAbout_Ginseng->setText(QCoreApplication::translate("MainWindow", "&About Ginseng", nullptr));
        actionDocumentation->setText(QCoreApplication::translate("MainWindow", "&Documentation", nullptr));
        actionCut->setText(QCoreApplication::translate("MainWindow", "&Cut", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "&Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "&Redo", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "C&opy", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "&Paste", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Sa&ve As", nullptr));
        actionRun->setText(QCoreApplication::translate("MainWindow", "&Run", nullptr));
        actionDebug->setText(QCoreApplication::translate("MainWindow", "&Debug", nullptr));
        actionStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        actionFind->setText(QCoreApplication::translate("MainWindow", "&Find", nullptr));
        actionContinue->setText(QCoreApplication::translate("MainWindow", "Continue", nullptr));
        actionStep->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
#if QT_CONFIG(tooltip)
        actionStep->setToolTip(QCoreApplication::translate("MainWindow", "Step", nullptr));
#endif // QT_CONFIG(tooltip)
        actionInterrupt->setText(QCoreApplication::translate("MainWindow", "Interrupt", nullptr));
        actionNext->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
        actionReplace->setText(QCoreApplication::translate("MainWindow", "R&eplace", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "&Settings", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "&Close", nullptr));
#if QT_CONFIG(tooltip)
        findClose->setToolTip(QCoreApplication::translate("MainWindow", "Close Search", nullptr));
#endif // QT_CONFIG(tooltip)
        findClose->setText(QString());
        searchBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search...", nullptr));
        matchCase->setText(QCoreApplication::translate("MainWindow", "Match Case", nullptr));
#if QT_CONFIG(tooltip)
        findPrev->setToolTip(QCoreApplication::translate("MainWindow", "Find Previous", nullptr));
#endif // QT_CONFIG(tooltip)
        findPrev->setText(QString());
#if QT_CONFIG(tooltip)
        findNext->setToolTip(QCoreApplication::translate("MainWindow", "Find Next", nullptr));
#endif // QT_CONFIG(tooltip)
        findNext->setText(QString());
        tabBar->setTabText(tabBar->indexOf(initial_input), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "Toolbar", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Fi&le", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuDebug->setTitle(QCoreApplication::translate("MainWindow", "&Debug", nullptr));
        dock->setWindowTitle(QCoreApplication::translate("MainWindow", "O&utput", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
