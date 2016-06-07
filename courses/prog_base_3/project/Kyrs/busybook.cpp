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

     if(!busyreg.open()){

         qDebug() << busyreg.lastError().text();
          return;
      }
      else {

         qDebug() << "otkrilo database reg!";

    }

     QString sign = "1";
     QString res;
     QSqlQuery qrybusyreg("SELECT * FROM Reg where Sign = '"+sign+"'");
     while(qrybusyreg.next()){

         res  = qrybusyreg.value(4).toString();

     }
     busyreg.close();



    busydb = QSqlDatabase::addDatabase("QSQLITE");
    busydb.setDatabaseName("D:/Kyrs/Kyrs/Book.db");

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
    busydb.open();
    QString val = ui->tableView->model()->data(index).toString();

    QSqlQuery qry;

    qry.prepare("select * from Book where Genre = '"+val+"' or Name = '"+val+"' or Author = '"+val+"' or Year = '"+val+"'");

    if(qry.exec()){

        while(qry.next()){

            ui->lineEdit_g->setText(qry.value(0).toString());
            ui->lineEdit_n->setText(qry.value(1).toString());
            ui->lineEdit_a->setText(qry.value(2).toString());
            ui->lineEdit_y->setText(qry.value(3).toString());

        }
    }

}

void Busybook::on_pushButton_give_clicked()
{
    QString busyname , busygenre , busyauthor , busyyear , idd , sign = "1";
    QString n = "0";

    busyname = ui->lineEdit_n->text();
    busygenre = ui->lineEdit_g->text();
    busyauthor = ui->lineEdit_a->text();
    busyyear = ui->lineEdit_y->text();
    busyreg.open();

    QSqlQuery qt("SELECT * FROM  Reg where Sign = '"+sign+"'");

    while(qt.next()){
        idd = qt.value(4).toString();

    }
   ui->lineEdit_y->setText(idd);
    busyreg.close();
    busydb.open();
    QSqlQuery b;
    b.prepare ("update Book set Status  = '"+n+"' where Status = '"+idd+"' and Name = '"+busyname+"' and Genre = '"+busygenre+"' and Author = '"+busyauthor+"' and Year = '"+busyyear+"'");

    if(!busydb.isOpen()){

        puts("sadsfd");
    }
    else {
        puts ("ads");
    }
    if(b.exec()){
        QMessageBox::information(0,"Otdal" , "Vce ok!");
        busydb.close();
    }
}
