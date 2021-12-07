#include "../../Entidades/Firmas/Aserradero.h"
#include <iostream>
#include "../../Entidades/Firmas/constantes.h"

using namespace std;

void Aserradero::mostrar(){
   
    Edificio::mostrar();
    cout << "Produccion: " << endl;
    cout << "Produce 25 de madera." << endl;
    cout << "No prodeuce andycoins. " << endl;
    cout << "No produce energia." << endl;
    cout << endl;
}

Aserradero::Aserradero(string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios) : Edificio(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios){

}

Aserradero::~Aserradero(){}

char Aserradero::getAbreviaturaDeNombre(){
    return CARACTER_ASERRADERO;
}
