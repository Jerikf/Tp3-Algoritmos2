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

        //PRE: El numero de jugador es igual a 1 o 2.
        //POS: Inicializa el programa, donde se comenzará a escoger opciones del menu
        int iniciar_segundo_menu(int numero_jugador);
        
        //PRE: El numero de jugador es igual a 1 o 2.
        //POS: Establece la ubicacion del personaje en el mapa.
        void establecer_posicion_personaje(int numero_jugador);
        
        // PRE: El numero de jugador es igual a 1 o 2.
        // POS: Determina que jugador es el usuario.
        void establecer_jugadores(int numero_jugador);

        // PRE: El jugador esta cargado.
        // POS: Devuelve true si alcanza la cantidad de energia para la opcion, false en caso contrario
        bool verificar_energia(Jugador* jugador, int opcion);

        // PRE: Las opciones son validas y el jugador esta cargado.
        // POS: Dependiendo de la opcion , modifca la cantidad de energia del jugador.
        void modificar_energia(Jugador* jugador, int opcion);

        void seleccionar_jugador_energia(int jugador_numero, int opcion);
        
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