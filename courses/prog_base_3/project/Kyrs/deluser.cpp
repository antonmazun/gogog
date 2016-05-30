#include "deluser.h"
#include "ui_deluser.h"
#include "mainwindow1.h"
Deluser::Deluser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deluser)
{
    ui->setupUi(this);



    delusbd = QSqlDatabase::addDatabase("QSQLITE");

    delusbd.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");

    if(!delusbd.open()){

        qDebug() << delusbd.lastError().text();
         return;
     }
     else {

        qDebug() << "Success!";

   }

    //All conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    //conn.connOpen();
    QSqlQuery * qry = new QSqlQuery(delusbd);
    qry->prepare("select Name  , Surname, Username  from Reg");
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
   // delusbd.close();
}

Deluser::~Deluser()
{
    delete ui;
}

void Deluser::on_pushButton_back_deluser_clicked()
{
    close();
    Admin admback;
    admback.setModal(true);
    admback.exec();


}

void Deluser::on_tableView_activated(const QModelIndex &index)
{
    delusbd.isOpen();
    QString val = ui->tableView->model()->data(index).toString();

    QSqlQuery qry;

    qry.prepare("select * from Reg where Name = '"+val+"' or Surname = '"+val+"' or Username = '"+val+"'");

    if(qry.exec()){

        while(qry.next()){
            ui->lineEdit_name_del->setText(qry.value(0).toString());
            ui->lineEdit_sur_del->setText(qry.value(1).toString());
            ui->lineEdit_user_del->setText(qry.value(2).toString());

        }
    }

}

void Deluser::on_pushButton_deluser_clicked()
{
    QString name , surname;
    name = ui->lineEdit_name_del->text();
    surname = ui->lineEdit_sur_del->text();
    if(name.size() == 0 &&  surname.size() == 0){
        QMessageBox::information(0, "Non delete", "Deleted book is not succesfull");
    }
    else{
    QSqlQuery del;
    del.prepare("Delete from Reg where Name = '"+name+"' and Surname= '"+surname+"'");
    if(del.exec()){
        QMessageBox::information(0, "Delete", "Deleted user is succesfull");


    }
    else {
          QMessageBox::information(0, "Delete", "Deleted user is  not succesfull");
    }

}
}

void Deluser::on_pushButton_update_clicked()
{
    Deluser deluser;
    QSqlQueryModel * modaluser = new QSqlQueryModel();

    //conn.connOpen();
    QSqlQuery * qryuser = new QSqlQuery(deluser.delusbd);

    qryuser->prepare("select Name , Surname , Username  from Reg");
    qryuser->exec();

    modaluser->setQuery(*qryuser);
    ui->tableView->setModel(modaluser);

}

void Deluser::on_pushButton_search_delus_clicked()
{

    QString surname , name , username ;


   name =  ui->lineEdit_name_del->text();
   surname = ui->lineEdit_sur_del->text();
   username = ui->lineEdit_user_del->text();




    if(!delusbd.isOpen()){
        qDebug() << "Failed to opened database";
        return;
    }
    QSqlQuery   src;
    QString str = "select * from Book where ";

    if (name.size() > 0 && surname.size() == 0 && username.size() == 0)
    {

        str = "select * from Reg where Name = '"+name+"'";
    }

    if (name.size() == 0 && surname.size() > 0 && username.size() == 0)
    {

        str = "select * from Reg where Surname = '"+surname+"'";
    }

    if (name.size() == 0 && surname.size() == 0 && username.size() > 0)
    {

        str = "select * from Reg where Username = '"+username+"'";
    }



}
