#include "Inventario.h"
#include "constantes.h"

using namespace std;

Inventario::Inventario(){

    materiales = nullptr;
    cant_tipo_materiales = NULO;

    crear_materiales();
}

void Inventario::crear_materiales(){

    materiales = new Material[cant_tipo_materiales + 1];

    for(int i = 0; i < cant_tipo_materiales; i++){
        materiales[i].obtener_material(VACIO, NULO);
    }
}

void Inventario::agregar_material(string nombre_material, int cantidad_material){

    materiales[cant_tipo_materiales].obtener_material(nombre_material, cantidad_material);

    cantidad_material ++;

    Material* nuevo_materiales = new Material[cantidad_material];
 
    for(int i = 0; i < cant_tipo_materiales; i++){
        nuevo_materiales[i] = materiales[i];
    }

    delete[] materiales;

    crear_materiales();

    for(int i = 0; i < cant_tipo_materiales; i++){
        materiales[i] = nuevo_materiales[i];
    }

    delete[] nuevo_materiales;
}

Material* Inventario::devolver_materiales(){

    return materiales;
}

Material Inventario::devovler_material(int posicion){

    return materiales[posicion];
}
