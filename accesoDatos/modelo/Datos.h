#ifndef DATOS_H
#define DATOS_H
#include <stdbool.h>
#include <string>

#include "../../entidades/firmas/Coordenada.h"
#include "../../estructura/Vect.h"
#include "../../entidades/firmas/Mapa.h"
#include "../../entidades/firmas/Edificio.h"
#include "../../entidades/firmas/PlantaElectrica.h"
#include "../../entidades/firmas/Aserradero.h"
#include "../../entidades/firmas/Obelisco.h"
#include "../../entidades/firmas/Fabrica.h"
#include "../../entidades/firmas/Escuela.h"
#include "../../entidades/firmas/Mina.h"
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

        //PRE: Recibe 2 partes del archivo leído ---> 1ero: (valor,  2do: valor) 
		//POS: Devuele la coordenada extraída de las 2 partes pasadas por parámetro
        Coordenada extraerCoordenada(string,string);
        
    public:
    
        //PRE: Recibe los nombre de los archivos(deben existir)
		//POS: Asigna a los atributos los nombres de archivos según corresponda
        Datos(string,string,string, string);

        //PRE:
		//POS:Destructor
        ~Datos();

        //PRE: Recibe un vector de edificios
		//POS: Carga los datos del archivo edificios al vector
        void cargarDatosEdificios(Vect<Edificio>* edificios);
        
        //PRE: Recibe un vector de materiales
		//POS: Carga los datos del archivo materiales al vector
        void cargarDatosMateriales(Vect<Material>* materiales);
        
        //PRE: Recibe la dirección de un mapa(se modificará desde acá)
		//POS: Construye el mapa cargando los datos del archivo mapa
        void cargarDatosMapa(Mapa** mapa);
        
        //PRE: Recibe un mapa y un vectore de edificios
		//POS: Llena el mapa con edificios según diga el archivo de ubicaciones
        void cargarDatosUbicaciones(Mapa* mapa, Vect<Edificio>*);

        //PRE: Recibe un vector de materiales
		//POS: Actualiza el archivo materiales, guardando los datos que almacena el vector
        void guardarDatosMateriales(Vect<Material>* materiales);
        
        //PRE: Recibe un vector de edificios
		//POS: Actualiza el archivo edificios, guardando los datos que almacena el vector
        void gurdarDatosEdificios(Vect<Edificio>* edificios);
        
        //PRE: Recibe un mapa
		//POS: Actualiza el archivo mapa, guardando los datos que almacena el mapa
        void guardarDatosMapa(Mapa* mapa);
        
        //PRE: Recibe un mapa
		//POS: Actualiza el archivo ubicaciones, según sea cada edificio del casillero construible
        void guardarDatosUbicaciones(Mapa* mapa);

        

};

#endif //DATOS_H