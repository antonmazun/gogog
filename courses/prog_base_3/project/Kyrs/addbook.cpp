#include "addbook.h"
#include "ui_addbook.h"
#include "mainwindow1.h"
#include <cstdlib>
#include "mainwindow1.h"
Addbook::Addbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addbook)
{

    ui->setupUi(this);
setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );
    bookdb = QSqlDatabase::addDatabase("QSQLITE");
    bookdb.setDatabaseName("D:/Kyrs/Kyrs/Book.db");
    if(!bookdb.open()){
        qDebug() << bookdb.lastError().text();
         return;
     }
     else {
        qDebug() << "Success book!";
   }
/*
    reg.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");
    if(!reg.open()){
        qDebug() << reg.lastError().text();
         return;
     }
     else {
        qDebug() << "Success reg!";
   }
*/
}

Addbook::~Addbook()
{
    delete ui;
}

void Addbook::on_pushButton_save_clicked()
{
    if(!bookdb.isOpen()){
         qDebug() << "Failed to opened database";
         return;
     }
    QString author, genre , year ,name, des;
   // int year;
    // QSqlQuery tmp;
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
          ui->label_status->setText("incorrect year");

}






          else if(author.size() < 1)
        {
        ui->label_status->setText("Please enter author");
        }
       else  if(genre.size() < 1)
        {
        ui->label_status->setText("Please enter genre");
        }
       else  if(name.size() < 1)
        {
        ui->label_status->setText("Please enter name of book");
        }

       else
        {
           QString status = "0";
            QSqlQuery que;
            que.prepare("insert into Book(Genre , Name , Author , Year, Descriptions , Status) values ('"+genre+"' ,'"+name+"' ,'"+author+"' , '"+year+"' , '"+des+"' , '"+status+"')");

                    if(que.exec())
                    {


                       // QString signf = "0";
                      //  mydb.isOpen();
//                        QSqlQuery qrybookup;

//                        qrybookup.prepare("update Book set Status = '"+status+"' where Name = '"+name+"' and Author = '"+author+"' ");
                        // QMessageBox::critical(this , tr("Registration"),tr("Registration is successfull"));
                        QMessageBox::information(0, "ADD", "Added book is succesfull");
                        //  mydb.close();
                        close();
                       /* Entry entry;
                        entry.setModal(true);
                        entry.exec();*/
                    }
                    else
                    {
                     QMessageBox::critical(this , tr("Error") , que.lastError().text());
                     // QMessageBox::information(0, "Registration", "Change your username");
                    }
          }
}

void Addbook::on_pushButton_clicked()
{
    close();
    All all;
    all.setModal(true);
    all.exec();
}
/*
void Addbook::on_pushButton_2_clicked()
{

    regadd.isOpen();
     QString sign = "0";
     QString signf = "1";
     QSqlQuery qryf;

     qryf.prepare("Update Reg set Sign = '"+sign+"' where Sign = '"+signf+"'");
     if(qryf.exec()){
         regadd.close();
         close();
         MainWindow1 signin;
         signin.show();

     }
}
*/
