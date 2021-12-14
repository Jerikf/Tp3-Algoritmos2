#include "../Firmas/Mapa.h"
#include <iostream>
#include "../Firmas/constantes.h"

Mapa::Mapa(int cant_filas, int cant_columnas){
    
    this->cant_filas = cant_filas;
    this->cant_columnas = cant_columnas;

    this->casilleros = new Casillero**[cant_filas];
    
    for(int pos = 0; pos < cant_filas; pos++){
        this->casilleros[pos] = new Casillero*[cant_columnas];
    }

    for(int i = 0; i < this->cant_filas; i++){
        for(int j = 0; j < this->cant_columnas; j++){
                this->casilleros[i][j] = NULL;
        }
    }
}

Mapa::~Mapa(){
    
    for(int fila = 0; fila < this->cant_filas; fila++){
        for(int col = 0; col < this->cant_columnas; col++){
            if(casilleros[fila][col]){
                delete this->casilleros[fila][col];
            }
        }
        delete[] this->casilleros[fila];

    }
    
    delete[] this->casilleros;
}

void Mapa::agregar_casillero(Casillero* casillero, Coordenada coordenada){
    
    if(coordenada.getFila() >= this->cant_filas || coordenada.getColumna() >= this->cant_columnas){
        
        cout << "\n\n ERROR --> SE INGRESÒ UNA COORDENADA FUERA DEL RANGO DEL MAPA" << endl;
    }
    else if(casilleros[coordenada.getFila()][coordenada.getColumna()]){
        
        cout << "\n\n ERROR --> NO SE PUEDE AGREGAR EL CASILLERO PORQUE ESTÀ OCUPADO EL LUGAR" << endl;
    }
    else{
        casilleros[coordenada.getFila()][coordenada.getColumna()] = casillero;
    }
}

Casillero* Mapa::getCasillero(Coordenada coordenada){
    
    if(coordenada.getFila() >= this->cant_filas || coordenada.getColumna() >= this->cant_columnas){
        
        return NULL;
    }
    
    return this->casilleros[coordenada.getFila()][coordenada.getColumna()];
}

int Mapa::obtenerCantDeCasilleros(char tipoDeCasillero){
    int cantTotal = 0;
    for(int fil = 0; fil < this->cant_filas; fil++){
        for(int col = 0; col < this->cant_columnas; col++){
            
            if(this->casilleros[fil][col]->getTipo() == tipoDeCasillero){
                cantTotal++;
            }
        }
    }
    
    return cantTotal;
}

int Mapa::devolver_cant_filas(){
    
    return this->cant_filas;
}

int Mapa::devolver_cant_columnas(){
    
    return this->cant_columnas;
}

void Mapa::mostrar(){
    
    char tipo;
    
    for(int fila = 0; fila < this->cant_filas; fila++){
       
        Edificio* edificio = NULL;
        Material* material = NULL;
        for(int columna = 0; columna < this->cant_columnas; columna++){
            if(this->casilleros[fila][columna]){
                tipo = this->casilleros[fila][columna]->getTipo();
                if( tipo == TERRENO){
                    edificio = this->casilleros[fila][columna]->getEdificio();
                    if(edificio){
                        cout << edificio->devolver_abreviatura();
                    }
                    else{
                        cout << tipo  << ' ';
                    }
                }
                else if(tipo == CAMINO || tipo == BETUN || tipo == MUELLE){
                    material = this->casilleros[fila][columna]->getMaterial();

                    if(material){
                        cout  << material->devolver_abreviatura();
                    }
                    else{
                        cout << tipo << ' ';
                    }
                }
                else{
                    cout <<  tipo << ' ';
                }
            }

        }
        cout << "\n";
    }

}