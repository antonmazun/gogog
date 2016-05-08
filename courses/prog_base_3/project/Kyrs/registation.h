#ifndef REGISTATION_H
#define REGISTATION_H

#include <QDialog>

namespace Ui {
class Registation;
}

class Registation : public QDialog
{
    Q_OBJECT
    
public:
    explicit Registation(QWidget *parent = 0);
    ~Registation();
    
private:
    Ui::Registation *ui;
};

#endif // REGISTATION_H
