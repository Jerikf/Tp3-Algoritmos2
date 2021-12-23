#include "../firmas/Material.h"
#include "../../recursos/firmas/Recursos.h"
#include <iostream>

const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";

const char PIEDRA_ABREVIATURA = 'S';
const char MADERA_ABREVIATURA = 'W';
const char METAL_ABREVIATURA = 'I';

void Material::mostrar(){
    Recurso recurso;

    cout << "\n\n"; 
	cout << "|---------------------------------------------|" << endl;
	cout << "		" << recurso.convertirAMayuscula(this->nombre) << endl;
	cout << "	" << "CANDTIDAD MATERIAL : " << this->cantidad << endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "\n"; 
}

Material::Material(string nombre, int cantidad){
    this->nombre = nombre;
    this->cantidad = cantidad;
}

Material::~Material(){}

string Material::getNombre(){
    return this->nombre;
}

int Material::getCantidad(){
    return this->cantidad;
}
void Material::setCantidad(int cantidad){
    this->cantidad = cantidad;
}

char Material::getAbreviaturaDeNombre(){
    
    char abreviatura = ' ';
    if(this->nombre == PIEDRA){
        abreviatura = PIEDRA_ABREVIATURA;
    }else if(this->nombre == MADERA){
        abreviatura = MADERA_ABREVIATURA;
    }else if(this->nombre == METAL){
        abreviatura = METAL_ABREVIATURA;
    }

    return abreviatura;
}