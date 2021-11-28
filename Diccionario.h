#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED
#include "Nodo.h"
#include <iostream>

template <class T>
class Diccionario{

    private:

    Nodo<T>* raiz;

    // PRE: -
    // POST: Inserta un nodo al arbol.
    Nodo<T>* insertar_nodo(Nodo<T>* nodo, T dato);
    
    // PRE: -
    // POST: Muestra por pantalla el arbol inorder.
    void imprimir_arbol_inorder(Nodo<T> * nodo);
    
    // PRE: -
    // POST: Busca el nodo y lo devuelve.
    Nodo<T>* buscar_nodo(Nodo<T>* nodo, T dato);
    
    // PRE: -
    // POST: Busca el nodo minimo y devuelve el contenido.
    T buscar_nodo_min(Nodo<T>* nodo);
    
    // PRE: -
    // POST: Busca el nodo maximo y devuelve el contenido.
    T buscar_nodo_max(Nodo<T>* nodo);
    
    // PRE: -
    // POST: Devuelve el contenido del nodo sucesor.
    T buscar_sucesor(Nodo<T>* nodo);
    
    // PRE: -
    // POST: Devuelve el contenido del nodo predecesor.
    T buscar_predecesor(Nodo<T>* nodo);
    
    // PRE: -
    // POST: Elimina un nodo.
    Nodo<T>* eliminar_nodo(Nodo<T>* nodo, T dato);
    
    // PRE: -
    // POST: Limpia la memoria de todos los nodos.
    void limpiar_arbol(Nodo<T>* nodo);

    public:

    // PRE: -
    // POST: Inicializa el diccionario.
    Diccionario();

    // PRE: -
    // POST: Inserta un nodo al arbol.
    void insertar_nodo(T dato);
    
    // PRE: -
    // POST: Muestra por pantalla el arbol inorder.
    void imprimir_arbol_inorder();
    
    // PRE: -
    // POST: Devuelve true si encontro el dato en el arbol, false en caso contario.
    bool buscar_nodo(T dato);
    
    // PRE: -
    // POST: Busca el nodo minimo y devuelve el contenido.
    T buscar_nodo_min();
    
    // PRE: -
    // POST: Busca el nodo maximo y devuelve el contenido.
    T buscar_nodo_max();
    
    // PRE: -
    // POST: Devuelve el contenido del nodo sucesor.
    T buscar_sucesor();
    
    // PRE: -
    // POST: Devuelve el contenido del nodo predecesor.
    T buscar_predecesor();
    
    // PRE: -
    // POST: Elimina un nodo.
    void eliminar_nodo(T dato);
    
    // PRE: -
    // POST: Limpia la memoria de todos los nodos.
    void limpiar_arbol();

    // PRE: -
    // POST: Devuelve la raiz.
    Nodo<T>* devolver_raiz();

    // PRE: -
    // POST: Devuelve true si el arbol esta vacio, false en caso contrario.
    bool arbol_vacio();

    // PRE: -
    // POST: Limpia la memoria dinamica restante.
    ~Diccionario();
};

template<class T>
Diccionario<T>::Diccionario(){

    raiz = nullptr;
}

template<class T>
Nodo<T>* Diccionario<T>::insertar_nodo(Nodo<T>* nodo, T dato){

    if(nodo == nullptr){
        nodo = new Nodo<T>(dato);
    }
    else if(dato > nodo->devolver_dato()){
        nodo->obtener_rama_derecha(insertar_nodo(nodo->devolver_rama_derecha(), dato), nodo);
    }
    else{
        nodo->obtener_rama_izquierda(insertar_nodo(nodo->devolver_rama_izquierda(), dato), nodo);
    }

    return nodo;
}

template<class T>
void Diccionario<T>::insertar_nodo(T dato){

    this-> raiz = insertar_nodo(this-> raiz, dato);
}

template<class T>
void Diccionario<T>::imprimir_arbol_inorder(Nodo<T>* nodo){

    if(nodo != nullptr){
        imprimir_arbol_inorder(nodo->devolver_rama_izquierda());
        std::cout << nodo->devolver_dato() << ' ';
        imprimir_arbol_inorder(nodo->devolver_rama_derecha());
    }
}

template<class T>
void Diccionario<T>::imprimir_arbol_inorder(){

    this-> imprimir_arbol_inorder(this-> raiz);
}


template<class T>
Nodo<T>* Diccionario<T>::buscar_nodo(Nodo<T>* nodo, T dato){

    if(nodo == nullptr || nodo->devolver_dato() == dato){
        return nodo;
    }
    
    if(dato > nodo->obtener_dato()){
        buscar_nodo(nodo->devolver_rama_derecha(), dato);
    }
    return buscar_nodo(nodo->devolver_rama_izquierda(), dato);
}

template<class T>
bool Diccionario<T>::buscar_nodo(T dato){

    Nodo<T>* resultado = buscar_nodo(this-> raiz, dato);

    return resultado != nullptr;
}




#endif // DICCIONARIO_H_INCLUDED