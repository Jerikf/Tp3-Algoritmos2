#include "../firmas/Mina.h"
#include <iostream>

void Mina::mostrar(){
    Edificio::mostrar();
    cout << "        MATERIAL BRINDADO | CANTIDAD : PIEDRA 15" << endl;
}

Mina::Mina(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){

}

Mina::~Mina(){}

char Mina::getAbreviaturaDeNombre(){
    return MINA_ABREVIATURA;
}