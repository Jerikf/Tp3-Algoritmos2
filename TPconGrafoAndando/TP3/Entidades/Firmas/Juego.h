#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "../../Datos/Firmas/Datos.h"


class Juego{

    private:

    Datos datos;
    
    public:


    // PRE: -
    // POST: Inicializa los datos del juego.
    void obtener_datos();

    // PRE: -
    // POST: Muestra por pantalla el primer menu del juego.
    void generar_primer_menu();

    // PRE: -
    // POST: Muestra por pantalla el segundo menu del juego.
    void generar_segundo_menu();

    // PRE: -
    // POST: Vuelve al menu.
    void volver_menu();

    // PRE: -
    // POST: Genera las opciones del los menus.
    void generar_opciones();

    // PRE: -
    // POST: Inicialza el juego.
    void inicializar_juego();

    // PRE: -
    // POST: Limpia la memoria dinamica restante del programa.
    void limpiar_memoria();


};

#endif //Juego_H_INCLUDED