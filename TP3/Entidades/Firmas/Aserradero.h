#ifndef ASERRADERO_H_INCLUDED
#define ASERRADERO_H_INCLUDED

#include "Edificio.h"

class Aserradero: public Edificio{

    public:

    //PRE: -
    //POST: Inicializa y crea el aserradero.
    Aserradero(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

    //PRE:
    //POST: Muestra la informacion del edificio.
    void mostrar();

    //PRE:
    //POST: Destruye el aserradero.
    ~Aserradero();

    //PRE: -
    //POST: Devuelve la abreviatura del edificio.
    char devolver_abreviatura();

};

#endif //ASERRADERO_H_INCLUDED