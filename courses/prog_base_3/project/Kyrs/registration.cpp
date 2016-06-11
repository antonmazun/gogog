#include "registration.h"
#include "ui_registration.h"
#include "mainwindow1.h"
#include "entry.h"


Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{

    ui->setupUi(this);
    setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");
    if(!mydb.open()){
        qDebug() << mydb.lastError().text();
         return;
     }
     else {
        qDebug() << "Success!";
   }

}

Registration::~Registration()
{
    delete ui;
}



void Registration::on_pushButton_reg_clicked()
{
        mydb.open();
    if(!mydb.isOpen()){
         qDebug() << "Failed to opened database";
         return;
     }
    QString name, surname ,username, password;
        name = ui->lineEdit_name_reg->text();
        surname = ui->lineEdit_sur_reg->text();
        username = ui->lineEdit_usname_reg->text();
        password = ui->lineEdit_pas_reg->text();
        if(name.size() < 1)
        {
        ui->labelinf->setText("Enter your name");
        }
       else  if(surname.size() < 1)
        {
        ui->labelinf->setText("Enter your surname");
        }
       else  if(username.size() < 1)
        {
        ui->labelinf->setText("Enter your username");
        }
       else if(password.size() < 1)
        {
        ui->labelinf->setText("Enter your password");
        }
       else
        {
            QSqlQuery que;
            que.prepare("insert into Reg(name , surname , username , password) values ('"+name+"' ,'"+surname+"' ,'"+username+"' , '"+password+"')");

                    if(que.exec())
                    {

                        QString sign = "1";
                       // QString signf = "0";
                      //  mydb.isOpen();
                        QSqlQuery qryreg;

                        qryreg.prepare("update Reg set Sign = '"+sign+"' where Username = '"+username+"' and Password = '"+password+"' ");
                            if(qryreg.exec()){

                            // QMessageBox::critical(this , tr("Registration"),tr("Registration is successfull"));
                        QMessageBox::information(0, "Registration", "Registration is successfull");
                        //  mydb.close();
                        //mydb.close();
                        close();
                        Entry entry;
                        entry.setModal(true);
                        entry.exec();
                    }
                 }
                    else
                    {
                     QMessageBox::critical(this , tr("Error") , que.lastError().text());
                     // QMessageBox::information(0, "Registration", "Change your username");
                    }
          }

}
