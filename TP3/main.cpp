#include "./Entidades/Firmas/Juego.h"

int main(){

    Juego juego;
    juego.obtener_datos();
    juego.inicializar_juego();
    juego.limpiar_memoria();

/*
   Material* material_1 = new Material("alambre", 65);
   Vect<Material>* material = new Vect<Material>();
   material->agregar(material_1);
   material_1 = new Material("pan", 20);
   material->agregar(material_1);
   
   delete material;
   
*/
    return 0;

}