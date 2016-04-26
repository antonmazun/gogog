/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created: Tue 26. Apr 22:03:15 2016
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
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
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(300, 174);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 130, 75, 23));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 30, 135, 74));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAutoFillBackground(false);
        lineEdit->setDragEnabled(false);
        lineEdit->setReadOnly(false);

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setAutoFillBackground(false);
        lineEdit_2->setDragEnabled(false);
        lineEdit_2->setReadOnly(false);

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setAutoFillBackground(false);
        lineEdit_3->setDragEnabled(false);
        lineEdit_3->setReadOnly(false);

        verticalLayout->addWidget(lineEdit_3);

        widget1 = new QWidget(Dialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 31, 52, 77));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, pushButton);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog", "Search!", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Genre", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Author", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
