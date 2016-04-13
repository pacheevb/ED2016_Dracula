#include "vcortarmazo.h"
#include "ui_vcortarmazo.h"
#include "vdireccion.h"
#include "deck.h"
#include "tablero.h"
#include "globales.h"
#include <iostream>


VCortarMazo::VCortarMazo(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::VCortarMazo)
{
    ui->setupUi(this);
}

VCortarMazo::~VCortarMazo()
{
    delete ui;
}

void VCortarMazo::on_bSeguir_clicked()
{
    VDireccion vd;
    vd.setModal(true);
    this->close();
    vd.exec();

}

void VCortarMazo::on_bCortarMazo_clicked()
{
    Deck* mazo = Deck::getInstance();
    Tablero* tJuego = Tablero::getInstance();

    bool listo = true;
    mazo->mezclar();

    if (mazo->seleccionar(0).getColor() == "Rojo" && mazo->seleccionar(1).getColor() == "Negro") {
        tJuego->setJActual(1);
    }
    else if (mazo->seleccionar(0).getColor() == "Negro" && mazo->seleccionar(1).getColor() == "Rojo") {
        tJuego->setJActual(2);
    }
    else if (mazo->seleccionar(0).getColor() == mazo->seleccionar(1).getColor()) {
        if (mazo->seleccionar(0).getColor() == "Rojo") {
            if (mazo->seleccionar(0).getPalo() == "Corazon" && mazo->seleccionar(1).getPalo() == "Diamante") {
                tJuego->setJActual(1);
                cout << "Acá!" << endl;
            }
            else if(mazo->seleccionar(0).getPalo() == "Diamante" && mazo->seleccionar(1).getPalo() == "Corazon") {
                tJuego->setJActual(2);
            }
            else if (mazo->seleccionar(0).getPalo() == mazo->seleccionar(1).getPalo()) {
                if (mazo->seleccionar(0).getValue() > mazo->seleccionar(1).getValue()) {
                    tJuego->setJActual(1);
                }
                else {
                    tJuego->setJActual(2);
                }
            }
        }
        else {
            listo = false;
            cout << "Prueba" << endl;
        }
    }

    if(listo){
        ui->bCortarMazo->setEnabled(false);
        ui->bSeguir->setEnabled(true);
    }

    string var =":/Cartas/Recursos/Cartas/"+mazo->seleccionar(0).getDireccion()+".png";
    QString qs = QString::fromLocal8Bit(var.c_str());
    QPixmap pixmap(qs);
    QIcon ButtonIcon(pixmap);

    ui->carta1->setIcon(ButtonIcon);
    ui->carta1->setIconSize(QSize(ui->carta1->width(), ui->carta1->height()));

    var =":/Cartas/Recursos/Cartas/"+mazo->seleccionar(1).getDireccion()+".png";
    qs = QString::fromLocal8Bit(var.c_str());
    pixmap = qs;
    ButtonIcon = pixmap;

    ui->carta2->setIcon(ButtonIcon);
    ui->carta2->setIconSize(QSize(ui->carta2->width(), ui->carta2->height()));

}
