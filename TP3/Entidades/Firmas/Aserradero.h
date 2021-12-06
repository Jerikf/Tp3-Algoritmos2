#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "Edificio.h"

class Aserradero: public Edificio{

    public:

    //PRE: -
    //POS: Inicializa y crea el aserradero.
    Aserradero(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

    //PRE:
    //POST: Muestra la informacion del edificio.
    void mostrar();

    //PRE:
    //POS: Destruye el aserradero.
    ~Aserradero();
};

#endif //ASERRADERO_H