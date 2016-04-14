#ifndef VMESA_H
#define VMESA_H

#include <QDialog>
#include "tablero.h"

namespace Ui {
class VMesa;
}

class VMesa : public QDialog
{
    Q_OBJECT

public:
    explicit VMesa(QWidget *parent = 0);
    ~VMesa();

private slots:
    void on_mano1_clicked();
    void turno();
    void botonesMano(bool entrada);
    void botonesMesa(bool entrada);

    void on_campo2_clicked();

    void on_mano2_clicked();

    void on_mano3_clicked();

    void on_mano4_clicked();

    void on_campo1_clicked();

    void on_campo3_clicked();

    void on_campo4_clicked();

    void on_campo6_clicked();

    void on_campo7_clicked();

    void on_campo8_clicked();

    void on_campo9_clicked();

private:
    Ui::VMesa *ui;
    Tablero* tJuego = Tablero::getInstance();
};

#endif // VMESA_H
