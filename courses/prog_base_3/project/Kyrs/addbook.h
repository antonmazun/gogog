#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>
#include <QSqlDatabase>
#include <cstdlib>
namespace Ui {
class Addbook;
}

class Addbook : public QDialog
{
    Q_OBJECT
    
public:
    explicit Addbook(QWidget *parent = 0);
    ~Addbook();
    
private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Addbook *ui;
    QSqlDatabase bookdb;

    QSqlDatabase regadd;


};

#endif // ADDBOOK_H
