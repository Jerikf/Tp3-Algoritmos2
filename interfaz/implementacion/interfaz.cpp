#include "../firma/Interfaz.h"
#include <iostream>

//opciones menu inicial
const int MODIFICAR_EDIFICIO_POR_NOMBRE = 1;
const int LISTAR_TODOS_LOS_EDIFICIOS_INICIAL = 2;
const int MOSTRAR_MAPA_INICIAL = 3;
const int COMENZAR_PARTIDA = 4;
const int GUARDAR_Y_SALIR = 5;

//opciones jugador
const int CONSTRUIR_EDIFICIO_POR_NOMBRE = 1;
const int LISTAR_LOS_EDIFICIOS_CONSTRUIDOS = 2;
const int LISTAR_TODOS_LOS_EDIFICIOS = 3;
const int DEMOLER_EDIFICIO_POR_COORDENADA = 4;
const int MOSTRAR_MAPA = 5;
const int CONSULTAR_COORDENADA = 6;
const int MOSTRAR_INVENTARIO = 7;
const int RECOLECTAR_RECURSOS_PRODUCIDOS = 8;
const int LLUVIA_DE_RECURSOS = 9;
const int GUARDAR_SALIR = 10;


#ifdef _WIN32
    const char* CLEAR = "cls";
#else

    const char* CLEAR = "clear";

#endif

bool Interfaz::validarOpcion(int opcion, int limiteInferior, int limiteSuperior){
    return (opcion >= limiteInferior && opcion <= limiteSuperior);
}

int Interfaz::obtenerOpcion( int limiteInferior, int limiteSuperior ){
    int opcion = 0;
	bool esValido = false;
	while(!esValido) {
        cout << "SELECCIONE UNA OPCIÒN DEL " << limiteInferior << " AL " << limiteSuperior << endl;
        cin >> opcion;
        if (validarOpcion(opcion, limiteInferior, limiteSuperior))
            esValido = true;
        else {
            system(CLEAR);
            cout << "OPCIÓN INCORRECTA. LAS OPCIONES SON ENTRE " << limiteInferior << " Y " << limiteSuperior << endl;
        }
    }
	return opcion;
}

Interfaz::Interfaz(Juego* juego){
    this->juego = juego;
}

Interfaz::~Interfaz(){}

void Interfaz::mostrarMenuInicial(){
    cout << "╔═════════════╗" << endl;
    cout << "║ Preparacion:║ " << endl;
    cout << "╚═════════════╝" << endl;

    cout << "\t" << "╔════════════════════════════════════════╗" << endl;
    cout << "\t" << "║ 1)- Modificar edificio por nombre.     ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 2)- Listar todos los edificios.        ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 3)- Mostrar mapa.                      ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 4)- Comenzar partida.                  ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 5)- Guardar y salir.                   ║" << endl;
    cout << "\t" << "╚════════════════════════════════════════╝" << endl;
}

void Interfaz::volver_menu(){

    cout << "        " << "╔══════════════════════════════╗" << endl;
    cout << "        " << "║Oprima 0 para volver al menu: ║" << endl;
    cout << "        " << "╚══════════════════════════════╝" << endl;

    string numero = "1";
    cin >> numero;

    while (numero != "0"){
        cout << "            " << "╔══════════════════════════╗" << endl;
        cout << "            " << "║ ----CARACTER INVALIDO----║" << endl;
        cout << "            " << "╚══════════════════════════╝" << endl;

        cout << endl;
        cout << "          " << "╔══════════════════════════════╗" << endl;
        cout << "          " << "║Oprima 0 para volver al menu: ║" << endl;
        cout << "          " << "╚══════════════════════════════╝" << endl;

        cin >> numero;
    }
}

void Interfaz::iniciarMenuInicial(){
    int opcion = 0;
    while(opcion != COMENZAR_PARTIDA && opcion != GUARDAR_Y_SALIR ){
        system(CLEAR);
        mostrarMenuInicial();
        opcion = obtenerOpcion(1,5);
        switch (opcion) {
            case MODIFICAR_EDIFICIO_POR_NOMBRE:
                cout << "work in progress" << endl;
                break;
            case LISTAR_TODOS_LOS_EDIFICIOS_INICIAL:
                cout << "work in progress" << endl;
                break;
            case MOSTRAR_MAPA_INICIAL:
                system(CLEAR);
                cout << "		MOSTRANDO MAPA" << endl;
                this->juego->mostrarMapa();
                cout << "\n";
                break;
            case COMENZAR_PARTIDA:
                cout << "work in progress" << endl;
                break;
            case GUARDAR_Y_SALIR:
                cout << "work in progress" << endl;
                break;
        }
        if(opcion != COMENZAR_PARTIDA && opcion != GUARDAR_Y_SALIR)
            volver_menu();
    }
}

void Interfaz::iniciar(){

    /*int opcion ;
	Coordenada coordenada;
    int fila, columna = 0;
	string nombre = "";
	bool salir = false;*/

    iniciarMenuInicial();

    //esto va a ser el menu del jugador
	/*do{
		this->juego->mostrarMenu();
		opcion = this->obtenerOpcion();
		switch (opcion){
			case CONSTRUIR_EDIFICIO_POR_NOMBRE:

				system(CLEAR);
                cout << "\n\n\n";
				cout << "		CONSTRUCCIÓN DEL EDIFICIO" << endl;
				cout << "\nINGRESE EL NOMBRE DEL EDIFICIO PARA CONSTRUIRLO" << endl;
				cin >> nombre;
				cout << "\n" ;

                cout << "\n SE PEDIRÁ UNA COORDENADA INGRESANDO PRIMERO LA FILA Y LUEGO LA COLUMNA" << endl;
                cout << "\nINGRESE LA FILA" << endl;
                cin >> fila;
                cout << "\nINGRESE LA COLUMNA" << endl;
                cin >> columna;

                coordenada.setFila(fila);
				coordenada.setColumna(columna);
				system(CLEAR);
				this->juego->construirEdificioPorNombre(nombre, coordenada);
				break;

			case LISTAR_LOS_EDIFICIOS_CONSTRUIDOS:

				cout << "\n\n\n"; //en caso no funcione en windows el limpiar :v
				system(CLEAR); 
				this->juego->listarEdificiosConstruidos();
				cout << "\n\n";
				break;

			case LISTAR_TODOS_LOS_EDIFICIOS:

                cout << "\n\n\n";
				system(CLEAR);
                this->juego->listarTodosLosEdificios();
				break;

			case DEMOLER_EDIFICIO_POR_COORDENADA:

				system(CLEAR);
                cout << "\n\n\n";
				cout << "DEMOLICIÓN DE UN EDIFICIO POR COORDENADA" << endl;
                cout << "\nINGRESE LA FILA" << endl;
                cin >> fila;
                cout << "\nINGRESE LA COLUMNA" << endl;
                cin >> columna;

                coordenada.setFila(fila);
				coordenada.setColumna(columna);
				system(CLEAR);
				this->juego->demolerEdificioPorCoordenada(coordenada);
				break;

			case MOSTRAR_MAPA:
				cout << "\n\n\n";
				system(CLEAR);
				cout << "		SE MOSTRARÁ EL MAPA" << endl;
				this->juego->mostrarMapa();

				cout << "\n\n";
				break;

			case CONSULTAR_COORDENADA:
				system(CLEAR);
				cout << "\n\n\n";
				cout << "CONSULTAR COORDENADA" << endl;
				cout << "\nINGRESE LA FILA" << endl;
                cin >> fila;
                cout << "\nINGRESE LA COLUMNA" << endl;
                cin >> columna;

				coordenada.setFila(fila);
				coordenada.setColumna(columna);
				system(CLEAR);
				this->juego->consultarCoordenada(coordenada);
				break;

			case MOSTRAR_INVENTARIO:
				cout << "\n\n\n\n\n";
				system(CLEAR);
				cout << "		MUESTRA DE INVENTARIO" << endl;
				this->juego->mostrarInventario();
				break;

			case RECOLECTAR_RECURSOS_PRODUCIDOS:

				cout << "\n\n\n";
				system(CLEAR);
				cout << "RECOLECTOR DE RECURSOS PRODUCIDOS" << endl;
				this->juego->recolectarRecursosProducidos();
				break;

			case LLUVIA_DE_RECURSOS:

				cout << "\n\n\n";
				this->juego->lluviaDeRecursos();
				system(CLEAR);
				cout << "LLUVIA DE RECURSOS | SI HUBO ESPACIO EN LOS CAMINOS SE COMPLETÓ CORRECTAMENTE" << endl;
				break;

			case GUARDAR_SALIR:

				cout << "\n\n\n";
				system(CLEAR);
				cout << "GUARDAR Y SALIR" << endl;
				this->juego->guardarSalir();
				salir = true;
				break;

			default :
				cout << "INGRESÒ UNA OPCIÓN INCORRECTA!!!" << endl;
				break;
		}
	}while(!salir);
    */
	cout << "\n\n\n-------------------------HASTA LA PRÓXIMA-----------------------" << endl;
}


