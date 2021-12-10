#include "../firmas/Construible.h"
#include <iostream>

#include "../firmas/PlantaElectrica.h"
#include "../firmas/Aserradero.h"
#include "../firmas/Obelisco.h"
#include "../firmas/Fabrica.h"
#include "../firmas/Escuela.h"
#include "../firmas/Mina.h"
#include "../firmas/MinaOro.h"


const int EXITO = 0;
const int ERROR = -1;

const string PLATAN_ELECTRICA = "planta electrica";
const string ASERRADERO = "aserradero";
const string MINA_ORO = "mina oro";
const string OBELISCO = "obelisco";
const string FABRICA = "fabrica";
const string ESCUELA = "escuela";
const string PLANTA = "planta";
const string MINA = "mina";


Construible::Construible() : Casillero(){
    this->edificio = NULL;
}
Construible::~Construible(){
    delete edificio;
}
Construible::Construible(char tipo, Edificio* edificio): Casillero(tipo){
    this->edificio = edificio;
}
Construible::Construible(char tipo) : Casillero(tipo){
    this->edificio = NULL;
}

Edificio* Construible::getEdificio(){
    return this->edificio;
}

Material* Construible::getMaterial(){
    return NULL;
}

void Construible:: mostrar(){
    if(this->edificio){
        cout << "\n\n\n";
        cout << "|--------------------------------------------------------|" << endl;
        cout << "SOY UN CASILLERO CONSTRUIBLE Y ME ENCUENTRO OCUPADO POR : " << endl;
        this->edificio->mostrar();
        cout << "|--------------------------------------------------------|" << endl;
    }else{
        cout << "\n\n\nESTOY VACÍO --> SOY UN CASILLERO CONSTRUIBLE" << endl;
    }
    
}

int Construible::construirEdificio(Edificio* edificio){
    int estado = ERROR;
    if(!this->edificio){
        Edificio* edificioConstruido = NULL;

        //Obtendo sus datos
        string nombre = edificio->getNombre();
        int cantPiedra = edificio->getCantPiedra();
        int cantMadera = edificio->getCantMadera();
        int cantMetal = edificio->getCantMetal();
        int cantMaxPermitidos = edificio->getMaxCantPermitidos();

        //Me genera una nueva instancia dependiendo de que tipo de Edificio sea
        if(PLATAN_ELECTRICA == nombre){
            edificioConstruido = new PlantaElectrica(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
        }else if(ASERRADERO == nombre){
            edificioConstruido = new Aserradero(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
        }else if(OBELISCO == nombre){
            edificioConstruido = new Obelisco(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
        }else if(FABRICA == nombre){
            edificioConstruido = new Fabrica(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
        }else if(ESCUELA == nombre){
            edificioConstruido = new Escuela(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
        }else if(MINA == nombre){
            edificioConstruido = new Mina(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
        }else if(MINA_ORO == nombre){
            edificioConstruido = new MinaOro(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
        }

        //Me construyo el edificio
        this->edificio = edificioConstruido;
        cout << "\n\n\n SE CONSTRUYÒ CORRECTAMENTE EL EDIFCIO !!\n" << endl;
        estado = EXITO;
    }else
        cout << "\n\n ERROR --> NO SE PUEDE CONTRUIR EDIFICIO PORQUE YA EL CASILLERO YA SE ENCUENTRA OCUPADO\n\n" << endl;

    return estado;
}

int Construible::construirMaterial(Material* material){
    return ERROR;
}

Edificio* Construible::demolerEdificio(){
    Edificio* edificioResultado = NULL;
    if(this->edificio){
        edificioResultado = this->edificio;
        this->edificio = NULL;
        cout << "\n\n\n SE DEMOLIÓ CORRECTAMENTE EL EDIFICIO" << endl;
    }else
        cout << "\n\n\n ERROR --> CASILLERO VACÍO" << endl;
    return edificioResultado;
}