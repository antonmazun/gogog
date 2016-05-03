#ifndef ALL_H
#define ALL_H

#include <QDialog>
#include <QComboBox>
namespace Ui {
class All;
}

class All : public QDialog
{
    Q_OBJECT
    
public:
    explicit All(QWidget *parent = 0);
    ~All();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::All *ui;
};

#endif // ALL_H
