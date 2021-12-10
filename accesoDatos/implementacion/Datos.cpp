#include "../modelo/Datos.h"
#include <iostream>
#include <fstream>

const string PLATAN_ELECTRICA = "planta electrica";
const string ASERRADERO = "aserradero";
const string OBELISCO = "obelisco";
const string FABRICA = "fabrica";
const string ESCUELA = "escuela";
const string MINA = "mina";
const string MINA_ORO = "mina oro";
const string PLANTA = "planta";
const string ORO = "oro";

const string N_PIEDRA = "piedra";
const string N_MADERA = "madera";
const string N_METAL = "metal";
const string N_ANDYCOINS = "andycoins";

const int CANT_PIEDRA = 100;
const int CANT_MADERA = 50;
const int CANT_METAL = 50;
const int CANT_ANDYCOINS = 250;

const char LAGO = 'L';
const char TERRENO = 'T';
const char CAMINO = 'C';
const char BETUN = 'B';
const char MUELLE = 'M';

const string JUGADOR1 = "1";
const string JUGADOR2 = "2";


Datos::Datos(string nombreArchivoEdificios, string nombreArchivoMateriales, string nombreArchivoMapa, string nombreArchivoUbicaciones){
    this->nombreArchivoEdificios = nombreArchivoEdificios;
    this->nombreArchivoMateriales = nombreArchivoMateriales;
	this->nombreArchivoMapa = nombreArchivoMapa;
	this->nombreArchivoUbicaciones = nombreArchivoUbicaciones;
}

Datos::~Datos(){}

void Datos:: cargarDatosEdificios(Diccionario<Edificio>* edificios){

    fstream archivoEdificios(this->nombreArchivoEdificios, ios::in);
	if(!archivoEdificios.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO" << endl;
		archivoEdificios.open(this->nombreArchivoEdificios, ios::out);
		archivoEdificios.close();
		archivoEdificios.open(this->nombreArchivoEdificios, ios::in);
	}
	string nombre, nombreComplemento, complementoNombreMina, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos = "";
	Edificio* edificio = NULL;
	while(archivoEdificios >> nombre){
        

        if(nombre == MINA){
            archivoEdificios >> complementoNombreMina;
        }


        if(nombre == MINA && complementoNombreMina != ORO){
            cantPiedra = complementoNombreMina;
            cout << " el nombre es : " << complementoNombreMina << endl;
        }else{
            if(nombre == MINA && complementoNombreMina == ORO)
                nombre = nombre + " " + complementoNombreMina;

            if(nombre == PLANTA){
                archivoEdificios >> nombreComplemento;
                nombre = nombre + " " + nombreComplemento; 
            }
            archivoEdificios >> cantPiedra;
        }

		archivoEdificios >> cantMadera;
		archivoEdificios >> cantMetal;
		archivoEdificios >> cantMaxPermitidos;

		// verifico que edificio es y asigno los valores
        if(nombre == PLATAN_ELECTRICA){
            edificio = new PlantaElectrica(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else if(nombre == ASERRADERO){
            edificio = new Aserradero(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else if(nombre == OBELISCO){
            edificio = new Obelisco(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else if(nombre == FABRICA){
            edificio = new Fabrica(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else if(nombre == ESCUELA){
            edificio = new Escuela(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else if(nombre == MINA){
            edificio = new Mina(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else if(nombre == MINA_ORO){
            edificio = new MinaOro(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else{
            cout << "NO HAY UN EDIFICIO RECONOCIBLE" << endl;
        }

        //Ahora lo agrego a vec de edificios
        if(edificio){
            edificios->insertar(nombre, edificio);
            edificio = NULL; // Sirve cuando NO exista un edificio reconcible no intente agregar otra vez el guardado anterior.
        }

	}

	archivoEdificios.close();
}

void Datos:: cargarDatosMateriales(Vect<Material>* materialesJugador1, Vect<Material>* materialesJugador2){
	fstream archivoMateriales(this->nombreArchivoMateriales, ios::in);
	if(!archivoMateriales.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO " << this->nombreArchivoMateriales << endl;
		archivoMateriales.open(this->nombreArchivoMateriales, ios::out);
		archivoMateriales.close();
		archivoMateriales.open(this->nombreArchivoMateriales, ios::in);
	}

	string nombre, cantMaterial1, cantMaterial2;
	Material* material1;
    Material* material2;

	while(archivoMateriales >> nombre){
		archivoMateriales >> cantMaterial1;
        archivoMateriales >> cantMaterial2;

		material1 = new Material(nombre,(int)stol(cantMaterial1));
		materialesJugador1->agregar(material1);
        material2 = new Material(nombre, (int)stol(cantMaterial2));
        materialesJugador2->agregar(material2);
	}

	archivoMateriales.close();
}

void Datos::cargarDatosMapa(Mapa** mapa){
	fstream archivoMapa(this->nombreArchivoMapa, ios::in);
	if(!archivoMapa.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO " << this->nombreArchivoMapa << endl;
		archivoMapa.open(this->nombreArchivoMapa, ios::out);
		archivoMapa.close();
		archivoMapa.open(this->nombreArchivoMapa, ios::in);
	}

    string cantFilas, cantColumnas;
    archivoMapa >> cantFilas;
    archivoMapa >> cantColumnas;
    *mapa = new Mapa((int)stol(cantFilas),(int)stol(cantColumnas));
    char tipo;
    Casillero* casillero;


    for(int i = 0; i < (int)stol(cantFilas); i++){
        for(int j = 0; j < (int)stol(cantColumnas); j++){
            archivoMapa >> tipo;
            Coordenada coordenada(i,j);

            cout << tipo << " " ;
            
            if(tipo == CAMINO || tipo == BETUN || tipo == MUELLE){
                casillero = new Transitable(tipo);
            }
            else if(tipo == TERRENO){
                casillero = new Construible(tipo);
            }else if(tipo == LAGO){
                casillero = new Inaccesible(tipo);
            }
            //agrego el casillero al mapa esto asumiendo que no vendrá un tipo que no fuera L-T-C
            (*mapa)->agregarCasillero(casillero, coordenada);
        }
        cout << "\n";
    }
	archivoMapa.close();
}

int Datos::obtenerDatoNumerico(string cadena){
    string resultado = "";
    for(int i = 0; i < (int)cadena.length(); i++){
        if(isdigit(cadena[i]))
            resultado += cadena[i];
    }
    return (int)stol(resultado);
}

Coordenada Datos::extraerCoordenada(string ubicacion1, string ubicacion2){
    Coordenada coordenada;
    coordenada.setFila(obtenerDatoNumerico(ubicacion1));
    coordenada.setColumna(obtenerDatoNumerico(ubicacion2));
    return coordenada;
}

void Datos::cargarDatosUbicaciones(Mapa* mapa, Diccionario<Edificio> *edificios, Vect<Coordenada>* ubicacionesJugador1, Vect<Coordenada>* ubicacionesJugador2){
    fstream archivoUbicaciones(this->nombreArchivoUbicaciones, ios::in);
	if(!archivoUbicaciones.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO " << this->nombreArchivoUbicaciones << endl;
		archivoUbicaciones.open(this->nombreArchivoUbicaciones, ios::out);
		archivoUbicaciones.close();
		archivoUbicaciones.open(this->nombreArchivoUbicaciones, ios::in);
	}

 
    Edificio* edificio = NULL;
    Material* material = NULL;

    string nombre,complementoNombre,complementoNombreMina = "";
    string ubicacion1, ubicacion2;

    bool estadoActivoJugador1 = false;
    bool estadoActivoJugador2 = false;
    bool estadoActivoMateriales = true;


    while(archivoUbicaciones >> nombre){

        if(nombre == PLANTA){
            archivoUbicaciones >> complementoNombre;
            nombre = nombre + " " + complementoNombre;
        }

        if(nombre == MINA){
            archivoUbicaciones >> complementoNombreMina;
        }


        if(nombre == MINA && complementoNombreMina != ORO){
            ubicacion1 = complementoNombreMina;
            archivoUbicaciones >> ubicacion2;
        }else{
            if(nombre == MINA && complementoNombreMina == ORO)
                nombre = nombre + " " + complementoNombreMina;
            archivoUbicaciones >> ubicacion1;
            archivoUbicaciones >> ubicacion2;
        }


        //CARGADO DE LAS UBICACIONES DE LOS MATERIALES
        if(estadoActivoMateriales && nombre != JUGADOR1 && nombre != JUGADOR2){ //En caso de que no haya ningún material

            //Asigno la cantidad de material según sea el tipo
            if(nombre == N_MADERA){
                material = new Material(nombre, CANT_MADERA);
            }else if(nombre == N_METAL){
                material = new Material(nombre, CANT_METAL);
            }else if(nombre == N_PIEDRA){
                material = new Material(nombre, CANT_PIEDRA);
            }else if(nombre == N_ANDYCOINS){
                material = new Material(nombre, CANT_ANDYCOINS);
            }

            //Construyo el material en su coordenada correspondiente!
            mapa->getCasillero(extraerCoordenada(ubicacion1, ubicacion2))->construirMaterial(material);
            material = NULL;

        }else if(nombre == JUGADOR1){

            mapa->getCasillero(extraerCoordenada(ubicacion1, ubicacion2))->jugador_entra_casillero((int)stol(JUGADOR1));
            estadoActivoJugador1 = true;
            estadoActivoMateriales = false;

        }else if(nombre == JUGADOR2){

            mapa->getCasillero(extraerCoordenada(ubicacion1, ubicacion2))->jugador_entra_casillero((int)stol(JUGADOR2));
            estadoActivoJugador2 = true;
            estadoActivoJugador1 = false;
        }

        if(estadoActivoJugador1 || estadoActivoJugador2){

            edificio = edificios->buscar(nombre); //Busco si existe en el diccionario de edificios

            if(edificio){
                mapa->getCasillero(extraerCoordenada(ubicacion1,ubicacion2))->construirEdificio(edificio);
                edificio = NULL;
                Coordenada* coordenada = new Coordenada(obtenerDatoNumerico(ubicacion1), obtenerDatoNumerico(ubicacion2));


                if(estadoActivoJugador1)
                    ubicacionesJugador1->agregar(coordenada);
                else if(estadoActivoJugador2)
                    ubicacionesJugador2->agregar(coordenada);
                coordenada = NULL;

            }
        }
    }
    archivoUbicaciones.close();
    mapa->mostrar();

}


void Datos:: guardarDatosMateriales(Vect<Material>* materiales){
	ofstream archivoMateriales(this->nombreArchivoMateriales);
	for(int pos = 0; pos < materiales->obtenerCantidad(); pos++){
		archivoMateriales << materiales->obtenerDato(pos)->getNombre() << ' ' << materiales->obtenerDato(pos)->getCantidad() << '\n';
	}

}

void Datos::gurdarDatosEdificios(Vect<Edificio>* edificios){
	ofstream archivoEdificios(nombreArchivoEdificios);
	for(int pos = 0; pos < edificios->obtenerCantidad(); pos++){
		archivoEdificios << edificios->obtenerDato(pos)->getNombre() << ' '
										 << edificios->obtenerDato(pos)->getCantPiedra() << ' '
										 << edificios->obtenerDato(pos)->getCantMadera() << ' '
										 << edificios->obtenerDato(pos)->getCantMetal() << ' '
										 << edificios->obtenerDato(pos)->getMaxCantPermitidos() << '\n';
	}
}

void Datos::guardarDatosMapa(Mapa* mapa){

    ofstream archivoMapa(this->nombreArchivoMapa);
    archivoMapa << mapa->getCantFilas() << ' ' << mapa->getCantColumnas() << '\n';

    for(int fila = 0; fila < mapa->getCantFilas(); fila++){
        for(int col = 0; col < mapa->getCantColumnas(); col++){
            Coordenada coordenada(fila,col);
            if(col == mapa->getCantColumnas()- 1){
                //Soluciona cuando llega al final de las columnas y no genere un espacio extra al final
                archivoMapa << mapa->getCasillero(coordenada)->getTipo();
            }else
                archivoMapa << mapa->getCasillero(coordenada)->getTipo() << ' ';
        }
        archivoMapa << '\n'; //Hago un salto de línea para generar la siguiente fila
    }
}

void Datos::guardarDatosUbicaciones(Mapa* mapa){
    ofstream archivoUbicaciones(this->nombreArchivoUbicaciones);
    Edificio* edificio = NULL;

    for(int fila = 0; fila < mapa->getCantFilas(); fila++){
        for(int col = 0; col < mapa->getCantColumnas(); col++){
            Coordenada coordenada(fila,col);
            edificio = mapa->getCasillero(coordenada)->getEdificio();
            //Como Construible puede o no tener edificio si lo tiene se tiene que guardar
            //NO me preocupo si es un Casillero Inaccesible o Transitable porque devolveran NULL se aplica bien el polimorfismo
            if(edificio){
                archivoUbicaciones << edificio->getNombre() << ' ' << '(' << coordenada.getFila() << ", " << coordenada.getColumna() << ")\n"; 
            }
        }
    }
}