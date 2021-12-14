#ifndef INACCESIBLE_H
#define INACCESIBLE_H

#include "Casillero.h"

class Inaccesible : public Casillero
{
    private:

    public:

        //PRE:
        //POS:Contruye el Casillero Inaccesible vacio
        Inaccesible();

        //PRE: Recibe un tipo de casillero
        //POS: Construye el Casillero Inaccesible asingando el tipo a la clase padre
        Inaccesible(char);

        //PRE:
        //POS: Destructor
        ~Inaccesible();

        //PRE:
        //POS: Retorna -1(ERROR) porque no sabe responder a este mensaje
        int construirEdificio(Edificio*);

        //PRE: Recibe un Material 
        //POS: Retorna -1(ERROR) porque no puede contruir un material en este casillero
        int construirMaterial(Material*);

        //PRE:
        //POS: Retorna NULL porque no sabe responder a este mensaje
        Edificio* getEdificio();

        //PRE:
        //POS: Retorna NULL porque no sabe responder a este mensaje
        Material* getMaterial();

        //PRE: -
        //POST: devuelve NULL porque no sabe responder a este mensaje
        Material* recolectarMaterial();

        //PRE:
        //POS: Retorna NULL, además muestra que no se puede demoler 
        Edificio* demolerEdificio();

        //PRE:
        //POS: Muestra quien es
        void mostrar();
};

#endif //INACCESIBLE_H