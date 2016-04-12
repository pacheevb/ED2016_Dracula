#include "vmesa.h"
#include "ui_vmesa.h"

VMesa::VMesa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VMesa)
{
    ui->setupUi(this);
}

VMesa::~VMesa()
{
    delete ui;
}



