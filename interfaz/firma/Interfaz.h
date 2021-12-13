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
        //POS: Incia el Primer menu y devuelve COMENZAR_PARTIDA o GUARDAR_Y_SALIR
        int iniciarMenuInicial();

        //PRE:
        //POS: Muentra un sub menu para regresar al menu
        void volver_menu();

        //PRE:
        //POS: Muestra el menu de opciones y devuelve FINALIZAR_TURNO o GUARDAR_SALIR
        void mostrar_segundo_menu();

        //pre: tienen que estar cargados los datos del mapa
        //post: devuelve true si la coordenada esta dentro del mapa, false en caso contrario
        bool esCoordenadaValida(Coordenada coordenada);

        //pre: el mapa debe estar cargado correctamente
        //post: se interactuara con el usuario y en caso de que el jugador se pueda mover lo hara por el camino de minimo costo de energia
        void moverJugadorACoordenada(int jugador);

        void determinarPosicionJugador(int jugador);
        //PRE: -
        //POS: Inicializa el programa, donde se comenzará a escoger opciones del menu
        int iniciar_segundo_menu(int jugador);

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