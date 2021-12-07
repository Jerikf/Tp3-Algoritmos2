#ifndef COORDENADA_H
#define COORDENADA_H

using namespace std;

class Coordenada
{
    private:
        int fila;
        int columna;

    public:

        //PRE: Recibe una fila y columna
        //POS: Construye la coordenada asignando a los atributos correspondientes
        Coordenada(int, int);

        //PRE:
        //POS:Construye la coordeanda vacia
        Coordenada();

        //PRE:
        //POS:Destructor
        ~Coordenada();

        //PRE:
        //POS: Muestra sus atributos
        void mostrar();

        //PRE:
        //POS: Retorna su fila
        int getFila();

        //PRE:
        //POS: Retorna su columna
        int getColumna();

        //PRE: recibe una fila a actualizar
        //POS: Actualiza su fila
        void setFila(int);

        //PRE: Recibe una columna a actualizar
        //POS: Actualiza la columna
        void setColumna(int);
};

#endif //COORDENADA_H