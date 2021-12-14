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
    juego.inicializarCargadoDatos();

    system(CLEAR_SCREEN);
    Mapa * mapa;
    datos->cargarDatosMapa(&mapa);
    mapa->mostrar();

    int jugador;
    cout << "Ingrese si es jugador 1 o 2 (con otro numero se rompe): ";
    cin >> jugador;
    cout << "Cargando banca" << endl;
    Grafo grafo(mapa, jugador);

    Coordenada punto_inicial, punto_final;
    int x;
    cout << "Ingresa coordenada inicial:" << endl;
    cin >> x;
    punto_inicial.setFila(x);
    cin >> x;
    punto_inicial.setColumna(x);

    cout << "Ingresa coordenada final:" << endl;
    cin >> x;
    punto_final.setFila(x);
    cin >> x;
    punto_final.setColumna(x);

    int  tope_camino;
    int costo_camino;
    Coordenada * coordenadas_camino = grafo.obtener_camino_minimo(punto_inicial, punto_final, &tope_camino, &costo_camino);
    cout << "Costo camino: " << costo_camino << endl;
    for( int i = 0; i < tope_camino; i++ ){
        cout << "(" << coordenadas_camino[i].getFila() << ";" << coordenadas_camino[i].getColumna() << ") ";
    }
    cout << endl;

    mapa->mostrar_recorrido_jugador(coordenadas_camino, tope_camino, jugador);
    delete[] coordenadas_camino;
    //saco a jugador 1 para evitar errores
    Coordenada coordenada = punto_final;
    Casillero * casillero = mapa->getCasillero(coordenada);
    casillero->jugador_deja_casillero();


    //agrego jugador 2 para ver como afecta al recorrido
    coordenada.setFila(13);
    coordenada.setColumna(14);
    casillero = mapa->getCasillero(coordenada);
    casillero->jugador_entra_casillero(2);

    coordenada.setFila(0);
    coordenada.setColumna(1);
    casillero = mapa->getCasillero(coordenada);
    casillero->jugador_entra_casillero(2);

    coordenada.setFila(3);
    coordenada.setColumna(14);
    casillero = mapa->getCasillero(coordenada);
    casillero->jugador_entra_casillero(2);

    coordenada.setFila(4);
    coordenada.setColumna(4);
    casillero = mapa->getCasillero(coordenada);
    casillero->jugador_entra_casillero(2);

    grafo.actualizar_grafo(mapa);
    coordenadas_camino = grafo.obtener_camino_minimo(punto_inicial, punto_final, &tope_camino, &costo_camino);
    mapa->mostrar_recorrido_jugador(coordenadas_camino, tope_camino, jugador);


    delete[] coordenadas_camino;
    delete mapa;
    return 0;

}
//para compilar
//g++ -g ./entidades/implementacion/* ./estructura/* ./accesoDatos/implementacion/* ./interfaz/implementacion/* ./recursos/implementacion/* ./grafo/* pruebas_grafo.cpp -o tp -Werror -Wall -Wconversion
//para ejecutar
//valgrind -s --tool=memcheck --leak-check=yes --leak-check=full --track-origins=yes ./tp