ifndef SEARCH_DELUSER_H
#define SEARCH_DELUSER_H

#include <QDialog>

namespace Ui {
class Search_deluser;
}

class Search_deluser : public QDialog
{
    Q_OBJECT
    
public:
    explicit Search_deluser(QWidget *parent = 0);
    ~Search_deluser();
    
private:
    Ui::Search_deluser *ui;
};

#endif // SEARCH_DELUSER_H
