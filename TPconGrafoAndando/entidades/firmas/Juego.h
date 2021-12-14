#ifndef JUEGO_H
#define JUEGO_H
#include <stdbool.h>
#include <string>

#include "../../estructura/Vect.h"
#include "../../accesoDatos/modelo/Datos.h"
#include "../../entidades/firmas/Jugador.h"
#include "Mapa.h"
#include "Edificio.h"
#include "Material.h"

using namespace std;

class Juego
{
    private:
        Datos* datos;
        Vect<Edificio>* edificios; 
        Vect<Material>* materiales; // Este es el inventario del jugador, hay que sacarlo de aca
        Mapa* mapa;
        Jugador* jugador_1;
        Jugador* jugador_2;

        //PRE: Recibe el nombre de un edificio
        //POS: Devuelve un vector de coordenadas que se bucaron en el mapa, en caso de no haber ningún edificio con dicho nombre devuelve null
        Vect<Coordenada>* obtenerCoordenadas(string);

        //PRE: Recibe el nombre de un material
        //POS: Devuelve el material en caso de encontrarse en el vect de materiales, caso contrario devuelve NULL
        Material* obtenerMaterial(string);

        //PRE: Recibe el nombre de un edificio
        //POS: Devuelve el edificio en caso de encontrarse en el vect de edificios, caso contrario devuelve NULL
        Edificio* obtenerEdificio(string);

        //PRE:
        //POS: Devuelve una coordenada aleatoria válida(que esté en el rango del mapa, tanto fila como columna)
        Coordenada obtenerCoordenadaAleatoriaValida();

        //PRE: Recibe la cantidad de materiales a recoletar y un Material
        //POS: Recolecta el material con la/las coordeanda aleatoria/s tantas veces sea la cantidad de material pasado
        void recolectarMateriales(int,Material*);

        
        
    public:

        //PRE: Recibe la clase datos, un vector de edificios y materiales
        //POS: Construye el juego y instancia los datos pasados por parametros, además instancia en NULL EL MAPA
        Juego(Datos*, Vect<Edificio>*, Vect<Material>*);

        // PRE: -
        // POST: Inicializa el jugador, sin parametros.
       // Juego();

        //PRE:
        //POS: Libera la memoria de los datos, edificios, material y del mapa(en caso no esté vacío)
        ~Juego();

        //PRE:
        //POS: Carga todos los datos de edificios, materiales y mapa
        void inicializarCargadoDatos();

        //PRE:
        //POS: Muestra el menu de opciones
        void mostrarMenu();

        //PRE:
        //POS: Lista todos los edificios construidos
        void listarEdificiosConstruidos();

        //PRE:
        //POS: Lista todos los edificios existentes
        void listarTodosLosEdificios();

        //PRE:
        //POS: Muestra todos los materiales existentes
        void mostrarInventario();

        //PRE: Recibe un nombre de edificio y una coordenada
        //POS: Construye el edificio en caso que sea correcto los parámetros
        void construirEdificioPorNombre(string,Coordenada);

        //PRE: Recibe una coordenada
        //POS: Demuele el edificio si la coordenada es correcta
        void demolerEdificioPorCoordenada(Coordenada);

        //PRE: Recibe una coordeanda
        //POS: Muestra que hay en el casillero según la coordeanda pasa, este sabe responderse a sí mismo y llama a su contenido
        void consultarCoordenada(Coordenada);

        //PRE:
        //POS: Recolecta los materiales que pueden producir o no los edificios construidos, modificando así la cantidad de los materiales
        void recolectarRecursosProducidos();

        //PRE:
        //POS: Actualiza los arhicvos edificios, materiales, mapas y ubicaciones
        void guardarSalir(); 

        //PRE:
        //POS: Crea cantidad  de Materiales aleatorios con cada material, además también tiene coordenadas aleatorias y lo contruye en el casillero correspondiente de ser Transitable
        void lluviaDeRecursos();

        //PRE:
        //POS: Muestra el mapa según pedido en la consigna
        void mostrarMapa();
        
        // PRE: -
        // POS: Obtiene al jugador 1.
        //Jugador* obtener_jugador_1();

        // PRE: -
        // POS: Obtiene al jugador 2.
        //Jugador* obtener_jugador_2();

        //No se si son necesarias las funciones de set.

};

#endif //JUEGO_H