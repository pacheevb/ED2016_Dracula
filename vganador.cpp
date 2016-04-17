#include "vganador.h"
#include "vcortarmazo.h"
#include "ui_vganador.h"
#include "tablero.h"
#include "string"

VGanador::VGanador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VGanador)
{
    ui->setupUi(this);

    string var = tJuego->getGanador();
    QString qs = QString::fromLocal8Bit(var.c_str());
    ui->lGanador->setText(qs);

    var = to_string(tJuego->getPuntajeJ1());
    qs = QString::fromLocal8Bit(var.c_str());
    ui->lPuntaje1->setText(qs);

    var = to_string(tJuego->getPuntajeJ2());
    qs = QString::fromLocal8Bit(var.c_str());
    ui->lPuntaje2->setText(qs);

}

VGanador::~VGanador()
{
    delete ui;
}

void VGanador::on_bVolver_clicked()
{
    tJuego->resetTablero();
    VCortarMazo vCm;
    vCm.setModal(true);
    this->close();
    vCm.exec();
}

void VGanador::on_bSalir_clicked()
{
    this->close();
}
