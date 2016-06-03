#ifndef DELUSER_H
#define DELUSER_H

#include <QDialog>
#include "mainwindow1.h"
namespace Ui {
class Deluser;
}

class Deluser : public QDialog
{
    Q_OBJECT
    
public:
    explicit Deluser(QWidget *parent = 0);
    ~Deluser();
    
private slots:
    void on_pushButton_back_deluser_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_deluser_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_search_delus_clicked();

private:
    Ui::Deluser *ui;
QSqlDatabase delusbd;
};

#endif // DELUSER_H
