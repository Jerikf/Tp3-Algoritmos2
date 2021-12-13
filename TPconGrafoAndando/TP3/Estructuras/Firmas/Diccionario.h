#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <stdbool.h>
#include "Nodo.h"

const int ERRORR = -1;
const int EXITOO = 0;


template <typename T>
class Diccionario
{
    private:
        Nodo<T>* raiz;
        
    public:

		//PRE:
		//POS: Construye el Diccionarioor instanciando la cnatidad en 0 y los datos en NULL
        Diccionario();

		//PRE:
		//POS: Libera la memoria de todo su contenido
        ~Diccionario();

		//PRE: Recibe un dato tipo T
		//POS: Agregar el dato al Diccionario retornando 0 en caso de EXITOO sino -1(ERRORR)
        int insertar(string, T*);

		//PRE:
		//POS: Busca en el árbol el elemento y lo borra, devuelve 0 si pudo eliminarlo y sino -1
        int borrar(T*);

        //PRE:
        //POS: Devuelve el elemento encontrado o sino NULL sino lo encuentra
        T* buscar(string);

        //PRE:
        //POS: Devuelve el elmento almacenado en la raiz o NULL si el árbol está vacío o no existe
        T* obtenerRaiz();

        //PRE:
        //POS: Devuelve true si el árbol está vacío o el árbol es null, false si el árbol tiene elementos
        bool estaVacio();

		//PRE: 
		//POS: Muestra todos los datos que tiene en modo inorder
        void mostrarInorder();

        //PRE: 
		//POS: Muestra todos los datos que tiene en modo inorder
        void mostrarPreorden();

        //PRE: 
		//POS: Muestra todos los datos que tiene en modo inorder
        void mostrarPostorden();

    private:

        Nodo<T>* insertar_t(Nodo<T>*, string clave, T* nuevoNodo);
        Nodo<T>* buscar_t(Nodo<T>*, string clave);
        void mostrarInorder_t(Nodo<T>*);
        void mostrarPreorden_t(Nodo<T>*);
        void mostrarPostorden_t(Nodo<T>*);
        void liberarMemoria(Nodo<T>*);


};


//-------------------------------------FUNCIONES PRIVADAS---------------------------------------------
template<typename T>
Nodo<T>* Diccionario<T>::insertar_t(Nodo<T>* nodo, string clave,  T* dato){
    if(!nodo){
        nodo = new Nodo<T>(dato);
        nodo->asignarClave(clave);
        
    }else{
        if( clave > nodo->obtenerClave() || nodo->obtenerClave() == clave){
            nodo->asignarDerecha(this->insertar_t(nodo->obtenerDerecha(), clave, dato));
        }else
            nodo->asignarIzquierda(this->insertar_t(nodo->obtenerIzquierda(), clave, dato));
    }
    return nodo;

}

template<typename T>
Nodo<T>* Diccionario<T>::buscar_t(Nodo<T>* nodo, string clave){
    if(!nodo || nodo->obtenerClave() == clave){
        return nodo;
    }else if(clave > nodo->obtenerClave()){
        return buscar_t(nodo->obtenerDerecha(), clave);
    }else{
        return buscar_t(nodo->obtenerIzquierda(), clave);
    }
}

template<typename T>
void Diccionario<T>::liberarMemoria(Nodo<T>* nodo){
    if(!nodo) return ;
    this->liberarMemoria(nodo->obtenerIzquierda());
    this->liberarMemoria(nodo->obtenerDerecha());
    delete nodo;
}

template<typename T>
void Diccionario<T>::mostrarInorder_t(Nodo<T>* nodo){
    if(nodo != NULL){
        mostrarInorder_t(nodo->obtenerIzquierda());
        nodo->obtenerElemento()->mostrar();
        mostrarInorder_t(nodo->obtenerDerecha());
    }
}

template<typename T>
void Diccionario<T>::mostrarPreorden_t(Nodo<T>* nodo){
    if(nodo != NULL){
        nodo->obtenerElemento()->mostrar();
        mostrarPreorden_t(nodo->obtenerIzquierda());
        mostrarPreorden_t(nodo->obtenerDerecha());
    }
}

template<typename T>
void Diccionario<T>::mostrarPostorden_t(Nodo<T>* nodo){
    if(nodo != NULL){
        mostrarPostorden_t(nodo->obtenerIzquierda());
        mostrarPostorden_t(nodo->obtenerDerecha());
        nodo->obtenerElemento()->mostrar();
    }
}




//--------------------------------------------------FIN----------------------------------------------------

template<typename T>
Diccionario<T>::Diccionario(){
    this->raiz = NULL;
}

template<typename T>
Diccionario<T>::~Diccionario(){
    this->liberarMemoria(this->raiz);
}

template<typename T>
int Diccionario<T>::insertar(string clave, T* dato){
    if(!dato || clave == "" ) return ERRORR;
    this->raiz = this->insertar_t(this->raiz, clave, dato);
    return EXITOO;
}

template<typename T>
T* Diccionario<T>::obtenerRaiz(){
    if(this->estaVacio()) return NULL;
    return this->raiz->obtenerElemento();
}

template<typename T>
bool Diccionario<T>::estaVacio(){
    return (!this->raiz);
}

template<typename T>
T* Diccionario<T>::buscar(string clave){
    if(clave == "") return NULL;
    Nodo<T>* nodoBuscado = this->buscar_t(this->raiz, clave);
    if(!nodoBuscado) return NULL;
    return (!nodoBuscado)? NULL : nodoBuscado->obtenerElemento();

}

template<typename T>
void Diccionario<T>::mostrarInorder(){
    if(!this->estaVacio())
        this->mostrarInorder_t(this->raiz);
    else{
        cout << "Está vacìo" << endl;
    }
}

template<typename T>
void Diccionario<T>::mostrarPreorden(){
    if(!this->estaVacio())
        this->mostrarPreorden_t(this->raiz);
    else{
        cout << "Está vacío" << endl;
    }
}

template<typename T>
void Diccionario<T>::mostrarPostorden(){
    if(!this->estaVacio())
        this->mostrarPostorden_t(this->raiz);
    else{
        cout << "Está vacío" << endl;
    }
}



#endif //DICCIONARIO_H

