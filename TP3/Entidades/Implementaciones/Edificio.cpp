#include "../../Entidades/Firmas/Edificio.h"
#include <iostream>

using namespace std;

void Edificio::mostrar(){

    cout << "Nombre: " << nombre_edificio << endl;
    cout << "Cantidad de materiales: " << endl;
    cout << "Piedra: " << cant_piedra << endl;
    cout << "Madera: " << cant_madera << endl;
    cout << "Metal: " << cant_metal << endl;
    cout << endl;
}

Edificio::Edificio(string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios){
   
    this->nombre_edificio = nombre_edificio;
    this->cant_piedra = cant_piedra;
    this->cant_madera = cant_madera;
    this->cant_metal = cant_metal;
    this->cant_max_edificios = cant_max_edificios;
}

void Edificio::obtener_edificio(string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios){
    
    this->nombre_edificio = nombre_edificio;
    this->cant_piedra = cant_piedra;
    this->cant_madera = cant_madera;
    this->cant_metal = cant_metal;
    this->cant_max_edificios = cant_max_edificios;
}

Edificio::~Edificio(){}


string Edificio::devolver_nombre(){
    return this-> nombre_edificio;
}

int Edificio::devolver_piedra(){
    return this-> cant_piedra;
}

int Edificio::devolver_madera(){
    return this-> cant_madera;
}

int Edificio::devolver_metal(){
    return this-> cant_metal;
}

int Edificio::devolver_cant_maxima_edificios(){
    return this-> cant_max_edificios;
}



