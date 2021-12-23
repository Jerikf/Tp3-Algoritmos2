#ifndef VERTICE_H
#define VERTICE_H
#include "../entidades/firmas/Coordenada.h"

class Vertice{
private:
    Coordenada coordenada;
    char tipo_terreno;

public:
    //constructor por defecto vertice
    Vertice();

    //pre:-
    //post: carga la coordenada al vertice
    void cargar_coordenada(Coordenada coordenada);

    //pre:-
    //post: carga la coordenada al vertice
    void cargar_coordenada(int fila, int columna);

    //pre:-
    //post: carga el tipo de terreno al vertice
    void cargar_tipo_terreno(char tipo_terreno);

    //pre:-
    //post: devuelve la coordenada del vertice
    Coordenada obtener_coordenada();

    //pre:-
    //post: devuelve el tipo de terreno del vertice
    char obtener_tipo_terreno();
};

#endif // VERTICE_H