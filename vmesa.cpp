#include "vmesa.h"
#include "ui_vmesa.h"
#include "tablero.h"

VMesa::VMesa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VMesa)
{
    ui->setupUi(this);

    Deck* mazo = Deck::getInstance();

    mazo->mezclar();
    tJuego->getpDir1() == 0 ? ui->lj1direccion->setText("Horizontal") : ui->lj1direccion->setText("Vertical");
    tJuego->getpDir2() == 0 ? ui->lj2direccion->setText("Horizontal") : ui->lj2direccion->setText("Vertical");

    tJuego->repartir();
    turno();

    QPixmap pixmap = tJuego->getCartaQString(mazo->topCarta());
    QIcon ButtonIcon = pixmap;
    ui->campo5->setIcon(ButtonIcon);
    ui->campo5->setIconSize(QSize(ui->campo5->width(), ui->campo5->height()));
}

void VMesa::turno(){
    botonesMano(true);
    string var = tJuego->getJActual() == 1 ? "Jugador 1" : "Jugador 2";
    QString qs = QString::fromLocal8Bit(var.c_str());
    ui->ljugador->setText(qs);

    if(tJuego->getJActual() == 1){

        if(tJuego->getCartasJ1()[0].getCara() == ""){
            ui->mano1->setEnabled(false);
        }
        if(tJuego->getCartasJ1()[1].getCara() == ""){
            ui->mano2->setEnabled(false);
        }
        if(tJuego->getCartasJ1()[2].getCara() == ""){
            ui->mano3->setEnabled(false);
        }
        if(tJuego->getCartasJ1()[3].getCara() == ""){
            ui->mano4->setEnabled(false);
        }

        QPixmap pixmap(tJuego->getCartaQString(tJuego->getCartasJ1()[0]));
        QIcon ButtonIcon(pixmap);
        ui->mano1->setIcon(ButtonIcon);
        ui->mano1->setIconSize(QSize(ui->mano1->width(), ui->mano1->height()));

        pixmap = tJuego->getCartaQString(tJuego->getCartasJ1()[1]);
        ButtonIcon = pixmap;
        ui->mano2->setIcon(ButtonIcon);
        ui->mano2->setIconSize(QSize(ui->mano2->width(), ui->mano2->height()));

        pixmap = tJuego->getCartaQString(tJuego->getCartasJ1()[2]);
        ButtonIcon = pixmap;
        ui->mano3->setIcon(ButtonIcon);
        ui->mano3->setIconSize(QSize(ui->mano3->width(), ui->mano3->height()));

        pixmap = tJuego->getCartaQString(tJuego->getCartasJ1()[3]);
        ButtonIcon = pixmap;
        ui->mano4->setIcon(ButtonIcon);
        ui->mano4->setIconSize(QSize(ui->mano4->width(), ui->mano4->height()));
    } else {

        if(tJuego->getCartasJ2()[0].getCara() == ""){
            ui->mano1->setEnabled(false);
        }
        if(tJuego->getCartasJ2()[1].getCara() == ""){
            ui->mano2->setEnabled(false);
        }
        if(tJuego->getCartasJ2()[2].getCara() == ""){
            ui->mano3->setEnabled(false);
        }
        if(tJuego->getCartasJ2()[3].getCara() == ""){
            ui->mano4->setEnabled(false);
        }

        QPixmap pixmap(tJuego->getCartaQString(tJuego->getCartasJ2()[0]));
        QIcon ButtonIcon(pixmap);

        ui->mano1->setIcon(ButtonIcon);
        ui->mano1->setIconSize(QSize(ui->mano1->width(), ui->mano1->height()));

        pixmap = tJuego->getCartaQString(tJuego->getCartasJ2()[1]);
        ButtonIcon = pixmap;
        ui->mano2->setIcon(ButtonIcon);
        ui->mano2->setIconSize(QSize(ui->mano2->width(), ui->mano2->height()));

        pixmap = tJuego->getCartaQString(tJuego->getCartasJ2()[2]);
        ButtonIcon = pixmap;
        ui->mano3->setIcon(ButtonIcon);
        ui->mano3->setIconSize(QSize(ui->mano3->width(), ui->mano3->height()));

        pixmap = tJuego->getCartaQString(tJuego->getCartasJ2()[3]);
        ButtonIcon = pixmap;
        ui->mano4->setIcon(ButtonIcon);
        ui->mano4->setIconSize(QSize(ui->mano4->width(), ui->mano4->height()));
    }
}

void VMesa::botonesMano(bool entrada){
    ui->mano1->setEnabled(entrada);
    ui->mano2->setEnabled(entrada);
    ui->mano3->setEnabled(entrada);
    ui->mano4->setEnabled(entrada);
}

void VMesa::botonesMesa(bool entrada){
    ui->campo1->setEnabled(entrada);
    ui->campo2->setEnabled(entrada);
    ui->campo3->setEnabled(entrada);
    ui->campo4->setEnabled(entrada);
    ui->campo5->setEnabled(entrada);
    ui->campo6->setEnabled(entrada);
    ui->campo7->setEnabled(entrada);
    ui->campo8->setEnabled(entrada);
    ui->campo9->setEnabled(entrada);
}

VMesa::~VMesa()
{
    delete ui;
}

void VMesa::on_mano1_clicked()
{
    tJuego->setCartaSeleccionada(tJuego->getJActual() == 1 ? tJuego->getCartasJ1()[0] : tJuego->getCartasJ2()[0]);
    tJuego->getJActual() == 1 ? tJuego->getCartasJ1()[0] = Carta("", "") : tJuego->getCartasJ2()[0] = Carta("", "");
    ui->lTexto->setText("¿Donde la quieres poner?");
    botonesMano(false);
}

void VMesa::on_mano2_clicked()
{
    tJuego->setCartaSeleccionada(tJuego->getJActual() == 1 ? tJuego->getCartasJ1()[1] : tJuego->getCartasJ2()[1]);
    tJuego->getJActual() == 1 ? tJuego->getCartasJ1()[1] = Carta("", "") : tJuego->getCartasJ2()[1] = Carta("", "");
    ui->lTexto->setText("¿Donde la quieres poner?");
    botonesMano(false);
}

void VMesa::on_mano3_clicked()
{
    tJuego->setCartaSeleccionada(tJuego->getJActual() == 1 ? tJuego->getCartasJ1()[2] : tJuego->getCartasJ2()[2]);
    tJuego->getJActual() == 1 ? tJuego->getCartasJ1()[2] = Carta("", "") : tJuego->getCartasJ2()[2] = Carta("", "");
    ui->lTexto->setText("¿Donde la quieres poner?");
    botonesMano(false);
}

void VMesa::on_mano4_clicked()
{
    tJuego->setCartaSeleccionada(tJuego->getJActual() == 1 ? tJuego->getCartasJ1()[3] : tJuego->getCartasJ2()[3]);
    tJuego->getJActual() == 1 ? tJuego->getCartasJ1()[3] = Carta("", "") : tJuego->getCartasJ2()[3] = Carta("", "");
    ui->lTexto->setText("¿Donde la quieres poner?");
    botonesMano(false);
}

void VMesa::on_campo1_clicked()
{
    QPixmap pixmap = tJuego->getCartaQString(tJuego->getCartaSeleccionada());
    QIcon ButtonIcon = pixmap;
    ui->campo1->setIcon(ButtonIcon);
    ui->campo1->setIconSize(QSize(ui->campo1->width(), ui->campo1->height()));
    tJuego->getJActual() == 1 ? tJuego->setJActual(2) : tJuego->setJActual(1);
    turno();
}

void VMesa::on_campo2_clicked()
{
    QPixmap pixmap = tJuego->getCartaQString(tJuego->getCartaSeleccionada());
    QIcon ButtonIcon = pixmap;
    ui->campo2->setIcon(ButtonIcon);
    ui->campo2->setIconSize(QSize(ui->campo2->width(), ui->campo2->height()));
    tJuego->getJActual() == 1 ? tJuego->setJActual(2) : tJuego->setJActual(1);
    turno();
}

void VMesa::on_campo3_clicked()
{
    QPixmap pixmap = tJuego->getCartaQString(tJuego->getCartaSeleccionada());
    QIcon ButtonIcon = pixmap;
    ui->campo3->setIcon(ButtonIcon);
    ui->campo3->setIconSize(QSize(ui->campo3->width(), ui->campo3->height()));
    tJuego->getJActual() == 1 ? tJuego->setJActual(2) : tJuego->setJActual(1);
    turno();
}

void VMesa::on_campo4_clicked()
{
    QPixmap pixmap = tJuego->getCartaQString(tJuego->getCartaSeleccionada());
    QIcon ButtonIcon = pixmap;
    ui->campo4->setIcon(ButtonIcon);
    ui->campo4->setIconSize(QSize(ui->campo4->width(), ui->campo4->height()));
    tJuego->getJActual() == 1 ? tJuego->setJActual(2) : tJuego->setJActual(1);
    turno();
}

void VMesa::on_campo6_clicked()
{
    QPixmap pixmap = tJuego->getCartaQString(tJuego->getCartaSeleccionada());
    QIcon ButtonIcon = pixmap;
    ui->campo6->setIcon(ButtonIcon);
    ui->campo6->setIconSize(QSize(ui->campo6->width(), ui->campo6->height()));
    tJuego->getJActual() == 1 ? tJuego->setJActual(2) : tJuego->setJActual(1);
    turno();
}

void VMesa::on_campo7_clicked()
{
    QPixmap pixmap = tJuego->getCartaQString(tJuego->getCartaSeleccionada());
    QIcon ButtonIcon = pixmap;
    ui->campo7->setIcon(ButtonIcon);
    ui->campo7->setIconSize(QSize(ui->campo7->width(), ui->campo7->height()));
    tJuego->getJActual() == 1 ? tJuego->setJActual(2) : tJuego->setJActual(1);
    turno();
}

void VMesa::on_campo8_clicked()
{
    QPixmap pixmap = tJuego->getCartaQString(tJuego->getCartaSeleccionada());
    QIcon ButtonIcon = pixmap;
    ui->campo8->setIcon(ButtonIcon);
    ui->campo8->setIconSize(QSize(ui->campo8->width(), ui->campo8->height()));
    tJuego->getJActual() == 1 ? tJuego->setJActual(2) : tJuego->setJActual(1);
    turno();
}

void VMesa::on_campo9_clicked()
{
    QPixmap pixmap = tJuego->getCartaQString(tJuego->getCartaSeleccionada());
    QIcon ButtonIcon = pixmap;
    ui->campo9->setIcon(ButtonIcon);
    ui->campo9->setIconSize(QSize(ui->campo9->width(), ui->campo9->height()));
    tJuego->getJActual() == 1 ? tJuego->setJActual(2) : tJuego->setJActual(1);
    turno();
}
