#include "../../Entidades/Firmas/Material.h"
#include "../../Entidades/Firmas/constantes.h"

#include <iostream>

using namespace std;

Material::Material(){

    nombre_material = VACIO;
    cantidad_material = NULO;
}

Material::Material(string nombre_material, int cantidad_material){

    this-> nombre_material = nombre_material;
    this-> cantidad_material = cantidad_material;
}

void Material::obtener_material(string nombre_material, int cantidad_material){

    this-> nombre_material = nombre_material;
    this-> cantidad_material = cantidad_material;
}

string Material::devolver_nombre_material(){

    return nombre_material;
}

int Material::devolver_cantidad_material(){

    return cantidad_material;
}

void Material::mostrar(){
    cout << "\n\n"; 
	cout << "|---------------------------------------------|" << endl;
	cout << "		" << nombre_material << endl;
	cout << "	" << "CANDTIDAD MATERIAL : " << this->cantidad_material << endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "\n"; 
}

char Material::getAbreviaturaDeNombre(){
    
    char abreviatura = ' ';
    if(this->nombre_material == PIEDRA){
        abreviatura = 'S';
    }else if(this->nombre_material == MADERA){
        abreviatura = 'W';
    }else if(this->nombre_material == METAL){
        abreviatura = 'I';
    }

    return abreviatura;
}