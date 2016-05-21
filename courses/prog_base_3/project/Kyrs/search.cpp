#include "search.h"
#include "ui_search.h"
#include "mainwindow1.h"


Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);


    bkdb = QSqlDatabase::addDatabase("QSQLITE");
    bkdb.setDatabaseName("D:/Kyrs/Kyrs/Book.db");
   // dbadm.setDatabaseName("D:/Kyrs/Kyrs/Admins.db");
    if(!bkdb.open()){
        qDebug() << bkdb.lastError().text();
         return;
     }
     else {
        qDebug() << "Success!";
   }
}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_clicked()
{
    QString genre , name , author , year;


   genre =  ui->lineEdit_genre->text();
  name =   ui->lineEdit_name->text();
   author  =  ui->lineEdit_aut->text();
   year = ui->lineEdit_year->text();




    if(!bkdb.isOpen()){
        qDebug() << "Failed to opened database";
        return;
    }


    QSqlQuery src;


    if(src.exec("select * from Book where Genre = '"+genre+"' and Name = '"+name+"' and Author = '"+author+"'   and  Year = '"+year+"'")){
        int count = 0;
        while(src.next()){
            count++;
        }

        if(count == 1){
             ui->label_status->setText("Norm ");
        }
        if( count  < 1)  {
            ui->label_status->setText("neNorm1 ");

       }
}
            // or Name  = '" +name+"' or Author = '"+author+"'  or  Year = '"+year+"'")){
 /*else   if(src.exec("select * from Book where Name = '"+name+"' ")){

       ui->label_status->setText("Norm1 ");


}*/


//}

//        if(count == 1 ){

          //   ui->label_status->setText("Norm ");

         /*  All admin;
            admin.setModal(true);
            admin.exec();*/
       // }
}
//}
//}
