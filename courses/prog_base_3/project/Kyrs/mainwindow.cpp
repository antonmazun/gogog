#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "all.h"
#include "search.h"
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*
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
    */
   // tableView = new QComboBox();
 /*  model = new QSqlTableModel(this ,db);
    model->setTable("Book");
    model->select();
    ui->tableView->setModel(model);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(2);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Search_but_clicked()
{

    Search search;
    search.setModal(true);
    search.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    All all;
    all.setModal(true);
    all.exec();

    model = new QSqlTableModel(this ,db);
   //comboBox = new QComboBox(this , db);
     model->setTable("Book");
    model->select();
    //ui->tableView->setModel(model);
 //   ui->comboBox->setModel(model);
   // ui->comboBox->setModelColumn(2);

}
