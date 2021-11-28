#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "Inventario.h"
#include "Diccionario.h"

class Jugador{

    private:

    Inventario inventario;

    public:
    

    // Pre: EL invnetario esta bien cargado.
    // Post: Se obtiene el inventario del jugador.
    void obtener_inventario(Inventario inventario);
    
    // Pre: -
    // Post: Devuelve el inventario del jugador.
    Inventario devolver_inventario();
    
    // Pre: -
    // Post: Limpia la memoria dinamica de los materiales dependindo del inventario del juagador.
    void limpiar_inventario();



};

#endif // JUGADOR_H_INCLUDED