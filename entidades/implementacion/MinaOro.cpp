#include "../firmas/MinaOro.h"
#include <iostream>

void MinaOro::mostrar(){
    Edificio::mostrar();
    cout << "        MATERIAL BRINDADO | CANTIDAD : ANDYCOINS 50" << endl;
    cout << endl;
}

MinaOro::MinaOro(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){

}

MinaOro::~MinaOro(){}

char MinaOro::getAbreviaturaDeNombre(){
    return MINA_ORO_ABREVIATURA;
}