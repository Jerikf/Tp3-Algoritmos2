#include "../firma/Interfaz.h"
#include <iostream>

//opciones menu inicial
const int MODIFICAR_EDIFICIO_POR_NOMBRE = 1;
const int LISTAR_TODOS_LOS_EDIFICIOS = 2;
const int MOSTRAR_MAPA = 3;
const int COMENZAR_PARTIDA = 4;
const int GUARDAR_SALIR_MENU_INICIAL = 5;

//opciones jugador
const int CONSTRUIR_EDIFICIO_POR_NOMBRE = 1;
const int LISTAR_MIS_EDIFICIOS_CONSTRUIDOS = 2;
const int DEMOLER_EDIFICIO_POR_COORDENADA = 3;
const int ATACAR_EDIFICIO_POR_COORDENADA = 4;
const int REPARAR_EDIFICIO_POR_COORDENADA = 5;
const int COMPRAR_BOMBAS = 6;
const int CONSULTAR_COORDENADA = 7;
const int MOSTRAR_INVENTARIO = 8;
const int MOSTRAR_OBJETIVOS = 9;
const int RECOLECTAR_RECURSOS_PRODUCIDOS = 10;
const int MOVERSE_A_UNA_COORDENADA = 11;
const int FINALIZAR_TURNO = 12;
const int GUARDAR_SALIR = 13;


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

Interfaz::Interfaz(){
    this->juego = new Juego();
}


Interfaz::~Interfaz(){
	delete juego;
}

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

void Interfaz::mostrar_segundo_menu(){
    cout << "\n\n\n";
	cout << "------------------MENU------------------" << endl;
	cout << "1.  CONSTRUIR EDIFICIO POR NOMBRE       |" << endl;
	cout << "2.  LISTAR MIS EDIFICIOS CONSTRUIDOS    |" << endl;
	cout << "3.  DEMOLER UN EDIFICIO POR COORDENADA  |" << endl;
	cout << "4.  ATACAR UN EDIFICIO POR COORDENADA   |" << endl;
	cout << "5.  REPARAR UN EDIFICIO POR COORDENADA  |" << endl;
    cout << "6.  COMPRAR BOMBAS                      |" << endl;
    cout << "7.  CONSULTAR COORDENADA                |" << endl;
    cout << "8.  MOSTRAR INVENTARIO                  |" << endl;
    cout << "9.  MOSTRAR OBJETIVOS                   |" << endl;
	cout << "10. RECOLECTAR RECURSOS PRODUCIDOS      |" << endl;
    cout << "11. MOVERSE A UNA COORDENADA            |" << endl;
    cout << "12. FINALIZAR TURNO                     |" << endl;
    cout << "13. GUARDAR Y SALIR                     |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "\n\n";

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

int Interfaz::iniciarMenuInicial(){
    int opcion = 0;
    while(opcion != COMENZAR_PARTIDA && opcion != GUARDAR_SALIR_MENU_INICIAL ){
        system(CLEAR);
        mostrarMenuInicial();
        opcion = obtenerOpcion(1,5);
        switch (opcion) {
            case MODIFICAR_EDIFICIO_POR_NOMBRE:
                juego->modificar_edificio_por_nombre();
                break;
            case LISTAR_TODOS_LOS_EDIFICIOS:
                juego->mostrar_primer_edificios();
                break;
            case MOSTRAR_MAPA:
                system(CLEAR);
                cout << "		MAPA" << endl;
                this->juego->mostrarMapa();
                cout << "\n";
                break;
            case COMENZAR_PARTIDA:
                //cout << "work in progress" << endl;
                //this->mostrar_segundo_menu();
                break;
            case GUARDAR_SALIR_MENU_INICIAL:
                juego->Gurdar_datos_edificios();
                break;
        }
        if(opcion != COMENZAR_PARTIDA && opcion != GUARDAR_SALIR_MENU_INICIAL)
            volver_menu();
    }
    return opcion;
}


int Interfaz::iniciar_segundo_menu(int jugador){
    int opcion;
	Coordenada coordenada;
    int fila, columna = 0;
	string nombre = "";
	bool salir = false;
	do{
		this->mostrar_segundo_menu();
		opcion = this->obtenerOpcion(1,13);
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
				if(jugador == 1){
					this->juego->construirEdificioPorNombre(nombre, coordenada, juego->obtener_jugador_1());
				}
				else if(jugador == 2){
					this->juego->construirEdificioPorNombre(nombre, coordenada, juego->obtener_jugador_2());
				}
				
				break;

			case LISTAR_MIS_EDIFICIOS_CONSTRUIDOS:
                cout << "work in progress" << endl;
                break;
				/*
				cout << "\n\n\n"; //en caso no funcione en windows el limpiar :v
				system(CLEAR); 
				this->juego->listarEdificiosConstruidos();
				cout << "\n\n";
				break;
				*/
			    //cout << "Error " << endl;

			/*case LISTAR_TODOS_LOS_EDIFICIOS:

                cout << "\n\n\n";
				system(CLEAR);
                this->juego->listarTodosLosEdificios();
				break;*/

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
				if(jugador == 1){
					this->juego->demolerEdificioPorCoordenada(coordenada, juego->obtener_jugador_1());
				}
				else if(jugador == 2){
					this->juego->demolerEdificioPorCoordenada(coordenada, juego->obtener_jugador_2());
				}
				break;
				

			case ATACAR_EDIFICIO_POR_COORDENADA:
                cout << "work in progress" << endl;
				break;

            case REPARAR_EDIFICIO_POR_COORDENADA:
                cout << "work in progress" << endl;
                break;

            case COMPRAR_BOMBAS:
                cout << "work in progress" << endl;
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
				if(jugador == 1){
					this->juego->mostrarInventario(juego->obtener_jugador_1());
				}
				else if(jugador == 2){
					this->juego->mostrarInventario(juego->obtener_jugador_2());
				}
				break;

            case MOSTRAR_OBJETIVOS:
                cout << "work in progress" << endl;
                break;

			case RECOLECTAR_RECURSOS_PRODUCIDOS:
                /*
				cout << "\n\n\n";
				system(CLEAR);
				cout << "RECOLECTOR DE RECURSOS PRODUCIDOS" << endl;
				this->juego->recolectarRecursosProducidos();
				break;
				*/
			cout << "Error" << endl;

            case MOVERSE_A_UNA_COORDENADA:
                cout << "work in progress" << endl;
                break;

            case FINALIZAR_TURNO:
                salir = true;
                break;

            case GUARDAR_SALIR:
                /*cout << "\n\n\n";
                system(CLEAR);
                cout << "GUARDAR Y SALIR" << endl;
                this->juego->guardarSalir();*/
                salir = true;
                cout << "work in progress" << endl;
                break;

			default :
				cout << "INGRESÒ UNA OPCIÓN INCORRECTA!!!" << endl;
				break;
		}
	}while(!salir);

    return opcion;
}

void Interfaz::iniciar(){
	juego->inicializarCargadoDatos();
    bool terminoJuego = false;
    if(!juego->obtener_esta_ubicaciones() || juego->obtener_cant_lineas() == 0) {
        system(CLEAR);
        if (iniciarMenuInicial() == COMENZAR_PARTIDA) {
            while(!terminoJuego){
                system(CLEAR);
                cout << "MENU JUGADOR 1" << endl;
                if(iniciar_segundo_menu(1) == GUARDAR_SALIR)
                    terminoJuego = true;
                if(!terminoJuego) {
                    system(CLEAR);
                    cout << "MENU JUGADOR 2" << endl;
                    if (iniciar_segundo_menu(2) == GUARDAR_SALIR)
                        terminoJuego = true;
                }
            }
        }
    }
    else{//esto deberia ser jugar_juego
        while(!terminoJuego){
            system(CLEAR);
            cout << "MENU JUGADOR 1" << endl;
            if(iniciar_segundo_menu(1) == GUARDAR_SALIR)
                terminoJuego = true;
            if(!terminoJuego) {
                system(CLEAR);
                cout << "MENU JUGADOR 2" << endl;
                if (iniciar_segundo_menu(2) == GUARDAR_SALIR)
                    terminoJuego = true;
            }
        }
    }
    cout << "\n\n\n-------------------------HASTA LA PRÓXIMA-----------------------" << endl;
}


