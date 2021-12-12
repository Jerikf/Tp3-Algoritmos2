#include "../firmas/Escuela.h"
#include <iostream>

void Escuela::mostrar(){
    Edificio::mostrar();
    cout << "        MATERIAL BRINDADO : NO BRINDA" << endl;
}

Escuela::Escuela(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){

}

Escuela::~Escuela(){}

char Escuela::getAbreviaturaDeNombre(){
    return ESCUELA_ABREVIATURA;
}
