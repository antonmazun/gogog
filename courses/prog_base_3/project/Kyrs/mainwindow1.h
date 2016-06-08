#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QSqlDatabase>
#include "QMessageBox"
#include "all.h"
#include "admin.h"
#include "searchbook.h"
#include <stdlib.h>
#include <QFileDialog>
#include <QFileInfo>

#include <QMessageBox>
namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow1(QWidget *parent = 0);
    ~MainWindow1();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_registation_clicked();

    void on_label_3_linkActivated(const QString &link);

    void on_pushButton_clicked();

private:
    Ui::MainWindow1 *ui;
    QSqlDatabase db;
    QSqlDatabase dbadm;
};

#endif // MAINWINDOW1_H
