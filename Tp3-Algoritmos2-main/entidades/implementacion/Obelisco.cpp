#include "../firmas/Obelisco.h"
#include <iostream>

void Obelisco::mostrar(){
    Edificio::mostrar();
    cout << "        MATERIAL BRINDADO : NO BRINDA" << endl;
    cout << endl;
}

Obelisco::Obelisco(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){

}

Obelisco::~Obelisco(){}

char Obelisco::getAbreviaturaDeNombre(){
    return OBELISCO_ABREVIATURA;
}