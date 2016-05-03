/********************************************************************************
** Form generated from reading UI file 'all.ui'
**
** Created: Mon 2. May 16:13:59 2016
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALL_H
#define UI_ALL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_All
{
public:
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *All)
    {
        if (All->objectName().isEmpty())
            All->setObjectName(QString::fromUtf8("All"));
        All->resize(714, 300);
        tableView = new QTableView(All);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 501, 281));
        pushButton = new QPushButton(All);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(530, 70, 121, 141));

        retranslateUi(All);

        QMetaObject::connectSlotsByName(All);
    } // setupUi

    void retranslateUi(QDialog *All)
    {
        All->setWindowTitle(QApplication::translate("All", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("All", "Submit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class All: public Ui_All {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALL_H
