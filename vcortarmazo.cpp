#include "vcortarmazo.h"
#include "ui_vcortarmazo.h"
#include "vdireccion.h"
#include "deck.h"
#include "tablero.h"
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

    Carta izq = mazo->topCarta();
    Carta der = mazo->topCarta();

    if (izq.getColor() == "Rojo" && der.getColor() == "Negro") {
        tJuego->setJActual(1);
    }
    else if (izq.getColor() == "Negro" && der.getColor() == "Rojo") {
        tJuego->setJActual(2);
    }
    else if (izq.getColor() == der.getColor()) {
        if (izq.getColor() == "Rojo") {
            if (izq.getPalo() == "Corazon" && der.getPalo() == "Diamante") {
                tJuego->setJActual(1);
            }
            else if(izq.getPalo() == "Diamante" && der.getPalo() == "Corazon") {
                tJuego->setJActual(2);
            }
            else if (izq.getPalo() == der.getPalo()) {
                if (izq.getValue() > der.getValue()) {
                    tJuego->setJActual(1);
                }
                else {
                    tJuego->setJActual(2);
                }
            }
        }
        else {
            listo = false;
        }
    }

    if(listo){
        ui->bCortarMazo->setEnabled(false);
        ui->bSeguir->setEnabled(true);
    }

    string var =":/Cartas/Recursos/Cartas/"+izq.getDireccion()+".png";
    QString qs = QString::fromLocal8Bit(var.c_str());
    QPixmap pixmap(qs);
    QIcon ButtonIcon(pixmap);

    ui->carta1->setIcon(ButtonIcon);
    ui->carta1->setIconSize(QSize(ui->carta1->width(), ui->carta1->height()));

    var =":/Cartas/Recursos/Cartas/"+der.getDireccion()+".png";
    qs = QString::fromLocal8Bit(var.c_str());
    pixmap = qs;
    ButtonIcon = pixmap;

    ui->carta2->setIcon(ButtonIcon);
    ui->carta2->setIconSize(QSize(ui->carta2->width(), ui->carta2->height()));
}
