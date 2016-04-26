/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Tue 26. Apr 22:57:20 2016
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(361, 207);
        Dialog->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 40, 52, 77));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(11);
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        widget1 = new QWidget(Dialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(90, 40, 135, 74));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_3 = new QLineEdit(widget1);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        widget2 = new QWidget(Dialog);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(40, 140, 251, 25));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(widget2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Name", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Genre", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Author", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog", "Search!", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Dialog", "View busy books", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Dialog", "View all books", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
