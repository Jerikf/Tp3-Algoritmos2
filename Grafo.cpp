#include "Grafo.h"

/*Grafo::Grafo(){
    this->matriz_adyacencia = nullptr;
    this->vertices = -1;
}*/

void Grafo::cargar_vertices( int filas, int columnas){
    int contador = 0;
    for( int i = 0; i < filas; i++ ){
        for( int j = 0; j < columnas; j++ ){
            this->vertices[contador].setFila(i);
            this->vertices[contador].setColumna(j);
            contador++;
        }
    }
}

void Grafo::inicializar_matriz_adyacencia(){
    this->matriz_adyacencia = new int*[this->cant_vertices];
    for( int i = 0; i < this->cant_vertices; i++ ){
        this->matriz_adyacencia[i] = new int[this->cant_vertices];
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

void Grafo::cargar_matriz_adyacencia( /*Casillero *** mapa*/ ){
    for( int i = 0; i < this->cant_vertices; i++ ){
        for( int j = i; j < this->cant_vertices; j++ ){
            if( vertices_son_adyacentes( this->vertices[i], this->vertices[j] )){
                matriz_adyacencia[i][j] = 1;
                matriz_adyacencia[j][i] = 1;
            }
            else{
                matriz_adyacencia[i][j] = 0;
                matriz_adyacencia[j][i] = 0;
            }
        }
    }
}

Grafo::Grafo( int filas, int columnas/*, Casillero *** mapa*/ ){
    this->cant_vertices = filas * columnas;
    this->vertices = new Coordenada[this->cant_vertices];
    // TODO esto tambien seria de la lista
    cargar_vertices(filas, columnas);
    inicializar_matriz_adyacencia();
    cargar_matriz_adyacencia( /*mapa*/ );

}

void Grafo::imprimir_matriz_adyacencia(){
    for( int i = 0; i < this->cant_vertices; i++ ){
        for( int j = 0; j < this->cant_vertices; j++ ){
            cout << this->matriz_adyacencia[i][j] << " ";
        }
        cout << endl;
    }
}

Grafo::~Grafo(){
    for( int i = 0; i < this->cant_vertices; i++ ){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;

    delete[] vertices;
}