#include "vmesa.h"
#include "ui_vmesa.h"
#include "tablero.h"

VMesa::VMesa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VMesa)
{
    ui->setupUi(this);

    Tablero* tJuego = Tablero::getInstance();
    Deck* mazo = Deck::getInstance();

    tJuego->getpDir1() == 0 ? ui->lj1direccion->setText("Horizontal") : ui->lj1direccion->setText("Vertical");
    tJuego->getpDir2() == 0 ? ui->lj2direccion->setText("Horizontal") : ui->lj2direccion->setText("Vertical");

    string var = tJuego->getJActual() == 1 ? "Jugador 1" : "Jugador 2";
    QString qs = QString::fromLocal8Bit(var.c_str());
    ui->ljugador->setText(qs);

    var = "Ronda ";
    qs = QString::fromLocal8Bit(var.c_str());
    ui->lronda->setText(qs);

    tJuego->repartir();

    if(tJuego->getJActual() == 1){
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

    QPixmap pixmap = tJuego->getCartaQString(mazo->topCarta());
    QIcon ButtonIcon = pixmap;
    ui->campo5->setIcon(ButtonIcon);
    ui->campo5->setIconSize(QSize(ui->campo5->width(), ui->campo5->height()));
}

VMesa::~VMesa()
{
    delete ui;
}

void VMesa::on_mano1_clicked()
{
    Tablero* tJuego = Tablero::getInstance();
    Deck* mazo = Deck::getInstance();

    tJuego->getJActual() == 1 ? tJuego->setJActual(2) : tJuego->setJActual(1);
}
