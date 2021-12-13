#include "../../Entidades/Firmas/Mina.h"
#include <iostream>
#include "../../Entidades/Firmas/constantes.h"

using namespace std;

void Mina::mostrar(){
    
    Edificio::mostrar();
    cout << "Produccion: " << endl;
    cout << "Produce 15 de piedra." << endl;
    cout << "No prodeuce andycoins. " << endl;
    cout << endl;

}

Mina::Mina(string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios) : Edificio(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios){

}

Mina::~Mina(){}

char Mina::devolver_abreviatura(){
    return CARACTER_MINA;
}