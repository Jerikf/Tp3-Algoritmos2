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
#include "Mapa.h"
#include "Transitable.h"
#include "Construible.h"
#include "Inaccesible.h"
#include "../../Estructuras/Firmas/Vect.h"

class Jugador{

    private:

    Diccionario<Edificio>* edificios;
    Vect<Material>* inventario;
    Mapa * mapa;

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
    // POST: Limpia el diccionario.
    void limpiar_diccionario();

    void limpiar_mapa();

};

#endif // JUGADOR_H_INCLUDED