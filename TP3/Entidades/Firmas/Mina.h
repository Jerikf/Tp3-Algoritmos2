#ifndef MINA_H_INCLUDED
#define MINA_H_INCLUDED

#include "Edificio.h"

class Mina: public Edificio{

    public:

    //PRE: -
    //POST: Construye la fabrica, pasando los argumento a la clase padre Edificio
    Mina(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

    //PRE: -
    //POST: Muestra la informaciond del edificio.
    void mostrar();

    //PRE: -
    //POST: Destruye la mina.
    ~Mina();

    //PRE: -
    //POST: Devuelve la abreviatura del edificio.
    char devolver_abreviatura();
};

#endif //MINA_H_INCLUDED