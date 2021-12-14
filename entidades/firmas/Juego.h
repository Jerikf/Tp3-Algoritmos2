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
        Diccionario<Edificio>* edificios;
        Mapa* mapa;
        Jugador* jugador_1;
        Jugador* jugador_2;
        Vect<string>* objetivos;
        
        //PRE: Recibe el nombre de un edificio y un jugador.
        //POS: Devuelve un vector de coordenadas que se bucarà en las coordenadas de los edificios Construidos del jugador, en caso de no haber ningún edificio con dicho nombre devuelve null
        Vect<Coordenada>* obtenerCoordenadas(string nombre_edificio, Jugador* jugador);

        //PRE: Recibe el nombre de un material y un jugador.
        //POS: Devuelve el material en caso de encontrarse en el vector de materilaes del jugador, caso contrario devuelve NULL
        Material* obtenerMaterial(string nombre_material, Jugador* jugador);

        //PRE: Recibe el nombre de un edificio
        //POS: Devuelve el edificio en caso de encontrarse en el Diccionario de edificios, caso contrario devuelve NULL
        Edificio* obtenerEdificio(string nombre_edificio);

        //PRE:
        //POS: Devuelve una coordenada aleatoria válida(que esté en el rango del mapa, tanto fila como columna)
        Coordenada obtenerCoordenadaAleatoriaValida();

        //PRE: Recibe la cantidad de materiales a recoletar y un Material
        //POS: Recolecta el material con la/las coordeanda aleatoria/s tantas veces sea la cantidad de material pasado
        void recolectarMateriales(int cantDeMaterialesARecolectar,Material* material);

        // PRE: Recibe el nombre del material y el nombre del edificio.
        // POS: Modifica los valores de los materiales.
        void modificar_valores_materiales(string material, string nombre_edificio);

        // PRE: Los materiale son validos.
        // POS: Dependiendo del nombre del material, modifica la cantdiad de construccion del edificio.
        void modificar_valor_material(string material, int cantidad_material, string nombre_edificio);

        // PRE: Recibe el puntero al jugador, la cantidad de edificios y el nombre del edificio.
        // POS: Modifica la cantidad de edificios, sumnadolos.
        void contar_edificios(int &cant_edificios, string nombre_edificio, Jugador* jugador);

        // PRE: ReciBe la cantidad del recurso, el puntero al jugador y el nombre del material.
        // POS: Agrega al inventario el recurso dependiendo de cantidad del recurso.
        void recolectar_recurso(int cantidad_recurso, Jugador* jugador, string nombre_material);

        // PRE: -
        // POS: Carga el vector con los objetivos.
        void cargar_objetivos();

        // PRE: -
        // POS: Establece de manera aleatoria los objetivos del jugador.
        void establecer_objetivos_jugadores();

        // PRE: Recibe el nombre del objetivo.
        // POST: Agrega el objetivo al vector.
        void agregar_objetivo(string nombre);

        // PRE: Recibe un puntero al nombre del objetivo.
        // POS: Muestra el objetivo del jugador.
        void mostrar_objetivo(string *objetivo);
        
    public:

        //PRE: Recibe la clase datos, un diccionario de edificios y materiales
        //POS: Construye el juego y instancia los datos pasados por parametros, además instancia en NULL EL MAPA
        Juego(Datos*, Diccionario<Edificio>*);

        // PRE: -
        // POST: Inicializa el jugador, sin parametros.
        Juego();

        //PRE:
        //POS: Libera la memoria de los datos, edificios, material y del mapa(en caso no esté vacío)
        ~Juego();

        //PRE: -
        //POS: Carga todos los datos de edificios, materiales y mapa
        void inicializarCargadoDatos();

        // PRE: -
        // POS: Modicia el diccionario de edificios y el archivo.
        void modificar_edificio_por_nombre();

        //PRE: -
        //POS: Lista todos los edificios existentes.
        void listarTodosLosEdificios();

        //PRE: -
        //POS: Muestra el mapa según pedido en la consigna.
        void mostrarMapa();

        //PRE: -
        //POS: Actualiza los arhicvos edificios, materiales, mapas y ubicaciones.
        void guardarSalir(); 


        //PRE: Recibe un nombre de edificio, una coordenada y un jugador.
        //POS: Construye el edificio del jugador en caso que sea correcto los parámetros.
        void construirEdificioPorNombre(string nombre_edificio, Coordenada coordenada, Jugador* jugador);

        //PRE: Recibe un  jugador.
        //POS: Lista todos los edificios construidos del jugador.
        void listarEdificiosConstruidos(Jugador* jugador);

        //PRE: Recibe una coordenada y un  jugador.
        //POS: Demuele el edificio del jugador si la coordenada es correcta.
        void demolerEdificioPorCoordenada(Coordenada coordenada, Jugador* jugador);

        //PRE: Recibe una coordenada y un  jugador a atacar.
        //POS: Ataca a un edificio del rival si la coordenada es válida, cuando se ataca se respeta la consigna pedida.
        void atacarEdificioPorCoordenada(Coordenada coordenada, Jugador* jugador);

        //PRE: Recibe una coordeanda y un  jugador.
        //POS: Si en dicha coordenada hay un edificio reparable del jugador, se lo reparará con el criterio pedido en la consiga.
        void repararEdificioPorCoordenada(Coordenada coordenada, Jugador* jugador);

        // PRE: Recibe un jugador
        // POS: Agrega bombas en el invnetario del jugadro a camio de andycoins..
        void comprar_bombas(Jugador* jugador);

        //PRE: Recibe una coordeanda.
        //POS: Muestra que hay en el casillero según la coordeanda pasa, este sabe responderse a sí mismo y llama a su contenido.
        void consultarCoordenada(Coordenada coordenada);

        //PRE: Recibe un  jugador.
        //POS: Muestra los objetivos que cumplir, y el progreso de dicho jugador.
        void mostrarObjetivos(Jugador* jugador);

        //PRE: Recibe un entero que hace referencia al  jugador que quier mostrar su inventario.
        //POS: Muestra todos los materiales existente del jugador especificado.
        void mostrarInventario(Jugador* jugador);

        // PRE: -
        // POS: Muestra los objetivos del jugador.
        void mostrar_objetivos(Jugador* jugador);

        //PRE: Recibe un  jugador.
        //POS: Recolecta los materiales del jugador que pueden producir o no los edificios construidos, modificando así la cantidad de los materiales.
        void recolectarRecursosProducidos(Jugador*);

        //pre: el mapa debe estar cargado correctamente con el jugador ubicado en el mapa y la coordenada debe estar dentro del mapa.
        //post: si la coordenada se encuentra desocupada y se cuenta con la energia necesaria y el usuario quiere, se movera al jugador hasta dicha
        //      coordenada recorriendo el camino de minimo costo de energia.
        void moverJugador(Coordenada puntoFinal, int jugador);

        //PRE: -
        //POS: Crea cantidad  de Materiales aleatorios con cada material, además también tiene coordenadas aleatorias y lo contruye en el casillero correspondiente de ser Transitable
        void lluviaDeRecursos();

        // PRE: -
        // POS: Devuelve al jugador 1.
        Jugador* obtener_jugador_1();

        // PRE: -
        // POS: Devuelve al jugador 2.
        Jugador* obtener_jugador_2();
        
        // PRE: -
        // POS: Devuelve los edificios.
        Diccionario<Edificio>* obtener_edificios();
        
        // PRE: -
        // POS: Devuelve el mapa.
        Mapa* obtener_mapa();

        // PRE: -
        // POS: Guarda las modificaciones de edificios en el archivos de edificios.txt
        void Gurdar_datos_edificios();

        // PRE: -
        // POS: Obtiene la cantidad de lineas del archivo de ubicaiones, obtiene 0 si esta en blanco, llamandose a datos.
        int obtener_cant_lineas();
        
        // PRE: -
        // POS: Obtiene true si el archivo ubiaciones esta, false en caso contrario., llamadose a datos.
        bool obtener_esta_ubicaciones();
        

        // PRE: -
        // POS: Obtiene todos los objetivos del juego.
        Vect<string>* obtener_objetivos();


        
        

};

#endif //JUEGO_H