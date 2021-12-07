#include "../Firmas/Mapa.h"
#include <iostream>



const char TERRENO = 'T';
const char CAMINO = 'C';
const char LAGO = 'L';
const char MUELLE = 'M';
const char BETUN = 'B';



Mapa::Mapa(int cantFilas, int cantColumnas){
    this->cantFilas = cantFilas;
    this->cantColumnas = cantColumnas;

    //Reservo memoria para las Filas
    this->casilleros = new Casillero**[cantFilas];
    
    //Reservo memoria para las Columnas
    for(int pos = 0; pos < cantFilas; pos++){
        this->casilleros[pos] = new Casillero*[cantColumnas];
    }

    //Instancio en NUll el contenido || sirve para evitar los errores SUMMARY de valgrind

    for(int i = 0; i < this->cantFilas; i++){
        for(int j = 0; j < this->cantColumnas; j++){
                this->casilleros[i][j] = NULL;
        }
    }
}

Mapa::~Mapa(){
    for(int fila = 0; fila < this->cantFilas; fila++){
        for(int col = 0; col < this->cantColumnas; col++){
            if(casilleros[fila][col]) // en caso tenga algùn casillero que no sea NULL
                delete this->casilleros[fila][col]; //Libero memoria de cada uno de los casilleros guardados
        }
        delete[] this->casilleros[fila]; // Libero memoria de fila
    }
    delete[] this->casilleros; // libero la "matriz" casilleros
}

void Mapa::agregarCasillero(Casillero* casillero, Coordenada coordenada){
    if(coordenada.getFila() >= this->cantFilas || coordenada.getColumna() >= this->cantColumnas){
        cout << "\n\n ERROR --> SE INGRESÒ UNA COORDENADA FUERA DEL RANGO DEL MAPA" << endl;
    }else if(casilleros[coordenada.getFila()][coordenada.getColumna()]){
        cout << "\n\n ERROR --> NO SE PUEDE AGREGAR EL CASILLERO PORQUE ESTÀ OCUPADO EL LUGAR" << endl;
    }else{
        casilleros[coordenada.getFila()][coordenada.getColumna()] = casillero;
    }
}

//^ↀᴥↀ^ ---> (＾• ω •＾) ---> =ටᆼට=

Casillero* Mapa::getCasillero(Coordenada coordenada){
    if(coordenada.getFila() >= this->cantFilas || coordenada.getColumna() >= this->cantColumnas)
        return NULL;
    return this->casilleros[coordenada.getFila()][coordenada.getColumna()];
}

int Mapa::obtenerCantDeCasilleros(char tipoDeCasillero){
    int cantTotal = 0;
    for(int fil = 0; fil < this->cantFilas; fil++){
        for(int col = 0; col < this->cantColumnas; col++){
            if(this->casilleros[fil][col]->getTipo() == tipoDeCasillero)
                cantTotal++;
        }
    }
    return cantTotal;
}

int Mapa::getCantFilas(){
    return this->cantFilas;
}

int Mapa::getCantColumnas(){
    return this->cantColumnas;
}

//TODO-->Modificar para que muestre como corresponde
void Mapa::mostrar(){
    char tipo;
    for(int fila = 0; fila < this->cantFilas; fila++){
        Edificio* edificio = NULL;
        Material* material = NULL;
        for(int columna = 0; columna < this->cantColumnas; columna++){
            if(this->casilleros[fila][columna]){
                tipo = this->casilleros[fila][columna]->getTipo();
                if( tipo == TERRENO){
                    edificio = this->casilleros[fila][columna]->getEdificio();

                    if(edificio){
                        cout << edificio->getAbreviaturaDeNombre();
                    }else
                        cout  << ' ';
                   
                }else if( tipo == CAMINO || tipo == BETUN || tipo == MUELLE ){

                    material = this->casilleros[fila][columna]->getMaterial();

                    if(material){
                        cout  << material->getAbreviaturaDeNombre();
                    }else
                        cout << ' ';

                }else{
                    cout << ' ';
                }
            }

        }
        cout << "\n";
    }
}