#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "vcortarmazo.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    //setStyleSheet("background-image:url(:/Recursos/Recursos/logo.png)");
    ui->setupUi(this);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_bIniciar_clicked()
{
    VCortarMazo vcm;
    vcm.setModal(true);
    this->close();
    vcm.exec();
}
