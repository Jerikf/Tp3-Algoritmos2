#include "../firmas/Mapa.h"
#include <iostream>
#include "../../recursos/firmas/colors.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif



const char TERRENO = 'T';
const char CAMINO = 'C';
const char LAGO = 'L';
const char MUELLE = 'M';
const char BETUN = 'B';
const char NO_HAY_JUGADOR = 0;



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
                        cout << BGND_GREEN_2 << TXT_DARK_RED_52 << edificio->getAbreviaturaDeNombre() << END_COLOR;
                    }else
                        cout << BGND_GREEN_2 << ' ' << END_COLOR;
                   
                }else if( tipo == CAMINO || tipo == BETUN || tipo == MUELLE ){

                    material = this->casilleros[fila][columna]->getMaterial();

                    if( tipo == CAMINO )
                        cout << BGND_GRAY_245;

                    else if( tipo == BETUN )
                        cout << BGND_DARK_GRAY_239;

                    else cout << BGND_BROWN_94;

                    if(material){
                        cout << TXT_DARK_RED_52 << material->getAbreviaturaDeNombre() << END_COLOR;
                    }else
                        cout << ' ' << END_COLOR;

                }else{
                    cout << BGND_BLUE_27 << ' ' <<END_COLOR;
                }
            }

        }
        cout << "\n";
    }
}

void Mapa::mostrar_recorrido_jugador(Coordenada * recorrido, int tope_recorrido, int jugador){
    //si hay un material creo que lo deberia agregar por ahora no lo hace (imprime jugador por encima de material)
    char tipo;
    bool hay_jugador;
    for( int i = 0; i < tope_recorrido; i++ ){

        this->casilleros[recorrido[i].getFila()][recorrido[i].getColumna()]->jugador_deja_casillero();
        this->casilleros[recorrido[i].getFila()][recorrido[i].getColumna()]->jugador_entra_casillero(jugador);
        //ToDo esto debería llamar tope_recorrido veces a mostrar mapa pero por ahora queda asi
        for(int fila = 0; fila < this->cantFilas; fila++){
            Edificio* edificio = NULL;
            Material* material = NULL;
            for(int columna = 0; columna < this->cantColumnas; columna++){
                hay_jugador = false;
                if(recorrido[i].getFila() == fila && recorrido[i].getColumna() == columna )
                    hay_jugador = true;

                if(this->casilleros[fila][columna]){
                    tipo = this->casilleros[fila][columna]->getTipo();
                    if( tipo == TERRENO){
                        edificio = this->casilleros[fila][columna]->getEdificio();

                        if(edificio){
                            cout << BGND_GREEN_2 << TXT_DARK_RED_52 << edificio->getAbreviaturaDeNombre() << END_COLOR;
                        }
                        else if(hay_jugador){
                            cout << BGND_GREEN_2 << TXT_DARK_RED_52 << this->casilleros[fila][columna]->devolver_jugador_casillero() << END_COLOR;
                        }
                        else
                            cout << BGND_GREEN_2 << ' ' << END_COLOR;

                    }else if( tipo == CAMINO || tipo == BETUN || tipo == MUELLE ){

                        material = this->casilleros[fila][columna]->getMaterial();

                        if( tipo == CAMINO )
                            cout << BGND_GRAY_245;

                        else if( tipo == BETUN )
                            cout << BGND_DARK_GRAY_239;

                        else cout << BGND_BROWN_94;

                        if(material){
                            cout << TXT_DARK_RED_52 << material->getAbreviaturaDeNombre() << END_COLOR;
                        }
                        else if(hay_jugador){
                            cout << TXT_DARK_RED_52 << this->casilleros[fila][columna]->devolver_jugador_casillero() << END_COLOR;
                        }else
                            cout << ' ' << END_COLOR;

                    }else if(hay_jugador){
                        cout << BGND_BLUE_27 << TXT_DARK_RED_52 << this->casilleros[fila][columna]->devolver_jugador_casillero() <<END_COLOR;
                    }else{
                        cout << BGND_BLUE_27 << ' ' <<END_COLOR;
                    }

                }

            }
            cout << "\n";
        }
        usleep(500000);
        cout << "\x1B[2J\x1B[H";
    }
}