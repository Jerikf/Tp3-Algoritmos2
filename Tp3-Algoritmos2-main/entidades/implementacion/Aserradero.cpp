#include "../firmas/Aserradero.h"
#include <iostream>

void Aserradero::mostrar(){
    Edificio::mostrar();
    cout << "        MATERIAL BRINDADO | CANTIDAD : MADERA 25" << endl;
    cout << endl;
}

Aserradero::Aserradero(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){

}

Aserradero::~Aserradero(){}

char Aserradero::getAbreviaturaDeNombre(){
    return ASERRADERO_ABREVIATURA;
}