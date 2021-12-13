#ifndef CONSTRUIBLE_H
#define CONSTRUIBLE_H

#include "Casillero.h"

class Construible : public Casillero
{
    private:
        Edificio* edificio;

    public:

        //PRE:
        //POS: Construye el casillero Construille asignandole NULL al edificio
        Construible();

        //PRE:
        //POS: Construye el casillero Construible asignando el tipo y edificios a sus atributos
        Construible(char,Edificio*);

        //PRE: Recibe un Material 
        //POS: Retorna -1(ERROR) porque no puede contruir un material en este casillero
        int construirMaterial(Material*);

        //PRE:
        //POS: Construye el casillero construible asigna el tipo de edificio a su padre y pone en NULL al edificio
        Construible(char);

        //PRE:
        //POS:Libera la memoria del edificio
        ~Construible();

        //PRE:
        //POS:Muestra quién es y llama a mostrar del edificio
        void mostrar();

        //PRE: Recibe un Edificio
        //POS: Consruye el edificio, si está vacio lo construye y devuelve 0 caso contrario -1
        //     Construye según sea el edifcio generando una nueva instancia    
        int construirEdificio(Edificio*);

        //PRE:
        //POS: Retorna el edificio contenido o null caso que esté vacio
        Edificio* getEdificio();

        //PRE:
        //POS: Retorna NULL porque no sabe responder a este mensaje
        Material* getMaterial();

        //PRE:
        //POS: Demuele un edificio(instancia el puntero de edificio en null) retornando el edificio apuntado
        Edificio* demolerEdificio();
        
};

#endif //CONSTRUIBLE_H