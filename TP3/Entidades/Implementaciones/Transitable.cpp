#include "../Firmas/Transitable.h"
#include <iostream>

Transitable::Transitable(){
    this->material = NULL;
}

Transitable::Transitable(char tipo, Material* material) : Casillero(tipo){
    this->material = material;
}

Transitable::Transitable(char tipo) : Casillero(tipo){
    this->material = NULL;
}

Transitable::~Transitable(){
    delete material;
}

Material* Transitable::getMaterial(){
    return this->material;
}

void Transitable::setMaterial(Material* material){
    this->material = material;
}

void Transitable::mostrar(){
    if(this->material){
        cout << "\n\n\n";
        cout << "|--------------------------------------------------------------|" << endl;
        cout << "SOY UN CASILLERO TRANSITABLE Y ME ENCUENTRO OCUPADO POR : " << endl;
        this->material->mostrar();
        cout << "|--------------------------------------------------------------|" << endl;
    }else{
        cout << "\n\n\nESTO VACÍO--> SOY UN CASILLERO TRANSITALBE" << endl;
    }
    
}

int Transitable::construirEdificio(Edificio* edificio){
    cout << "\n\n\n ERROR --> NO SE PUEDE CONSTRUIR EDIFICIO PORQUE SOY UN : CASILLERO TRANSITABLE\n" << endl;
    return -1;
}

Edificio* Transitable::getEdificio(){
    return NULL;
}

Edificio* Transitable::demolerEdificio(){
    cout << "\n\n\n ERROR-> NO SE PUEDE DEMOLER EL EDIFICIO PORQUE SOY UN : CASILLERO TRANSITABLE" << endl;
    return NULL;
}

int Transitable::construirMaterial(Material* material){
    int estado = -1;

    if(!this->material){
        // Me genero una nueva instancia con la copia de los elementos del material pasado por parámetro
        // TODO--> Se podía haber hecho con un constructor copia, lo intenté pero tuve problemas de memoria(en un futuro cambiarlo por constructor copia)
        Material* materialConstruible = new Material(material->devolver_nombre_material(), material->devolver_cantidad_material());
        this->material = materialConstruible;
        estado = 0;

        // TODO --> ESTO DEBERÍA DARLE RESPONSABILIDAD AL QUE LO PIDE, YA QUE PARA ESO SE DEVUELVE EM MENSAJE DE EXITO/ERROR
        cout << "\n\n\n SE CONSTRUYÒ CORRECTAMENTE EL MATERIAL !!\n" << endl;

    }else
        cout << "\n\n\nERROR--> SOY UN CASILLERO TRANSITABLE PERO ME ENCUENTRO OCUPADO POR UN MATERIAL" << endl;
    return estado;
}