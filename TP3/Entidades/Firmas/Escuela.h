#ifndef ESCUELA_H
#define ESCUELA_H

#include "Edificio.h"

class Escuela : public Edificio
{
    private:
        /* data */

    public:

    //PRE: -
    //POS: Inicializa y crea la escuela.
    Escuela(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);
        
    //PRE: -
    //POST: Muestra la informacion del edificio.
    void mostrar();

    //PRE:
    //POS:Destructor
    ~Escuela();

};

#endif //ESCUELA_H