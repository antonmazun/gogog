#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlTableModel> // ���������� ������� ��
#include <QDebug>
#include <QSqlError>
#include <QSQlRecord>
#include <QSqlQuery> // ����� �������
#include <QComboBox>
#include <QTableView>
#include "search.h"
#include "mainwindow.h"
#include "all.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_Search_but_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel * model;

};

#endif // MAINWINDOW_H
