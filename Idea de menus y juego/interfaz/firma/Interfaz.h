#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "../../entidades/firmas/Juego.h"


class Interfaz
{
    private:
        Juego* juego;

        //PRE: Recibe una opción del menu(tiene que ser un entero)
        //POS: Valida la opción que esté en ese rango
        bool validarOpcion(int);

        //PRE:
        //POS: pide al usuario una opcion, retornará la opcion ya validada.
        int obtenerOpcion();

    public:

        //PRE: Recibe un juego, 
        //POS: Construye la interfaz, instancia el argumento pasado con el atributo
        Interfaz(Juego*);

        //PRE:
        //POS: Destructor
        ~Interfaz();

        //PRE:
        //POS: Inicializa el programa, donde se comenzará a escoger opciones del menu
        void iniciar_segundo_menu(int numero);
        
        // PRE: -
        // POST: Inicialza el primer menu del juego.
        void iniciar_primer_menu();




};

#endif //INTERFAZ_H