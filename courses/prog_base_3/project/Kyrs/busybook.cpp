#include "busybook.h"
#include "ui_busybook.h"
#include "mainwindow1.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
Busybook::Busybook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Busybook)
{
    ui->setupUi(this);

    busyreg = QSqlDatabase::addDatabase("QSQLITE");
    busyreg.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");
    busyreg.open();
     if(!busyreg.open()){

         qDebug() << busyreg.lastError().text();
          return;
      }
      else {

         qDebug() << "otkrilo database reg!";

    }

     QString sign2 = "1";
     QString res;
     QSqlQuery qrybusyreg("SELECT * FROM Reg where Sign = '"+sign2+"'");
     while(qrybusyreg.next()){

         res  = qrybusyreg.value(4).toString();
//ui->label_proverka->setText(res);
     }

   busyreg.close();



    busydb = QSqlDatabase::addDatabase("QSQLITE");
    busydb.setDatabaseName("D:/Kyrs/Kyrs/Book.db");
    busydb.open();
    if(!busydb.open()){

        qDebug() << busydb.lastError().text();
         return;
     }
     else {

        qDebug() << "Success!";

   }

   QSqlQueryModel * modalbusy = new QSqlQueryModel();
   QSqlQuery * qrybusy = new QSqlQuery(busydb);
   qrybusy->prepare("select Genre ,Name , Author , Year from Book where  Status = '"+res+"'");
   qrybusy->exec();

   modalbusy->setQuery(*qrybusy);
   ui->tableView->setModel(modalbusy);
   busydb.close();

}

Busybook::~Busybook()
{
    delete ui;
}

void Busybook::on_pushButton_2_clicked()
{
    close();
    Searchbook s;
    s.setModal(true);
    s.exec();

}


void Busybook::on_tableView_activated(const QModelIndex &index)
{

    busydb1 = QSqlDatabase::addDatabase("QSQLITE");
    busydb1.setDatabaseName("D:/Kyrs/Kyrs/Book.db");
    busydb1.open();
    QString val = ui->tableView->model()->data(index).toString();

    QSqlQuery qry;

    qry.prepare("select * from Book where Genre = '"+val+"' or Name = '"+val+"' or Author = '"+val+"' or Year = '"+val+"'");

    if(qry.exec()){

        while(qry.next()){

            ui->lineEdit_g->setText(qry.value(0).toString());
            ui->lineEdit_n->setText(qry.value(1).toString());
            ui->lineEdit_a->setText(qry.value(2).toString());
            ui->lineEdit_y->setText(qry.value(3).toString());
            if(!busydb1.isOpen()){

                qDebug() << "ne otkrito";
            }
        }
    }

busydb1.close();
}


void Busybook::on_pushButton_give_clicked()
{
    QString busyname , busygenre , busyauthor , busyyear , result , s = "1";
    QString n = "0";
 // busyreg.open();
    busyname = ui->lineEdit_n->text();
    busygenre = ui->lineEdit_g->text();
    busyauthor = ui->lineEdit_a->text();
    busyyear = ui->lineEdit_y->text();

    busyreg_click = QSqlDatabase::addDatabase("QSQLITE");
    busyreg_click.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");
    busyreg_click.open();
     if(!busyreg_click.open()){

         qDebug() << busyreg_click.lastError().text();
          return;
      }
      else {

         qDebug() << "otkrilo database reg!";

    }



     QSqlQuery qrybusyreg("SELECT * FROM Reg where Sign = '"+s+"'");
     while(qrybusyreg.next()){

         result  = qrybusyreg.value(4).toString();

     }
     busyreg_click.close();

     busybd_click = QSqlDatabase::addDatabase("QSQLITE");
     busybd_click.setDatabaseName("D:/Kyrs/Kyrs/Book.db");
     busybd_click.open();
     if(!busybd_click.open()){

         qDebug() <<"problema ";
          return;
      }
      else {

         qDebug() << "Success snova!";

    }


    QSqlQuery b;
    b.prepare ("update Book set Status  = '"+n+"' where Status = '"+result+"' and Name = '"+busyname+"' and Genre = '"+busygenre+"' and Author = '"+busyauthor+"' and Year = '"+busyyear+"'");


    if(!busybd_click.isOpen()){

        puts("bd ne otkrito s knigami");
    }

    else {
        puts ("ads");
    }
    if(b.exec()){
        QMessageBox::information(0,"Otdal" , "Vce ok!");
        ui->lineEdit_a->clear();
        ui->lineEdit_g->clear();
        ui->lineEdit_n->clear();
        ui->lineEdit_y->clear();
       // busybd_click.close();
        ////////////////****Обновление базы*****\\\\\\\\\\\\\\\\\\






       QSqlQueryModel * modalbusy = new QSqlQueryModel();
       QSqlQuery * qrybusy = new QSqlQuery(busybd_click);
       qrybusy->prepare("select Genre ,Name , Author , Year from Book where  Status = '"+result+"'");
       qrybusy->exec();

       modalbusy->setQuery(*qrybusy);
       ui->tableView->setModel(modalbusy);


    }
    busybd_click.close();
}
/*
void Busybook::on_pushButton_sear_busy_clicked()
{



      bdreg = QSqlDatabase::addDatabase("QSQLITE");
      bdreg.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");
      bdreg.open();
       if(!bdreg.open()){

           qDebug() << bdreg.lastError().text();
            return;
        }
        else {

           qDebug() << "otkrilo database reg!";

      }
     QString status = "1";
     QString id;
     QSqlQuery qrybusyreg("SELECT * FROM Reg where Sign = '"+status+"'");
     while(qrybusyreg.next()){

         id  = qrybusyreg.value(4).toString();
            ui->lineEdit_a->setText(id);
     }



   bdreg.close();


   bdbooks = QSqlDatabase::addDatabase("QSQLITE");
   bdbooks.setDatabaseName("D:/Kyrs/Kyrs/Book.db");
   bdbooks.open();
    if(!bdbooks.open()){

        qDebug() << bdbooks.lastError().text();
         return;
     }
     else {

        qDebug() << "otkrilo database reg!";

   }
    QString genre2 , name2 , author2 , year2;

   genre2 = ui->lineEdit_g->text();
   name2 =  ui->lineEdit_n->text();
   author2 = ui->lineEdit_a->text();
   year2 = ui->lineEdit_y->text();


   QSqlQuery  src;


   QString str = "select * from Book where ";



   if (genre2.size() > 0 && name2.size() == 0 && author2.size() == 0 && year2.size() == 0)
   {

       str = "select * from Book where Genre = '"+genre2+"'  and Status = '"+id+"'";
   }

   if (genre2.size() == 0 && name2.size() > 0 && author2.size() == 0 && year2.size() == 0)
   {

       str = "select * from Book where Name= '"+name2+"' and Status = '"+id+"'";
   }

   if (genre2.size() == 0 && name2.size() == 0 && author2.size()  > 0 && year2.size() == 0)
   {

       str = "select * from Book where Author= '"+author2+"''and Status = '"+id+"'";
   }

   if (genre2.size() == 0 && name2.size() == 0 && author2.size()  == 0 && year2.size() > 0)
   {

       str = "select * from Book where Year= '"+year2+"'  and Status = '"+id+"'";
   }

   if (genre2.size() > 0 && name2.size() > 0 && author2.size()  == 0 && year2.size() == 0)
   {

       str = "select * from Book where Name= '"+name2+"'and Status = '"+id+"'";
   }


   if (genre2.size() > 0 && name2.size() == 0 && author2.size()  > 0 && year2.size() == 0)
   {

       str = "select * from Book where Author= '"+author2+"' 'and Status = '"+id+"'";
   }

   if (genre2.size() > 0 && name2.size() == 0 && author2.size()  == 0 && year2.size() > 0)
   {

       str = "select * from Book where Year= '"+year2+"' and Status = '"+id+"'";
   }

   if (genre2.size() == 0 && name2.size() > 0 && author2.size()  > 0 && year2.size() == 0)
   {

       str = "select * from Book where Author= '"+author2+"''and Status = '"+id+"'";
   }

   if (genre2.size() == 0 && name2.size() > 0 && author2.size()  == 0 && year2.size() > 0)
   {

       str = "select * from Book where Year= '"+year2+"' and Status = '"+id+"'";
   }

   if (genre2.size() == 0 && name2.size() == 0 && author2.size()  > 0 && year2.size() > 0)
   {

       str = "select * from Book where Year= '"+year2+"' and Status = '"+id+"'";
   }

   if (genre2.size() > 0 && name2.size() > 0 && author2.size()  > 0 && year2.size() == 0)
   {

       str = "select * from Book where Author= '"+author2+"' and Status = '"+id+"'";
   }

   if (genre2.size() > 0 && name2.size() > 0 && author2.size()  == 0 && year2.size() > 0 )
   {

       str = "select * from Book where Genre = '"+genre2+"' and Name = '"+name2+"' and Year = '"+year2+"' and Status  = '"+id+"' ";
   }

   if (genre2.size() > 0 && name2.size() == 0 && author2.size()  > 0 && year2.size() > 0 )
   {

       str = "select * from Book where Genre = '"+genre2+"' and Author = '"+author2+"' and Year = '"+year2+"' and Status  = '"+id+"' ";
   }

   if (genre2.size() == 0 && name2.size() > 0 && author2.size()  > 0 && year2.size() > 0 )
   {

       str = "select * from Book where Name = '"+name2+"' and Author = '"+author2+"' and Year = '"+year2+"' and Status  = '"+id+"' ";
   }
   if (genre2.size() > 0 && name2.size() > 0 && author2.size()  > 0 && year2.size() > 0 )
   {

       str = "select * from Book where Name = '"+name2+"' and Author = '"+author2+"' and Year = '"+year2+"' and Genre = '"+genre2+"' and Status  = '"+id+"'";
   }

    if(genre2.size() == 0 && name2.size() == 0 && author2.size() == 0 && year2.size() == 0){
        QMessageBox::critical(0,"Search" , "vedite danie");

   }


        if(src.exec(str)){
       int count = 0;

       while(src.next()){

           count++;


           QSqlQueryModel * modelbook = new QSqlQueryModel();
           QSqlQuery * qrybook_b = new QSqlQuery(bdbooks);



           qrybook_b->prepare(str);
           qrybook_b->exec();

           modelbook->setQuery(*qrybook_b);
           ui->tableView->setModel(modelbook);

      }



       if( count == 0 )  {

               QMessageBox::critical( 0 , "Search" , "ne nashlo");

               QSqlQueryModel * modalbookbusy = new QSqlQueryModel();

               QSqlQuery * qrybusybook = new QSqlQuery(bdbooks);

               qrybusybook->prepare("select *  from Book where Status = '"+id+"' ");
               qrybusybook->exec();

               modalbookbusy->setQuery(*qrybusybook);
               ui->tableView->setModel(modalbookbusy);

               ui->lineEdit_a->clear();
               ui->lineEdit_g->clear();
               ui->lineEdit_n->clear();
               ui->lineEdit_y->clear();
      }
     bdbooks.close();
}



}

*/
