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
    //Coordenada ** matriz_recorrido;
    int cant_vertices;

    //Metodos
    int** inicializar_matriz_costos(int ** matriz_adyacencia);
    void calcular_matriz_costos();
public:
    Floyd(int ** matriz_adyacencia/*, Vertice * vertices*/, int cant_vertices);

    // Imprime.
    void imprimir_matriz_costos();
    
    // Destructor.
    ~Floyd();
};

#endif // FLOYD_H
