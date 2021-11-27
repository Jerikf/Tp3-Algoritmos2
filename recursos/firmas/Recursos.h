#ifndef RECURSOS_H
#define RECURSOS_H
#include <stdbool.h>
#include <string>


using namespace std;

class Recurso
{
    private:

    public:

        //PRE:
		//POS:Contruye el Recurso vacio
        Recurso();

        //PRE:
		//POS: Destructor
        ~Recurso();

        //PRE: Recibe una cadena
		//POS: Convirete la cadena recibida en mayúscula y lo devuelve
        string convertirAMayuscula(string);

        //PRE: Recibe dos números enteros que será el rango, donde el rango1 < que el rango 2
        //POS: Devuelve un número aleatorio generado entre el rango1 y el rango2
        int obtenerNumAleatorio(int,int);
  
};

#endif //RECURSOS_H