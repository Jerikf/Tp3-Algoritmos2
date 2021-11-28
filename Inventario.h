#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED
#include "Material.h"

class Inventario{

    private:

    Material *materiales;
    int cant_tipo_materiales;

    public:

    // PRE: -
    // POST: Inicializa el inventario.
    Inventario();

    // PRE: -
    // POST: Crea e inicializa un vector dinamico de materiales.
    void crear_materiales();

    // PRE: -
    // POST: Agrega un material al inventario.
    void agregar_material(std::string nombre_material, int cantidad_material);

    // PRE: La posicion es mayor o igual a 0.
    // POST: Devuelve el material por posicion.
    Material devovler_material(int posicion);

    // PRE: -
    // POST: Devuelve todos los materiales.
    Material* devolver_materiales();
};

#endif //INVENTARIO_H_INCLUDED