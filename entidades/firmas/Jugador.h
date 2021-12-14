#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "../../estructura/Vect.h"
#include "../../grafo/Grafo.h"
#include "Material.h"
#include "Coordenada.h"


class Jugador{

    private:

    int cant_energia;
    Vect<Material>* inventario;
    Vect<Coordenada>* coordenadasDeEdificiosConstruidos;
    Grafo* grafo;
    string* primer_objetivo;
    string* segundo_objetivo;

    public:

    //PRE:
    //POS: Construye su Jugador, e instancia sus atributos privados, además asiganar el grafo pasado por paràmetro al grafo del jugador
    Jugador(Grafo* grafo);

    //PRE:
    //POS: Construye el jugador Instanciando todos sus atributos privados
    Jugador();

    // PRE: -
    // POST: Establece la energia del jugador.
    void establecer_energia(int cant_energia);

    // PRE: -
    // POST: Establece el vector del inventario del jugador.
    void establecer_inventario(Vect<Material>* inventario);

    // PRE: -
    // POST: Establece el vector de ubiaciones del jugador.
    void establecer_ubicaciones(Vect<Coordenada>* ubicaciones); 

    // PRE: -
    // POST: Establece el grafo del jugador.
    void establecer_grafo(Mapa* mapa, int numero);

    // PRE: -
    // POST: Obtiene la cantidad de energia del jugador.
    int obtener_cant_energia();

    //PRE: Recibe su número del jugador y un mapa
    //POS: Devuelve la coordeanda del jugador que se encuentra en el mapa
    Coordenada obtenerMiPosicion(int, Mapa*);

    // PRE: -
    // POST: Obtiene el inventario del jugador.
    Vect<Material>* obtener_inventario();

    // PRE: -
    // POST: Obtiene las ubicaciones del jugador.
    Vect<Coordenada>* obtener_coordenadasDeEdificiosConstruidos();

    // PRE: -
    // POST: Obtiene el grafo del jugador.
    Grafo* obtener_grafo();

    //pre: el mapa tiene que estar cargado correctamente y las coordenadas ser posiciones validas
    //post: devuelve nullptr si jugador no tiene la energia suficiente o un vector de coordenadas con el recorrido realizado
    Coordenada * jugadorSeMueve(Coordenada puntoInicial, Coordenada puntoFinal, int* topeCamino, Mapa * mapa);



    // PRE: -
    // POS: Destruye el jugador.
    ~Jugador();
    
    // PRE: -
    // POS: Establece los objetivos del jugador.
    void establecer_objetivos(string* primer_objetivo, string*segundo_objetivo);

    // PRE: -
    // POS: Obtiene el primer objetivo.
    string* obtener_primer_objetivo();

    // PRE: -
    // POS: Obtiene el segundo objetivo.
    string* obtener_segundo_objetivo();
};

#endif // JUGADOR_H_