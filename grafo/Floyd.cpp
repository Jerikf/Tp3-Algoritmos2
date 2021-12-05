#include "Floyd.h"

const int INFINITO = 99999;

int** Floyd::inicializar_matriz_costos( int ** matriz_adyacencia ){
    int ** matriz_costos = new int*[cant_vertices];
    for( int i = 0; i < cant_vertices; i++ ){
        matriz_costos[i] = new int[cant_vertices];
    }

    for( int i = 0; i < cant_vertices; i++ ){
        for( int j = 0; j < cant_vertices; j++ ){
            if( i == j)
                matriz_costos[i][j] = 0;

            else if( matriz_adyacencia[i][j] != 0 )
                matriz_costos[i][j] = matriz_adyacencia[i][j];

            else matriz_costos[i][j] = INFINITO;
        }
    }
    return matriz_costos;
}

void Floyd::calcular_matriz_costos(){
    for( int k = 0; k < cant_vertices; k++ ){
        for( int i = 0; i < cant_vertices; i++ ){
            for( int j = 0; j < cant_vertices; j++ ){
                if( (matriz_costos[i][k] + matriz_costos[k][j]) < matriz_costos[i][j] ){
                    matriz_costos[i][j] = (matriz_costos[i][k] + matriz_costos[k][j]);
                }
            }
        }
    }
}

Floyd::Floyd(int ** matriz_adyacencia/*, Vertice * vertices*/, int cant_vertices){
    this->cant_vertices = cant_vertices;
    matriz_costos = inicializar_matriz_costos( matriz_adyacencia);
    calcular_matriz_costos();
}

void Floyd::imprimir_matriz_costos(){
    for( int i = 0; i < cant_vertices; i++ ) {
        for (int j = 0; j < cant_vertices; j++) {
            cout << matriz_costos[i][j] << " ";
        }
        cout << endl;
    }
}

Floyd::~Floyd(){
    for( int i = 0; i < cant_vertices; i++ ){
        delete[] matriz_costos[i];
    }
    delete[] matriz_costos;
}