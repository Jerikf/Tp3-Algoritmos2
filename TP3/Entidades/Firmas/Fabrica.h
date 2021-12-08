#ifndef FABRICA_H_INCLUDED
#define FABRICA_H_INCLUDED

#include "Edificio.h"

class Fabrica: public Edificio{
   
    public:
        
    // PRE: -
    // POST: Inicializa y crea la fabrica.
    Fabrica(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

    //PRE: -
    //POST: Muestra la informacion del edificio.
    void mostrar();

    //PRE: -
    //POST: Destruye la fabrica.
    ~Fabrica();

    //PRE: -
    //POST: Devuelve la abreviatura del edificio.
    char devolver_abreviatura();
};

#endif //FABRICA_H_INCLUDED