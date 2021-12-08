#ifndef VERTICE_H
#define VERTICE_H
#include "../Entidades/Firmas/Coordenada.h"

class Vertice{
private:
    Coordenada coordenada;
    char tipo_terreno;

public:
    Vertice();

    void cargar_coordenada(Coordenada coordenada);

    void cargar_coordenada(int fila, int columna);

    void cargar_tipo_terreno(char tipo_terreno);

    Coordenada obtener_coordenada();

    char obtener_tipo_terreno();
};

#endif // VERTICE_H