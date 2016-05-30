#ifndef SEARCHUSER_H
#define SEARCHUSER_H

#include <QDialog>

namespace Ui {
class Searchuser;
}

class Searchuser : public QDialog
{
    Q_OBJECT
    
public:
    explicit Searchuser(QWidget *parent = 0);
    ~Searchuser();
    
private:
    Ui::Searchuser *ui;
};

#endif // SEARCHUSER_H
