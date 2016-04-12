#include "vcortarmazo.h"
#include "ui_vcortarmazo.h"
#include "vdireccion.h"
#include "deck.h"
#include "tablero.h"
#include "globales.h"

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

    bool listo = true;

    if (mazo->seleccionar(0).getColor() == "Rojo" && mazo->seleccionar(1).getColor() == "Negro") {
        tJuego->setJActual(1);
    }
    else if (mazo->seleccionar(0).getColor() == "Negro" && mazo->seleccionar(1).getColor() == "Rojo") {
        tJuego->setJActual(2);
    }
    else if (mazo->seleccionar(0).getColor() == mazo->seleccionar(1).getColor()) {
        if (mazo->seleccionar(0).getColor() == "Rojo") {
            if (mazo->seleccionar(0).getPalo() == "Corazon" && mazo->seleccionar(1).getPalo() == "Rombo") {
                tJuego->setJActual(1);
            }
            else if(mazo->seleccionar(0).getPalo() == "Rombo" && mazo->seleccionar(1).getPalo() == "Corazon") {
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
        }
    }
//:/Cartas/Recursos/PNG-cards-1.3/AsCorazon.png
//    QPixmap pixmap("url(:/Cartas/Recursos/PNG-cards-1.3/"+ mazo->seleccionar(0).getDireccion() +".png)");
//    QIcon ButtonIcon(pixmap);

//    QPushButton carta1;

//    carta1->setIcon(ButtonIcon);
//    carta1->setIconSize(pixmap.rect().size())

}
