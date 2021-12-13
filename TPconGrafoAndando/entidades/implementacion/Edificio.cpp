#include "../firmas/Edificio.h"
#include "../../recursos/firmas/Recursos.h"
#include <iostream>


void Edificio::mostrar(){
    Recurso recurso;
    //cout << "\n\n"; 
	//cout << "|---------------------------------------------|" << endl;
	cout << "		"<< recurso.convertirAMayuscula(this->nombre) << endl;
	cout << "	CANTIDAD DE PIEDRA : " << this->cantPiedra << endl;
	cout << "	CANTIDAD DE MADERA : " << this->cantMadera << endl;
	cout << "	CANTIDAD DE METAL : " << this->cantMetal << endl;
	cout << "	CANTIDAD MAXIMOS PERMITIDOS: " << this->maxCantPermitidos << endl;
	//cout << "|---------------------------------------------|" << endl;
}

Edificio::Edificio(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos){
    this->nombre = nombre;
    this->cantPiedra = cantPiedra;
    this->cantMadera = cantMadera;
    this->cantMetal = cantMetal;
    this->maxCantPermitidos = cantMaxPermitidos;
}
//Edificio::Edificio(){}

Edificio::~Edificio(){}


string Edificio::getNombre(){
    return this->nombre;
}

int Edificio::getCantPiedra(){
    return this->cantPiedra;
}

int Edificio::getCantMadera(){
    return this->cantMadera;
}

int Edificio::getCantMetal(){
    return this->cantMetal;
}

int Edificio::getMaxCantPermitidos(){
    return this->maxCantPermitidos;
}



