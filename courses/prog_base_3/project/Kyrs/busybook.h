#ifndef BUSYBOOK_H
#define BUSYBOOK_H

#include <QDialog>

namespace Ui {
class Busybook;
}

class Busybook : public QDialog
{
    Q_OBJECT
    
public:
    explicit Busybook(QWidget *parent = 0);
    ~Busybook();
    
private:
    Ui::Busybook *ui;
};

#endif // BUSYBOOK_H
