#include "../../Entidades/Firmas/Obelisco.h"
#include <iostream>
#include "../../Entidades/Firmas/constantes.h"

using namespace std;

void Obelisco::mostrar(){
    
    Edificio::mostrar();
    cout << endl;
    cout << "Produccion: " << endl;
    cout << "No produce materiales" << endl;
    cout << "No prodeuce andycoins. " << endl;
    cout << "No produce energia." << endl;
    cout << endl;
}

Obelisco::Obelisco(string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios) : Edificio(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios){

}

Obelisco::~Obelisco(){}

char Obelisco::devolver_abreviatura(){
    return CARACTER_OBELISCO;
}
