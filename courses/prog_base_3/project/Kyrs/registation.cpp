#include "registation.h"
#include "ui_registation.h"

Registation::Registation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registation)
{
    ui->setupUi(this);
}

Registation::~Registation()
{
    delete ui;
}
