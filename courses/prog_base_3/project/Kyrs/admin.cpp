#include "admin.h"
#include "ui_admin.h"
#include "mainwindow1.h"
#include "deletebook.h"
Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_add_book_clicked()
{
    close();
    All all;
    all.setModal(true);
    all.exec();

}

void Admin::on_pushButton_del_book_clicked()
{
    close();
    Deletebook del;
    del.setModal(true);
    del.exec();
}
