#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT
    
public:
    explicit Admin(QWidget *parent = 0);
    ~Admin();
    
private slots:
    void on_pushButton_add_book_clicked();

    void on_pushButton_del_book_clicked();

private:
    Ui::Admin *ui;
     //QSqlDatabase dbadm;
};

#endif // ADMIN_H
