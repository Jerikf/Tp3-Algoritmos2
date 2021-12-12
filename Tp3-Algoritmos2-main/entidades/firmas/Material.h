#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>

using namespace std;

class Material
{
    private:
        string nombre;
        int cantidad;

    public:

        //PRE: Recibe un nobmre del material y su cantidad
        //POS: Crear el material instanciando los datos correspondientes
        Material(string, int);

        //PRE:
        //POS: Destructor
        ~Material();

        //PRE:
        //POS: Muestra su contenido
        void mostrar();

        //PRE:
        //POS: Retorna su nombre
        string getNombre();

        //PRE:
        //POS: Retorna su cantidad
        int getCantidad();

        //PRE:
        //POS: Devuelve la abreviatura según sea el nombre del meaterial
        char getAbreviaturaDeNombre();

        //PRE: Recibe una cantidad para para actualizar
        //POS: Actualiza la cantidad del material
        void setCantidad(int cantidad);
};

#endif //MATERIAL_H