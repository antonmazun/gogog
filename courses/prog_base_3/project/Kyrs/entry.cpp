#include "entry.h"
#include "ui_entry.h"
#include "mainwindow1.h"

Entry::Entry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Entry)
{
setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );
    ui->setupUi(this);
    QImage image;
    image.load("D:/Kyrs/Kyrs/cat1.jpg");

    image = image.scaledToWidth(ui->label->width(), Qt::SmoothTransformation);
    ui->label->setPixmap(QPixmap::fromImage(image));

  entrydb = QSqlDatabase::addDatabase("QSQLITE");
    entrydb.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");
     if(!entrydb.open()){
         qDebug() << entrydb.lastError().text();
          return;
      }
      else {
         qDebug() << "Success reg!";
    }

entrydb.close();
}

Entry::~Entry()
{
    delete ui;
}
/*
void Entry::on_pushButton_all_clicked()
{

    All all;
    all.setModal(true);
    all.exec();

}
*/
void Entry::on_pushButton_search_clicked()
{
    Search sch;
    sch.setModal(true);
    sch.exec();
}





void Entry::on_pushButton_search_3_clicked()
{
    close();
    Searchbook book;
    book.setModal(true);
    book.exec();

}

void Entry::on_pushButton_all_3_clicked()
{

}

void Entry::on_pushButton_clicked()
{
    entrydb.open();
       QString sign = "0";
       QString signf = "1";
       QSqlQuery qryf;

       qryf.prepare("Update Reg set Sign = '"+sign+"' where Sign = '"+signf+"'");
       if(qryf.exec()){
           entrydb.close();
           close();
           MainWindow1 signin;
           signin.show();

       }

}

void Entry::on_pushButton_2_clicked()
{
    entrydb.open();
   /* QString login, password, logcompar, pascompar, search = "1";
        login=ui->lineEdit_logdel->text();
        password=ui->lineEdit_passdel->text();

        if(!prtf.isOpen())
        {
            qDebug()<<"Failed to open the database";
        }
        connOpen();

        QSqlQuery query ("SELECT * FROM prtf where Search = '"+search+"'");

             while (query.next())
             {
             logcompar = query.value(3).toString();
             pascompar = query.value(4).toString();
             }


       if(password != pascompar)
       {
           ui->label_mesdel->setText("Password is not correct");
       }
       else if(login != logcompar)
       {
           ui->label_mesch->setText("Login is not correct");
       }
       else if(login.size() < 1)
       {
           ui->label_mesdel->setText("Enter your login");
       }
       else if(password.size() < 1)
       {
           ui->label_mesdel->setText("Enter your password");
       }
       else
       {*/
           QSqlQuery qry;
           qry.prepare("Delete from  Reg where Sign = '1'");
            if(qry.exec())
            {
                close();
               entrydb.close();

            }
            else
            {
                QMessageBox::critical(this, tr("Error::"), qry.lastError().text());
            }
       }


