#ifndef BUSYBOOK_H
#define BUSYBOOK_H

#include <QDialog>
#include "mainwindow1.h"
namespace Ui {
class Busybook;
}

class Busybook : public QDialog
{
    Q_OBJECT
    
public:
    explicit Busybook(QWidget *parent = 0);
    ~Busybook();
    
private slots:
    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_give_clicked();

    void on_pushButton_sear_busy_clicked();

private:
    Ui::Busybook *ui;
    QSqlDatabase busydb;
    QSqlDatabase busyreg;
    QSqlDatabase busyreg_click;
     QSqlDatabase busybd_click;
     QSqlDatabase busyreg_src;
     QSqlDatabase busybook_src;

     QSqlDatabase busydb1;



     QSqlDatabase bdreg;
     QSqlDatabase bdbooks;
};




#endif // BUSYBOOK_H


