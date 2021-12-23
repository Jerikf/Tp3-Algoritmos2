#include "../firmas/Inaccesible.h"
#include <iostream>

const int ERROR = -1;

Inaccesible::Inaccesible() : Casillero(){}
Inaccesible::Inaccesible(char tipo) : Casillero(tipo){}
Inaccesible::~Inaccesible(){}
void Inaccesible::mostrar(){
    cout << "\n\n\n|----------------------------------------------------|" << endl;
    cout << "   SOY VACÌO --> SOY UN CASILLERO INACCESIBLE" << endl;
    cout << "|----------------------------------------------------|" << endl;
}
int Inaccesible::construirEdificio(Edificio* edificio){
    cout << "\n\n\n ERROR --> NO SE PUEDE CONSTRUIR EDIFICIO PORQUE SOY UN : CASILLERO INACCESIBLE\n" << endl;
    return ERROR;
}
Edificio* Inaccesible::getEdificio(){
    return NULL;
}

Material* Inaccesible::getMaterial(){
    return NULL;
}

Material* Inaccesible::recolectarMaterial(){
    return NULL;
}

Edificio* Inaccesible::demolerEdificio(){
    cout << "\n\n\n ERROR-> NO SE PUEDE DEMOLER EL EDIFICIO PORQUE SOY UN : CASILLERO INACCESIBLE" << endl;
    return NULL;
}

int Inaccesible::construirMaterial(Material* material){
    return ERROR;
}