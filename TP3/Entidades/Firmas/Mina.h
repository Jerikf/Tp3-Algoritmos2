#ifndef MINA_H
#define MINA_H

#include "Edificio.h"

class Mina : public Edificio{

    public:

    //PRE: -
    //POST: Construye la fabrica, pasando los argumento a la clase padre Edificio
    Mina(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

    //PRE: -
    //POS: Muestra la informaciond del edificio.
    void mostrar();

    //PRE:
    //POST: Destruye la mina.
    ~Mina();
};

#endif //MINA_H