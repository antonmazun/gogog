#ifndef SEARCHUSER_H
#define SEARCHUSER_H

#include <QDialog>
#include "mainwindow1.h"
namespace Ui {
class Searchuser;
}

class Searchuser : public QDialog
{
    Q_OBJECT
    
public:
    explicit Searchuser(QWidget *parent = 0);
    ~Searchuser();
  // QSqlDatabase delusbd;
    
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Searchuser *ui;
    QSqlDatabase delusbd;
};

#endif // SEARCHUSER_H
