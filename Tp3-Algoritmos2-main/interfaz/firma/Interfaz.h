#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "../../entidades/firmas/Juego.h"


class Interfaz
{
    private:
        Juego* juego;

        //PRE: Recibe una opción del menu(tiene que ser un entero)
        //POS: Valida la opción que esté en ese rango
        bool validarOpcion(int opcion, int limiteInferior, int limiteSuperior);

        //PRE:
        //POS: pide al usuario una opcion, retornará la opcion ya validada.
        int obtenerOpcion(int limiteInferior, int limiteSuperior);

        //PRE:
        //POS: Muestra el primer Menu
        void mostrarMenuInicial();

        //PRE:
        //POS: Incia el Primer menu
        void iniciarMenuInicial();

        //PRE:
        //POS: Muentra un sub menu para regresar al menu
        void volver_menu(int numero);

        //PRE:
        //POS: Muestra el menu de opciones
        void mostrar_segundo_menu(int numero);

        //PRE:
        //POS: Inicializa el programa, donde se comenzará a escoger opciones del menu
        int iniciar_segundo_menu(int numero);

        void establecer_posicion_personaje(int jugador);

        void establecer_jugadores(int jugador);

        void correr_juego();
        
        //PRE: -
        //POS: Le pregunta al usuario si quiere ser el jugador 1 o jugador 2, despues se posicionaran a ambos jugadores en un casillero transitable del mapa.
        void elegir_personaje();

    public:

        //PRE: Recibe un juego, 
        //POS: Construye la interfaz, instancia el argumento pasado con el atributo
        Interfaz(Juego*);

        //PRE: Constructor Vacio 
        //POS: Construye la interfaz, instancia el juego
        Interfaz();

        //PRE:
        //POS: Destructor
        ~Interfaz();

        //PRE:
        //POS: Inicializa el programa, donde se comenzará a escoger opciones del menu
        void iniciar();




};

#endif //INTERFAZ_H