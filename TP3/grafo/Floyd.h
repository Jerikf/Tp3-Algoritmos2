#ifndef FLOYD_H
#define FLOYD_H
#include "../Entidades/Firmas/Coordenada.h"
#include "Vertice.h"
#include <iostream>

using namespace std;

class Floyd{
private:
    //Atributos
    int ** matriz_costos;
    //la matriz de recorrido trabaja con las posiciones de los vertices en el vector
    int ** matriz_recorrido;
    int cant_vertices;

    //Metodos
    int** inicializar_matriz_costos(int ** matriz_adyacencia);
    int** inicializar_matriz_recorrido();
    void calcular_matrices();

public:
    Floyd(int ** matriz_adyacencia, int cant_vertices);

    int* obtener_camino_minimo(int posicion_vertice_1, int posicion_vertice_2, int * tope_camino);

    ~Floyd();
};

#endif // FLOYD_H
