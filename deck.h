#ifndef DECK_H
#define DECK_H


#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "assert.h"
#include "Carta.h"
#include "linkedstack.h"

using namespace std;

class Deck{

private:
    const int Cartas_por_deck = 52;
    bool ya;
    LinkedStack<Carta> deck;
    int contador;

public:


    static Deck* getInstance() {
        static Deck m_instance;
        return &m_instance;
    }

    Deck(){
        crear();
    }

    ~Deck(){
        deck.~LinkedStack();
    }

    void crear(){
        deck.clear();

        string caras[] = {"As","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez",
                        "Jack","Dama","Rey"};
        string palos[] = {"Corazon","Diamante","Espada","Trebol"};
        for (int i = 0; i < Cartas_por_deck;i++){
            deck.push(Carta(caras[i % 13],palos[i / 13] ));
        }

        deck.push(Carta("Joker", "Negro"));
        deck.push(Carta("Joker", "Rojo"));
    }

    void mezclar(){

        crear();

        Carta deckTemp[54];
        for(int i = 0; i < 54; i++){
            deckTemp[i] = deck.pop();
        }

        for (int primero = 0; primero < 54; primero++){
            int segundo = (rand() + time(0)) % 54;
            Carta temp = deckTemp[primero];
            deckTemp[primero] = deckTemp[segundo];
            deckTemp[segundo] = temp;
            deckTemp[segundo].print();
        }

        for(int i = 0; i < 54; i++){
            deck.push(deckTemp[i]);
        }
    }

    Carta topCarta(){
        cout << deck.getSize() << endl;
        return deck.pop();
    }
};

#endif // DECK_H
