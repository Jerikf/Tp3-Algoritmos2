#ifndef GRAFO_H
#define GRAFO_H
#include "../Entidades/Firmas/Mapa.h"
#include "../Entidades/Firmas/Coordenada.h"
#include "../Entidades/Firmas/Casillero.h"
#include "Vertice.h"
#include <iostream>

using namespace std;

class Grafo{

private:
    //Atributos
    int ** matriz_adyacencia;
    Vertice * vertices;
    int cant_vertices;

    //Metodos
    void cargar_vertices(int filas, int columnas);
    void cargar_tipo_terreno(Mapa * mapa);
    void inicializar_matriz_adyacencia();
    bool vertices_son_adyacentes( Coordenada coordenada1, Coordenada coordenada2 );
    int determinar_peso_arista( int posicion_vertice );
    void cargar_matriz_adyacencia();

public:
    // pre: el mapa debe estar cargado correctamente
    // post: crea un grafo con la matriz de adyacencia del mapa inicializada
    Grafo( Mapa * mapa );

    // pre: -
    // post: se imprime por pantalla la matriz de adyacencia del grafo
    void imprimir_matriz_adyacencia();

    ~Grafo();

};

#endif // GRAFO_H