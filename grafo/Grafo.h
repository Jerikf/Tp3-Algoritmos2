#ifndef GRAFO_H
#define GRAFO_H
#include "../entidades/firmas/Mapa.h"
#include "../entidades/firmas/Coordenada.h"
#include "../entidades/firmas/Casillero.h"
#include "Vertice.h"
#include "Floyd.h"
#include <iostream>

using namespace std;

class Grafo{

private:
    //Atributos
    int jugador;
    int ** matriz_adyacencia;
    Vertice * vertices;
    int cant_vertices;
    Floyd * algoritmo_camino_minimo;

    //Metodos
    void cargar_vertices(int filas, int columnas);
    void cargar_tipo_terreno(Mapa * mapa);
    void inicializar_matriz_adyacencia();
    bool vertices_son_adyacentes( Coordenada coordenada1, Coordenada coordenada2 );
    int determinar_peso_arista( int posicion_vertice, int jugador );
    void cargar_matriz_adyacencia(int jugador);
    int obtener_posicion_vertice(Coordenada coordenada);

public:
    // pre: el mapa debe estar cargado correctamente
    // post: crea un grafo con la matriz de adyacencia del mapa inicializada dependiendo del jugador
    Grafo( Mapa * mapa, int jugador);

    void actualizar_grafo( Mapa * mapa );

    //ToDo --> el vector de coordenadas se crea dinamicamente pero el jugador se tiene que encargar de
    //ToDo --> eliminarlo cada vez que lo usa, lo deberia eliminar grafo (2 formas o paso puntero por parametro o lo guardo como atributo, o no se encarga)
    Coordenada * obtener_camino_minimo(Coordenada punto_inicial, Coordenada punto_final, int * tope_camino, int * costo_camino);

    ~Grafo();

};

#endif // GRAFO_H