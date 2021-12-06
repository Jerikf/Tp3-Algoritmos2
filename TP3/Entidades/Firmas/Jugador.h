#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "Edificio.h"
#include "Material.h"
#include "../../Estructuras/Firmas/Diccionario.h"
#include "Aserradero.h"
#include "Escuela.h"
#include "Mina.h"
#include "PlantaElectrica.h"
#include "Obelisco.h"
#include "Fabrica.h"
#include "Mina_oro.h"
#include "../../Estructuras/Firmas/Vect.h"

class Jugador{

    private:

    Diccionario<Edificio>* edificios;
    Vect<Material>* inventario;

    public:
    
    // PRE: -
    // POST: Inicializa el jugador.
    Jugador();   

    // PRE: -
    // POST: Crea el diccionario.
    void crear_diccionario();

    // PRE: -
    // POST: Crea un vector dinamico de materiales.
    void crear_inventario();
    
    // PRE: El diccionario es valido.
    // POST: Se obtiene le diccionario de edificios.
    void obtener_edificios(Diccionario<Edificio> *edificios);

    // PRE: -
    // POST: Se obtiene el inventario.
    void obtener_invnetario(Vect<Material> *invnetario);

    void limpiar_inventario();

    // PRE: -
    // POST: Devuelve el diccionario de edificios.
    Diccionario<Edificio>* devolver_edificios();

    // PRE: -
    // POST: Devuelve el inventario.
    Vect<Material>* devolver_inventario();

    // PRE: -
    // POST: Limpia el diccionario.
    void limpiar_diccionario();

};

#endif // JUGADOR_H_INCLUDED