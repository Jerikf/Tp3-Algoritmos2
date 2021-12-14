#ifndef VECT_H
#define VECT_H
#include <stdbool.h>
#include <string>
//#include "../../entidades/firmas/Edificio.h"


const int ERROR = -1;
const int EXITO = 0;

template <typename T>
class Vect
{
    private:
        int cantidad;
        T** datos;
        

    public:

		//PRE:
		//POS: Construye el vector instanciando la cnatidad en 0 y los datos en NULL
        Vect();

		//PRE:
		//POS: Libera la memoria de todo su contenido en los datos
        ~Vect();

		//PRE: Recibe un dato tipo T
		//POS: Agregar el dato a los datos retornando 0 en caso de exito sino -1(ERROR)
        int agregar(T*);

		//PRE:
		//POS: Retorna la cantidad de datos que tiene
        int obtenerCantidad();

		//PRE: El tipo T debe implementar el método mostrar() sino genera error
		//POS: Muestra todos los datos que tiene(llamando a su propia instancia mostrar del contenido)
        void mostrar();

		//PRE: Recibe la posición del vector en el rango correcto!
		//POS: Devuelve el dato en dicha posición correcta
		T* obtenerDato(int);

};

template<typename T>
Vect<T>::Vect(){
    this->cantidad = 0;
    this->datos = NULL;
}

template<typename T>
Vect<T>::~Vect(){
	if(this->datos){
		for(int pos = 0; pos < this->cantidad; pos++){
			delete this->datos[pos];
		}
	}
	delete[] this->datos;
}

template<typename T>
int Vect<T>::agregar(T* dato){
    T** nuevoVect = new T*[this->cantidad + 1];
	//El peor caso sería que no se pueda reservar memoria, si pasara esto no podría copiar los datos ni seguir
	if(!nuevoVect) return ERROR;
	
	//Copio los datos
	for(int pos = 0; pos < this->cantidad; pos++){
		nuevoVect[pos] = this->datos[pos];
	}

	//agrego el nuevo dato 
	nuevoVect[this->cantidad] = dato;

	//libero el contenedor datos , sus valores no! porque aún los conservo! en el nuevo 
	if(this->cantidad != 0){
		delete[] this->datos;
	}

	//reasigno el nuevo vector y aumento la cantidad de datos que tengo
	this->datos = nuevoVect;
	this->cantidad++;
	return EXITO;
}

template<typename T>
void Vect<T>::mostrar(){
	for(int i = 0; i < this->cantidad; i++){
		datos[i]->mostrar();
	}
}

template<typename T>
int Vect<T>::obtenerCantidad(){
	return this->cantidad;
}

template<typename T>
T* Vect<T>::obtenerDato(int posicion){
	return this->datos[posicion];
}



#endif //VECT_H
