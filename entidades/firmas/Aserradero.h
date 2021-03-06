#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "Edificio.h"

class Aserradero : public Edificio{
    private:
        /* data */

    public:

        //PRE: Recibe un nombre, cantidades de piedra, madera, metal y un maximo permitido.
        //POS: Construye el aserradero instanciado con los valores pasados.
        Aserradero(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos);

        //PRE: -
        //POS: Destructor
        ~Aserradero();

        //PRE: -
        //POS: Retorta su abreviatura de su propio nombre.
        char getAbreviaturaDeNombre();

        //PRE: -
        //POS:Llama al mostrar del padre(que tiene toda la info del edificio) y además muestra que brinda material.
        void mostrar();

        //PRE: -
        //POS: Establece la cantidad de vida del edificio.
        void setVida();
};

#endif //ASERRADERO_H