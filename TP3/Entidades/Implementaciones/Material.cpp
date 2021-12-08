#include "../../Entidades/Firmas/Material.h"
#include "../../Entidades/Firmas/constantes.h"
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
    
    cout << "Nombre: " << nombre_material << endl;
    cout << "Cantidad: " << cantidad_material << endl;
    cout << endl;
}

char Material::devolver_abreviatura(){
    
    char abreviatura = ' ';
    if(this->nombre_material == PIEDRA){
        abreviatura = CARACTER_PIEDRA;
    }else if(this->nombre_material == MADERA){
        abreviatura = CARACTER_MADERA;
    }else if(this->nombre_material == METAL){
        abreviatura = CARACTER_METAL;
    }

    return abreviatura;
}