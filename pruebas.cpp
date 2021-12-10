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
#include "./entidades/firmas/Jugador.h"
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
    //---------------------PRUEBAS DEL USO DEL DICCIONAARIO IMPLEMENTADO CON UN ABB----------------
    /*
    //Creamos 3 Edificios
    Edificio* escuela = new Escuela("Peregrini", 10, 15, 17, 19);
    Edificio* fabrica = new Fabrica("Los Andes", 5, 10, 12, 14);
    Edificio* obelisco = new Obelisco("Zulio9", 0, 5, 7, 9);

	//Creamos el diccionario
    Diccionario<Edificio>* dicc = new Diccionario<Edificio>();
    
    //Insertamos
    dicc->insertar("escuela", escuela);
    dicc->insertar("abrica", fabrica); // se puso abrica para tener un nodo a la izquierda luego de la raiz
    dicc->insertar("obelisco", obelisco);

    //Verificamos que la raiz sea Peregrini
    dicc->obtenerRaiz()->mostrar();
    cout << "\n\n\n -----------------" << endl;

    //Mostramos los recorridos y verificar que muestre correctamente

    //Peregrini-Los Andes- Zulio9
    dicc->mostrarPreorden();
    cout << "\n\n\n -----------------" << endl;

    //Los Andes - Peregrini - Zulio9
    dicc->mostrarInorder();
    cout << "\n\n\n -----------------" << endl;

    //Los Andes - Zulio9 - Peregrini
    dicc->mostrarPostorden();
    cout << "\n\n\n -----------------" << endl;

    //Buscamos cada edificio insertado individualmente
    dicc->buscar("escuela")->mostrar();
    dicc->buscar("abrica")->mostrar();
    dicc->buscar("obelisco")->mostrar();


    //liberamos la memoria
    delete dicc;

    //---------------------------------------------FIN DE PRUEBAS DEL DICCIONARIO---------------------------
    */
    //Pruebas grafo

    /*Datos* datos = new Datos("edificios.txt","materiales.txt","mapa.txt","ubicaciones.txt");
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


    delete mapa;*/


    //-----------------------------------Prueba con archivo Edificios y materiales -------------------------------------
    /*Mapa* mapa;
    Diccionario<Edificio>* diccEdificios = new Diccionario<Edificio>;
    Datos* datos = new Datos("edificios.txt", "materiales.txt", "mapa.txt", "ubicaciones.txt");
    Vect<Material>* materialesJugador1 = new Vect<Material>;
    Vect<Material>* materialesJguador2 = new Vect<Material>; 

    Vect<Coordenada>* ubicacionesJugador1 = new Vect<Coordenada>;
    Vect<Coordenada>* ubicacionesJugador2 = new Vect<Coordenada>;
    datos->cargarDatosEdificios(diccEdificios);
    //datos->cargarDatosMateriales(materialesJugador1, materialesJguador2);
    datos->cargarDatosMapa(&mapa);
    datos->cargarDatosUbicaciones(mapa, diccEdificios,ubicacionesJugador1, ubicacionesJugador2);
   // int cant_energia = 100;
    //Grafo* grafo_1 = new Grafo(mapa, 1);
   // Grafo* grafo_2 = new Grafo(mapa, 2);//Van en juego


    //Jugador* jugador_1 = new Jugador(grafo_1);
   //Se carga en juego.
   // Jugador* jugador_2 = new Jugador(grafo_2);


    //materialesJugador1->mostrar();
    //materialesJguador2->mostrar();
    //diccEdificios->mostrarInorder();

   // ubicacionesJugador2->mostrar();
   // ubicacionesJugador1->mostrar();

  // jugador_1->obtener_ubiaciones()->mostrar();
    

    delete diccEdificios;
    delete materialesJguador2;
    delete materialesJugador1;
    delete datos;
    delete mapa;
    delete ubicacionesJugador2;
    delete ubicacionesJugador1;*/
   // delete grafo_1;
   // delete grafo_2;
  //  delete jugador_1;
   // delete jugador_2;



    //--------------------------------------------PRUEBA DE GUARDADO DE MATERIALES Y EDIFICIOS----------------------

    Diccionario<Edificio>* diccEdificios = new Diccionario<Edificio>;
    Datos* datos = new Datos("edificios.txt", "materiales.txt", "mapa.txt", "ubicaciones.txt");
    Vect<Material>* materialesJugador1 = new Vect<Material>;
    Vect<Material>* materialesJugador2 = new Vect<Material>;

    datos->cargarDatosEdificios(diccEdificios);
    datos->cargarDatosMateriales(materialesJugador1, materialesJugador2);

    //---> llamo a la funcion guardar datos de edificios y materiales, debería verse reflejado en el mismo forma de archivo
    datos->gurdarDatosEdificios(diccEdificios);
    datos->guardarDatosMateriales(materialesJugador1, materialesJugador2);

    delete diccEdificios;
    delete datos;
    delete materialesJugador1;
    delete materialesJugador2;



    return 0;
}
// para compilar
//g++ -g ./entidades/implementacion/* ./estructura/* ./accesoDatos/implementacion/* ./interfaz/implementacion/* ./recursos/implementacion/* ./grafo/* main.cpp -o tp -Werror -Wall -Wconversion
//para ejecutar
//valgrind --tool=memcheck --leak-check=yes --leak-check=full --track-origins=yes ./tp