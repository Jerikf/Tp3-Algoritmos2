#include "../firmas/Escuela.h"
#include <iostream>

void Escuela::mostrar(){
    Edificio::mostrar();
    cout << "        MATERIAL BRINDADO : NO BRINDA" << endl;
    cout << "        Vida: 1 bomba." << endl;
    cout << endl;
}

Escuela::Escuela(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){
    setVida();
}

Escuela::~Escuela(){}

char Escuela::getAbreviaturaDeNombre(){
    return ESCUELA_ABREVIATURA;
}

void Escuela::setVida(){

    cantVida = 1;
}
