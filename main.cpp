#include "./entidades/firmas/Material.h"
#include "./entidades/firmas/Edificio.h"
#include "./entidades/firmas/Escuela.h"
#include "./entidades/firmas/Aserradero.h"
#include "./entidades/firmas/Mina.h"
#include "./estructura/Vect.h"
#include "./entidades/firmas/Mapa.h"
#include "./accesoDatos/modelo/Datos.h"
#include "./entidades/firmas/Casillero.h"
#include "./entidades/firmas/Transitable.h"
#include "./entidades/firmas/Construible.h"
#include "./entidades/firmas/Inaccesible.h"
#include "./entidades/firmas/Juego.h"
#include "./interfaz/firma/Interfaz.h"
#include <iostream>

#ifdef _WIN32
    const char* CLEAR_SCREEN = "cls";
#else

    const char* CLEAR_SCREEN = "clear";

#endif

int main(){
    //Defino las herramientas que utilizaré
    Datos* datos = new Datos("edificios.txt","materiales.txt","mapa.txt","ubicaciones.txt");
    Vect<Edificio>* edificios = new Vect<Edificio>; 
    Vect<Material>* materiales = new Vect<Material>;
    Juego juego(datos, edificios, materiales); //TODO--> Puedo instanciar directamente  en el constructor, cuál serái lo mejor?
    Interfaz interfaz(&juego);

    //Cargo los datos del archivo
    juego.inicializarCargadoDatos();
    system(CLEAR_SCREEN);

    interfaz.iniciar();
  


    return 0;
}


//-------------------------  ^ↀᴥↀ^ ---> (＾• ω •＾) ---> =ටᆼට=   --------------------------------------