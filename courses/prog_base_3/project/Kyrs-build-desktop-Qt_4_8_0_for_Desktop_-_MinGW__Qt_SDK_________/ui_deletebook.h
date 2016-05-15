/********************************************************************************
** Form generated from reading UI file 'deletebook.ui'
**
** Created: Sun 15. May 21:34:04 2016
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEBOOK_H
#define UI_DELETEBOOK_H

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
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deletebook
{
public:
    QTableView *tableView;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Deletebook)
    {
        if (Deletebook->objectName().isEmpty())
            Deletebook->setObjectName(QString::fromUtf8("Deletebook"));
        Deletebook->resize(646, 336);
        tableView = new QTableView(Deletebook);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(295, 10, 331, 291));
        label_5 = new QLabel(Deletebook);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 200, 37, 19));
        QFont font;
        font.setPointSize(12);
        label_5->setFont(font);
        lineEdit_5 = new QLineEdit(Deletebook);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(50, 150, 201, 101));
        pushButton_2 = new QPushButton(Deletebook);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 310, 131, 23));
        widget = new QWidget(Deletebook);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 30, 234, 102));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Rod"));
        font1.setPointSize(11);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_2->addWidget(lineEdit_4);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);


        horizontalLayout->addLayout(verticalLayout_2);

        widget1 = new QWidget(Deletebook);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(40, 270, 158, 25));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(widget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        retranslateUi(Deletebook);

        QMetaObject::connectSlotsByName(Deletebook);
    } // setupUi

    void retranslateUi(QDialog *Deletebook)
    {
        Deletebook->setWindowTitle(QApplication::translate("Deletebook", "Dialog", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Deletebook", "\320\236\320\277\320\270\321\201", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Deletebook", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\320\270 \320\262\321\201\321\226 \320\272\320\275\320\270\320\263\320\270", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Deletebook", "\320\235\320\260\320\267\320\262\320\260 \320\272\320\275\320\270\320\263\320\270", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Deletebook", "\320\226\320\260\320\275\321\200", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Deletebook", "\320\220\320\262\321\202\320\276\321\200", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Deletebook", "\320\240\321\226\320\272", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Deletebook", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Deletebook", "\320\235\320\260\320\267\320\260\320\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Deletebook: public Ui_Deletebook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEBOOK_H
