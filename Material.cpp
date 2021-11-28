#include "Material.h"
#include "constantes.h"

using namespace std;

Material::Material(){

    nombre_material = VACIO;
    cantidad_material = NULO;
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