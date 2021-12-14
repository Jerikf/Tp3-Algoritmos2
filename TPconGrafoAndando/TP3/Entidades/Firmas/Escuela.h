#ifndef ESCUELA_H_INCLUDED
#define ESCUELA_H_INCLUDED

#include "Edificio.h"

class Escuela: public Edificio{

    public:

    //PRE: -
    //POST: Inicializa y crea la escuela.
    Escuela(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);
        
    //PRE: -
    //POST: Muestra la informacion del edificio.
    void mostrar();

    //PRE: -
    //POST:Destructor
    ~Escuela();

    //PRE: -
    //POST: Devuelve la abreviatura del edificio.
    char devolver_abreviatura();

};

#endif //ESCUELA_H_INCLUDED