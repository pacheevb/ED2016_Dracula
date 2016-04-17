#ifndef TABLERO_H
#define TABLERO_H

#include "assert.h"
#include "Deck.h"
#include <qstring.h>

using namespace std;

class Tablero{
    private:
        Carta tablero[3][3];

        LinkedStack<int> posMano;
        LinkedStack<int> posMesa;
        LinkedStack<int> jugadores;
        LinkedStack<Carta> cartas;

        int JActual = 1;
        int pdir1 = 0;
        int pdir2 = 0;

        int ronda = 1;
        int puntajeJ1;
        int puntajeJ2;

        Carta player1[4];
        Carta player2[4];
        Carta cartaSeleccionada;

        static bool bandera;

    public:

        Tablero(){
        }

        void resetTablero(){
            ronda = 1;
            puntajeJ1 = 0;
            puntajeJ2 = 0;
            Deck* mazo = Deck::getInstance();
            mazo->mezclar();
        }

        QString getCartaQString(Carta pCarta){
            string str = ":/Cartas/Recursos/Cartas/"+pCarta.getDireccion()+".png";
            QString qStr = QString::fromLocal8Bit(str.c_str());

            return qStr;
        }

        static Tablero* getInstance() {
            static Tablero m_instance;
            return &m_instance;
        }

        void repartir(){
            Deck *mazo = Deck::getInstance();
            for(int i = 0; i < 4; i++){
                player1[i] = mazo->topCarta();
            }
            for(int i = 0; i < 4; i++){
                player2[i] = mazo->topCarta();
            }
        }

        void reset(){
            for(int fila = 0;fila < 3; fila++){
                for (int columna = 0; columna < 3; columna++){
                    tablero[fila][columna] = Carta();
                }
            }
        }

        bool isFull(){
            bool lleno = true;
            for (int i = 0; i < 3;i++){
                for (int j = 0; j < 3; j++){
                    if (tablero[i][j].getCara() == ""){
                        lleno = false;
                    }
                }
            }
            return lleno;
        }

        bool comprobarRonda(){
            if(!isFull()){
                return false;
            }else{
                int medioFila = puntajeFila(0);
                int medioColumna = puntajeColumna(0);
                int menorFila = puntajeFila(1);
                int menorColumna = puntajeColumna(1);
                int mayorFila = puntajeFila(2);
                int mayorColumna = puntajeColumna(2);

                int puntajesFila[3] = {medioFila,menorFila,mayorFila};
                int puntajesColumna[3] = {medioColumna,menorColumna,mayorColumna};

                int j, temp;
                for (int i = 0; i < 3; i++){
                    j = i;
                    while (j > 0 && puntajesFila[j] < puntajesFila[j-1]){
                        temp = puntajesFila[j];
                        puntajesFila[j] = puntajesFila[j-1];
                        puntajesFila[j-1] = temp;
                        j--;
                        }
                }

                for (int i = 0; i < 3; i++){
                    j = i;
                    while (j > 0 && puntajesColumna[j] < puntajesColumna[j-1]){
                        temp = puntajesColumna[j];
                        puntajesColumna[j] = puntajesColumna[j-1];
                        puntajesColumna[j-1] = temp;
                        j--;
                        }
                }

                int puntajes1[3];
                int puntajes2[3];

                if(pdir1 == 0){
                    for(int i = 0; i < 3; i++){
                        puntajes1[i] = puntajesFila[i];
                    }

                    for(int i = 0; i < 3; i++){
                        puntajes2[i] = puntajesColumna[i];
                    }
                } else {
                    for(int i = 0; i < 3; i++){
                        puntajes2[i] = puntajesFila[i];
                    }

                    for(int i = 0; i < 3; i++){
                        puntajes1[i] = puntajesColumna[i];
                    }
                }

                if (puntajes1[2] > puntajes2[2]){
                    puntajeJ1 += puntajes1[2]+ (puntajes1[2] - puntajes2[2]);
                    puntajeJ2 += puntajes2[2];
                }else if(puntajes1[2] < puntajes2[2]){
                    puntajeJ1 += puntajes1[2];
                    puntajeJ2 += puntajes2[2]+ (puntajes2[2] - puntajes1[2]);
                }else if (puntajes1[1] > puntajes2[1]){
                    puntajeJ1 += puntajes1[1]+ (puntajes1[1] - puntajes2[1]);
                    puntajeJ2 += puntajes2[1];
                }else if (puntajes1[1] < puntajes2[1]){
                    puntajeJ1 += puntajes1[1];
                    puntajeJ2 += puntajes2[1]+ (puntajes2[1] - puntajes1[1]);
                }else if (puntajes1[0] > puntajes2[0]){
                    puntajeJ1 += puntajes1[0]+ (puntajes1[0] - puntajes2[0]);
                    puntajeJ2 += puntajes2[0];
                }else if (puntajes1[0] < puntajes2[0]){
                    puntajeJ1 += puntajes1[0];
                    puntajeJ2 += puntajes2[0]+ (puntajes2[0] - puntajes1[0]);
                }else{
                    puntajeJ1 += puntajes1[2];
                    puntajeJ2 += puntajes2[2];
                }

                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        tablero[i][j] = Carta("", "");
                    }
                }

                posMano.clear();
                posMesa.clear();
                cartas.clear();
                jugadores.clear();

                return true;
            }
        }

        //las casillas de la matriz en este caso estan numeradas del 1 al 9
        bool setJugada (Carta carta, int numcasilla){
            bool  valido = false;
            switch (numcasilla)
            {
            case 1:
                valido = validar(0,0);
                if (valido == true){
                    tablero[0][0] = carta;
                }
                return valido;

            case 2:
                valido = validar(0,1);
                if (valido == true){
                    tablero[0][1] = carta;
                }
                return valido;

            case 3:
                valido = validar(0,2);
                if (valido == true){
                    tablero[0][2] = carta;
                }
                return valido;

            case 4:
                valido = validar(1,0);
                if (valido == true){
                    tablero[1][0] = carta;
                }
                return valido;

            case 5:
                valido = (tablero[1][1].getCara()=="");
                if (valido){
                    tablero[1][1] = carta;
                }
                break;

            case 6:
                valido = validar(1,2);
                if (valido == true){
                    tablero[1][2] = carta;
                }
                return valido;

            case 7:
                valido = validar(2,0);
                if (valido == true){
                    tablero[2][0] = carta;
                }
                return valido;

            case 8:
                valido = validar(2,1);
                if (valido == true){
                    tablero[2][1] = carta;
                }
                return valido;

            case 9:
                valido = validar(2,2);
                if (valido == true){
                    tablero[2][2] = carta;
                }
                return valido;
            }
        }

        bool validar(int fila, int columna){
            switch (fila)
            {
                case 0:
                    if (columna == 0){
                        return ( (tablero[0][0].getCara() == "") && (tablero[0][1].getCara() != "" || tablero[1][0].getCara()!="") );
                        break;

                    }else if(columna == 1){
                        return (tablero[0][1].getCara() == "");
                        break;

                    }else if (columna == 2){
                        return ((tablero[0][2].getCara() == "") && (tablero[0][1].getCara()!="" || tablero[1][2].getCara()!=""));
                    }

                case 1:
                    if (columna == 0){
                        return (tablero[1][0].getCara()=="");

                    }else if (columna == 2){
                        return (tablero[1][2].getCara()=="");
                    }

                case 2:
                    if (columna == 0){
                        return ((tablero[2][0].getCara()=="")&& (tablero[1][0].getCara()!="" || tablero[2][1].getCara()!=""));

                    }else if(columna == 1){
                        return (tablero[2][1].getCara() == "");

                    }else if (columna == 2){
                        return ((tablero[2][2].getCara() == "")&& (tablero[1][2].getCara()!="" || tablero[2][1].getCara()!=""));
                    }
                default:
                    return false;
            }
            return false;
        }

        int puntajeFila(int fila){
            //veo si alguno de la fila es vampiro
            if ((tablero[fila][0].getValue() == -1) || (tablero[fila][1].getValue() == -1) || (tablero[fila][2].getValue() == -1)){
                return 0;
            }else{
                int suma = 0;
                int multiplicar = 1;

                //agarro las cartas de la fila
                Carta c1 = tablero[fila][0];
                Carta c2 = tablero[fila][1];
                Carta c3 = tablero[fila][2];

                //veo si hay 2 del mismo palo

                if (((c1.getPalo() == c2.getPalo()) && (c1.getPalo() != ""))|| ((c2.getPalo() == c3.getPalo()) && (c2.getPalo() != "") )|| ((c1.getPalo() == c3.getPalo()) && (c3.getPalo() != "") )){
                    multiplicar = multiplicar * 2;
                }

                //si tiene 3 cartas del mismo color
                if (c1.getColor() == c2.getColor() && c2.getColor() == c3.getColor()){
                    multiplicar = multiplicar * 3;
                }

                //veo si son de mismo palo
                if (c1.getPalo() == c2.getPalo() && c2.getPalo() == c3.getPalo()){
                    multiplicar = multiplicar * 5;
                }

                switch(fila){
                case 0:
                    for (int i = 0; i < 3; i++){
                            if (tablero[0][i].getCara()!="Rey"){
                                suma = suma + tablero[0][i].getValue();
                            }
                    }

                    suma = suma * multiplicar;
                    return suma;

                case 1:
                    for (int i = 0; i < 3; i++){
                            if (tablero[1][i].getCara()!="Rey"){
                                suma = suma + tablero[1][i].getValue();
                            }
                    }
                    suma = suma * multiplicar;
                    return suma;

                case 2:
                    for(int i = 0; i < 3; i++){
                            if (tablero[2][i].getCara()!="Rey"){
                                suma = suma + tablero[2][i].getValue();
                            }
                    }
                    suma = suma * multiplicar;
                    return suma;

                }
            }
        }

        int puntajeColumna(int columna){
            if ((tablero[0][columna].getValue() == -1) || (tablero[1][columna].getValue() == -1)|| (tablero[2][columna].getValue() == -1)){
                return 0;
            }else{
                int suma = 0;
                int multiplicar = 1;


                //agarro las cartas de la columna
                Carta c1 = tablero[0][columna];
                Carta c2 = tablero[1][columna];
                Carta c3 = tablero[2][columna];

                //veo si hay 2 del mismo palo
                if (((c1.getPalo() == c2.getPalo()) && (c1.getPalo() != ""))|| ((c2.getPalo() == c3.getPalo()) && (c2.getPalo() != ""))|| ((c1.getPalo() == c3.getPalo()) && (c3.getPalo() != ""))){
                    multiplicar = multiplicar * 2;
                }

                //si tiene 3 cartas del mismo color
                if (c1.getColor() == c2.getColor() && c2.getColor() == c3.getColor()){
                    multiplicar = multiplicar * 3;
                }

                //veo si son de mismo palo
                if (c1.getPalo() == c2.getPalo()&& c2.getPalo() == c3.getPalo()){
                    multiplicar = multiplicar * 5;
                }

                switch(columna){
                case 0:
                    for (int i = 0; i < 3; i++){
                            if (tablero[i][0].getCara() != "Dama"){
                                suma = suma + tablero[i][0].getValue();
                            }
                    }
                    suma = suma * multiplicar;
                    return suma;

                case 1:
                    for (int i = 0; i < 3; i++){
                            if (tablero[i][1].getCara() != "Dama"){
                                suma = suma + tablero[i][1].getValue();
                            }
                    }
                    suma = suma * multiplicar;
                    return suma;

                case 2:
                    for (int i = 0; i < 3; i++){
                            if(tablero[i][2].getCara() != "Dama"){
                                suma = suma + tablero[i][2].getValue();
                            }
                    }
                    suma = suma * multiplicar;
                    return suma;

                }
            }
        }

        //Getters & Setters

        void setTablero(int pFila, int pCol, Carta pCarta){
            tablero[pFila][pCol] = pCarta;
        }

        Carta* getCartasJ1(){
            return player1;
        }

        Carta* getCartasJ2(){
            return player2;
        }

        void setJActual(int pA){
            JActual = pA;
        }

        int getJActual() {
            return JActual;
        }

        int getpDir1(){
            return pdir1;
        }

        void setpDir1(int value){
            pdir1 = value;
        }

        int getpDir2(){
            return pdir2;
        }

        void setpDir2(int value){
            pdir2 = value;
        }

        Carta getCartaSeleccionada(){
            return cartaSeleccionada;
        }

        void setCartaSeleccionada(Carta pCarta){
            cartaSeleccionada = pCarta;
        }

        int getRonda(){
            return ronda;
        }

        void incRonda(){
            ronda++;
        }

        string getGanador(){
            if(puntajeJ1 > puntajeJ2){
                return "Jugador 1";
            } else {
                return "Jugador 2";
            }
        }

        int getPuntajeJ1(){
            return puntajeJ1;
        }

        int getPuntajeJ2(){
            return puntajeJ2;
        }

        //Codigo de Undo

        int getSizeUndo(){
            return jugadores.getSize();
        }

        void pushJugada(int pPosCarta, int pJugador, Carta pCarta){
            posMano.push(pPosCarta);
            jugadores.push(pJugador);
            cartas.push(pCarta);
        }

        void pushPosMesa(int pPosMesa){
            posMesa.push(pPosMesa);
        }

        int popPosicionMano(){
            return posMano.pop();
        }

        int popPosicionMesa(){
            return posMesa.pop();
        }

        int popJugador(){
            return jugadores.pop();
        }

        Carta popCarta(){
            return cartas.pop();
        }

        void imprimirTope(){
            cout << "Posicion: " << posMano.topValue() << " - " << "Carta: " << cartas.topValue().getDireccion() << endl;
        }
};

#endif // TABLERO_H
