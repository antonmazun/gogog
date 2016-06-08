#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "entry.h"
#include "registration.h"
#include "all.h"
#include "QLabel"
#include "admin.h"

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );
    ui->setupUi(this);
   /* setWindowFlags(Qt::Window
       | Qt::WindowMinimizeButtonHint
       | Qt::WindowMaximizeButtonHint
       | Qt::CustomizeWindowHint);*/
   setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );

    QImage image;
    image.load("D:/Kyrs/Kyrs/cat.jpg");

    image = image.scaledToWidth(ui->label->width(), Qt::SmoothTransformation);
//    ui->label_5->setPixmap(QPixmap::fromImage(image));



  QString filename = "D:/Kyrs/Kyrs/cat.jpg";
    image.load(filename);
    QSize PicSize(400, 500);
    image = image.scaled(PicSize,Qt::KeepAspectRatio);
    ui->label_5->setPixmap(QPixmap::fromImage(image));











    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");
   // dbadm.setDatabaseName("D:/Kyrs/Kyrs/Admins.db");
    if(!db.open()){
        qDebug() << db.lastError().text();
         return;
     }
     else {
        qDebug() << "Success vxod!";
   }
  //  dbadm = QSqlDatabase::addDatabase("QSQLITE");



}



MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_pushButton_login_clicked()
{
    QString username , password;
        username = ui->lineEdit_login->text();
        password = ui->lineEdit_pas->text();

        if(!db.isOpen()){
            qDebug() << "Failed to opened database";
            return;
        }
       /* if(!dbadm.isOpen()){
            qDebug() << "Failed to opened database";
            return;
        }*/

        QSqlQuery que;

        if(que.exec("select * from Reg where Username = '" + username +"'and Password  = '" +password+"'")){

            int count = 0;
            while(que.next()){
                count++;
            }

            if(count == 1){

                QString sign = "1";
                QSqlQuery qrys;
                qrys.prepare("update Reg set Sign = '"+sign+"' where Username = '"+username+"' and Password = '"+password+"'");

                ui->label_4->setText("username and password is correct");
                if(qrys.exec()){
                    close();


                }
                if( username == "1" && password == "1"){

                    Admin admin;
                    admin.setModal(true);
                    admin.exec();
                    db.close();
                }

                else {
                  Entry en;
                  en.setModal(true);
                  en.exec();
                   db.close();
  }
              }

            if(count > 1){
                ui->label_4->setText("Duplicate username and password ");
            }
            if(count < 1){
                ui->label_4->setText("username and password is not correct");
    }

}
}

void MainWindow1::on_pushButton_registation_clicked()
{
    close();
    Registration reg;
    reg.setModal(true);
    reg.exec();


}

void MainWindow1::on_pushButton_clicked()
{
    close();
}
