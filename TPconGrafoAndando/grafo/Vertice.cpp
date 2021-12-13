#include "Vertice.h"

Vertice::Vertice(){}

void Vertice::cargar_coordenada(Coordenada coordenada) {
    this->coordenada = coordenada;
}

void Vertice::cargar_coordenada(int fila, int columna) {
    coordenada.setFila(fila);
    coordenada.setColumna(columna);
}

void Vertice::cargar_tipo_terreno(char tipo_terreno) {
    this->tipo_terreno = tipo_terreno;
}

Coordenada Vertice::obtener_coordenada() {
    return coordenada;
}

char Vertice::obtener_tipo_terreno() {
    return tipo_terreno;
}
