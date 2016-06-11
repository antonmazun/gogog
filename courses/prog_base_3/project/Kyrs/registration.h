#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT
    
public:
    explicit Registration(QWidget *parent = 0);
    ~Registration();

private slots:
    void on_pushButton_reg_clicked();

    void on_lineEdit_sur_reg_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::Registration *ui;
    QSqlDatabase mydb;
    QSqlDatabase dbreg;
};

#endif // REGISTRATION_H
