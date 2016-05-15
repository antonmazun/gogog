/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created: Sun 15. May 21:30:41 2016
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_add_book;
    QPushButton *pushButton_del_book;
    QPushButton *pushButton_del_user;
    QPushButton *pushButton_edit_user;

    void setupUi(QDialog *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(270, 224);
        groupBox = new QGroupBox(Admin);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 241, 161));
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 188, 128));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_add_book = new QPushButton(widget);
        pushButton_add_book->setObjectName(QString::fromUtf8("pushButton_add_book"));

        verticalLayout->addWidget(pushButton_add_book);

        pushButton_del_book = new QPushButton(widget);
        pushButton_del_book->setObjectName(QString::fromUtf8("pushButton_del_book"));

        verticalLayout->addWidget(pushButton_del_book);

        pushButton_del_user = new QPushButton(widget);
        pushButton_del_user->setObjectName(QString::fromUtf8("pushButton_del_user"));

        verticalLayout->addWidget(pushButton_del_user);

        pushButton_edit_user = new QPushButton(widget);
        pushButton_edit_user->setObjectName(QString::fromUtf8("pushButton_edit_user"));

        verticalLayout->addWidget(pushButton_edit_user);


        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QDialog *Admin)
    {
        Admin->setWindowTitle(QApplication::translate("Admin", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Admin", "\320\234\320\265\320\275\321\216 \320\260\320\264\320\274\321\226\320\275\321\226\321\201\321\202\321\200\320\260\321\202\320\276\321\200\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_add_book->setText(QApplication::translate("Admin", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\272\320\275\320\270\320\263\321\203", 0, QApplication::UnicodeUTF8));
        pushButton_del_book->setText(QApplication::translate("Admin", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \320\272\320\275\320\270\320\263\321\203", 0, QApplication::UnicodeUTF8));
        pushButton_del_user->setText(QApplication::translate("Admin", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \320\272\320\276\321\200\320\270\321\201\321\202\321\203\320\262\320\260\321\207\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_edit_user->setText(QApplication::translate("Admin", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\321\202\320\270 \320\272\320\276\321\200\320\270\321\201\321\202\321\203\320\262\320\260\321\207\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
