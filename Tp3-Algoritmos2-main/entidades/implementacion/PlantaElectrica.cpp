#include "../firmas/PlantaElectrica.h"
#include <iostream>

void PlantaElectrica::mostrar(){
    Edificio::mostrar();
    cout << "        MATERIAL BRINDADO : NO BRINDA" << endl;
    cout << "        Vida: 1 bomba." << endl;
    cout << endl;
}

PlantaElectrica::PlantaElectrica(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){
    setVida();
}

PlantaElectrica::~PlantaElectrica(){}

char PlantaElectrica::getAbreviaturaDeNombre(){
    return PLATAN_ELECTRICA_ABREVIATURA;
}

void PlantaElectrica::setVida(){

    cantVida = 1;
}