#ifndef CASILLERO_H
#define CASILLERO_H
#include <stdbool.h>
#include <string>

#include "Edificio.h"
#include "Material.h"

using namespace std;

class Casillero
{
    protected:
        char tipo;
    public:

        //PRE: recibe un tipo de casillero
        //POS: Construye el casillero, asignando el tipo 
        Casillero(char);

        //PRE:
        //POS: Constructor vacio
        Casillero();

        //PRE:
        //POS: Destructor
        virtual ~Casillero();

        //PRE:
        //POS: Cada subClase implementará según sepa responder el mensaje
        virtual void mostrar()=0;

        //PRE:
        //POS: Cada subClase implementará según sepa responder el mensaje
        virtual int construirEdificio(Edificio*)=0;

        //PRE:
        //POS: CADA SubClase implementará segun sepa responder el mensaje
        virtual int construirMaterial(Material*)=0;

        //PRE:
        //POS: Cada subClase implementará según sepa responder el mensaje
        virtual Edificio* getEdificio()=0;

        //PRE:
        //POS: Cada subClase implementará según sepa responder el mensaje
        virtual Material* getMaterial()=0;

        //PRE:
        //POS: Cada subClase implementará según sepa responder el mensaje
        virtual Edificio* demolerEdificio()=0;

        //PRE:
        //POS: Retorna el tipo
        char getTipo();

        //PRE:
        //POS:Actualiza el tipo
        void setTipo(char);
};

#endif //CASILLERO_H