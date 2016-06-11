#ifndef ENTRY_H
#define ENTRY_H

#include <QDialog>
#include "mainwindow1.h"


namespace Ui {
class Entry;
}

class Entry : public QDialog
{
    Q_OBJECT
    
public:
    explicit Entry(QWidget *parent = 0);
    ~Entry();
    
private slots:
    void on_pushButton_all_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_search_3_clicked();

    void on_pushButton_all_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Entry *ui;
    QSqlDatabase entrydb;
};

#endif // ENTRY_H
