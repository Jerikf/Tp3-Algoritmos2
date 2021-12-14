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
const int DEMOLER_EDIFICIO_POR_COORDENADA = 3;
const int ATACAR_EDIFICIO_POR_COORDENADA = 4;
const int REPARAR_EDIFICIO_POR_COORDENADA = 5;
const int COMPRAR_BOMBAS = 6;
const int CONSULTAR_COORDENADA = 7;
const int MOSTRAR_INVENTARIO = 8;
const int MOSTRAR_OBJETIVOS = 9;
const int RECOLECTAR_RECURSOS = 10;
const int MOVERSE_A_COORDENADA = 11;
const int FINALIZAR_TURNO = 12;
const int GUARDAR_Y_SALIR_DOS = 13;

const int JUGADOR1 = 1;
const int JUGADOR2 = 2;

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

void Interfaz::mostrar_segundo_menu(int numero){

    if(numero == 1){
        cout << "╔══════════════════════════════════════════════════════════════════════════════════════╗" << endl;
        cout << "║ Gestor de construccion de Andypolis del Jugador 1, seleccione alguna de las opciones:║ " << endl;
        cout << "╚══════════════════════════════════════════════════════════════════════════════════════╝" << endl;

        cout << "Cantidad de energia: " << juego->obtener_jugador_1()->obtener_cant_energia() << endl;
    }
    else if(numero == 2){
        cout << "╔══════════════════════════════════════════════════════════════════════════════════════╗" << endl;
        cout << "║ Gestor de construccion de Andypolis del Jugador 2, seleccione alguna de las opciones:║ " << endl;
        cout << "╚══════════════════════════════════════════════════════════════════════════════════════╝" << endl;

        cout << "Cantidad de energia: " << juego->obtener_jugador_2()->obtener_cant_energia() << endl;
    }


    cout << "\t" << "╔════════════════════════════════════════╗" << endl;
    cout << "\t" << "║ 1)- Construir edificio por nombre.     ║" << endl;
    cout << "\t" << "║   - Energia necesaria: 15.             ║" << endl;
    cout << "\t" << "║ 2)- Listar edificios construidos.      ║" << endl;
    cout << "\t" << "║   - Energia necesaria: 0.              ║" << endl;
    cout << "\t" << "║ 3)- Demoler edificio por coordenada.   ║" << endl;
    cout << "\t" << "║   - Energia necesaria: 15.             ║" << endl;
    cout << "\t" << "║ 4)- Atacar edifcio por coordenada.     ║" << endl;
    cout << "\t" << "║   - Energia necesaria: 30.             ║" << endl;
    cout << "\t" << "║ 5)- Reparar edificio por coordenada.   ║" << endl;
    cout << "\t" << "║   - Energia necesaria: 25.             ║" << endl;
    cout << "\t" << "║ 6)- Comprar bombas.                    ║" << endl;
    cout << "\t" << "║   - Energia necesaria: 5.              ║" << endl;
    cout << "\t" << "║ 7)- Consultar coordenadas.             ║" << endl;
    cout << "\t" << "║   - Energia necesaria: 0.              ║" << endl;
    cout << "\t" << "║ 8)- Mostrar inventario.                ║" << endl;
    cout << "\t" << "║   - Energia necesaria: 0.              ║" << endl;
    cout << "\t" << "║ 9)- Mostrar objetivos.                 ║" << endl;
    cout << "\t" << "║   - Energia necesaria: 0.              ║" << endl;
    cout << "\t" << "║ 10)- Recolectar recursos producidos.   ║" << endl;
    cout << "\t" << "║    - Energia necesaria: 20.            ║" << endl;
    cout << "\t" << "║ 11)- Moverse a una coordenada.         ║" << endl;
    cout << "\t" << "║    - Energia necesaria: Varia.         ║" << endl;
    cout << "\t" << "║ 12)- Finalizar turno.                  ║" << endl;
    cout << "\t" << "║    - Energia necesaria: 0.             ║" << endl;
    cout << "\t" << "║ 13)- Guardar y salir.                  ║" << endl;
    cout << "\t" << "║    - Energia necesaria: 0.             ║" << endl;
    cout << "\t" << "╚════════════════════════════════════════╝" << endl;

}

void Interfaz::volver_menu(int numero){

    if(numero == 1){
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
    else{

        cout << "        " << "╔════════════════════════════════╗" << endl;
        cout << "        " << "║Oprima 0 para cambiar de turno: ║" << endl;
        cout << "        " << "╚════════════════════════════════╝" << endl;

        string numero = "1";
        cin >> numero;

        while (numero != "0"){
            cout << "            " << "╔══════════════════════════╗" << endl;
            cout << "            " << "║ ----CARACTER INVALIDO----║" << endl;
            cout << "            " << "╚══════════════════════════╝" << endl;

            cout << endl;
            cout << "          " << "╔════════════════════════════════╗" << endl;
            cout << "          " << "║Oprima 0 para cambiar de turno: ║" << endl;
            cout << "          " << "╚════════════════════════════════╝" << endl;

            cin >> numero;
        }


    }

}

void Interfaz::establecer_posicion_personaje(int jugador){

    cout << "Acaba de elegir al jugador " << jugador <<", ahora ponga las coordenadas de aparacicion: "  << endl;

    bool exito = false;
    while(!exito){

        juego->mostrarMapa();
        cout << "Fila: ";
        int fila;
        cin >> fila;
        int columna;
        cout << "Columna: ";
        cin >> columna;

        Coordenada coordenada_jugador;
        coordenada_jugador.setFila(fila);
        coordenada_jugador.setColumna(columna);

        if(fila > 0 && fila < juego->obtener_mapa()->getCantFilas() && columna > 0 && columna < juego->obtener_mapa()->getCantColumnas()){

            cout << "Las coordenadas no son validas, vuelva a intentarar." << endl;
        }
        else{
            if(!(juego->obtener_mapa()->getCasillero(coordenada_jugador)->getTipo() == 'T')){
                cout << "No es un casillero transitable, ponga otras coordenadas." << endl;
            }
            else{
                juego->obtener_mapa()->getCasillero(coordenada_jugador)->jugador_entra_casillero(jugador);
                cout << "El jugador " << jugador << " esta en (" << fila << ", " << columna << ")" << endl;
                exito = true;
            }
        }


    }


}

void Interfaz::establecer_jugadores(int jugador){

    while(jugador != 1 && jugador != 2){
        cout << "No es un numero valido, elija entre 1 o 2" << endl;
        cin >> jugador;
    }

    establecer_posicion_personaje(jugador);

    int descarte;
    if(jugador == 1){
        descarte = jugador + 1;
    }
    else if(jugador == 2){
        descarte = jugador - 1;
    }

    cout << "Ahora sigue con el jugador " << descarte << "." << endl;

    establecer_posicion_personaje(descarte);
}

void Interfaz::elegir_personaje(){



    cout << "Elija al jugador 1 (1) o jugador 2 (2). " << endl;

    int jugador;
    cin >> jugador;

    establecer_jugadores(jugador);

}

bool Interfaz::verificar_energia(Jugador* jugador, int opcion){

    bool energia_suficiente = true;

    if(opcion == CONSTRUIR_EDIFICIO_POR_NOMBRE){
        if(jugador->obtener_cant_energia() < 15){
            energia_suficiente = false;
        }
    }
    else if(opcion == DEMOLER_EDIFICIO_POR_COORDENADA){
        if(jugador->obtener_cant_energia() < 15){
            energia_suficiente = false;
        }
    }
    else if(opcion == ATACAR_EDIFICIO_POR_COORDENADA){
        if(jugador->obtener_cant_energia() < 30){
            energia_suficiente = false;
        }
    }
    else if(opcion == REPARAR_EDIFICIO_POR_COORDENADA){
        if(jugador->obtener_cant_energia() < 25){
            energia_suficiente = false;
        }
    }
    else if(opcion == COMPRAR_BOMBAS){
        if(jugador->obtener_cant_energia() < 5){
            energia_suficiente = false;
        }
    }
    else if(opcion == RECOLECTAR_RECURSOS){
        if(jugador->obtener_cant_energia() < 20){
            energia_suficiente = false;
        }
    }

    return energia_suficiente;
}

void Interfaz::modificar_energia(Jugador* jugador, int opcion){

    if(opcion == CONSTRUIR_EDIFICIO_POR_NOMBRE){
        jugador->establecer_energia(jugador->obtener_cant_energia() - 15);
    }
    else if(opcion == DEMOLER_EDIFICIO_POR_COORDENADA){
        jugador->establecer_energia(jugador->obtener_cant_energia() - 15);
    }
    else if(opcion == ATACAR_EDIFICIO_POR_COORDENADA){
        jugador->establecer_energia(jugador->obtener_cant_energia() - 30);
    }
    else if(opcion == REPARAR_EDIFICIO_POR_COORDENADA){
        jugador->establecer_energia(jugador->obtener_cant_energia() - 25);
    }
    else if(opcion == COMPRAR_BOMBAS){
        jugador->establecer_energia(jugador->obtener_cant_energia() - 5);
    }
    else if(opcion == RECOLECTAR_RECURSOS){
        jugador->establecer_energia(jugador->obtener_cant_energia() - 20);
    }
    else if(opcion == FINALIZAR_TURNO){
        cout << "SE ACABA DE FINALIZAR EL TURNO. " << endl;
        cout << "Acaba de obtener 20 de energia." << endl;
        if((jugador->obtener_cant_energia() + 20) > 100){
            cout << "NO SE PUEDE TENER MAS DE 100 DE ENERGIA POR TURNO." << endl;
            jugador->establecer_energia(100);
            cout << "LE QUEDARA 100 DE ENERGIA." << endl;
        }
        else{
            jugador->establecer_energia(jugador->obtener_cant_energia() + 20);
        }
    }


}

void Interfaz::seleccionar_jugador_energia(int numero, int opcion){

    if(numero == 1){

        if(verificar_energia(juego->obtener_jugador_1(), opcion)){

            modificar_energia(juego->obtener_jugador_1(), opcion);
        }
        else{
            cout << "No tiene energia suficienta para realizar la accion." << endl;
        }
    }
    else if(numero == 2){

        if(verificar_energia(juego->obtener_jugador_2(), opcion)){

            modificar_energia(juego->obtener_jugador_2(), opcion);
        }
        else{
            cout << "No tiene energia suficienta para realizar la accion." << endl;
        }
    }


}

void Interfaz::iniciarMenuInicial(){
    int opcion = 0;
    while(opcion != COMENZAR_PARTIDA && opcion != GUARDAR_Y_SALIR ){
        system(CLEAR);
        opcion = obtenerOpcion(1,5);
        switch (opcion) {
            case MODIFICAR_EDIFICIO_POR_NOMBRE:
                juego->modificar_edificio_por_nombre();
                volver_menu(1);
                break;
            case LISTAR_TODOS_LOS_EDIFICIOS_INICIAL:
                juego->mostrar_primer_edificios();
                volver_menu(1);
                break;
            case MOSTRAR_MAPA_INICIAL:
                system(CLEAR);
                cout << "		MAPA" << endl;
                this->juego->mostrarMapa();
                cout << "\n";
                volver_menu(1);
                break;
            case COMENZAR_PARTIDA:
                elegir_personaje();
                correr_juego();
                break;
            case GUARDAR_Y_SALIR:
                juego->Gurdar_datos_edificios();
                break;
        }
        if(opcion != COMENZAR_PARTIDA && opcion != GUARDAR_Y_SALIR){}
    }
}

bool Interfaz::esCoordenadaValida(Coordenada coordenada){
    if (coordenada.getFila() >= juego->obtener_mapa()->getCantFilas() || coordenada.getFila() < 0 ||
        coordenada.getColumna() >= juego->obtener_mapa()->getCantColumnas() || coordenada.getColumna() < 0){
        cout << "Coordenada invalida" << endl;
        return false;
    }
    else return true;

    //int opcion ;
}

bool Interfaz::puedoMoverJugadorACoordenada( Coordenada puntoInicial, Coordenada* puntoFinal, Grafo* grafo, int* costoCamino, int energiaJugador ){
    juego->mostrarMapa();
    int fil, col;
    Casillero* casilleroActual;
    bool puedoMoverJugador = false;
    cout << "Ingrese coordenada a la que desea moverse: " << endl;
    cout << "Fila: ";
    cin >> fil;
    cout << "Columna: ";
    cin >> col;
    puntoFinal->setFila(fil);
    puntoFinal->setColumna(col);
    if(esCoordenadaValida(*puntoFinal)){
        casilleroActual = juego->obtener_mapa()->getCasillero(*puntoFinal);
        if( casilleroActual->devolver_jugador_casillero() != 0 || casilleroActual->getEdificio() != nullptr ) {
            cout << "La coordenada dada se encuentra ocupada" << endl;
            return false;
        }
        else puedoMoverJugador = true;
    }
    //grafo->actualizar_grafo(juego->obtener_mapa());
    (*costoCamino) = grafo->obtenerCostoCamino(puntoInicial, (*puntoFinal));
    if( (*costoCamino) > energiaJugador){
        cout << "No se cuenta con la energía suficiente para realizar el recorrido" << endl;
        return false;
    }
    string x;
    cout << "Costo recorrido: " << (*costoCamino) << endl << "Desea realizarlo?: Si | No" << endl;
    cin >> x;
    if( x != "Si" && x != "si") {
        cout << "No se realizo el recorrido" << endl;
        return false;
    }
    //aca deberia restar la energia del jugador
    return puedoMoverJugador;
}

int Interfaz::iniciar_segundo_menu(int jugador){
    int opcion;
    
    string nombre = "";
    bool salir = false;
    while(!salir){
        juego->obtener_mapa()->mostrar();
        this->mostrar_segundo_menu(jugador);
        opcion = this->obtenerOpcion(1,13);
        if(opcion == CONSTRUIR_EDIFICIO_POR_NOMBRE){

			Coordenada coordenada;
			int fila, columna;
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

			if(jugador == JUGADOR1)
				this->juego->construirEdificioPorNombre(nombre, coordenada, juego->obtener_jugador_1());
			else
				this->juego->construirEdificioPorNombre(nombre, coordenada, juego->obtener_jugador_2());

			juego->obtener_jugador_1()->obtener_coordenadasDeEdificiosConstruidos()->mostrar();
			cout << juego->obtener_jugador_1()->obtener_cant_energia() << endl;

			
            

            

            volver_menu(1);
        }
        else if(opcion == LISTAR_LOS_EDIFICIOS_CONSTRUIDOS){

            /*
            cout << "\n\n\n"; //en caso no funcione en windows el limpiar :v
            system(CLEAR);
            this->juego->listarEdificiosConstruidos();
            cout << "\n\n";
            break;
            */
            cout << "Error" << endl;
            volver_menu(1);
        }
        else if(opcion == DEMOLER_EDIFICIO_POR_COORDENADA){

            seleccionar_jugador_energia(jugador, opcion);

            //cout << "\n\n\n";
            //system(CLEAR);
            //this->juego->listarTodosLosEdificios();
            volver_menu(1);
        }
        else if(opcion == ATACAR_EDIFICIO_POR_COORDENADA){


            seleccionar_jugador_energia(jugador, opcion);

            /*system(CLEAR);
            cout << "\n\n\n";
            cout << "DEMOLICIÓN DE UN EDIFICIO POR COORDENADA" << endl;
            cout << "\nINGRESE LA FILA" << endl;
            cin >> fila;
            cout << "\nINGRESE LA COLUMNA" << endl;
            cin >> columna;

            coordenada.setFila(fila);
            coordenada.setColumna(columna);
            system(CLEAR);
            if(numero == 1){
                this->juego->demolerEdificioPorCoordenada(coordenada, juego->obtener_jugador_1());
            }
            else if(numero == 2){
                this->juego->demolerEdificioPorCoordenada(coordenada, juego->obtener_jugador_2());
            }
            */
            volver_menu(1);
        }
        else if(opcion == REPARAR_EDIFICIO_POR_COORDENADA){

            seleccionar_jugador_energia(jugador, opcion);

            /*
            cout << "\n\n\n";
            system(CLEAR);
            cout << "		SE MOSTRARÁ EL MAPA" << endl;
            this->juego->mostrarMapa();
            */

            volver_menu(1);
        }
        else if(opcion == COMPRAR_BOMBAS){

            seleccionar_jugador_energia(jugador, opcion);

            if(jugador == 1){
                juego->comprar_bombas(juego->obtener_jugador_1());
            }
            else if(jugador == 2){
                juego->comprar_bombas(juego->obtener_jugador_2());
            }


            volver_menu(1);
        }
        else if(opcion == CONSULTAR_COORDENADA){

            /*
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
            */

            cout << "Error" << endl;
            volver_menu(1);
        }
        else if(opcion == MOSTRAR_INVENTARIO){


            system(CLEAR);
            if(jugador == 1){
                this->juego->mostrarInventario(juego->obtener_jugador_1());
            }
            else if(jugador == 2){
                this->juego->mostrarInventario(juego->obtener_jugador_2());
            }

            volver_menu(1);
        }
        else if(opcion == MOSTRAR_OBJETIVOS){

            /*
            cout << "\n\n\n";
            this->juego->lluviaDeRecursos();
            system(CLEAR);
            cout << "LLUVIA DE RECURSOS | SI HUBO ESPACIO EN LOS CAMINOS SE COMPLETÓ CORRECTAMENTE" << endl;
            break;
            */
            cout << "Error" << endl;
            volver_menu(1);
        }
        else if(opcion == RECOLECTAR_RECURSOS){

            seleccionar_jugador_energia(jugador, opcion);

            if(jugador == 1){
                juego->recolectar_recursos(juego->obtener_jugador_1());
            }
            else if(jugador == 2){
                juego->recolectar_recursos(juego->obtener_jugador_2());
            }

            volver_menu(1);
        }
        else if(opcion == MOVERSE_A_COORDENADA){
            Coordenada puntoInicial, puntoFinal;
            Grafo * grafo;
            int energiaJugador, costoCamino;
            if(jugador == JUGADOR1) {
                grafo = juego->obtener_jugador_1()->obtener_grafo();
                energiaJugador = juego->obtener_jugador_1()->obtener_cant_energia();
                puntoInicial = juego->obtener_jugador_1()->obtenerMiPosicion(1, juego->obtener_mapa());
            }
            else{
                grafo = juego->obtener_jugador_2()->obtener_grafo();
                energiaJugador = juego->obtener_jugador_2()->obtener_cant_energia();
                puntoInicial = juego->obtener_jugador_1()->obtenerMiPosicion(2, juego->obtener_mapa());
            }
            if(puedoMoverJugadorACoordenada(puntoInicial, &puntoFinal, grafo, &costoCamino, energiaJugador)){
                string x;
                int topeCamino;
                Coordenada* coordenadasCamino = grafo->obtener_camino_minimo(puntoInicial, puntoFinal, &topeCamino, &costoCamino);
                cout << "Costo camino: " << costoCamino << endl;
                for (int i = 0; i < topeCamino; i++){
                    cout << "(" << coordenadasCamino[i].getFila() << ";" << coordenadasCamino[i].getColumna() << ") ";
                }
                cout << endl;
                cout << "Ingrese cualquier tecla para avanzar";
                cin >> x;
                juego->obtener_mapa()->mostrar_recorrido_jugador(coordenadasCamino, topeCamino, jugador);
                delete[] coordenadasCamino;
            }
            volver_menu(1);
        }
    else if(opcion == FINALIZAR_TURNO){

        salir = true;
        if(jugador == 1){
            modificar_energia(juego->obtener_jugador_1(), opcion);
        }
        else if(jugador == 2){
            modificar_energia(juego->obtener_jugador_2(), opcion);
        }
        volver_menu(2);
    }
    else if(opcion == GUARDAR_Y_SALIR_DOS){

        cout << "\n\n\n";
        system(CLEAR);
        cout << "GUARDAR Y SALIR" << endl;
        this->juego->guardarSalir();
        salir = true;
    }
    else{
        volver_menu(1);
    }

}


if(opcion == 12){
return 12;
}
else if(opcion == 13){
return 13;
}

cout << "\n\n\n-------------------------HASTA LA PRÓXIMA-----------------------" << endl;


return 0;

}

void Interfaz::determinarPosicionJugador(int jugador){
    int fil, col;
    Coordenada coordenada(-1,-1);
    Casillero * casillero;
    bool coordenadaValida = false;
    while(!coordenadaValida) {
        while (!esCoordenadaValida(coordenada)) {
            system(CLEAR);
            juego->obtener_mapa()->mostrar();
            cout << "Ingrese ubicacion jugador " << jugador << ":" << endl;
            cout << "Fila: ";
            cin >> fil;
            cout << "Columna: ";
            cin >> col;
            coordenada.setFila(fil);
            coordenada.setColumna(col);
        }
        casillero = juego->obtener_mapa()->getCasillero(coordenada);
        if (casillero->getEdificio() || casillero->devolver_jugador_casillero() != 0) {
            cout << "El casillero se encuentra ocupado" << endl;
            coordenada.setFila(-1);
        }
        else coordenadaValida = true;
    }
    if(jugador == 1)
        casillero->jugador_entra_casillero(1);
    else casillero->jugador_entra_casillero(2);

    casillero = juego->obtener_mapa()->getCasillero(coordenada);

}

void Interfaz::iniciar(){
    juego->inicializarCargadoDatos();
    system("clear");

    if(!juego->obtener_esta_ubicaciones() || juego->obtener_cant_lineas() == 0){
        iniciarMenuInicial();
    }else{
        correr_juego();
    }
    cout << "\n\n\n-------------------------HASTA LA PRÓXIMA-----------------------" << endl;
}

void Interfaz::correr_juego(){

    bool construyo_obelisco = false;
    int opcion = -1;
    int turno_jugador = 1;

    while(construyo_obelisco == false && opcion != 13){

        if(turno_jugador == 1){
            opcion = iniciar_segundo_menu(1);
            turno_jugador ++;
        }
        else if(turno_jugador == 2){
            opcion = iniciar_segundo_menu(2);
            turno_jugador --;
        }

    }
}


