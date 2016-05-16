#include "deletebook.h"
#include "ui_deletebook.h"
#include "admin.h"
#include "mainwindow1.h"
#include "all.h"
//#include <QString>
Deletebook::Deletebook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deletebook)
{
    ui->setupUi(this);

    delbd = QSqlDatabase::addDatabase("QSQLITE");

    delbd.setDatabaseName("D:/Kyrs/Kyrs/Book.db");

    if(!delbd.open()){

        qDebug() << delbd.lastError().text();
         return;
     }
     else {

        qDebug() << "Success!";

   }
}

Deletebook::~Deletebook()
{
    delete ui;
}

void Deletebook::on_pushButton_3_clicked()
{
    close();
    Admin ad;
    ad.setModal(true);
    ad.exec();
}

void Deletebook::on_pushButton_2_clicked()
{

    Deletebook delb;
    QSqlQueryModel * modalbook = new QSqlQueryModel();

    //conn.connOpen();
    QSqlQuery * qrybook = new QSqlQuery(delb.delbd);

    qrybook->prepare("select Genre , Name , Author , Year  from Book");
    qrybook->exec();

    modalbook->setQuery(*qrybook);
    ui->tableView->setModel(modalbook);




}

void Deletebook::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();

    QSqlQuery qry;

    qry.prepare("select * from Book where Genre = '"+val+"'");

    if(qry.exec()){

        while(qry.next()){
            ui->lineEdit_4->setText(qry.value(1).toString());
            ui->lineEdit_2->setText(qry.value(0).toString());
             ui->lineEdit->setText(qry.value(2).toString());
              ui->lineEdit_3->setText(qry.value(3).toString());
              ui->lineEdit_5->setText(qry.value(4).toString());
        }
    }


}

void Deletebook::on_pushButton_delete_clicked()
{
    QString genre , author; //;, year , name, desc;// = ui->tableView->model()->data(index).toString();
    genre = ui->lineEdit_2->text();
    author = ui->lineEdit->text();
    QSqlQuery del;
    del.prepare("Delete from Book where Genre = '"+genre+"' and Author = '"+author+"'");
    if(del.exec()){
        QMessageBox::information(0, "Delete", "Deleted book is succesfull");
    }
    else {
          QMessageBox::information(0, "Delete", "Deleted book is  not succesfull");
    }

   /* QString valdel = ui->tableView->model()->data(index).toString();

    QSqlQuery del;

    del.prepare("select * from Book where Genre = '"+valdel+"'");
    if(qry.exec()){

        while(qry.next()){
            ui->lineEdit_4->setText(qry.value(1).toString());
            ui->lineEdit_2->setText(qry.value(0).toString());
             ui->lineEdit->setText(qry.value(2).toString());
              ui->lineEdit_3->setText(qry.value(3).toString());
              ui->lineEdit_5->setText(qry.value(4).toString());
        }
    }
    if(del.exec()){
        QMessageBox::information(0, "Delete", "Deleted book is succesfull");
    }
    else {
          QMessageBox::information(0, "Delete", "Deleted book is  not succesfull");
    }
    */
}
