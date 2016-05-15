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
