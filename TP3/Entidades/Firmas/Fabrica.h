#ifndef FABRICA_H
#define FABRICA_H

#include "Edificio.h"

class Fabrica:public Edificio{
   
    public:
        
    // PRE: -
    // POST: Inicializa y crea la fabrica.
    Fabrica(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

    //PRE: -
    //POS: Muestra la informacion del edificio.
    void mostrar();

    //PRE: -
    //POS: Destruye la fabrica.
    ~Fabrica();

    //PRE:
    //POS: Retorta su abreviatura de su propio nombre
    char getAbreviaturaDeNombre();
};

#endif //FABRICA_H