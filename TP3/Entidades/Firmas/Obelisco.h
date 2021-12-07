#ifndef OBELISCO_H
#define OBELISCO_H

#include "Edificio.h"

class Obelisco: public Edificio{

    public:

    //PRE:
    //POST: Inicializa y crea el obelisco.
    Obelisco(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

    //PRE:
    //POS: Muestra la informacion del edificio.
    void mostrar();

    //PRE:
    //POS: Destruye el obelisco.
    ~Obelisco();

    //PRE:
    //POS: Retorta su abreviatura de su propio nombre
    char getAbreviaturaDeNombre();
};

#endif //OBELISCO_H