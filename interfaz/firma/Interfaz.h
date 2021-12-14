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
        void volver_menu(int forma);

        //PRE: El numero de jugador es igual a 1 o 2.
        //POS: Muestra el menu de opciones
        void mostrar_segundo_menu(int numero_jugador);

        //pre: tienen que estar cargados los datos del mapa
        //post: devuelve true si la coordenada esta dentro del mapa, false en caso contrario
        bool esCoordenadaValida(Coordenada coordenada);

        //pre: el mapa debe estar cargado correctamente
        //post: se interactuara con el usuario para que elija a que casillero quiere mover al jugador. Devuelve true si es posivle mover al jugador,
        //      false en caso contrario.
        bool puedoMoverJugadorACoordenada(Coordenada puntoInicial, Coordenada* puntoFinal, Grafo* grafo, int* costoCamino, int energiaJugador);

        //pre: el mapa debe estar cargado correctamente
        //post: se interactuara con el usuario hasta que el jugador quede en una posicion valida para comenzar el juego
        void determinarPosicionJugador(int jugador);
        //PRE: -
        //PRE: El numero de jugador es igual a 1 o 2.
        //POS: Inicializa el programa, donde se comenzará a escoger opciones del menu
        int iniciar_segundo_menu(int numero_jugador);
        
        //PRE: El numero de jugador es igual a 1 o 2.
        //POS: Establece la ubicacion del personaje en el mapa.
        void establecer_posicion_personaje(int numero_jugador);
        
        // PRE: El numero de jugador es igual a 1 o 2.
        // POS: Determina que jugador es el usuario.
        void establecer_jugadores(int numero_jugador);
        
        // PRE: -
        // POS: Se encargara de ejecutar todas las funciones para que corra el juego, una vez comenzado.
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