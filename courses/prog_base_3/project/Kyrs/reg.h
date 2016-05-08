#ifndef REG_H
#define REG_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Reg;
}

class Reg : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Reg(QWidget *parent = 0);
    ~Reg();
     // QSqlDatabase userdb;
private slots:
    void on_pushButton_clicked();

private:
    Ui::Reg *ui;
     QSqlDatabase userdb;
};

#endif // REG_H
