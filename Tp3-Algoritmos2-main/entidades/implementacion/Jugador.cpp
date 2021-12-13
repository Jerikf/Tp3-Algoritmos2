#include "../../entidades/firmas/Jugador.h"

Jugador::Jugador(Grafo* grafo){

    this-> cant_energia = 50;
    this-> inventario = new Vect<Material>(); // Se crea sin materiales
    this-> coordenadasDeEdificiosConstruidos = new Vect<Coordenada>();// Se crea sin ubiaciones
    this-> grafo = grafo; // Lo recibe despues de cargarse el mapa.
}


Jugador::Jugador(){

    this-> cant_energia = 50;
    this-> inventario = new Vect<Material>(); 
    this-> coordenadasDeEdificiosConstruidos = new Vect<Coordenada>();
    this-> grafo = NULL; 
}


void Jugador::establecer_energia(int cant_energia){

    this-> cant_energia = cant_energia;
}

void Jugador::establecer_inventario(Vect<Material>* inventario){

    this-> inventario = inventario;
}

void Jugador::establecer_ubicaciones(Vect<Coordenada>* coordenadasDeEdificiosConstruidos){

    this-> coordenadasDeEdificiosConstruidos = coordenadasDeEdificiosConstruidos;
}

void Jugador::establecer_grafo(Mapa* mapa, int numero){
    this->grafo = new Grafo(mapa, numero);
}

int Jugador::obtener_cant_energia(){

    return cant_energia;
}

Coordenada Jugador::obtenerMiPosicion(int numeroDeJugador, Mapa* mapa){
    return mapa->obtenerPosicionDeJugador(numeroDeJugador);
}

Vect<Material>* Jugador::obtener_inventario(){

    return inventario;
}

Vect<Coordenada>* Jugador::obtener_coordenadasDeEdificiosConstruidos(){

    return this->coordenadasDeEdificiosConstruidos;
}

Grafo* Jugador::obtener_grafo(){

    return grafo;
}

Coordenada * Jugador::jugadorSeMueve(Coordenada puntoInicial, Coordenada puntoFinal, int* topeCamino, Mapa * mapa){
    int costoEnergia;
    Casillero * casillero = mapa->getCasillero(puntoInicial);
    establecer_grafo(mapa, casillero->devolver_jugador_casillero());
    grafo->actualizar_grafo(mapa);
    Coordenada * caminoRecorrido = grafo->obtener_camino_minimo(puntoInicial, puntoFinal, topeCamino, &costoEnergia);
    //verificar si quiere hacerlo (para hacerlo antes de actualizar_grafo (que es pesado) necesito funcion que devuelva el costo de energia
    //si no quiere hacerlo se devuelve null
    return caminoRecorrido;
}

Jugador::~Jugador(){

    delete inventario;
    delete this->coordenadasDeEdificiosConstruidos;
    if(grafo){
        delete grafo;
    }
}