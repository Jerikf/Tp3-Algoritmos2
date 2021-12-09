#include "./Entidades/Firmas/Juego.h"

int main(){

    Juego juego;
    juego.obtener_datos();
    juego.inicializar_juego();
    juego.limpiar_memoria();

    return 0;
}

//para compilar
//g++ -g ./Datos/Implementaciones/* ./Entidades/Implementaciones/* ./Estructuras/Firmas/* ./grafo/* main.cpp -o tp -Werror -Wall -Wconversion
//para correr
//valgrind --tool=memcheck --leak-check=yes --leak-check=full --track-origins=yes ./tp
