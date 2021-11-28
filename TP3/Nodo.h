#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <cstddef>


template <class T>
class Nodo{

    private:

    T dato;
    Nodo<T>* rama_izquierda;
    Nodo<T>* rama_derecha;
    Nodo<T>* rama_pariente;

    public:

    // PRE: -
    // POST: Inicializa el nodo.
    Nodo(T dato);

    // PRE: -
    // POST: Obtiene el dato.
    void obtener_dato(T dato);

    // PRE: Los punteros son validos.
    // POST: Obtiene la rama derecha.
    void obtener_rama_derecha(Nodo<T>* rama_derecha, Nodo<T>* rama_pariente);

    // PRE: Los punterois son validos.
    // POST: Obtiene la rama izquierda.
    void obtener_rama_izquierda(Nodo<T>* rama_izquierda, Nodo<T>* rama_pariente);

    // PRE: El puntero es valido.
    // POST: Obtiene la rama derecha.
    void obtener_rama_derecha(Nodo<T>* rama_derecha);

    // PRE: El puntero es valido.
    // POST: Obtiene la rama izquierda.
    void obtener_rama_izquierda(Nodo<T>* rama_izquierda);

    // PRE: El puntero es valido.
    // POST: Obtiene la rama pariente.
    void obtener_rama_pariente(Nodo<T>* rama_pariente);

    // PRE: -
    // POST: Devuelve la rama derecha.
    Nodo<T>* devolver_rama_derecha();

    // PRE: -
    // POST: Devuelve la rama izquierda.
    Nodo<T>* devolver_rama_izquierda();

    // PRE: -
    // POST: Devuelve la rama pariente.
    Nodo<T>* devolver_rama_pariente();

    // PRE: -
    // POST: Devuelve el dato.
    T devolver_dato();

    // PRE: -
    // POST: Devuelve true si el nodo es una hoja, false en caso contrario.
    bool verificar_hoja();

    // PRE: -
    // POST: Devuelve true si hay un unico hijo derecho, false en caso contrario.
    bool verificar_hijo_derecha();

    // PRE: -
    // POST: Devuelve true si hay un unico hijo izquierdo, false en caso contrario.
    bool verificar_hijo_izquierda();
};

template<class T>
Nodo<T>::Nodo(T dato){

    this-> dato = dato;
    rama_derecha = nullptr;
    rama_izquierda = nullptr;
    rama_pariente = nullptr;
}

template<class T>
void Nodo<T>::obtener_dato(T dato){
    
    this-> dato = dato;   
}

template<class T>
void Nodo<T>::obtener_rama_derecha(Nodo<T>* rama_derecha, Nodo<T>* rama_pariente){

    this-> rama_derecha = rama_derecha;
    this-> rama_pariente = rama_pariente;
}

template<class T>
void Nodo<T>::obtener_rama_izquierda(Nodo<T>* rama_izquierda, Nodo<T>* rama_pariente){

    this-> rama_izquierda = rama_izquierda;
    this-> rama_pariente = rama_pariente;
}

template<class T>
void Nodo<T>::obtener_rama_derecha(Nodo<T>* rama_derecha){

    this-> rama_derecha = rama_derecha;
}

template<class T>
void Nodo<T>::obtener_rama_izquierda(Nodo<T>* rama_izquierda){

    this-> rama_izquierda = rama_izquierda;
}

template<class T>
void Nodo<T>::obtener_rama_pariente(Nodo<T>* rama_pariente){

    this-> rama_pariente = rama_pariente;
}

template<class T>
Nodo<T>* Nodo<T>::devolver_rama_derecha(){

    return rama_derecha;
}

template<class T>
Nodo<T>* Nodo<T>::devolver_rama_izquierda(){

    return rama_izquierda;
}

template<class T>
Nodo<T>* Nodo<T>::devolver_rama_pariente(){

    return rama_pariente;
}

template<class T>
T Nodo<T>::devolver_dato(){

    return dato;
}

template<class T>
bool Nodo<T>::verificar_hoja(){

    return (devolver_rama_derecha() == nullptr && devolver_rama_izquierda() == nullptr);

}

template<class T>
bool Nodo<T>::verificar_hijo_derecha(){

    return (devolver_rama_derecha() != nullptr && devolver_rama_izquierda() == nullptr);
}

template<class T>
bool Nodo<T>::verificar_hijo_izquierda(){

    return (devolver_rama_derecha() == nullptr && devolver_rama_izquierda() != nullptr);
}


#endif // NODO_H_INCLUDED