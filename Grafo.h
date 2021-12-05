#ifndef GRAFO_H
#define GRAFO_H
#include "./entidades/firmas/Mapa.h"
#include "./entidades/firmas/Coordenada.h"
#include <iostream>

using namespace std;

class Grafo{

private:
    //Atributos
    int ** matriz_adyacencia;
    //TODO esto debería ser una lista
    Coordenada * vertices;
    int cant_vertices;

    //Metodos
    void cargar_vertices(int filas, int columnas);
    void inicializar_matriz_adyacencia();
    bool vertices_son_adyacentes( Coordenada coordenada1, Coordenada coordenada2 );
    void cargar_matriz_adyacencia( /*Casillero *** mapa*/);

public:
    //Grafo();

    // pre: el mapa debe estar cargado correctamente
    // post: crea un grafo con la matriz de adyacencia inicializada
    Grafo( int filas, int columnas/*, Casillero *** mapa*/ );

    void imprimir_matriz_adyacencia();

    ~Grafo();

};

#endif // GRAFO_H