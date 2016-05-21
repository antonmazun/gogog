#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include "mainwindow1.h"

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

private:
    Ui::Search *ui;
    QSqlDatabase bkdb;
};

#endif // SEARCH_H
