#ifndef GRAFO_H
#define GRAFO_H
#include "../Entidades/Firmas/Mapa.h"
#include "../Entidades/Firmas/Coordenada.h"
#include "../Entidades/Firmas/Casillero.h"
#include "Vertice.h"
#include "Floyd.h"
#include <iostream>

using namespace std;

class Grafo{

private:
    //Atributos
    int ** matriz_adyacencia;
    Vertice * vertices;
    int cant_vertices;
    Floyd * algoritmo_camino_minimo;

    //Metodos
    void cargar_vertices(int filas, int columnas);
    void cargar_tipo_terreno(Mapa * mapa);
    void inicializar_matriz_adyacencia();
    bool vertices_son_adyacentes( Coordenada coordenada1, Coordenada coordenada2 );
    int determinar_peso_arista( int posicion_vertice );
    void cargar_matriz_adyacencia();
    int obtener_posicion_vertice(Coordenada coordenada);

public:
    // pre: el mapa debe estar cargado correctamente
    // post: crea un grafo con la matriz de adyacencia del mapa inicializada
    Grafo( Mapa * mapa );

    //ToDo ==> esto deberia devolver un vector de coordenadas al jugador para que sepa como moverse
    void obtener_camino_minimo(Coordenada punto_inicial, Coordenada punto_final);

    ~Grafo();

};

#endif // GRAFO_H