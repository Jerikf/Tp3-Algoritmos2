#include "../../Entidades/Firmas/Juego.h"
#include <iostream>
#include "../../Entidades/Firmas/constantes.h"

using namespace std;

void Juego::obtener_datos(){

    datos.cargar_inventario();
    datos.cargar_edificios();
    datos.cargar_mapa();
   // datos.cargar_ubicaciones();
}

void Juego::inicializar_juego(){

    generar_opciones();

}

void Juego::limpiar_memoria(){

    datos.devovler_jugador_1().limpiar_inventario();
    datos.devovler_jugador_2().limpiar_inventario();
    datos.devovler_jugador_1().limpiar_diccionario();
    datos.devovler_jugador_2().limpiar_diccionario();
    datos.devovler_jugador_1().limpiar_mapa();
    datos.devovler_jugador_2().limpiar_mapa();
    datos.devovler_jugador_1().limpiar_grafo();
    datos.devovler_jugador_2().limpiar_grafo();
}

void Juego::generar_primer_menu(){
    
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

void Juego::generar_segundo_menu(){

    cout << "\t" << "╔════════════════╗" << endl;
    cout << "\t" << "║ Menu del juego ║" << endl;
    cout << "\t" << "╚════════════════╝" << endl;

    cout << "\t" << "╔════════════════════════════════════════╗" << endl;
    cout << "\t" << "║ 1)- Construir edificio por nombre.     ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 2)- Listar edificios construidos.      ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 3)- Listar todos los edificios.        ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 4)- Demoler edificio por coordenada.   ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 5)- Mostrar mapa.                      ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 6)- Consultar coordenada.              ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 7)- Mostrar inventario.                ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 8)- Recolectar recursos producidos.    ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 9)- Lluvia de recursos.                ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 10)- Guardar y salir.                  ║" << endl;
    cout << "\t" << "╚════════════════════════════════════════╝" << endl;


}

void Juego::volver_menu(){
    
    cout << endl;
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

void Juego::generar_opciones(){

    int opcion = 0;
    bool jugador_1_listo = false;

    cout << "Menu del primer jugador: " << endl;
    while(opcion != OPCION_4 && opcion != OPCION_5){
        //system(CLR_SCREEN);
        generar_primer_menu();
        cin >> opcion;
       // system(CLR_SCREEN);
        cout << endl;
        switch( opcion ){
            case OPCION_1:
                cout << "Error." << endl;
                break;
            case OPCION_2:
                datos.devovler_jugador_1().devolver_edificios()->mostrarInorder();
                break;
            case OPCION_3:
                datos.devovler_jugador_1().devolver_mapa()->mostrar();
                break;
            case OPCION_4:
                cout << "El jugador 1 esta listo para comenzar el juego." << endl;
                jugador_1_listo = true;
                break;
            case OPCION_5:
                break;
            default:
                cout << "             "     << "╔══════════════════════════╗" << endl;
                cout << "             "     << "║ ----CARACTER INVALIDO----║" << endl;
                cout << "             "     << "╚══════════════════════════╝" << endl;
        }
        if(opcion != OPCION_5 || opcion != OPCION_4){
            volver_menu();
        }
    }

    system(CLR_SCREEN);

    opcion = 0;
    bool jugador_2_listo = false;
    cout << "Menu del juador 2 " << endl;

    while (opcion != OPCION_4 && opcion != OPCION_5){
       // system(CLR_SCREEN);
       generar_primer_menu();
        cin >> opcion;
       // system(CLR_SCREEN);
        cout << endl;
        switch( opcion ){
            case OPCION_1:
                cout << "Error." << endl;
                break;
            case OPCION_2:
                datos.devovler_jugador_2().devolver_edificios()->mostrarInorder();
                break;
            case OPCION_3:
                datos.devovler_jugador_2().devolver_mapa()->mostrar();
                break;
            case OPCION_4:
                cout << "El jugador 2 esta listo para comenzar el juego." << endl;
                jugador_2_listo = true;
                break;
            case OPCION_5:
                break;
            default:
                cout << "             "     << "╔══════════════════════════╗" << endl;
                cout << "             "     << "║ ----CARACTER INVALIDO----║" << endl;
                cout << "             "     << "╚══════════════════════════╝" << endl;
        }
        if(opcion != OPCION_5 || opcion != OPCION_4){
            volver_menu();
        }

        
    }
    
    if(jugador_1_listo && jugador_2_listo){
        cout << "Acaba de comenzar el juego." << endl;

    }
    
}