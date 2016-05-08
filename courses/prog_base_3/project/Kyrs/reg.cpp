#include "reg.h"
#include "ui_reg.h"
#include "mainwindow.h"
#include "all.h"
#include <QDialog>
Reg::Reg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reg)
{
    ui->setupUi(this);

    userdb = QSqlDatabase::addDatabase("QSQLITE");

    userdb.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");

    if(!userdb.open()){

        qDebug() << userdb.lastError().text();
         return;
     }
     else {

        qDebug() << "Success!";

   }
}

Reg::~Reg()
{


    delete ui;
}

void Reg::on_pushButton_clicked()
{
    QString username , password;

    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();


    if(!userdb.isOpen()){

        qDebug() << "Failed to opened database";
        return;

    }
    QSqlQuery que;

    if(que.exec("select * from Reg where Username = '" + username +"'and Password  = '" + password+"'")){

        int count = 0;

        while(que.next()){

            count++;
        }
        if(count == 1){
            ui->label_3->setText("username and password is correct");
       //this->hide();
        Reg reg;
      //  reg.setModal(true);
        reg.show();
           // MainWindow w;
            //w.setModal(w);
            // w.show();
           /* MainWindow mwnd;
            mwnd.setModal(true);
            mwnd.exec();*/
        }
        if(count > 1)
            ui->label_3->setText("Duplicate username and password ");

        if(count < 1)
            ui->label_3->setText("username and password is not correct");

}
}
