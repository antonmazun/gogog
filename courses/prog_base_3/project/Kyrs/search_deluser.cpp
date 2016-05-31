#include "search_deluser.h"
#include "ui_search_deluser.h"

Search_deluser::Search_deluser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search_deluser)
{
    ui->setupUi(this);
}

Search_deluser::~Search_deluser()
{
    delete ui;
}
