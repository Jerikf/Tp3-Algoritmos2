#ifndef PLANTAELECTRICA_H_INCLUDED
#define PLANTAELECTRICA_H_INCLUDED

#include "Edificio.h"

class PlantaElectrica: public Edificio{

    public:

    // PRE: -
    // POST: Inicializa y crea la planta electrica.
    PlantaElectrica(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

    //PRE: -
    //POST: Muestra la informacion de la planta electrica.
    void mostrar();

    //PRE: -
    //POST: Destruye la planta electrica.
    ~PlantaElectrica();

    //PRE: -
    //POST: Devuelve la abreviatura del edificio.
    char devolver_abreviatura();
};

#endif //PLANTAELECTRICA_H_INCLUDED