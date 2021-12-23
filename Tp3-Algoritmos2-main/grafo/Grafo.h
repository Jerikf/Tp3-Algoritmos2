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

    //pre:-
    //post: se van a cargar los vertices con sus coordenadas
    void cargar_vertices(int filas, int columnas);

    //pre: el mapa tiene que estar cargado correctamente
    //post: se cargaran los vertices con el tipo de terreno dependiendo del mapa
    void cargar_tipo_terreno(Mapa * mapa);

    //pre:-
    //post: se reserva la memoria de la matriz de adyacencia
    void inicializar_matriz_adyacencia();

    //pre:-
    //post: devuelve true si las coordenadas son adyacentes, false en caso contrario
    bool vertices_son_adyacentes( Coordenada coordenada1, Coordenada coordenada2 );

    //pre: jugador debe ser 1 o 2 y la posicion del vertice mayor a 0 y menor que la cantidad de vertices
    //post: devuelve el peso de la arista dependiendo del jugador y del terreno
    int determinar_peso_arista( int posicion_vertice, int jugador );

    //pre: el jugador debe ser 1 o 2
    //post: se cargara la matriz de adyacencia con los pesos de aristas correspondientes si son adyacentes y -1 si no son adyacentes
    void cargar_matriz_adyacencia(int jugador);

    //pre:-
    //post: devuelve la posicion del vertice
    int obtener_posicion_vertice(Coordenada coordenada);



public:
    // pre: el mapa debe estar cargado correctamente
    // post: crea un grafo con la matriz de adyacencia del mapa inicializada dependiendo del jugador
    Grafo( Mapa * mapa, int jugador);

    //pre: el mapa debe ser dek mismo tamanio que con el que se inicializo
    //post: se actualiza el grafo con los datos del mapa
    void actualizar_grafo( Mapa * mapa );

    //pre: el grafo tiene que estar actualizado o va a devolver un costo desactualizado
    //post: devuelve el costo de recorrer el camino minimo desde el punto inicial al final
    int obtenerCostoCamino(Coordenada puntoInicial, Coordenada puntoFinal);

    //pre: el grafo tiene que estar actualizado o el camino puede no ser el de minimo costo
    //post: devuelve un vector de coordenadas cargado con el recorrido del camino minimo, cargando el tope y el costo
    Coordenada * obtener_camino_minimo(Coordenada punto_inicial, Coordenada punto_final, int * tope_camino, int * costo_camino);

    ~Grafo();

};

#endif // GRAFO_H