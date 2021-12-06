#include "../../Entidades/Firmas/Mina_oro.h"
#include <iostream>

using namespace std;

Mina_oro::Mina_oro(string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edifios) : Edificio(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edifios){

}

void Mina_oro::mostrar(){

    Edificio::mostrar();
    cout << "No produce materiales." << endl;
    cout << "Prodeuce 50 andycoins." << endl;
    cout << "No produce energia." << endl;
}

Mina_oro::~Mina_oro(){}