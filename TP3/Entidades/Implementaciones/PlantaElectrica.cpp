#include "../../Entidades/Firmas/PlantaElectrica.h"
#include <iostream>
#include "../../Entidades/Firmas/constantes.h"

using namespace std;

void PlantaElectrica::mostrar(){
   
    Edificio::mostrar();
    cout << endl;
    cout << "Produccion: " << endl;
    cout << "No produce materiales.." << endl;
    cout << "No prodeuce andycoins. " << endl;
    cout << "Produce 15 de energia. " << endl;
    cout << endl;
}

PlantaElectrica::PlantaElectrica(string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios) : Edificio(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios){

}

PlantaElectrica::~PlantaElectrica(){}

char PlantaElectrica::devolver_abreviatura(){
    return CARACTER_PLANTA_ELECTRICA;
}

