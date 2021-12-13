#include "../firmas/Fabrica.h"
#include <iostream>

void Fabrica::mostrar(){
    Edificio::mostrar();
    cout << "        MATERIAL BRINDADO | CANTIDAD : METALES 40" << endl;
    cout << endl;
}

Fabrica::Fabrica(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){

}

Fabrica::~Fabrica(){}

char Fabrica::getAbreviaturaDeNombre(){
    return FABRICA_ABREVIATURA;
}