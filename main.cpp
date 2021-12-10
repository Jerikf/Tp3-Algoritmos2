#include "./entidades/firmas/Material.h"
#include "./entidades/firmas/Edificio.h"
#include "./entidades/firmas/Escuela.h"
#include "./entidades/firmas/Aserradero.h"
#include "./entidades/firmas/Mina.h"
#include "./estructura/Vect.h"
#include "./estructura/Diccionario.h"
#include "./entidades/firmas/Mapa.h"
#include "./accesoDatos/modelo/Datos.h"
#include "./entidades/firmas/Casillero.h"
#include "./entidades/firmas/Transitable.h"
#include "./entidades/firmas/Construible.h"
#include "./entidades/firmas/Inaccesible.h"
#include "./entidades/firmas/Juego.h"
#include "./interfaz/firma/Interfaz.h"
#include "./entidades/firmas/Coordenada.h"
#include "./grafo/Grafo.h"
#include "./grafo/Floyd.h"
#include <iostream>
#include <fstream>

#ifdef _WIN32
const char* CLEAR_SCREEN = "cls";
#else

const char* CLEAR_SCREEN = "clear";

#endif

int main(){
    Datos* datos = new Datos("edificios.txt","materiales.txt","mapa.txt","ubicaciones.txt");
    Vect<Edificio>* edificios = new Vect<Edificio>;
    Vect<Material>* materiales = new Vect<Material>;
    Juego juego(datos, edificios, materiales);
    Interfaz interfaz(&juego);

    juego.inicializarCargadoDatos();
    system(CLEAR_SCREEN);

    interfaz.iniciar();


    return 0;
}