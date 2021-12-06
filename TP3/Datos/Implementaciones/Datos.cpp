#include "../../Datos/Firmas/Datos.h"
#include "../../Entidades/Firmas/constantes.h"
#include <iostream>
#include "../../Estructuras/Firmas/Vect.h"

using namespace std;

void Datos::cargar_inventario(){

    ifstream archivo_materiales(PATH_MATERIALES);

    if(!archivo_materiales.fail()){
        
        Vect<Material>* inventario_1 = new Vect<Material>();
        Vect<Material>* inventario_2 = new Vect<Material>();
        Material *material_1;
        Material *material_2;

        string nombre_material;
        int cantidad_material_1;
        int cantidad_material_2;

        while(archivo_materiales >> nombre_material){

            archivo_materiales >> cantidad_material_1;
            archivo_materiales >> cantidad_material_2;

            material_1 = new Material(nombre_material, cantidad_material_1);
            material_2 = new Material(nombre_material, cantidad_material_2);

            inventario_1->agregar(material_1);
            inventario_2->agregar(material_2);

        }

        jugador_1.obtener_invnetario(inventario_1);
        jugador_2.obtener_invnetario(inventario_2);



    }
    else{
        cout << "ERROR AL LEER EL ARCHIVO " << PATH_MATERIALES << "." << endl;
    }

    archivo_materiales.close();

}

void Datos::cargar_edificios(){

    ifstream archivo_edificios(PATH_EDIFICIOS);

    if(!archivo_edificios.fail()){

        Diccionario<Edificio> *dic_edificios_1 = new Diccionario<Edificio>();
        Diccionario<Edificio> *dic_edificios_2 = new Diccionario<Edificio>();
        Edificio *edificio = NULL;
        Edificio *edificio_2 = NULL;

        string nombre_edificio;
        int cant_piedra;
        int cant_madera;
        int cant_metal;
        int cant_max_edificios;

        while(archivo_edificios >> nombre_edificio){
            
            archivo_edificios >> cant_piedra;
            archivo_edificios >> cant_madera;
            archivo_edificios >> cant_metal;

            archivo_edificios >> cant_max_edificios;
            
            designar_clase_edificio(edificio, nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios);
            designar_clase_edificio(edificio_2, nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios);
            dic_edificios_1->insertar(nombre_edificio, edificio);
            dic_edificios_2->insertar(nombre_edificio, edificio_2);


        }

        jugador_1.obtener_edificios(dic_edificios_1);
        jugador_2.obtener_edificios(dic_edificios_2);

        
    }
    else{
        cout << "ERROR AL LEER EL ARCHIVO " << PATH_EDIFICIOS << endl;
    }

    archivo_edificios.close();
}

void Datos::designar_clase_edificio(Edificio* &edificio, string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios){

    if(nombre_edificio == ASERRADERO){
        edificio = new Aserradero(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios);
    }
    else if(nombre_edificio == MINA){
        edificio = new Mina(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios);
    }
    else if(nombre_edificio == FABRICA){
        edificio = new Fabrica(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios);
    }
    else if(nombre_edificio == ESCUELA){
        edificio = new Escuela(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios);
    }
    else if(nombre_edificio == PLANTA_ELECTRICA){
        edificio = new PlantaElectrica(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios);
    }
    else if(nombre_edificio == OBELISCO){
        edificio = new Obelisco(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios);
    }
    else if(nombre_edificio == MINA_ORO){
        edificio = new Mina_oro(nombre_edificio, cant_piedra, cant_madera, cant_metal, cant_max_edificios);
    }

}


Jugador Datos::devovler_jugador_1(){

    return jugador_1;
}

Jugador Datos::devovler_jugador_2(){

    return jugador_2;
}