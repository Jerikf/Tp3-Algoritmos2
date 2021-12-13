#include "Grafo.h"

const char TERRENO = 'T';
const char CAMINO = 'C';
const char LAGO = 'L';
const char MUELLE = 'M';
const char BETUN = 'B';
const char CASILLERO_OCUPADO = 'X';

//estas constantes deberian ir en la clase jugador creo pero por ahora quedan aca
//tambien hay que ajustar valores dependiendo de si es el jugador 1 o 2
const int JUGADOR1 = 1;
const int JUGADOR2 = 2;
const int COSTO_TRANSITO_CAMINO = 4;
const int COSTO_TRANSITO_BETUN = 0;
const int COSTO_TRANSITO_TERRENO = 25;
const int COSTO_TRANSITO_LAGO_JUGADOR1 = 2;
const int COSTO_TRANSITO_LAGO_JUGADOR2 = 5;
const int COSTO_TRANSITO_MUELLE_JUGADOR1 = 5;
const int COSTO_TRANSITO_MUELLE_JUGADOR2 = 2;
const int COSTO_CASILLERO_OCUPADO = 99999;


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
    for( int i = 0; i < mapa->getCantFilas(); i++ ){
        for( int j = 0; j < mapa->getCantColumnas(); j++ ){
            coordenada_actual.setFila(i);
            coordenada_actual.setColumna(j);
            casillero_actual = mapa->getCasillero(coordenada_actual);
            if( !casillero_actual->getEdificio() && casillero_actual->devolver_jugador_casillero() != 0)
                vertices[contador].cargar_tipo_terreno( CASILLERO_OCUPADO);

            else vertices[contador].cargar_tipo_terreno( casillero_actual->getTipo());
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

int Grafo::determinar_peso_arista(int posicion_vertice, int jugador){
    int peso_arista;
    char tipo_terreno = vertices[posicion_vertice].obtener_tipo_terreno();

    if( tipo_terreno == CAMINO )
        peso_arista = COSTO_TRANSITO_CAMINO;
    else if( tipo_terreno == BETUN )
        peso_arista = COSTO_TRANSITO_BETUN;
    else if( tipo_terreno == TERRENO )
        peso_arista = COSTO_TRANSITO_TERRENO;
    else if( tipo_terreno == LAGO && jugador == JUGADOR1 )
        peso_arista = COSTO_TRANSITO_LAGO_JUGADOR1;
    else if( tipo_terreno == LAGO && jugador == JUGADOR2 )
        peso_arista = COSTO_TRANSITO_LAGO_JUGADOR2;
    else if( tipo_terreno == MUELLE && jugador == JUGADOR1 )
        peso_arista = COSTO_TRANSITO_MUELLE_JUGADOR1;
    else if( tipo_terreno == MUELLE && jugador == JUGADOR2 )
        peso_arista = COSTO_TRANSITO_MUELLE_JUGADOR2;
    else if( tipo_terreno == CASILLERO_OCUPADO )
        peso_arista = COSTO_CASILLERO_OCUPADO;

    return peso_arista;
}

void Grafo::cargar_matriz_adyacencia(int jugador){
    int peso_arista;
    for( int i = 0; i < cant_vertices; i++ ){
        for( int j = 0; j < cant_vertices; j++ ){
            if( vertices_son_adyacentes( vertices[i].obtener_coordenada(), vertices[j].obtener_coordenada() )){
                peso_arista = determinar_peso_arista(j, jugador);
                matriz_adyacencia[i][j] = peso_arista;
            }
            else{
                matriz_adyacencia[i][j] = -1;
            }
        }
    }
}

Grafo::Grafo( Mapa * mapa, int jugador ){
    cant_vertices = mapa->getCantFilas() * mapa->getCantColumnas();
    vertices = new Vertice[cant_vertices];
    this->jugador = jugador;

    cargar_vertices(mapa->getCantFilas(), mapa->getCantColumnas());
    cargar_tipo_terreno(mapa);
    inicializar_matriz_adyacencia();
    cargar_matriz_adyacencia(jugador);

    algoritmo_camino_minimo = new Floyd(matriz_adyacencia, cant_vertices);
    cout << endl;
}

void Grafo::actualizar_grafo(Mapa * mapa){
    cargar_tipo_terreno(mapa);
    cargar_matriz_adyacencia(jugador);
    algoritmo_camino_minimo->actualizar_matrices(matriz_adyacencia);
}

int Grafo::obtener_posicion_vertice(Coordenada coordenada){
    int posicion = -1;
    bool encontro_vertice = false;
    int i = 0;
    Coordenada coordenada_actual;
    while( !encontro_vertice && (i < cant_vertices)){
        coordenada_actual = vertices[i].obtener_coordenada();
        if((coordenada_actual.getFila() == coordenada.getFila()) && (coordenada_actual.getColumna() == coordenada.getColumna())){
            posicion = i;
            encontro_vertice = true;
        }
        i++;
    }
    return posicion;
}

Coordenada * Grafo::obtener_camino_minimo(Coordenada punto_inicial, Coordenada punto_final, int * tope_camino, int * costo_camino){
    int posicion_vertice_1 = obtener_posicion_vertice(punto_inicial);
    int posicion_vertice_2 = obtener_posicion_vertice(punto_final);

    int * camino = algoritmo_camino_minimo->obtener_camino_minimo(posicion_vertice_1, posicion_vertice_2, tope_camino, costo_camino);

    Coordenada * coordenadas_camino = new Coordenada[(*tope_camino)];

    for( int i = 0; i < (*tope_camino); i++ ){
        coordenadas_camino[i] = vertices[camino[i]].obtener_coordenada();
    };
    delete[] camino;
    return coordenadas_camino;
}

Grafo::~Grafo(){
    for( int i = 0; i < cant_vertices; i++ ){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
    delete[] vertices;
    delete algoritmo_camino_minimo;
}