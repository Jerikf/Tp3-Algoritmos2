#ifndef TRANSITABLE_H
#define TRANSITABLE_H

#include "Casillero.h"


class Transitable : public Casillero
{
    private:
        Material* material;
        
    public:

        //PRE:
        //POS: Construye el casillero transitable, instancia en NULL el material
        Transitable();

        //PRE: Recibe su tipo de casiiler y un material
        //POS: Construye el Transitable asignando los valores según corresponda
        Transitable(char,Material*);

        //PRE: Recibe su tipo de caisllero
        //POS: Construye el Transitable solo con el tipo de casillero 
        Transitable(char);

        //PRE:
        //POS: Libera la memoria del material
        ~Transitable();

        //PRE:
        //POS: Retorna el material o NULL según sea el caso
        Material* getMaterial();

        //PRE: Recibe un material
        //POS: Actualiza el material con el argumento pasado
        void setMaterial(Material*);

        //PRE: Recibe un edificio
        //POS: Retorna ERROR(-1) mostrando que no puede construir el edificio
        int construirEdificio(Edificio*);

        //PRE: Recibe un Material 
        //POS: Retorna 0(EXITO) si el lugar está vacío y además contruye correctamente, caso contrario retorna -1(ERROR)
        int construirMaterial(Material*);

        //PRE:
        //POS: Retorna NULL porque no sabe responder exactamente a este mensaje
        Edificio* getEdificio();

        //PRE:
        //POS: Muestra el mensaje que es otro casillero y retorna NULL
        Edificio* demolerEdificio();

        //PRE:
        //POS: Se muestra a si mismo y además llama para que se muestre el material
        void mostrar();
};

#endif //TRANSITABLE_H