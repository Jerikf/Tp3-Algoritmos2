#include "Datos.h"
#include "constantes.h"
#include <iostream>

using namespace std;

void Datos::cargar_inventario(){

    ifstream archivo_materiales(PATH_MATERIALES);

    if(!archivo_materiales.fail()){

        Inventario inventario_1;
        Inventario inventario_2;
        string nombre_material;
        int cantidad_material_1;
        int cantidad_material_2;

        while(archivo_materiales >> nombre_material){

            archivo_materiales >> cantidad_material_1;
            archivo_materiales >> cantidad_material_2;

            inventario_1.agregar_material(nombre_material, cantidad_material_1);
            inventario_2.agregar_material(nombre_material, cantidad_material_2);
        }

        jugador_1.obtener_inventario(inventario_1);
        jugador_2.obtener_inventario(inventario_2);
    }
    else{
        cout << "ERROR AL LEER EL ARCHIVO " << PATH_MATERIALES << "." << endl;
    }


}

void Datos::cargar_edificios(){

    
}

Jugador Datos::devovler_jugador_1(){

    return jugador_1;
}

Jugador Datos::devovler_jugador_2(){

    return jugador_2;
}