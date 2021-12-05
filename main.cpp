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
    Grafo grafo(mapa);
    grafo.imprimir_matriz_adyacencia();
    delete mapa;*/

    //Pruebas Floyd
    ifstream archivo("matriz_prueba.txt");
    int cant_vertices;
    archivo >> cant_vertices;

    int ** matriz_adyacencia = new int*[cant_vertices];
    for(int i = 0; i < cant_vertices; i++){
        matriz_adyacencia[i] = new int[cant_vertices];
    }

    for( int i = 0; i < cant_vertices; i++ ){
        for( int j = 0; j < cant_vertices; j++ ){
            archivo >> matriz_adyacencia[i][j];
        }
    }
    archivo.close();

    cout << "Matriz de adyacencia antes de calcular con Floyd" << endl;
    for( int i = 0; i < cant_vertices; i++ ){
        for( int j = 0; j < cant_vertices; j++ ){
            cout << matriz_adyacencia[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Despues de Floyd" << endl;
    Floyd  * floyd = new Floyd(matriz_adyacencia, cant_vertices);
    floyd->imprimir_matriz_costos();
    delete floyd;

    for( int i = 0; i < cant_vertices; i++ ){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
    return 0;
}
// para compilar
//g++ -g ./entidades/implementacion/* ./estructura/* ./accesoDatos/implementacion/* ./interfaz/implementacion/* ./recursos/implementacion/* ./grafo/* main.cpp -o tp -Werror -Wall -Wconversion
//para ejecutar
//valgrind --tool=memcheck --leak-check=yes --leak-check=full --track-origins=yes ./tp