#include "Grafo.h"

const char TERRENO = 'T';
const char CAMINO = 'C';
const char LAGO = 'L';
const char MUELLE = 'M';
const char BETUN = 'B';

//estas constantes deberian ir en la clase jugador creo pero por ahora quedan aca
//tambien hay que ajustar valores dependiendo de si es el jugador 1 o 2
const int COSTO_TRANSITO_CAMINO = 4;
const int COSTO_TRANSITO_BETUN = 0;
const int COSTO_TRANSITO_TERRENO = 25;
const int COSTO_TRANSITO_LAGO = 5;
const int COSTO_TRANSITO_MUELLE = 2;


void Grafo::cargar_vertices( int filas, int columnas){
    int contador = 0;
    for( int i = 0; i < filas; i++ ){
        for( int j = 0; j < columnas; j++ ){
            vertices[contador].cargar_coordenada(i, j);
            contador++;
        }
    }
}

void Grafo::cargar_tipo_terreno(Mapa * mapa){
    int contador = 0;
    Casillero * casillero_actual;
    Coordenada coordenada_actual;
    for( int i = 0; i < mapa->devolver_cant_filas(); i++ ){
        for( int j = 0; j < mapa->devolver_cant_columnas(); j++ ){
            coordenada_actual.setFila(i);
            coordenada_actual.setColumna(j);
            casillero_actual = mapa->getCasillero(coordenada_actual);
            vertices[contador].cargar_tipo_terreno( casillero_actual->getTipo());
            contador++;
        }
    }
}

void Grafo::inicializar_matriz_adyacencia(){
    matriz_adyacencia = new int*[cant_vertices];
    for( int i = 0; i < cant_vertices; i++ ){
        matriz_adyacencia[i] = new int[cant_vertices];
    }
}

bool Grafo::vertices_son_adyacentes( Coordenada coordenada1, Coordenada coordenada2 ){
    bool son_adyacentes = false;
    if( ((coordenada1.getFila() == coordenada2.getFila()) && ((coordenada1.getColumna()+1) == coordenada2.getColumna())) ||
        ((coordenada1.getFila() == coordenada2.getFila()) && ((coordenada1.getColumna()-1) == coordenada2.getColumna())) ||
        (((coordenada1.getFila()+1) == coordenada2.getFila()) && (coordenada1.getColumna() == coordenada2.getColumna())) ||
        (((coordenada1.getFila()-1) == coordenada2.getFila()) && (coordenada1.getColumna() == coordenada2.getColumna())) )
        son_adyacentes = true;

    return son_adyacentes;
}

int Grafo::determinar_peso_arista(int posicion_vertice){
    int peso_arista;
    char tipo_terreno = vertices[posicion_vertice].obtener_tipo_terreno();

    if( tipo_terreno == CAMINO )
        peso_arista = COSTO_TRANSITO_CAMINO;
    else if( tipo_terreno == BETUN )
        peso_arista = COSTO_TRANSITO_BETUN;
    else if( tipo_terreno == TERRENO )
        peso_arista = COSTO_TRANSITO_TERRENO;
    else if( tipo_terreno == LAGO )
        peso_arista = COSTO_TRANSITO_LAGO;
    else if( tipo_terreno == MUELLE )
        peso_arista = COSTO_TRANSITO_MUELLE;

    return peso_arista;
}

void Grafo::cargar_matriz_adyacencia(){
    int peso_arista;
    for( int i = 0; i < cant_vertices; i++ ){
        for( int j = 0; j < cant_vertices; j++ ){
            if( vertices_son_adyacentes( vertices[i].obtener_coordenada(), vertices[j].obtener_coordenada() )){
                peso_arista = determinar_peso_arista(j);
                matriz_adyacencia[i][j] = peso_arista;
            }
            else{
                matriz_adyacencia[i][j] = 0;
            }
        }
    }
}

Grafo::Grafo( Mapa * mapa ){
    cant_vertices = mapa->devolver_cant_filas() * mapa->devolver_cant_columnas();
    vertices = new Vertice[cant_vertices];

    cargar_vertices(mapa->devolver_cant_filas(), mapa->devolver_cant_columnas());
    cargar_tipo_terreno(mapa);
    inicializar_matriz_adyacencia();
    cargar_matriz_adyacencia();
}

void Grafo::imprimir_matriz_adyacencia(){
    for( int i = 0; i < cant_vertices; i++ ){
        for( int j = 0; j < cant_vertices; j++ ){
            cout << matriz_adyacencia[i][j] << " ";
        }
        cout << endl;
    }
}

Grafo::~Grafo(){
    for( int i = 0; i < cant_vertices; i++ ){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;

    delete[] vertices;
}