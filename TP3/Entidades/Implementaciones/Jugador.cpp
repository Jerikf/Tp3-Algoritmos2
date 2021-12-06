#include "../../Entidades/Firmas/Jugador.h"

Jugador::Jugador(){

   edificios = nullptr;
   inventario = nullptr;


}

void Jugador::crear_inventario(){

    inventario = new Vect<Material>();
}

void Jugador::crear_diccionario(){

    edificios = new Diccionario<Edificio>(); 
}

void Jugador::obtener_edificios(Diccionario<Edificio>* edificios){
    
    this-> edificios = edificios;
}

void Jugador::obtener_invnetario(Vect<Material>* inventario){

    this-> inventario = inventario;
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

Vect<Material>* Jugador::devolver_inventario(){

    return inventario;
}