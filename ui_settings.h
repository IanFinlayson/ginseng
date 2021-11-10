/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QPushButton *fontButton;
    QLabel *label_2;
    QSpinBox *tabWidth;
    QLabel *label_3;
    QLabel *label_5;
    QCheckBox *smartEdit;
    QCheckBox *lineNo;
    QWidget *tab_2;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QComboBox *schemeChooser;
    QLabel *label_6;
    QPushButton *background;
    QLabel *label_7;
    QPushButton *foreground;
    QLabel *label_8;
    QPushButton *keywords;
    QLabel *label_9;
    QPushButton *types;
    QLabel *label_11;
    QPushButton *values;
    QLabel *label_12;
    QPushButton *comments;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *termBackground;
    QPushButton *functions;
    QPushButton *termForeground;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *linesBackground;
    QPushButton *linesForeground;
    QLabel *label_17;
    QPushButton *search;
    QLabel *label_18;
    QPushButton *error;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(400, 351);
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(Settings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        fontButton = new QPushButton(tab);
        fontButton->setObjectName(QString::fromUtf8("fontButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, fontButton);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        tabWidth = new QSpinBox(tab);
        tabWidth->setObjectName(QString::fromUtf8("tabWidth"));
        tabWidth->setMinimum(1);
        tabWidth->setMaximum(8);
        tabWidth->setValue(4);

        formLayout->setWidget(1, QFormLayout::FieldRole, tabWidth);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        smartEdit = new QCheckBox(tab);
        smartEdit->setObjectName(QString::fromUtf8("smartEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, smartEdit);

        lineNo = new QCheckBox(tab);
        lineNo->setObjectName(QString::fromUtf8("lineNo"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineNo);


        horizontalLayout->addLayout(formLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        formLayout_2 = new QFormLayout(tab_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        schemeChooser = new QComboBox(tab_2);
        schemeChooser->setObjectName(QString::fromUtf8("schemeChooser"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, schemeChooser);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        background = new QPushButton(tab_2);
        background->setObjectName(QString::fromUtf8("background"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, background);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_7);

        foreground = new QPushButton(tab_2);
        foreground->setObjectName(QString::fromUtf8("foreground"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, foreground);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_8);

        keywords = new QPushButton(tab_2);
        keywords->setObjectName(QString::fromUtf8("keywords"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, keywords);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_9);

        types = new QPushButton(tab_2);
        types->setObjectName(QString::fromUtf8("types"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, types);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_11);

        values = new QPushButton(tab_2);
        values->setObjectName(QString::fromUtf8("values"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, values);

        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_12);

        comments = new QPushButton(tab_2);
        comments->setObjectName(QString::fromUtf8("comments"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, comments);

        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_10);

        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_13);

        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_2->setWidget(9, QFormLayout::LabelRole, label_14);

        termBackground = new QPushButton(tab_2);
        termBackground->setObjectName(QString::fromUtf8("termBackground"));

        formLayout_2->setWidget(8, QFormLayout::FieldRole, termBackground);

        functions = new QPushButton(tab_2);
        functions->setObjectName(QString::fromUtf8("functions"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, functions);

        termForeground = new QPushButton(tab_2);
        termForeground->setObjectName(QString::fromUtf8("termForeground"));

        formLayout_2->setWidget(9, QFormLayout::FieldRole, termForeground);

        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_2->setWidget(10, QFormLayout::LabelRole, label_15);

        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_2->setWidget(11, QFormLayout::LabelRole, label_16);

        linesBackground = new QPushButton(tab_2);
        linesBackground->setObjectName(QString::fromUtf8("linesBackground"));

        formLayout_2->setWidget(10, QFormLayout::FieldRole, linesBackground);

        linesForeground = new QPushButton(tab_2);
        linesForeground->setObjectName(QString::fromUtf8("linesForeground"));

        formLayout_2->setWidget(11, QFormLayout::FieldRole, linesForeground);

        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_2->setWidget(12, QFormLayout::LabelRole, label_17);

        search = new QPushButton(tab_2);
        search->setObjectName(QString::fromUtf8("search"));

        formLayout_2->setWidget(12, QFormLayout::FieldRole, search);

        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_2->setWidget(13, QFormLayout::LabelRole, label_18);

        error = new QPushButton(tab_2);
        error->setObjectName(QString::fromUtf8("error"));

        formLayout_2->setWidget(13, QFormLayout::FieldRole, error);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Settings);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Settings", "Editor Font", nullptr));
        fontButton->setText(QCoreApplication::translate("Settings", "Font Name | 12", nullptr));
        label_2->setText(QCoreApplication::translate("Settings", "Indentation Amount", nullptr));
        label_3->setText(QCoreApplication::translate("Settings", "Smart Editing", nullptr));
        label_5->setText(QCoreApplication::translate("Settings", "Line Numbers", nullptr));
        smartEdit->setText(QString());
        lineNo->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Settings", "Editing", nullptr));
        label_4->setText(QCoreApplication::translate("Settings", "Color Scheme", nullptr));
        label_6->setText(QCoreApplication::translate("Settings", "Code Background", nullptr));
        background->setText(QString());
        label_7->setText(QCoreApplication::translate("Settings", "Code Foreground", nullptr));
        foreground->setText(QString());
        label_8->setText(QCoreApplication::translate("Settings", "Keywords", nullptr));
        keywords->setText(QString());
        label_9->setText(QCoreApplication::translate("Settings", "Types", nullptr));
        types->setText(QString());
        label_11->setText(QCoreApplication::translate("Settings", "Values", nullptr));
        values->setText(QString());
        label_12->setText(QCoreApplication::translate("Settings", "Comments", nullptr));
        comments->setText(QString());
        label_10->setText(QCoreApplication::translate("Settings", "Functions", nullptr));
        label_13->setText(QCoreApplication::translate("Settings", "Terminsl Background", nullptr));
        label_14->setText(QCoreApplication::translate("Settings", "Terminal Foreground", nullptr));
        termBackground->setText(QString());
        functions->setText(QString());
        termForeground->setText(QString());
        label_15->setText(QCoreApplication::translate("Settings", "Line No. Background", nullptr));
        label_16->setText(QCoreApplication::translate("Settings", "Line No. Foreground", nullptr));
        linesBackground->setText(QString());
        linesForeground->setText(QString());
        label_17->setText(QCoreApplication::translate("Settings", "Search Highlight", nullptr));
        search->setText(QString());
        label_18->setText(QCoreApplication::translate("Settings", "Error Highlight", nullptr));
        error->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Settings", "Colors", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
