#include "Jugador.h"


void Jugador::obtener_inventario(Inventario invnetario){
    
    limpiar_inventario();
    this-> inventario = invnetario;
}

Inventario Jugador::devolver_inventario(){

    return inventario;
}

void Jugador::limpiar_inventario(){

    delete[] inventario.devolver_materiales();

}
