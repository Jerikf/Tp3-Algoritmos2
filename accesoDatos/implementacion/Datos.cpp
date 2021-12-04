#include "../modelo/Datos.h"
#include <iostream>
#include <fstream>

const string PLATAN_ELECTRICA = "planta electrica";
const string ASERRADERO = "aserradero";
const string OBELISCO = "obelisco";
const string FABRICA = "fabrica";
const string ESCUELA = "escuela";
const string MINA = "mina";
const string PLANTA = "planta";

const char LAGO = 'L';
const char TERRENO = 'T';
const char CAMINO = 'C';
const char BETUN = 'B';
const char MUELLE = 'M';

Datos::Datos(string nombreArchivoEdificios, string nombreArchivoMateriales, string nombreArchivoMapa, string nombreArchivoUbicaciones){
    this->nombreArchivoEdificios = nombreArchivoEdificios;
    this->nombreArchivoMateriales = nombreArchivoMateriales;
	this->nombreArchivoMapa = nombreArchivoMapa;
	this->nombreArchivoUbicaciones = nombreArchivoUbicaciones;
}

Datos::~Datos(){}

void Datos:: cargarDatosEdificios(Vect<Edificio>* edificios){

    fstream archivoEdificios(this->nombreArchivoEdificios, ios::in);
	if(!archivoEdificios.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO" << endl;
		archivoEdificios.open(this->nombreArchivoEdificios, ios::out);
		archivoEdificios.close();
		archivoEdificios.open(this->nombreArchivoEdificios, ios::in);
	}
	string nombre, nombreComplemento, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos;
	Edificio* edificio = NULL;
	while(archivoEdificios >> nombre){
        if(nombre == PLANTA){
            archivoEdificios >> nombreComplemento;
        }
		archivoEdificios >> cantPiedra;
		archivoEdificios >> cantMadera;
		archivoEdificios >> cantMetal;
		archivoEdificios >> cantMaxPermitidos;

		// verifico que edificio es y asigno los valores
        if(nombre + " " + nombreComplemento == PLATAN_ELECTRICA){
            edificio = new PlantaElectrica(nombre + " " + nombreComplemento,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
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
        }else{
            cout << "NO HAY UN EDIFICIO RECONOCIBLE" << endl;
        }

        //Ahora lo agrego a vec de edificios
        if(edificio){
            edificios->agregar(edificio);
            edificio = NULL; // Sirve cuando NO exista un edificio reconcible no intente agregar otra vez el guardado anterior.
        }

	}

	archivoEdificios.close();
}

void Datos:: cargarDatosMateriales(Vect<Material>* materiales){
	fstream archivoMateriales(this->nombreArchivoMateriales, ios::in);
	if(!archivoMateriales.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO " << this->nombreArchivoMateriales << endl;
		archivoMateriales.open(this->nombreArchivoMateriales, ios::out);
		archivoMateriales.close();
		archivoMateriales.open(this->nombreArchivoMateriales, ios::in);
	}

	string nombre, cantMaterial;
	Material* material;

	while(archivoMateriales >> nombre){
		archivoMateriales >> cantMaterial;

		material = new Material(nombre,(int)stol(cantMaterial));
		materiales->agregar(material);
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

Coordenada Datos::extraerCoordenada(string ubicacion1, string ubicacion2){
    Coordenada coordenada;
    string filaAConvertir, columnaAConvertir;

    //obtengo los datos numéricos(en string)
    filaAConvertir = ubicacion1[1];
    columnaAConvertir = ubicacion2[0];

    //convierto los datos a int y los seteo a la coordenada
    coordenada.setFila((int)stol(filaAConvertir));
    coordenada.setColumna((int)stol(columnaAConvertir));
    return coordenada;
}

void Datos::cargarDatosUbicaciones(Mapa* mapa, Vect<Edificio> *edificios){
    fstream archivoUbicaciones(this->nombreArchivoUbicaciones, ios::in);
	if(!archivoUbicaciones.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO " << this->nombreArchivoUbicaciones << endl;
		archivoUbicaciones.open(this->nombreArchivoUbicaciones, ios::out);
		archivoUbicaciones.close();
		archivoUbicaciones.open(this->nombreArchivoUbicaciones, ios::in);
	}

    Edificio* edificio = NULL;

    string nombre,complementoNombre;
    string ubicacion1, ubicacion2;


    while(archivoUbicaciones >> nombre){
        if(nombre == PLANTA){
            archivoUbicaciones >> complementoNombre;
            nombre = nombre + " " + complementoNombre;
        }
        archivoUbicaciones >> ubicacion1;
        archivoUbicaciones >> ubicacion2;
        int pos = 0;
        bool seEncontro = false;
        //Busco si existe en el vect de edificios
        while( !seEncontro && pos < edificios->obtenerCantidad()){
            if(edificios->obtenerDato(pos)->getNombre() == nombre){
                edificio = edificios->obtenerDato(pos);
                seEncontro = true;
            }
            pos++;
        }
        //silo encontré construiré el edificio en dicho casillero(en caso de que la coordenada esté mal
        //y sea de un casillero Inaccesible no habrá problemas porque construirEdificio lo redifinen
        //todos los casilleros, responde al mensaje según sea su caso correspondiente)
        if(seEncontro){
            mapa->getCasillero(extraerCoordenada(ubicacion1,ubicacion2))->construirEdificio(edificio);
            edificio = NULL;
        }
    }
    archivoUbicaciones.close();
    //mapa->mostrar();

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