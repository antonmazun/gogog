#ifndef SEARCHBOOK_H
#define SEARCHBOOK_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "mainwindow.h"
namespace Ui {
class Searchbook;
}

class Searchbook : public QDialog
{
    Q_OBJECT
    
public:
    explicit Searchbook(QWidget *parent = 0);
    ~Searchbook();
    
private slots:

    void on_tableView_1_activated(const QModelIndex &index);

    void on_pushButton_search_1_clicked();

    void on_pushButton_clicked();

    void on_pushButton_take_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Searchbook *ui;
    QSqlDatabase srcbd;
     QSqlTableModel srcmodel;
     QSqlDatabase dbregsrc;
     QSqlDatabase regg;
      QSqlDatabase bookdb1;
      QSqlDatabase bdact;
      QSqlDatabase bdsearch1;
      QSqlDatabase bdtake;
};

#endif // SEARCHBOOK_H



