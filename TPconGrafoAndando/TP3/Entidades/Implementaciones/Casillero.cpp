#include "../Firmas/Casillero.h"
#include <iostream>

Casillero::Casillero(char tipo){
    this->tipo = tipo;
}

Casillero::~Casillero(){}

Casillero::Casillero(){}

char Casillero:: getTipo(){
    return this->tipo;
}

void Casillero::setTipo(char tipo){
    this->tipo = tipo;
}