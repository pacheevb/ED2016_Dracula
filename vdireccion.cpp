#include "vdireccion.h"
#include "ui_vdireccion.h"

VDireccion::VDireccion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VDireccion)
{
    ui->setupUi(this);
}

VDireccion::~VDireccion()
{
    delete ui;
}
