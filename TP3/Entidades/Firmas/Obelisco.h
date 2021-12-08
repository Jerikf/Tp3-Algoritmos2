#ifndef OBELISCO_H_INCLUDED
#define OBELISCO_H_INCLUDED

#include "Edificio.h"

class Obelisco: public Edificio{

    public:

    //PRE: -
    //POST: Inicializa y crea el obelisco.
    Obelisco(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

    //PRE: -
    //POST: Muestra la informacion del edificio.
    void mostrar();

    //PRE: -
    //POST: Destruye el obelisco.
    ~Obelisco();

    //PRE: -
    //POST: Devuelve la abreviatura del edificio.
    char devolver_abreviatura();
};

#endif //OBELISCO_H_INCLUDED