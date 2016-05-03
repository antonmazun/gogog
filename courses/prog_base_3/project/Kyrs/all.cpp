#include "all.h"
#include "ui_all.h"
#include "mainwindow.h"
#include "search.h"
#include <QSqlQuery>
#include <QComboBox>
All::All(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::All)
{
    ui->setupUi(this);
}

All::~All()
{
    delete ui;
}

void All::on_pushButton_clicked()
{
    QSqlDatabase db;
    QSqlQuery query =   QSqlQuery(db);
    if(!query.exec("select * from Book")){
        qDebug() << query.lastError().databaseText();
        qDebug() << query.lastError().driverText();
    }
    while(query.next()){
        qDebug() << query.record();

    }
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("Book");

    if(!db.open()){

        qDebug() << db.lastError().text();
        return;
    }
    else {

        qDebug() << "Success!";
    }
    //model = new QSqlTableModel(this ,db);
   //comboBox = new QComboBox(this , db);
    // model->setTable("Book");
    /// model->select();
    // ui->tableView->setModel(model);
  //   ui->comboBox->setModel(model);
    // ui->comboBox->setModelColumn(2);
}
