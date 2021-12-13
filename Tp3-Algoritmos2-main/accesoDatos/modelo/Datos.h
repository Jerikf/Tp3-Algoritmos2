#ifndef DATOS_H
#define DATOS_H
#include <stdbool.h>
#include <string>

#include "../../entidades/firmas/Coordenada.h"
#include "../../estructura/Vect.h"
#include "../../estructura/Diccionario.h"
#include "../../entidades/firmas/Mapa.h"
#include "../../entidades/firmas/Edificio.h"
#include "../../entidades/firmas/PlantaElectrica.h"
#include "../../entidades/firmas/Aserradero.h"
#include "../../entidades/firmas/Obelisco.h"
#include "../../entidades/firmas/Fabrica.h"
#include "../../entidades/firmas/Escuela.h"
#include "../../entidades/firmas/Mina.h"
#include "../../entidades/firmas/MinaOro.h"
#include "../../entidades/firmas/Material.h"

#include "../../entidades/firmas/Casillero.h"
#include "../../entidades/firmas/Construible.h"
#include "../../entidades/firmas/Transitable.h"
#include "../../entidades/firmas/Inaccesible.h"

using namespace std;


class Datos
{
    private:
        string nombreArchivoEdificios;
        string nombreArchivoMateriales;
        string nombreArchivoMapa;
        string nombreArchivoUbicaciones;
        bool esta_archivo_ubiaciones;
        int cant_lineas_ubicaiones;

        //PRE: Recibe 2 partes del archivo leído ---> 1ero: (valor,  2do: valor) 
		//POS: Devuele la coordenada extraída de las 2 partes pasadas por parámetro
        Coordenada extraerCoordenada(string,string);

        //PRE: Recibe una cade que como mìnimo tendrà un digito numèrico
        //POS: Devuelve todos los dígitos que se encuentra en la cadena
        int obtenerDatoNumerico(string);

        //PRE: Recibe una direccion de un archivo abierto, la coordenada y un entero que representa el número del jugador(ya sea 1 o 2 para cada jugador respectivamente)
        //POS: Asigna el jugador y su coordenada en el archivo ubicaciones
        void asignarJugadorAlArchivoUbicaciones(ofstream*, Coordenada, int);

        //PRE: Recibe un arhivo de ubicaciones abierto, ademàs un mapa y un vector de coordendas que indican los edificios construidos de dicho jugador que están en el mapa
        //POS: Asigna todos los nombres de edificios que se encuentran en el vector de coordenadas.
        void asignarEdificiosConstruidosDelJugadorAlArchivoUbicaciones(ofstream*, Mapa*, Vect<Coordenada>*);

        // PRE: -
        // POS: En el caso de que no este al archivo de ubiaciones, crea uno en blanco.
        void crear_archivo_ubicaciones();
        
    public:
    
        //PRE: Recibe los nombre de los archivos(deben existir)
		//POS: Asigna a los atributos los nombres de archivos según corresponda
        Datos(string,string,string, string);

        //PRE:
		//POS:Destructor
        ~Datos();

        //PRE: Recibe un vector de edificios
		//POS: Carga los datos del archivo edificios al vector
        void cargarDatosEdificios(Diccionario<Edificio>* edificios);
        
        //PRE: Recibe un vector de materiales
		//POS: Carga los datos del archivo materiales al vector
        void cargarDatosMateriales(Vect<Material>* materialesJugador1, Vect<Material>* materialesJugador2);
        
        //PRE: Recibe la dirección de un mapa(se modificará desde acá)
		//POS: Construye el mapa cargando los datos del archivo mapa
        void cargarDatosMapa(Mapa** mapa);
        
        //PRE: Recibe un mapa, un diccionario de edificios, y 2 vectores de coordenadas de cada jugador
		//POS: Llena el mapa con edificios según diga el archivo de ubicaciones, además carga en las coordenadas de cada
        //      jugador los edificios de cada uno.
        void cargarDatosUbicaciones(Mapa* mapa, Diccionario<Edificio> *edificios, Vect<Coordenada>* ubicacionesJugador1, Vect<Coordenada>* ubicacionesJugador2);

        //PRE: Recibe dos vectores de materiales(tanto del jugador1 como del jugador2)
		//POS: Actualiza el archivo materiales, guardando los datos que almacena el vector
        void guardarDatosMateriales(Vect<Material>* materiales, Vect<Material>* materiales2);
        
        //PRE: Recibe un Diccionario de edificios
		//POS: Actualiza el archivo edificios, guardando los datos que almacena el vector
        void gurdarDatosEdificios(Diccionario<Edificio>* edificios);
        
        //PRE: Recibe un mapa
		//POS: Actualiza el archivo mapa, guardando los datos que almacena el mapa
        void guardarDatosMapa(Mapa* mapa);
        
        //PRE: Recibe un mapa y dos vectores de coordenadas de edificios construidos de cada jugador
		//POS: Actualiza el archivo ubicaciones, según los materiales que haya en el mapa y los edificios de cada jugador
        void guardarDatosUbicaciones(Mapa* mapa, Vect<Coordenada>*, Vect<Coordenada>*);
        
        // PRE: -
        // POS: Obtiene la cantidad de lineas del archivo de ubicaiones, obtiene 0 si esta en blanco.
        int obtener_cant_lineas();
        
        // PRE: -
        // POS: Obtiene true si el archivo ubiaciones esta, false en caso contrario.
        bool obtener_esta_ubicaciones();
       

};

#endif //DATOS_H