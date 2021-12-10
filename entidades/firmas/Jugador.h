#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "../../estructura/Vect.h"
#include "../../grafo/Grafo.h"
#include "Material.h"
#include "Coordenada.h"


class Jugador{

    private:

    int cant_energia;
    Vect<Material>* inventario;
    Vect<Coordenada>* ubicaciones;
    Grafo* grafo;

    public:

    Jugador(Grafo* grafo);

    // PRE: -
    // POST: Establece la energia del jugador.
    void establecer_energia(int cant_energia);

    // PRE: -
    // POST: Establece el vector del inventario del jugador.
    void establecer_inventario(Vect<Material>* inventario);

    // PRE: -
    // POST: Establece el vector de ubiaciones del jugador.
    void establecer_ubicaciones(Vect<Coordenada>* ubicaciones); 

    // PRE: -
    // POST: Establece el grafo del jugador.
    void establecer_grafo(Grafo* grafo);

    // PRE: -
    // POST: Obtiene la cantidad de energia del jugador.
    int obtener_cant_energia();

    // PRE: -
    // POST: Obtiene el inventario del jugador.
    Vect<Material>* obtener_inventario();

    // PRE: -
    // POST: Obtiene las ubicaciones del jugador.
    Vect<Coordenada>* obtener_ubiaciones();

    // PRE: -
    // POST: Obtiene el grafo del jugador.
    Grafo* obtener_grafo();
};

#endif // JUGADOR_H_