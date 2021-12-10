#ifndef JUGADOR_H_
#include JUGADOR_H
#include "../../estructuras/Vect.h"
#include "../../grafo/Grafo.h"
#include "Material.h"
#include "Coordenada.h"


class Jugador{

    private:

    int cant_energia;
    Vect<Material>* inventario;
    Vect<Coordenada>* ubiaciones;
    Grafo* grafo;

    public:

    Jugador();

    // PRE: -
    // POST: Establece la energia del jugador.
    void establecer_energia();

    // PRE: -
    // POST: Establece el vector del inventario del jugador.
    void establecer_inventario();

    // PRE: -
    // POST: Establece el vector de ubiaciones del jugador.
    void establecer_ubicaciones(); 

    // PRE: -
    // POST: Establece el grafo del jugador.
    void establecer_grafo();

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