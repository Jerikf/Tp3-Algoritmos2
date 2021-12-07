#include "../../Entidades/Firmas/Jugador.h"

Jugador::Jugador(){

   edificios = nullptr;
   inventario = nullptr;
   mapa = nullptr;


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