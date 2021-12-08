#include "../../Entidades/Firmas/Fabrica.h"
#include <iostream>
#include "../../Entidades/Firmas/constantes.h"

using namespace std;

void Fabrica::mostrar(){
    
    Edificio::mostrar();
    cout << "Produccion: " << endl;
    cout << "Produce 40 de metal." << endl;
    cout << "No produuce andycoins. " << endl;
    cout << "No produce energia. " << endl;
    cout << endl;
}

Fabrica::Fabrica(string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios) : Edificio(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios){

}

Fabrica::~Fabrica(){}

char Fabrica::devolver_abreviatura(){
    return CARACTER_FABRICA;
}