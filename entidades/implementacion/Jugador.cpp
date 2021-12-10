#include "../../entidades/firmas/Jugador.h"

Jugador::Jugador(int cant_energia, Vect<Material>* inventario, Vect<Coordenada>* ubicaciones, Grafo* grafo){

    this-> cant_energia = cant_energia;
    this-> inventario = inventario;
    this-> ubicaciones = ubicaciones;
    this-> grafo = grafo;
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