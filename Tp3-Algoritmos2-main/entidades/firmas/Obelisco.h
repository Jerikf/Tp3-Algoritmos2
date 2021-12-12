#ifndef OBELISCO_H
#define OBELISCO_H

#include "Edificio.h"

class Obelisco : public Edificio
{
    private:
        /* data */

    public:

        //PRE:Recibe un nombre, cantidades de piedra, madera, metal y un maximo permitido
        //POS:Construye la fabrica, pasando los argumento a la clase padre Edificio
        Obelisco(string, int, int, int, int);

        //PRE:
        //POS:destructor
        ~Obelisco();

        //PRE:
        //POS: Retorta su abreviatura de su propio nombre
        char getAbreviaturaDeNombre();

        //PRE:
        //POS:Llama al mostrar del padre(que tiene toda la info del edificio) y además muestra que no brinda material
        void mostrar();
};

#endif //OBELISCO_H