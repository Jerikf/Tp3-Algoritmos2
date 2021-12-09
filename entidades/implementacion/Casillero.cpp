#include "../firmas/Casillero.h"

const int NO_HAY_JUGADOR = 0;

Casillero::Casillero(char tipo){
    jugador = NO_HAY_JUGADOR;
    this->tipo = tipo;
}

Casillero::~Casillero(){}

Casillero::Casillero(){
    jugador = NO_HAY_JUGADOR;
}

void Casillero::jugador_entra_casillero(int jugador){
    this->jugador = jugador;
}

int Casillero::devolver_jugador_casillero(){
    return jugador;
}

void Casillero::jugador_deja_casillero(){
    jugador = NO_HAY_JUGADOR;
}

char Casillero:: getTipo(){
    return this->tipo;
}

void Casillero::setTipo(char tipo){
    this->tipo = tipo;
}