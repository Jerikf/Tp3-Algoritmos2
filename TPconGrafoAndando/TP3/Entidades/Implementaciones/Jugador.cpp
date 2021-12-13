#include "../../Entidades/Firmas/Jugador.h"

Jugador::Jugador(){

   edificios = nullptr;
   inventario = nullptr;
   mapa = nullptr;
   coordenada_jugador = nullptr;
   coordenadas_edificios = nullptr;
   coordenadas_materiales = nullptr;
   grafo = nullptr;


}


void Jugador::obtener_edificios(Diccionario<Edificio>* edificios){
    
    this-> edificios = edificios;
}

void Jugador::obtener_invnetario(Vect<Material>* inventario){

    this-> inventario = inventario;
}

void Jugador::obtener_mapa(Mapa *mapa){

    this-> mapa = mapa;
}

void Jugador::limpiar_inventario(){

    delete inventario;
}

Diccionario<Edificio>* Jugador::devolver_edificios(){

    return edificios;
}

void Jugador::limpiar_diccionario(){

    delete edificios;
}

Mapa* Jugador::devolver_mapa(){

    return mapa;
}

Vect<Material>* Jugador::devolver_inventario(){

    return inventario;
}

void Jugador::limpiar_mapa(){

    delete mapa;
}

void Jugador::obtener_coordenadas_materiales(Vect<Coordenada>* coordenadas_materiales){

    this-> coordenadas_materiales = coordenadas_materiales;
}

void Jugador::obtener_coordenadas_edificios(Vect<Coordenada>* coordenadas_edificios){
    
    this-> coordenadas_edificios = coordenadas_edificios;
}

void Jugador::obtener_corrdenadas_jugador(Vect<Coordenada>* devolver_coordenadas_jugadores){

    this-> coordenada_jugador = coordenada_jugador;
}

Vect<Coordenada>* Jugador::devolver_coordenadas_materiales(){

    return coordenadas_materiales;
}

Vect<Coordenada>* Jugador::devolver_coordenadas_edifcios(){

    return coordenadas_edificios;
}

Vect<Coordenada>* Jugador::devolver_coordenadas_jugadores(){

    return coordenada_jugador;
}

void Jugador::obtener_grafo(Grafo* grafo){

    this-> grafo = grafo;
}

Grafo* Jugador::devolver_grafo(){

    return grafo;
}

void Jugador::limpiar_grafo(){

    delete grafo;
}