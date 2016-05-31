#include "searchuser.h"
#include "ui_searchuser.h"
#include "deluser.h"
Searchuser::Searchuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Searchuser)
{
    ui->setupUi(this);
    delusbd = QSqlDatabase::addDatabase("QSQLITE");
    delusbd.setDatabaseName("D:/Kyrs/Kyrs/Reg.db");
   // dbadm.setDatabaseName("D:/Kyrs/Kyrs/Admins.db");
    if(!delusbd.open()){
        qDebug() << delusbd.lastError().text();
         return;
     }
     else {
        qDebug() << "Success!";
   }
    QSqlQueryModel * mdlb = new QSqlQueryModel();

    //conn.connOpen();
    QSqlQuery * qrbk= new QSqlQuery(delusbd);

    //qrybook->prepare("select Genre , Name , Author , Year  from Book");
    qrbk->prepare("sselect * from Reg ");
    qrbk->exec();

    mdlb->setQuery(*qrbk);
    ui->tableView->setModel(mdlb);
}

Searchuser::~Searchuser()
{

    delete ui;
}

void Searchuser::on_pushButton_3_clicked()
{

    QString surname , name , username ;


   name =  ui->lineEdit_name->text();
   surname = ui->lineEdit_surname->text();
   username = ui->lineEdit_username->text();




    if(!delusbd.isOpen()){
        qDebug() << "Failed to opened database";
        return;
    }
    QSqlQuery src;
    QString str = "select * from Reg where";

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
    if(name.size() > 0 && surname.size() > 0 && username.size() == 0){

        str = "select  * from Reg where Surname = '"+surname+"'";

    }

    if(name.size() > 0 && surname.size() == 0 && username.size() > 0){

        str = "select  * from Reg where Username = '"+username+"'";

    }
    if(name.size() == 0 && surname.size() == 0 && username.size() == 0){

     QMessageBox::critical(0,"Search" , "vedite usera");

    }
//    else{
//        QMessageBox::critical( 0 , "Search" , "ne nashlo");
//    }
//    if(!src.exec(str)){

//        QMessageBox::critical( 0 , "Search" , "ne nashlo");
//}

    if(src.exec(str)){
   int count = 0;

   while(src.next()){

       count++;

       QSqlQueryModel * srdelus = new QSqlQueryModel();
       QSqlQuery * qryusdel = new QSqlQuery(delusbd);

       qryusdel->prepare(str);
       qryusdel->exec();

       srdelus->setQuery(*qryusdel);
       ui->tableView->setModel(srdelus);


  }
   if( count == 0 )  {

           QMessageBox::critical( 0 , "Search" , "ne nashlo");
  }

}
}

void Searchuser::on_pushButton_2_clicked()
{
    close();
    Deluser deluser;
    deluser.setModal(true);
    deluser.exec();

}

void Searchuser::on_tableView_activated(const QModelIndex &index)
{
    delusbd.isOpen();
    QString val = ui->tableView->model()->data(index).toString();

    QSqlQuery qry;

    qry.prepare("select * from Reg where Name = '"+val+"' or Surname = '"+val+"' or Username = '"+val+"'");

    if(qry.exec()){

        while(qry.next()){
            ui->lineEdit_name->setText(qry.value(0).toString());
            ui->lineEdit_surname->setText(qry.value(1).toString());
            ui->lineEdit_username->setText(qry.value(2).toString());

        }
    }
}

void Searchuser::on_pushButton_clicked()
{
    QString name , surname , username;
    name = ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    username  = ui->lineEdit_username->text();

    QSqlQuery del;
    del.prepare("Delete from Reg where Name = '"+name+"' and Surname = '"+surname+"'");
    if(name.size() == 0 &&  surname.size() == 0){
        QMessageBox::information(0, "Non delete", "Deleted book is not succesfull");
    }
    else if(del.exec()){
        QMessageBox::information(0, "Delete", "Deleted book is succesfull");
         ui->lineEdit_name->clear();
         ui->lineEdit_surname->clear();
         ui->lineEdit_username->clear();


    }

}

void Searchuser::on_pushButton_4_clicked()
{

    Searchuser search;
    QSqlQueryModel * modas = new QSqlQueryModel();

    //conn.connOpen();
    QSqlQuery * qrys = new QSqlQuery(search.delusbd);

    qrys->prepare("select * from Reg");
    qrys->exec();

    modas->setQuery(*qrys);
    ui->tableView->setModel(modas);


}
