#include "search.h"
#include "ui_search.h"
#include "mainwindow1.h"
#include "deletebook.h"
#include <QSqlTableModel>
#include <QLineEdit>
Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );

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
    QSqlQueryModel * mdlb = new QSqlQueryModel();

    //conn.connOpen();
    QSqlQuery * qrbk= new QSqlQuery(bkdb);

    //qrybook->prepare("select Genre , Name , Author , Year  from Book");
    qrbk->prepare("sselect * from Book ");
    qrbk->exec();

    mdlb->setQuery(*qrbk);
    ui->tableView->setModel(mdlb);
}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_clicked()
{
    QString genre , name , author , year;

   genre = ui->lineEdit_genre->text();
   name =  ui->lineEdit_name->text();
   author = ui->lineEdit_aut->text();
   year = ui->lineEdit_year->text();




    if(!bkdb.isOpen()){
        qDebug() << "Failed to opened database";
        return;
    }


    QSqlQuery   src;

    QString str = "select * from Book where ";
//    if (genre.size() == 0 && name.size() == 0 && author.size() == 0 && year.size() == 0){
//        QMessageBox::critical( 0 , "Search" , "Input parametr search");

//    }


    if (genre.size() > 0 && name.size() == 0 && author.size() == 0 && year.size() == 0)
    {

        str = "select * from Book where Genre = '"+genre+"'";
    }

    if (genre.size() == 0 && name.size() > 0 && author.size() == 0 && year.size() == 0)
    {

        str = "select * from Book where Name= '"+name+"'";
    }

    if (genre.size() == 0 && name.size() == 0 && author.size()  > 0 && year.size() == 0)
    {

        str = "select * from Book where Author= '"+author+"'";
    }

    if (genre.size() == 0 && name.size() == 0 && author.size()  == 0 && year.size() > 0)
    {

        str = "select * from Book where Year= '"+year+"'";
    }

    if (genre.size() > 0 && name.size() > 0 && author.size()  == 0 && year.size() == 0)
    {

        str = "select * from Book where Name= '"+name+"'";
    }


    if (genre.size() > 0 && name.size() == 0 && author.size()  > 0 && year.size() == 0)
    {

        str = "select * from Book where Author= '"+author+"'";
    }

    if (genre.size() > 0 && name.size() == 0 && author.size()  == 0 && year.size() > 0)
    {

        str = "select * from Book where Year= '"+year+"'";
    }

    if (genre.size() == 0 && name.size() > 0 && author.size()  > 0 && year.size() == 0)
    {

        str = "select * from Book where Author= '"+author+"'";
    }

    if (genre.size() == 0 && name.size() > 0 && author.size()  == 0 && year.size() > 0)
    {

        str = "select * from Book where Year= '"+year+"'";
    }

    if (genre.size() == 0 && name.size() == 0 && author.size()  > 0 && year.size() > 0)
    {

        str = "select * from Book where Year= '"+year+"'";
    }

    if (genre.size() > 0 && name.size() > 0 && author.size()  > 0 && year.size() == 0)
    {

        str = "select * from Book where Author= '"+author+"'";
    }

    if (genre.size() > 0 && name.size() > 0 && author.size()  == 0 && year.size() > 0 )
    {

        str = "select * from Book where Genre = '"+genre+"' and Name = '"+name+"' and Year = '"+year+"' ";
    }

    if (genre.size() > 0 && name.size() == 0 && author.size()  > 0 && year.size() > 0 )
    {

        str = "select * from Book where Genre = '"+genre+"' and Author = '"+author+"' and Year = '"+year+"' ";
    }

    if (genre.size() == 0 && name.size() > 0 && author.size()  > 0 && year.size() > 0 )
    {

        str = "select * from Book where Name = '"+name+"' and Author = '"+author+"' and Year = '"+year+"' ";
    }
    if (genre.size() > 0 && name.size() > 0 && author.size()  > 0 && year.size() > 0 )
    {

        str = "select * from Book where Name = '"+name+"' and Author = '"+author+"' and Year = '"+year+"' and Genre = '"+genre+"'";
    }

     if(genre.size() == 0 && name.size() == 0 && author.size() == 0 && year.size() == 0){
         QMessageBox::critical(0,"Search" , "vedite danie");

    }
//    else{
//        QMessageBox::critical( 0 , "Search" , "ne nashlo");
//    }


         if(src.exec(str)){
        int count = 0;

        while(src.next()){

            count++;

//            if( count  > 1 || count < 1 )  {

//                    QMessageBox::critical( 0 , "Search" , "ne nashlo");
//           }
            QSqlQueryModel * srbook = new QSqlQueryModel();
            QSqlQuery * qrybook = new QSqlQuery(bkdb);

            qrybook->prepare(str);
            qrybook->exec();

            srbook->setQuery(*qrybook);
            ui->tableView->setModel(srbook);


       }



        if( count == 0 )  {

                QMessageBox::critical( 0 , "Search" , "ne nashlo");
       }
}
}

void Search::on_pushButton_2_clicked()
{
    close();
    Deletebook delbook;
    delbook.setModal(true);
    delbook.exec();

}

void Search::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();

    QSqlQuery qry;

    qry.prepare("select * from Book where Genre = '"+val+"' or Name = '"+val+"' or Author = '"+val+"' or Year = '"+val+"'");

    if(qry.exec()){

        while(qry.next()){
            ui->lineEdit_genre->setText(qry.value(0).toString());
            ui->lineEdit_name->setText(qry.value(1).toString());
            ui->lineEdit_aut->setText(qry.value(2).toString());
            ui->lineEdit_year->setText(qry.value(3).toString());
            //ui->lineEdit_5->setText(qry.value(4).toString());
        }
    }

}


void Search::on_pushButton_del1_clicked()
{
    QString genre , author , name ,year;
    genre = ui->lineEdit_genre->text();
    author = ui->lineEdit_aut->text();
    name  = ui->lineEdit_name->text();
    year  =  ui->lineEdit_year->text();
    QSqlQuery del;
    del.prepare("Delete from Book where Genre = '"+genre+"' and Author = '"+author+"'");
    if(genre.size() == 0 &&  author.size() == 0){
        QMessageBox::information(0, "Non delete", "Deleted book is not succesfull");
    }
    else if(del.exec()){
        QMessageBox::information(0, "Delete", "Deleted book is succesfull");
        //on_pushButton_clicked();
         ui->lineEdit_genre->clear();
         ui->lineEdit_aut->clear();
         ui->lineEdit_name->clear();
         ui->lineEdit_year->clear();

    }

}


void Search::on_pushButton_update_clicked()
{

//   // Search delb1;
//    QSqlQueryModel * mdlb = new QSqlQueryModel();

//    //conn.connOpen();
//    QSqlQuery * qrbk= new QSqlQuery(bkdb);

//    //qrybook->prepare("select Genre , Name , Author , Year  from Book");
//    qrbk->prepare("select * from Book ");
//    qrbk->exec();

//    mdlb->setQuery(*qrbk);
//    ui->tableView->setModel(mdlb);

    //Search delb1;
    QSqlQueryModel * modalbook1 = new QSqlQueryModel();

    //conn.connOpen();
    QSqlQuery * qrybook1 = new QSqlQuery(bkdb);

    qrybook1->prepare("select * from Book");
    qrybook1->exec();

    modalbook1->setQuery(*qrybook1);
    ui->tableView->setModel(modalbook1);


}


void Search::on_pushButton_back_clicked()
{
    close();
    Deletebook dl;
    dl.setModal(true);
    dl.exec();

}
