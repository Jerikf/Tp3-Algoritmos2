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

    grafo = new Grafo(mapa, numero);
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

Jugador::~Jugador(){

    delete inventario;
    delete this->coordenadasDeEdificiosConstruidos;
    if(grafo){
        delete grafo;
    }
}