#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <stdbool.h>
#include <string>

class Edificio
{
    protected:
        std::string nombre_edificio;
        int cant_piedra;
        int cant_madera;
        int cant_metal;
        int cant_max_edificios;

    public:

        //PRE: Recibe un nombre, cantidades de piedra, madera, metal y un maximo permitido
        //POS: Construye el edificio instanciado con los valores pasados
        Edificio(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

        // PRE: -
        // POST: Obtiene los datos.
        void obtener_edificio(std::string nombre_edificio, int cant_piedra, int cant_madera, int cant_metal, int cant_max_edificios);

        //PRE: 
        //POS: Destruye el edificio
        virtual ~Edificio();

        //PRE:
        //POS: Muestra todos las propiedades del edificio
        virtual void mostrar();

        //PRE:
        //POS: Retorna el nombre del edificio
        std::string devolver_nombre();

        //PRE:
        //POS:Retorna la cantidad de la piedra
        int devolver_piedra();

        //PRE:
        //POS:Retorna la cantidad de la madera
        int devolver_madera();

        //PRE:
        //POS:Retorna la cantidad del metal
        int devolver_metal();

        //PRE:
        //POS:Retorna la cantidad maxima permitida para construir
        int devolver_cant_maxima_edificios();

        //PRE: -
        //POS: Devuelve la abreviatura del nombre.
        virtual char devolver_abreviatura() = 0;

};

#endif //EDIFICIO_H