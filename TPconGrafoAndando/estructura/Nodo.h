#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <string>
using namespace std;



template <typename T>
class Nodo {
    // Atributos
private:
    string clave;
    T* elemento;
    Nodo<T>* izquierda;
    Nodo<T>* derecha;

public:
    //Constructor
    //PRE: -
    //POS: 
    Nodo(T*);

    ~Nodo();

    string obtenerClave();
    T* obtenerElemento();
    Nodo<T>* obtenerIzquierda();
    Nodo<T>* obtenerDerecha();

    void asignarClave(string);
    void asignarElemento(T*);
    void asignarIzquierda(Nodo<T>*);
    void asignarDerecha(Nodo<T>*);

};


template<typename T>
Nodo<T>::Nodo(T* elemento){
    this->elemento = elemento;
    this->izquierda = NULL;
    this->derecha = NULL;
}

template<typename T>
Nodo<T>::~Nodo(){
    delete this->elemento;
}

template<typename T>
void Nodo<T>::asignarClave(string clave){
    this->clave = clave;
}

template<typename T>
void Nodo<T>::asignarElemento(T* elemento){
    this->elemento = elemento;
}

template<typename T>
void Nodo<T>::asignarIzquierda(Nodo<T>* izquierda){
    this->izquierda = izquierda;
}

template<typename T>
void Nodo<T>::asignarDerecha(Nodo<T>* derecha){
    this->derecha = derecha;
}


template<typename T>
string Nodo<T>::obtenerClave(){
    return this->clave;
}

template<typename T>
T* Nodo<T>::obtenerElemento(){
    return this->elemento;
}

template<typename T>
Nodo<T>* Nodo<T>::obtenerIzquierda(){
    return this->izquierda;
}

template<typename T>
Nodo<T>* Nodo<T>::obtenerDerecha(){
    return this->derecha;
}



#endif //NODO_H