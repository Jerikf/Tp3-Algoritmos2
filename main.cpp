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
#include <iostream>

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
