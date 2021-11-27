#ifndef ESCUELA_H
#define ESCUELA_H

#include "Edificio.h"

class Escuela : public Edificio
{
    private:
        /* data */

    public:

        //PRE:Recibe un nombre, cantidades de piedra, madera, metal y un maximo permitido
        //POS:Construye la escuela, pasando los argumento a la clase padre Edificio
        Escuela(string, int, int, int, int);

        //PRE:
        //POS:Destructor
        ~Escuela();
        
        //PRE:
        //POS: Retorta su abreviatura de su propio nombre
        char getAbreviaturaDeNombre();

        //PRE:
        //POS:Llama al mostrar del padre(que tiene toda la info del edificio) y además muestra que no brinda material
        void mostrar();
};

#endif //ESCUELA_H