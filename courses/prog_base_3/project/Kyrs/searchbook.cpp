#include "searchbook.h"
#include "ui_searchbook.h"
#include "mainwindow1.h"
#include "entry.h"
Searchbook::Searchbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Searchbook)
{
    ui->setupUi(this);



    srcbd = QSqlDatabase::addDatabase("QSQLITE");

    srcbd.setDatabaseName("D:/Kyrs/Kyrs/Book.db");

    if(!srcbd.open()){

        qDebug() << srcbd.lastError().text();
         return;
     }
     else {

        qDebug() << "Success!";

   }

    //All conn;
    QSqlQueryModel * modalbk = new QSqlQueryModel();

    //conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(srcbd);
    qry->prepare("select Genre ,Name , Author , Year from Book");
    qry->exec();

    modalbk->setQuery(*qry);
    ui->tableView_1->setModel(modalbk);


}

Searchbook::~Searchbook()
{
    delete ui;
}



void Searchbook::on_tableView_1_activated(const QModelIndex &index)
{

    QString val = ui->tableView_1->model()->data(index).toString();

    QSqlQuery qry;

    qry.prepare("select * from Book where Genre = '"+val+"' or Name = '"+val+"' or Author = '"+val+"' or Year = '"+val+"'");

    if(qry.exec()){

        while(qry.next()){
            ui->lineEdit_name1->setText(qry.value(1).toString());
            ui->lineEdit_genre1->setText(qry.value(0).toString());
            ui->lineEdit_aut1->setText(qry.value(2).toString());
            ui->lineEdit_year1->setText(qry.value(3).toString());
            ui->lineEdit1->setText(qry.value(4).toString());
        }
    }

}


void Searchbook::on_pushButton_clicked()
{
    close();
    Entry en;
    en.setModal(true);
    en.exec();

}


void Searchbook::on_pushButton_search_1_clicked()
{
    QString genre1 , name1 , author1 , year1;

   genre1 = ui->lineEdit_genre1->text();
   name1 =  ui->lineEdit_name1->text();
   author1 = ui->lineEdit_aut1->text();
   year1 = ui->lineEdit_year1->text();




    if(!srcbd.isOpen()){
        qDebug() << "Failed to opened database";
        return;
    }


    QSqlQuery   src;

    QString str = "select * from Book where ";
//    if (genre1.size() == 0 && name1.size() == 0 && author1.size() == 0 && year1.size() == 0){
//        QMessageBox::critical( 0 , "Search" , "Input parametr search");

//    }


    if (genre1.size() > 0 && name1.size() == 0 && author1.size() == 0 && year1.size() == 0)
    {

        str = "select * from Book where Genre = '"+genre1+"'";
    }

    if (genre1.size() == 0 && name1.size() > 0 && author1.size() == 0 && year1.size() == 0)
    {

        str = "select * from Book where Name= '"+name1+"'";
    }

    if (genre1.size() == 0 && name1.size() == 0 && author1.size()  > 0 && year1.size() == 0)
    {

        str = "select * from Book where Author= '"+author1+"'";
    }

    if (genre1.size() == 0 && name1.size() == 0 && author1.size()  == 0 && year1.size() > 0)
    {

        str = "select * from Book where Year= '"+year1+"'";
    }

    if (genre1.size() > 0 && name1.size() > 0 && author1.size()  == 0 && year1.size() == 0)
    {

        str = "select * from Book where Name= '"+name1+"'";
    }


    if (genre1.size() > 0 && name1.size() == 0 && author1.size()  > 0 && year1.size() == 0)
    {

        str = "select * from Book where Author= '"+author1+"'";
    }

    if (genre1.size() > 0 && name1.size() == 0 && author1.size()  == 0 && year1.size() > 0)
    {

        str = "select * from Book where Year= '"+year1+"'";
    }

    if (genre1.size() == 0 && name1.size() > 0 && author1.size()  > 0 && year1.size() == 0)
    {

        str = "select * from Book where Author= '"+author1+"'";
    }

    if (genre1.size() == 0 && name1.size() > 0 && author1.size()  == 0 && year1.size() > 0)
    {

        str = "select * from Book where Year= '"+year1+"'";
    }

    if (genre1.size() == 0 && name1.size() == 0 && author1.size()  > 0 && year1.size() > 0)
    {

        str = "select * from Book where Year= '"+year1+"'";
    }

    if (genre1.size() > 0 && name1.size() > 0 && author1.size()  > 0 && year1.size() == 0)
    {

        str = "select * from Book where Author= '"+author1+"'";
    }

    if (genre1.size() > 0 && name1.size() > 0 && author1.size()  == 0 && year1.size() > 0 )
    {

        str = "select * from Book where Genre = '"+genre1+"' and Name = '"+name1+"' and Year = '"+year1+"' ";
    }

    if (genre1.size() > 0 && name1.size() == 0 && author1.size()  > 0 && year1.size() > 0 )
    {

        str = "select * from Book where Genre = '"+genre1+"' and Author = '"+author1+"' and Year = '"+year1+"' ";
    }

    if (genre1.size() == 0 && name1.size() > 0 && author1.size()  > 0 && year1.size() > 0 )
    {

        str = "select * from Book where Name = '"+name1+"' and Author = '"+author1+"' and Year = '"+year1+"' ";
    }
    if (genre1.size() > 0 && name1.size() > 0 && author1.size()  > 0 && year1.size() > 0 )
    {

        str = "select * from Book where Name = '"+name1+"' and Author = '"+author1+"' and Year = '"+year1+"' and Genre = '"+genre1+"'";
    }

     if(genre1.size() == 0 && name1.size() == 0 && author1.size() == 0 && year1.size() == 0){
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
            QSqlQuery * qrybook = new QSqlQuery(srcbd);

            qrybook->prepare(str);
            qrybook->exec();

            srbook->setQuery(*qrybook);
            ui->tableView_1->setModel(srbook);


       }



        if( count == 0 )  {

                QMessageBox::critical( 0 , "Search" , "ne nashlo");

                QSqlQueryModel * modalbk = new QSqlQueryModel();

                //conn.connOpen();
                QSqlQuery * qry = new QSqlQuery(srcbd);
                qry->prepare("select Genre ,Name , Author , Year from Book");
                qry->exec();

                modalbk->setQuery(*qry);
                ui->tableView_1->setModel(modalbk);

                ui->lineEdit1->clear();
                ui->lineEdit_aut1->clear();
                ui->lineEdit_genre1->clear();
                ui->lineEdit_name1->clear();
                ui->lineEdit_year1->clear();
       }

}
}

void Searchbook::on_pushButton_take_clicked()
{



}

