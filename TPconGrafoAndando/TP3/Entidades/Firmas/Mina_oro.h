#ifndef MINA_ORO_H_INCLUDED
#define MINA_ORO_H_INCLUDED
#include "../../Entidades/Firmas/Edificio.h"

class Mina_oro: public Edificio{

    public:

    // PRE: -
    // POST: Inicializa la mina de oro.
    Mina_oro(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edifios);


    // PRE: -
    // POST: Muestra la informacion del edificio.
    void mostrar();

    // PRE: -
    // POST: Destruye la mina de oro.
    ~Mina_oro();

    //PRE: -
    //POST: Devuelve la abreviatura del edificio.
    char devolver_abreviatura();
};

#endif // MINA_ORO_H_INCLUDED