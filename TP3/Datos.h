#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED
#include "Jugador.h"
#include <fstream>

class Datos{

    private:

    Jugador jugador_1;
    Jugador jugador_2;


    public:
    
    
    // Pre: -
    // Post: Carga los datos del inventario de los jugadores.
    void cargar_inventario();

    // Pre: -
    // Post: Carga los datos del mapa de los jugadores.
    void cargar_mapa();

    // Pre: -
    // Post: Carga los datos de los edificios de los jugadores.
    void cargar_edificios();

    // PRE: -
    // POST: Devuelve al jugador 1.
    Jugador devovler_jugador_1();

    // PRE: -
    // POST: Devuelve al jugador 2.
    Jugador devovler_jugador_2();


};

#endif //DATOS_H_INCLUDED