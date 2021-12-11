#ifndef MINAORO_H
#define MINAORO_H

#include "Edificio.h"

class MinaOro : public Edificio
{
    private:
        /* data */

    public:

        //PRE:Recibe un nombre, cantidades de piedra, madera, metal y un maximo permitido
        //POS:Construye la fabrica, pasando los argumento a la clase padre Edificio
        MinaOro(string, int, int, int, int);

        //PRE:
        //POS:destructor
        ~MinaOro();

        //PRE:
        //POS: Retorta su abreviatura de su propio nombre
        char getAbreviaturaDeNombre();

        //PRE:
        //POS:Llama al mostrar del padre(que tiene toda la info del edificio) y además muestra que brinda material
        void mostrar();
};

#endif //MINAORO_H