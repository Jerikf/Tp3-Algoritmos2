#include "./Entidades/Firmas/Juego.h"

int main(){

    Juego juego;
    juego.obtener_datos();
    juego.inicializar_juego();
    juego.limpiar_memoria();

    return 0;
}