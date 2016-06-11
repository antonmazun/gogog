#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include "mainwindow1.h"
#include <QLineEdit>
#include "deletebook.h"
namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT
    
public:
    explicit Search(QWidget *parent = 0);
    ~Search();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_del1_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::Search *ui;
   QSqlDatabase bkdb;
};

#endif // SEARCH_H







