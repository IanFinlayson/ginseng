/********************************************************************************
** Form generated from reading UI file 'replace.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACE_H
#define UI_REPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Replace
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *find;
    QLabel *label_2;
    QLineEdit *replace;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *matchCase;
    QVBoxLayout *verticalLayout_2;
    QPushButton *next;
    QPushButton *repl;
    QPushButton *replaceAll;
    QSpacerItem *verticalSpacer;
    QPushButton *cancel;

    void setupUi(QDialog *Replace)
    {
        if (Replace->objectName().isEmpty())
            Replace->setObjectName(QString::fromUtf8("Replace"));
        Replace->resize(458, 156);
        horizontalLayout = new QHBoxLayout(Replace);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Replace);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        find = new QLineEdit(Replace);
        find->setObjectName(QString::fromUtf8("find"));

        verticalLayout->addWidget(find);

        label_2 = new QLabel(Replace);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        replace = new QLineEdit(Replace);
        replace->setObjectName(QString::fromUtf8("replace"));

        verticalLayout->addWidget(replace);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        matchCase = new QCheckBox(Replace);
        matchCase->setObjectName(QString::fromUtf8("matchCase"));
        matchCase->setChecked(true);

        verticalLayout->addWidget(matchCase);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        next = new QPushButton(Replace);
        next->setObjectName(QString::fromUtf8("next"));
        next->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(next);

        repl = new QPushButton(Replace);
        repl->setObjectName(QString::fromUtf8("repl"));

        verticalLayout_2->addWidget(repl);

        replaceAll = new QPushButton(Replace);
        replaceAll->setObjectName(QString::fromUtf8("replaceAll"));

        verticalLayout_2->addWidget(replaceAll);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        cancel = new QPushButton(Replace);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        verticalLayout_2->addWidget(cancel);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(Replace);

        QMetaObject::connectSlotsByName(Replace);
    } // setupUi

    void retranslateUi(QDialog *Replace)
    {
        Replace->setWindowTitle(QCoreApplication::translate("Replace", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Replace", "Find Text:", nullptr));
        label_2->setText(QCoreApplication::translate("Replace", "Replace with:", nullptr));
        matchCase->setText(QCoreApplication::translate("Replace", "Match case", nullptr));
        next->setText(QCoreApplication::translate("Replace", "Find Next", nullptr));
        repl->setText(QCoreApplication::translate("Replace", "Replace", nullptr));
        replaceAll->setText(QCoreApplication::translate("Replace", "Replace All", nullptr));
        cancel->setText(QCoreApplication::translate("Replace", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Replace: public Ui_Replace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACE_H
