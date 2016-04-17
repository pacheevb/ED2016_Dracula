#ifndef UNDO_H
#define UNDO_H

#include "linkedstack.h"
#include <iostream>

using namespace std;

class Undo
{
private:

    LinkedStack<int> posMano;
    LinkedStack<Carta> cartas;

public:
    Undo();

    void pushJugada(int pPosCarta, Carta pCarta){
        posMano.push(pPosCarta);
        cartas.push(pCarta);
    }

    int popPosicion(){
        return posMano.pop();
    }

    Carta popCarta(){
        return cartas.pop();
    }

    void imprimirTope(){
        cout << "Posicion: " << posMano.topValue() << " - " << "Carta: " << cartas.topValue() << endl;
    }
};

#endif // UNDO_H
