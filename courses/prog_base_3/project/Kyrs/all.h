#ifndef ALL_H
#define ALL_H

#include <QDialog>
#include <QComboBox>
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlTableModel> // показывает таблицу БД
#include <QDebug>
#include <QSqlError>
#include <QSQlRecord>
#include <QSqlQuery> // класс запроса
//#include <QComboBox>
#include <QTableView>
#include <QtSql>
#include <QFileInfo>
#include <QtDebug>
namespace Ui {
class All;
}

class All : public QDialog
{
    Q_OBJECT
    
public:

    explicit All(QWidget *parent = 0);
    ~All();
 //QSqlTableModel model;

private slots:
    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_all_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::All *ui;
    QSqlDatabase db;
    QSqlDatabase regall;
    //QSqlDatabase
    QSqlTableModel model;
   QSqlDatabase  bookdb;
};

#endif // ALL_H
