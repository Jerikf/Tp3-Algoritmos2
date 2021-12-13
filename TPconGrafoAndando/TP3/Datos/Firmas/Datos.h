#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED
#include "../../Entidades/Firmas/Jugador.h"
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

    // Pre: -
    // Post: Carga las ubicaiones del mapa.
    void cargar_ubicaciones();

    // PRE: -
    // POST: Devuelve al jugador 1.
    Jugador devovler_jugador_1();

    // PRE: -
    // POST: Devuelve al jugador 2.
    Jugador devovler_jugador_2();

    // PRE: El edificio apunta correctamente, y estan bien pasados los parametros.
    // POST: Designa una clase a cada edificio dependiendo del nombre.
    void designar_clase_edificio(Edificio* &edificio, std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

    // PRE: El casillero apunta correctamente, y estan bien pasados los parametros.
    // POST: Designa una clase a cada casillero dependiendo del tipo de caracter.
    void designar_clase_casillero(Casillero* &casillero, Coordenada coordenada, char tipo);

    // PRE: -
    // POST: Inicializa el grafo de ambos jugadores.
    void inicialziar_grafos(Mapa* mapa_1, Mapa* mapa_2);

};

#endif //DATOS_H_INCLUDED