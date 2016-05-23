#ifndef DELETEBOOK_H
#define DELETEBOOK_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
//#include <QString>
namespace Ui {
class Deletebook;
}

class Deletebook : public QDialog
{
    Q_OBJECT
    
public:
    explicit Deletebook(QWidget *parent = 0);
    ~Deletebook();
    
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_delete_clicked();

    void on_pushButton_clicked();

private:
    Ui::Deletebook *ui;
    QSqlDatabase delbd;
    QSqlTableModel delmodel;
};

#endif // DELETEBOOK_H
