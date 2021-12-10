#include "../../entidades/firmas/Jugador.h"

Jugador::Jugador(Grafo* grafo){

    this-> cant_energia = 100;
    this-> inventario = new Vect<Material>(); // Se crea sin materiales
    this-> ubicaciones = new Vect<Coordenada>();// Se crea sin ubiaciones
    this-> grafo = grafo; // Lo recibe despues de cargarse el mapa.
}

void Jugador::establecer_energia(int cant_energia){

    this-> cant_energia = cant_energia;
}

void Jugador::establecer_inventario(Vect<Material>* inventario){

    this-> inventario = inventario;
}

void Jugador::establecer_ubicaciones(Vect<Coordenada>* ubicaciones){

    this-> ubicaciones = ubicaciones;
}

void Jugador::establecer_grafo(Grafo* grafo){

    this-> grafo = grafo;
}

int Jugador::obtener_cant_energia(){

    return cant_energia;
}

Vect<Material>* Jugador::obtener_inventario(){

    return inventario;
}

Vect<Coordenada>* Jugador::obtener_ubiaciones(){

    return ubicaciones;
}

Grafo* Jugador::obtener_grafo(){

    return grafo;
}