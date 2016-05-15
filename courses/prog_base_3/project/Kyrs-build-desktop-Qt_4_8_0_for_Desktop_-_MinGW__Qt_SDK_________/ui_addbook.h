/********************************************************************************
** Form generated from reading UI file 'addbook.ui'
**
** Created: Sun 15. May 20:59:55 2016
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOK_H
#define UI_ADDBOOK_H

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

class Ui_Addbook
{
public:
    QPushButton *pushButton_save;
    QLabel *label_status;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_aut;
    QLabel *label_3;
    QLabel *label_name_book;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_aut;
    QLineEdit *lineEdit_genre;
    QLineEdit *lineEdit_name_add_book;
    QLineEdit *lineEdit_year;
    QLineEdit *lineEdit_des;

    void setupUi(QDialog *Addbook)
    {
        if (Addbook->objectName().isEmpty())
            Addbook->setObjectName(QString::fromUtf8("Addbook"));
        Addbook->resize(274, 237);
        pushButton_save = new QPushButton(Addbook);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(100, 200, 75, 23));
        label_status = new QLabel(Addbook);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(40, 250, 361, 41));
        widget = new QWidget(Addbook);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 45, 196, 128));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_aut = new QLabel(widget);
        label_aut->setObjectName(QString::fromUtf8("label_aut"));
        QFont font;
        font.setPointSize(12);
        label_aut->setFont(font);

        verticalLayout->addWidget(label_aut);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label_name_book = new QLabel(widget);
        label_name_book->setObjectName(QString::fromUtf8("label_name_book"));
        label_name_book->setFont(font);

        verticalLayout->addWidget(label_name_book);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_aut = new QLineEdit(widget);
        lineEdit_aut->setObjectName(QString::fromUtf8("lineEdit_aut"));

        verticalLayout_2->addWidget(lineEdit_aut);

        lineEdit_genre = new QLineEdit(widget);
        lineEdit_genre->setObjectName(QString::fromUtf8("lineEdit_genre"));

        verticalLayout_2->addWidget(lineEdit_genre);

        lineEdit_name_add_book = new QLineEdit(widget);
        lineEdit_name_add_book->setObjectName(QString::fromUtf8("lineEdit_name_add_book"));

        verticalLayout_2->addWidget(lineEdit_name_add_book);

        lineEdit_year = new QLineEdit(widget);
        lineEdit_year->setObjectName(QString::fromUtf8("lineEdit_year"));

        verticalLayout_2->addWidget(lineEdit_year);

        lineEdit_des = new QLineEdit(widget);
        lineEdit_des->setObjectName(QString::fromUtf8("lineEdit_des"));

        verticalLayout_2->addWidget(lineEdit_des);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(Addbook);

        QMetaObject::connectSlotsByName(Addbook);
    } // setupUi

    void retranslateUi(QDialog *Addbook)
    {
        Addbook->setWindowTitle(QApplication::translate("Addbook", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_save->setText(QApplication::translate("Addbook", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270", 0, QApplication::UnicodeUTF8));
        label_status->setText(QString());
        label_aut->setText(QApplication::translate("Addbook", "\320\220\320\262\321\202\320\276\321\200", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Addbook", "\320\226\320\260\320\275\321\200", 0, QApplication::UnicodeUTF8));
        label_name_book->setText(QApplication::translate("Addbook", "\320\235\320\260\320\267\320\262\320\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Addbook", "\320\240\321\226\320\272", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Addbook", "\320\236\320\277\320\270\321\201", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        lineEdit_name_add_book->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Addbook: public Ui_Addbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOK_H
