#include "../Firmas/Coordenada.h"
#include <iostream>

Coordenada::Coordenada(int fila, int columna){
    this->fila = fila;
    this->columna = columna;
}
Coordenada::Coordenada(){}

Coordenada::~Coordenada(){}

int Coordenada::getFila(){
    return this->fila;
}

int Coordenada::getColumna(){
    return this->columna;
}

void Coordenada::setFila(int fila){
    this->fila = fila;
}

void Coordenada::setColumna(int columna){
    this->columna = columna;
}

void Coordenada::mostrar(){
    cout << "Fila: " << this->fila << " Columna: " << this->columna << endl; 
}