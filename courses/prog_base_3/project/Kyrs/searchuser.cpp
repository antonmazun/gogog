#include "searchuser.h"
#include "ui_searchuser.h"

Searchuser::Searchuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Searchuser)
{
    ui->setupUi(this);
}

Searchuser::~Searchuser()
{
    delete ui;
}
