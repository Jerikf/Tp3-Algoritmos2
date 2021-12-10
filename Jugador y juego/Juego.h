#ifndef JUEGO_H_
#include JUEGO_H_
#include "../../estructuras/Diccionario.h"
#include "Mapa.h"
#include "Jugador.h"
#include "Edificio.h"

class Juego{

    private:

    Diccionario<Edificio>* edificios;
    Mapa* mapa;
    Jugador jugador_1;
    Jugador jugador_2;

    public:

    Juego();

    // PRE: -
    // POST: Establece el diccionario de edificios.
    void establecer_dic_edificios(Diccionario<Edificio>* dic_edificios);

    // PRE: -
    // POST: Establece el jugador 1.
    void establecer_jugador_1(Jugador jugador_1);

    // PRE: -
    // POST: Establece el jugador 1.
    void establecer_jugador_1(Jugador jugador_2);

    // PRE: -
    // POST: Establece el mapa.
    void establecer_mapa(Mapa *mapa);
 
    // PRE: -
    // POST: Obtiene el diccionario de edificios.
    Diccionario<Edificio>* obtener_dic_edificios();

    // PRE: -
    // POST: Obtiene el mapa.
    Mapa* obtener_mapa();

    // PRE: -
    // POST: Obtiene el jugador 1.
    Jugador obtener_jugador_1();

    // PRE: -
    // POST: Obtiene el jugador 2.
    Jugador obtener_jugador_2();

    // PRE: -
    // POST: Limpia la memoria dinamica del diccionario de edificios.
    void limpiar_dic_edificios();

    // PRE: -
    // POST: Limpia la memoria dinamica del mapa.
    void limpiar_mapa();
};

#endif // JUEGO_H_