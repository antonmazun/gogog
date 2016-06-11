#include "all.h"
#include "ui_all.h"
#include "mainwindow1.h"
#include "search.h"
#include <QSqlQuery> // класс запроса
#include <QComboBox>
#include <QDebug>
//#include <sqlite3.h>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSQlRecord>
#include "addbook.h"
//#include <QSqlQuery> // класс запроса
//#include <QComboBox>
#include <QTableView>
#include "admin.h"
All::All(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::All)
{
    ui->setupUi(this);
setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );

regall = QSqlDatabase::addDatabase("QSQLITE");
regall.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/Kyrs/Kyrs/Book.db");

    if(!db.open()){

        qDebug() << db.lastError().text();
         return;
     }
     else {

        qDebug() << "Success!";

   }

    //All conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    //conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(db);
    qry->prepare("select Genre , Name , Author , Year  from Book");
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    db.close();

/*
    regall.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");
    if(!regall.open()){
        qDebug() << regall.lastError().text();
         return;
     }
     else {
        qDebug() << "Success reg!";
   }
*/

   /*
    QSqlQueryModel * model = new QSqlQueryModel();

    QSqlQuery * qry = new QSqlQuery(mydb);

    qry->prepare("select * from doctors");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

    mydb.close();
    qDebug()«(model->rowCount());*/
}
/*
   // QSqlTableModel model;
    model  = new  QSqlTableModel (this , db);
    model.setTable("Book");
    model.select();
  // ui->tableView->setModel(model);
    //ui->comboBox->setModelColumn(2);

*/


All::~All()
{
   /* delete ui;
    All conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    //conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(conn.db);

    qry->prepare("select Genre , Name , Author , Year  from Book");
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
*/
}

void All::on_pushButton_clicked()
{

    All conn;
    close();
conn.setModal(true);
conn.exec();

QSqlQueryModel * modal = new QSqlQueryModel();

//conn.connOpen();
QSqlQuery * qry = new QSqlQuery(conn.db);

qry->prepare("select Genre , Name , Author , Year  from Book");
qry->exec();

modal->setQuery(*qry);
ui->tableView->setModel(modal);

//conn.coonClose();
//qDebug() << (modal->rowCount());

/*

  //  QSqlDatabase db;
    QSqlQuery query = QSqlQuery(db);

    if(!query.exec("SELECT * FROM Book")){
       qDebug() << query.lastError().databaseText();
        qDebug() << query.lastError().driverText();
        return;


     //  puts(" ploxa");

    }
   /* while(query.next()){
        qDebug() << query.record();

    }

//  QSqlTableModel model;
        model  = new QSqlTableModel(this , db);
        model.setTable("Book");
        model.select();
        ui->tableView->setModel(model);

    ui->comboBox->setModelColumn(5);

*/


}
/*
void All::on_tableView_activated(const QModelIndex &index)
{



}
*/



void All::on_pushButton_add_clicked()
{/*
    Addbook add;
    add.setModal(true);
    add.exec();
*/

}

void All::on_pushButton_2_clicked()
{
    close();
    Admin ad;
    ad.setModal(true);
    ad.exec();
}

void All::on_tableView_activated(const QModelIndex &index)
{

}

void All::on_pushButton_3_clicked()
{
    regall = QSqlDatabase::addDatabase("QSQLITE");
    regall.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");
 regall.open();
     QString sign = "0";
     QString signf = "1";
     QSqlQuery qryf;

 if(!regall.isOpen()){
         puts("ploxa");
}
     qryf.prepare("Update Reg set Sign = '"+sign+"' where Sign = '"+signf+"'");
     if(qryf.exec()){

         close();
         MainWindow1 signin;
         signin.show();
         close();
}

regall.close();
}



void All::on_pushButton_save_clicked()
{



    db.open();
    if(!db.isOpen()){
         qDebug() << "Failed to opened database";
         return;
     }
    QString author, genre , year ,name, des;

        author = ui->lineEdit_aut->text();
        genre = ui->lineEdit_genre->text();
        name = ui->lineEdit_name_add_book->text();
        year = ui->lineEdit_year->text();
        des = ui->lineEdit_des->text();
//        if (year.size() > 4 || year.toInt() > 2016){
//            ui->label_info->setText("incorrect year");
//        }
//        for(int i =0 ; i < year.length() ; i++){
//            if(year[i] > 'a' && year[i]  < 'z' || year.size() > 4 || year.toInt() > 2016 ){
//                ui->label_status->setText("incorrect year");
//            }


//        for (int i = 0 ; i < year.length() ; i++) {


   // }

//            else if (year[i] > 'a' && year[i]  < 'z'){
//             //ui->label_status->setText("di4b");
//                //  QMessageBox::critical(0 , "Error" , "di4b");
//                 ui->label_status->setText("di4b");
//        }

      // }
 for(int i = 0 ; i < year.length() ; i++){

     if (year[i] > 'a' && year[i]  < 'z'){
     //ui->label_status->setText("di4b");
          QMessageBox::critical(0 , "Error" , "di4b");
        // ui->label_status->setText("di4b");
    }
 }

      if(author.size() == 0 && genre.size() == 0 && name.size() == 0 && year.size() == 0 && des.size() == 0){
      QMessageBox::information(0 , "Error" , "Vvedite knigy");
  }
     else if(year.size() > 4 || year.toInt() > 2016 ){
          ui->label_info->setText("incorrect year");

}






          else if(author.size() < 1)
        {
        ui->label_info->setText("Please enter author");
        }
       else  if(genre.size() < 1)
        {
        ui->label_info->setText("Please enter genre");
        }
       else  if(name.size() < 1)
        {
        ui->label_info->setText("Please enter name of book");
        }

       else
        {
           QString status = "0";
            QSqlQuery que;
            que.prepare("insert into Book(Genre , Name , Author , Year, Descriptions , Status) values ('"+genre+"' ,'"+name+"' ,'"+author+"' , '"+year+"' , '"+des+"' , '"+status+"')");

                    if(que.exec())
                    { QMessageBox::information(0, "ADD", "Added book is succesfull");
                        on_pushButton_clicked();
                        db.close();

                        ui->lineEdit_aut->clear();
                        ui->lineEdit_genre->clear();
                        ui->lineEdit_name_add_book->clear();
                        ui->lineEdit_year->clear();
                        ui->lineEdit_des->clear();

                    }
                    else
                    {
                     QMessageBox::critical(this , tr("Error") , que.lastError().text());

                    }
          }
}
