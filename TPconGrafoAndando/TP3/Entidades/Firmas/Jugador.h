#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "../../Estructuras/Firmas/Diccionario.h"
#include "Aserradero.h"
#include "Escuela.h"
#include "Mina.h"
#include "PlantaElectrica.h"
#include "Obelisco.h"
#include "Fabrica.h"
#include "Mina_oro.h"
#include "Transitable.h"
#include "Construible.h"
#include "Inaccesible.h"
#include "../../grafo/Grafo.h"
#include "../../Estructuras/Firmas/Vect.h"

class Jugador{

    private:

    Diccionario<Edificio>* edificios;
    Vect<Material>* inventario;
    Mapa * mapa;
    Vect<Coordenada>* coordenadas_materiales;
    Vect<Coordenada>* coordenadas_edificios;
    Vect<Coordenada>* coordenada_jugador;
    Grafo* grafo;


    public:
    
    // PRE: -
    // POST: Inicializa el jugador.
    Jugador();   

    // PRE: El diccionario es valido.
    // POST: Se obtiene le diccionario de edificios.
    void obtener_edificios(Diccionario<Edificio> *edificios);

    // PRE: -
    // POST: Se obtiene el inventario.
    void obtener_invnetario(Vect<Material> *invnetario);

    // PRE: -
    // POST: Se obtiene el mapa.
    void obtener_mapa(Mapa* mapa);

    // PRE: -
    // POST: Se obtienen las coordenadas de cada material en el mapa.
    void obtener_coordenadas_materiales(Vect<Coordenada>* coordenadas_materiales);

    // PRE: -
    // POST: Se obtienen las coordenadas de cada edificio en el mapa.
    void obtener_coordenadas_edificios(Vect<Coordenada>* coordenadas_edificios);

    // PRE: -
    // POST: Se obtiene las coordenadas de cada jugador.
    void obtener_corrdenadas_jugador(Vect<Coordenada>* coordenadas_jugador);

    void limpiar_inventario();

    // PRE: -
    // POST: Devuelve el diccionario de edificios.
    Diccionario<Edificio>* devolver_edificios();

    // PRE: -
    // POST: Devuelve el inventario.
    Vect<Material>* devolver_inventario();

    // PRE: -
    // POST: Devuelve el mapa del jugador.
    Mapa* devolver_mapa();

    // PRE: -
    // POST: Devuelve el vector de coordenadas de los materiales.
    Vect<Coordenada>* devolver_coordenadas_materiales();

    // PRE: -
    // POST: Devuelve el vector de coordendas de los edificios.
    Vect<Coordenada>* devolver_coordenadas_edifcios();

    // PRE: -
    // POST: Devuelve el vector de coordenadas de los jugadores.
    Vect<Coordenada>* devolver_coordenadas_jugadores();

    // PRE: -
    // POST: Limpia el diccionario.
    void limpiar_diccionario();

    void limpiar_mapa();

    void obtener_grafo(Grafo *grafo);

    Grafo* devolver_grafo();

    void limpiar_grafo();

};

#endif // JUGADOR_H_INCLUDED