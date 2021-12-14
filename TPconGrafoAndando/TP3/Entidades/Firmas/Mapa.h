#ifndef MAPA_H
#define MAPA_H

#include "Casillero.h"
#include "Coordenada.h"

class Mapa{
   
    private:
        
    int cant_filas;
    int cant_columnas;
    Casillero*** casilleros;

    public:

    //PRE: Recibe la cantidad de filas y columnas
    //POST: Construye el mapa reservando memoria dinámica de casilleros según los parámetros pasados(para el tamaño), además inicializa todos en null
    Mapa(int cant_filas, int cant_columnas);

    //PRE:
    //POST: Muestra el mapa
    void mostrar();

    //PRE: Recibe un casillero y una coordenada
    //POST: Agrega el casillero si la coordeanda es válida
    void agregar_casillero(Casillero*, Coordenada);

    //PRE: Recibe una coordenda
    //POST: Devuelve el casillero que se encuentra en dicha coordeanda(en caso de ser válida)
    Casillero* getCasillero(Coordenada);

    //PRE: Recibe un Tipo de casillero
    //POST: Devuelve la cantidad de casilleros del mapa, según el tipo de casillero que sea pasado por parámetro
    int obtenerCantDeCasilleros(char);

    //PRE: -
    //POS: Retorna la cantidad de filas
    int devolver_cant_filas();

    //PRE: -
    //POST: Retorna la canti de columnas
    int devolver_cant_columnas();

    //PRE:
    //POST:Libera la memoria de todos los casilleros guardados 
    ~Mapa();
};

#endif //MAPA_H