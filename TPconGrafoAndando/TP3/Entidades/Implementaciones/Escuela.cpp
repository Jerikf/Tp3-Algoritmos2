#include "../../Entidades/Firmas/Escuela.h"
#include <iostream>
#include "../../Entidades/Firmas/constantes.h"

using namespace std;

void Escuela::mostrar(){
    
    Edificio::mostrar();
    cout << "Produccion: " << endl;
    cout << "No produce materiales." << endl;
    cout << "Produce 25 andycoins. " << endl;
    cout << "No produce energia. " << endl;
    cout << endl;
}

Escuela::Escuela(string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios) : Edificio(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios){

}

Escuela::~Escuela(){}

char Escuela::devolver_abreviatura(){
    return CARACTER_ESCUELA;
}