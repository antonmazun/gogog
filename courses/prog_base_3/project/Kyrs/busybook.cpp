#include "busybook.h"
#include "ui_busybook.h"

Busybook::Busybook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Busybook)
{
    ui->setupUi(this);
}

Busybook::~Busybook()
{
    delete ui;
}
