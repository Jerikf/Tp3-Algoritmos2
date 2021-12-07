#ifndef PLANTAELECTRICA_H
#define PLANTAELECTRICA_H

#include "Edificio.h"

class PlantaElectrica: public Edificio{

    public:

    // PRE: -
    // POST: Inicializa y crea la planta electrica.
    PlantaElectrica(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

    //PRE:
    //POS: Muestra la informacion de la planta electrica.
    void mostrar();

    //PRE: -
    //POS: Destruye la planta electrica.
    ~PlantaElectrica();

    //PRE:
    //POS: Retorta su abreviatura de su propio nombre
    char getAbreviaturaDeNombre();
};

#endif //PLANTAELECTRICA_H