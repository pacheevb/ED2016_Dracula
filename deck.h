#ifndef DECK_H
#define DECK_H


#include <cstdlib>
#include <ctime>
#include "Carta.h"
#include "AStack.h"
#include <iomanip>

using namespace std;


class Deck{

private:
    const int Cartas_por_deck = 52;
    bool ya;
    Carta* deck;
    int contador;

public:
    Deck(){
        string caras[] = {"As","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez",
                        "Jack","Dama","Rey"};
        string palos[] = {"Corazon","Diamante","Espada","Trebol"};
        deck = new Carta [54];
        for (int i = 0; i < Cartas_por_deck;i++){
            deck[i] = Carta(caras[i % 13],palos[i / 13] );
            if (deck[i].getPalo() == "Diamante" || deck[i].getPalo()=="Corazon"){
                deck[i].setColor("Rojo");
            }else{
                deck[i].setColor("Negro");
            }

        }
        deck[52] = Carta("Joker","");
        deck[52].setColor("Negro");
        deck[53] = Carta("Joker","");
        deck[53].setColor("Rojo");
    }

    ~Deck(){
        delete []deck;
    }

    void mostrar(){
        for(int i = 0; i<54;i++){
            cout << deck[i].print() << endl;
        }
    }

    void mezclar(){
        for (int primero = 0; primero < 54;primero++){
            int segundo = (rand() + time(0)) % 54;
            Carta temp = deck[primero];
            deck[primero] = deck[segundo];
            deck[segundo] = temp;
            deck[segundo].print();
        }
    }

    Carta topCarta(){
        return deck[contador++];
    }

    void cortar(int pos){
        if (pos != 0 && pos != 53){
            AStack<Carta> pila;

            for (int i = pos ; i < 54; i++){
                pila.push(deck[i]);
            }

            for (int j = 0; j < pos; j++){
                pila.push(deck[j]);
            }

            for (int k = 0; k < 54; k++){
                deck[k] = pila.pop();
            }
        }
    }

    Carta seleccionar(int pos){
        return deck[pos];
    }

};

#endif // DECK_H
