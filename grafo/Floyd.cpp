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

            else if( matriz_adyacencia[i][j] != -1 )
                matriz_costos[i][j] = matriz_adyacencia[i][j];

            else matriz_costos[i][j] = INFINITO;
        }
    }
    return matriz_costos;
}

int** Floyd::inicializar_matriz_recorrido(){
    int** matriz_recorrido = new int*[cant_vertices];
    for( int i = 0; i < cant_vertices; i++ ){
        matriz_recorrido[i] = new int[cant_vertices];
    }

    for( int columna = 0; columna < cant_vertices; columna++ ){
        for( int fila = 0; fila < cant_vertices; fila++ ){
            if( columna == fila ){
                matriz_recorrido[fila][columna] = -1;
            }
            else matriz_recorrido[fila][columna] = columna;
        }
    }
    return matriz_recorrido;
}

void Floyd::calcular_matrices(){
    for( int k = 0; k < cant_vertices; k++ ){
        for( int i = 0; i < cant_vertices; i++ ){
            for( int j = 0; j < cant_vertices; j++ ){
                if( (matriz_costos[i][k] + matriz_costos[k][j]) < matriz_costos[i][j] ){
                    matriz_costos[i][j] = (matriz_costos[i][k] + matriz_costos[k][j]);
                    matriz_recorrido[i][j] = k;
                }
            }
        }
    }
}

Floyd::Floyd(int ** matriz_adyacencia, int cant_vertices){
    this->cant_vertices = cant_vertices;
    matriz_costos = inicializar_matriz_costos( matriz_adyacencia );
    matriz_recorrido = inicializar_matriz_recorrido();
    calcular_matrices();
}

int* Floyd::obtener_camino_minimo(int posicion_vertice_1, int posicion_vertice_2, int * tope_camino){
    int * camino = new int[cant_vertices];
    int * aux = new int[cant_vertices];
    int aux1 = posicion_vertice_1;
    int aux2 = posicion_vertice_2;

    //ToDo hay un problema que arma bien el camino, por ejemplo del 0,0 al 3,3 pero no del 3,3 al 0,0
    //Todo ==> lo que hago es darlo vuelta por que asi lo calcula bien
    //Todo ==> tampoco imprime bien si voy de 0,3 a 3,0 en ningun sentido,se saltea una parte del camino
    if( posicion_vertice_1 > posicion_vertice_2 ){
        posicion_vertice_1 = posicion_vertice_2;
        posicion_vertice_2 = aux1;
    }

    //aca carga el recorrido desde el final hasta el principio
    (*tope_camino) = 0;
    while( posicion_vertice_1 != posicion_vertice_2 ){
        camino[(*tope_camino)] = posicion_vertice_2;
        posicion_vertice_2 = matriz_recorrido[posicion_vertice_2][posicion_vertice_1];
        (*tope_camino)++;
    }
    camino[(*tope_camino)] = posicion_vertice_1;

    //aca guarda las posiciones dependiendo del sentido en el que se mueva
    if( aux1 < aux2) {
        for (int i = 0; i < (*tope_camino); i++) {
            aux[i] = camino[(*tope_camino) - i];
        }
    }
    else{
        for (int i = 0; i < (*tope_camino); i++) {
            aux[i] = camino[i];
        }
    }
    aux[(*tope_camino)] = aux2;
    (*tope_camino)++;
    delete[] camino;

    return aux;
}

Floyd::~Floyd(){
    for( int i = 0; i < cant_vertices; i++ ){
        delete[] matriz_costos[i];
        delete[] matriz_recorrido[i];
    }
    delete[] matriz_costos;
    delete[] matriz_recorrido;
}