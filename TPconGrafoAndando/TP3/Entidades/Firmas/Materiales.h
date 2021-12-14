#ifndef MATERIALES_H_INCLUDED
#define MATERILAES_H_INCLUDED
#include <string>

class Material{

    private:

    std::string nombre_material;
    int cantidad_material;

    public:

    // PRE: -
    // POST: Inicializa el material.
    Material();

    // PRE: La cntidad es mayor a 0.
    // POST: Obtiene el material.ç
    void obtener_material(std::string nombre_material, int cantidad_material);

    // PRE: -
    // POST: Devuelve el nombre del material.
    std::string devolver_nombre_material();

    // PRE: -
    // POST: Devuelve la cantidad del material.
    int devolver_cantidad_material();
};

#endif // MATERIALES_H_INCLUDED
