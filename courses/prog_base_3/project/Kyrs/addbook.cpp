#include "addbook.h"
#include "ui_addbook.h"
#include "mainwindow1.h"

Addbook::Addbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addbook)
{
    ui->setupUi(this);

    bookdb = QSqlDatabase::addDatabase("QSQLITE");
    bookdb.setDatabaseName("D:/Kyrs/Kyrs/Book.db");
    if(!bookdb.open()){
        qDebug() << bookdb.lastError().text();
         return;
     }
     else {
        qDebug() << "Success!";
   }

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
    QString author, genre ,name, year, des;
    // QSqlQuery tmp;
        author = ui->lineEdit_aut->text();
        genre = ui->lineEdit_genre->text();
        name = ui->lineEdit_name_add_book->text();
        year = ui->lineEdit_year->text();
        des = ui->lineEdit_des->text();
        //bool f = false;//есть ли точка
           /* for(int i=0;i<year.size() - 1;i++)
            {
                if((year[i] >= '0') && (year[i] <= '9'))
                    continue;

            }*/
        if(author.size() < 1)
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
            QSqlQuery que;
            que.prepare("insert into Book(Genre , Name , Author , Year, Descriptions) values ('"+genre+"' ,'"+name+"' ,'"+author+"' , '"+year+"' , '"+des+"')");

                    if(que.exec())
                    {

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
