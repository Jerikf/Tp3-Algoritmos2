#ifndef MAPA_H
#define MAPA_H

#include "Casillero.h"
#include "Coordenada.h"
//#include "Jugador.h"

class Mapa
{
    private:
        int cantFilas;
        int cantColumnas;
        Casillero*** casilleros;

    public:

        //PRE: Recibe la cantidad de filas y columnas
        //POS: Construye el mapa reservando memoria dinámica de casilleros según los parámetros pasados(para el tamaño), además inicializa todos en null
        Mapa(int,int);

        //PRE:
        //POS:Libera la memoria de todos los casilleros guardados 
        ~Mapa();

        //PRE:
        //POS: Muestra el mapa
        void mostrar();

        void mostrar_recorrido_jugador( Coordenada * recorrido, int tope_recorrido, int numJugador/*, Jugador* jugador*/ );

        //PRE: Recibe un casillero y una coordenada
        //POS: Agrega el casillero si la coordeanda es válida
        void agregarCasillero(Casillero*,Coordenada);

        //PRE: Recibe una coordenda
        //POS: Devuelve el casillero que se encuentra en dicha coordeanda(en caso de ser válida)
        Casillero* getCasillero(Coordenada);

        //PRE: Recibe un Tipo de casillero
        //POS: Devuelve la cantidad de casilleros del mapa, según el tipo de casillero que sea pasado por parámetro
        int obtenerCantDeCasilleros(char);

        //PRE:
        //POS: Retorna la cantidad de filas
        int getCantFilas();

        //PRE:
        //POS: Retorna la canti de columnas
        int getCantColumnas();

        //PRE: Recibe el número de jugador que estoy buscando, debe existir dicho jugador en el mapa
        //POS: Devuelve la coordenada donde se encuentra dicho jugador
        Coordenada obtenerPosicionDeJugador(int);
};




#endif //MAPA_H