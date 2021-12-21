#include "../firmas/Juego.h"
#include "../../recursos/firmas/Recursos.h"
#include <iostream>


const string ASERRADERO = "aserradero";
const string FABRICA = "fabrica";
const string MINA = "mina";
const string ESCUELA = "escuela";
const string PLANTA_ELECTRICA = "planta electrica";
const string MINA_ORO = "mina oro";

const int CANT_PIEDRA_BRINDADA = 15;
const int CANT_MADERA_BRINDADA = 25;
const int CANT_METALES_BRINDADA = 40;

const int MIN_CANT_PIEDRA = 1;
const int MAX_CANT_PIEDRA = 2;

const int MIN_CANT_MADERA = 0;
const int MAX_CANT_MADERA = 1;

const int MIN_CANT_METAL = 2;
const int MAX_CANT_METAL = 4;

const char CAMINO = 'C';
const char TERRENO = 'T';

const int VACIO = 0;
const int INICIO = 0;

const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";
const string ANDYCOINS = "andycoins";
const string ENERGIA = "energia";
const string BOMBAS = "bombas";

const int CONSUMO_ENERGIA_CONSTRUIR_EDIFICIO = 15;
const int CONSUMO_ENERGIA_COMPRAR_BOMBAS = 5;
const int CONSUMO_ENERGIA_RECOLECTAR_RECUROSOS = 20;

const int RECURSOS_ASERRADERO = 25;
const int RECURSOS_MINA = 15;
const int RECURSOS_FABRICA = 40;
const int RECURSOS_ESCUELA = 25;
const int RECURSOS_PLANTA_ELECTRICA = 15;
const int RECURSOS_MINA_ORO = 50;  

const string COMPRAR_ANDYPOLIS = "Comprar andypolis";
const string BOMBARDERO = "Bombardero";
const string EDAD_DE_PIEDRA = "Edad de piedra";
const string ENERGETICO = "Energetico";
const string LETRADO = "Letrado";
const string MINERO = "Minero";
const string CANSADO = "Cansado";
const string CONSTRUCTOR = "Constructor";
const string ARMADO = "Armado";
const string EXTREMISTA = "Extremista";



//----------------------------IMPLEMENTACIÓN DE FUNCIONES PRIVADAS---------------------------------------

Vect<Coordenada>* Juego::obtenerCoordenadas(string nombre_edificio, Jugador* jugador){
    
    Vect<Coordenada>* coordenadasDelEdificioConstruido = new Vect<Coordenada>;
    Coordenada* coordenada = NULL;
    Edificio* edificio = NULL;

    for(int i = 0; i < jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerCantidad(); i++){
        edificio = this->mapa->getCasillero(*(jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(i)))->getEdificio();
        
        if(edificio && edificio->getNombre() == nombre_edificio){
            int fila = jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(i)->getFila();
            int columna = jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(i)->getColumna();
            coordenada = new Coordenada(fila, columna);
            coordenadasDelEdificioConstruido->agregar(coordenada);
        }
    }
    return coordenadasDelEdificioConstruido;
}

Material* Juego::obtenerMaterial(string nombre_material, Jugador* jugador){
    int pos = 0;
    bool seEncontro = false;
    Material* material = NULL;
    while(!seEncontro && pos < jugador->obtener_inventario()->obtenerCantidad()){
        material = jugador->obtener_inventario()->obtenerDato(pos);
        if(material->getNombre() == nombre_material)
            seEncontro = true;
        pos++;
    }

    return material;
    
}

Edificio* Juego::obtenerEdificio(string nombre_edificio){

    Edificio* edificio = NULL;
    edificio = this->edificios->buscar(nombre_edificio);
    return edificio;
}


Coordenada Juego::obtenerCoordenadaAleatoriaValida(){

    Coordenada coordenada;
    Recurso recurso;
    int fila; 
    int columna; 

    fila = recurso.obtenerNumAleatorio(INICIO, this->mapa->getCantFilas());
    columna = recurso.obtenerNumAleatorio(INICIO, this->mapa->getCantColumnas());
    coordenada.setFila(fila);
    coordenada.setColumna(columna);

    return coordenada;

}



void Juego::recolectarMateriales(int cantDeMaterialesARecolectar, Material* material){

    bool casilleroVacio = true;

    int cantCasillerosTransitables = this->mapa->obtenerCantDeCasilleros(CAMINO);
    //NO puedo generar coordenadas aleatorias si ya no tengo mas caminos en donde puedo construir un material
    if(cantDeMaterialesARecolectar <= cantCasillerosTransitables){
        //Sirve para generar todas las cantidaddes de materiales a recolectar
        for(int i = 0; i < cantDeMaterialesARecolectar; i++){

            while(casilleroVacio){
                //Si es exitoso es porque el casillero es Transitable y estaba vacío, sino debe volver a pedir nuevamente una coordenada
                if(this->mapa->getCasillero(this->obtenerCoordenadaAleatoriaValida())->construirMaterial(material) == EXITO)
                    casilleroVacio = false;
            }
            casilleroVacio = true;
        }
    }else
        cout << "YA NO TENGO MAS ESPACIO" << endl;
}

void Juego::modificar_valores_materiales(string nombre_material, string nombre_edificio){
    
    string decision;

    cout << "Desea modificar los valores de " <<  nombre_material << "?" << endl;
    cin >> decision;
    if(decision == "si"){
        cout << "Indique los nuevos valores de " <<  nombre_material << " entre 0 y 50000: " << endl;
        int cant_material;
        cin >> cant_material;

        if(cant_material > 0 && cant_material < 50000){
            
            modificar_valor_material(nombre_material, cant_material, nombre_edificio);
            
            cout << "Ahora el " << nombre_edificio << " se construye con " << cant_material << " de "<< nombre_material <<  "." << endl;
        }
        else{
            cout << "No cumple con los limites establecidos." << endl;
        }
                        
    }
    else{
        cout << "No se modificaron los valores de " << nombre_material << "." << endl;
        cout << endl;
    }
}

void Juego::modificar_valor_material(string nombre_material, int cant_material, string nombre_edificio){

    if(nombre_material == PIEDRA){

        edificios->buscar(nombre_edificio)->setCantPiedra(cant_material);
    }
    else if(nombre_material == MADERA){

        edificios->buscar(nombre_edificio)->setCantMadera(cant_material);
    }
    else if(nombre_material == METAL){

        edificios->buscar(nombre_edificio)->setCantMetal(cant_material);
    }
}

void Juego::contar_edificios(int &cant_edificios, string nombre_edificio, Jugador* jugador){

    int posicion = 0;
    Coordenada coordenada;

    while(posicion <  jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerCantidad()){

        coordenada.setFila(jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(posicion)->getFila());
        coordenada.setColumna(jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(posicion)->getColumna());
        if(mapa->getCasillero(coordenada)->getEdificio()->getNombre() == nombre_edificio){
            cant_edificios ++;
        }

        posicion++;
    }
}


void Juego::recolectar_recurso(int canitdad_recurso, Jugador* jugador, string nombre_material){

    if(canitdad_recurso > 0 && nombre_material != ENERGIA){
        
        bool esta = false;
        int posicion = 0;

        while(!esta && posicion < jugador->obtener_inventario()->obtenerCantidad()){

            if(jugador->obtener_inventario()->obtenerDato(posicion)->getNombre() == nombre_material){

                int canitdad_actual = jugador->obtener_inventario()->obtenerDato(posicion)->getCantidad();
                jugador->obtener_inventario()->obtenerDato(posicion)->setCantidad(canitdad_actual + canitdad_recurso);
                esta = true;
            }

            posicion ++;
        }
    }
    else if(canitdad_recurso > 0 && nombre_material == ENERGIA){

        int cantidad_actual = jugador->obtener_cant_energia();
        jugador->establecer_energia(cantidad_actual + RECURSOS_PLANTA_ELECTRICA);

    }


}

void Juego::cargar_objetivos(){
    
    agregar_objetivo(COMPRAR_ANDYPOLIS);
    agregar_objetivo(BOMBARDERO);
    agregar_objetivo(EDAD_DE_PIEDRA);
    agregar_objetivo(ENERGETICO);
    agregar_objetivo(LETRADO);
    agregar_objetivo(MINERO);
    agregar_objetivo(CANSADO);
    agregar_objetivo(CONSTRUCTOR);
    agregar_objetivo(ARMADO);
    agregar_objetivo(EXTREMISTA);  
    
}

void Juego::establecer_objetivos_jugadores(){

    srand(static_cast<unsigned int>(time(NULL)));
    
    int canitdad_elementos = objetivos->obtenerCantidad();
    int elemento_aleatorio_1 = (rand()% canitdad_elementos);
    int elemento_aleatorio_2 = (rand()% canitdad_elementos);
    
    jugador_1->establecer_objetivos(objetivos->obtenerDato(elemento_aleatorio_1), objetivos->obtenerDato(elemento_aleatorio_2));
    
    elemento_aleatorio_1 = (rand()% canitdad_elementos);
    elemento_aleatorio_2 = (rand()% canitdad_elementos);

    jugador_2->establecer_objetivos(objetivos->obtenerDato(elemento_aleatorio_1), objetivos->obtenerDato(elemento_aleatorio_2));
}


void Juego::agregar_objetivo(string nombre_objetivo){

    string *objetivo = new string;
    *objetivo = nombre_objetivo;

    objetivos->agregar(objetivo);
}

void Juego::mostrar_objetivo(string *objetivo){

    if(*objetivo == COMPRAR_ANDYPOLIS){
        cout << COMPRAR_ANDYPOLIS << ": haber juntado 100.000 andycoins a lo largo de la partida (las monedas gastadas también cuentan para este objetivo)" << endl;
        cout << endl;
    }
    else if(*objetivo == BOMBARDERO){
        cout << BOMBARDERO << ": haber usado 5 bombas." << endl;
        cout << endl;
    }
    else if(*objetivo == EDAD_DE_PIEDRA){
        cout << EDAD_DE_PIEDRA << ": tener en el inventario 50000 piedras" << endl;
        cout << endl;
    }
    else if(*objetivo == ENERGETICO){
        cout << ENERGETICO << ": haber terminado un turno con 100 puntos de energía." << endl;
        cout << endl;
    }
    else if(*objetivo == LETRADO){
        cout << LETRADO << ": haber construido el máximo posible de escuelas." << endl;
        cout << endl;
    }
    else if(*objetivo == MINERO){
        cout << MINERO << ": haber construido una mina de cada tipo." << endl;
        cout << endl;
    }
    else if(*objetivo == CANSADO){
        cout << CANSADO << ": terminar un turno con 0 de energía." << endl;
        cout << endl;
    }
    else if(*objetivo == CONSTRUCTOR){
        cout << CONSTRUCTOR << ": construir un edificio de cada tipo." << endl;
        cout << endl;
    }
    else if(*objetivo == ARMADO){
        cout << ARMADO << ": tener 10 bombas en el inventario." << endl;
        cout << endl;
    }
    else if(*objetivo == EXTREMISTA){
        cout << EXTREMISTA << ": haber comprado 500 bombas en una partida." << endl;
        cout << endl;
    }
  

}




//-----------------------IMPLMENTACION FUNCIONES PUBLICAS---------------------------

Juego::Juego(Datos* datos, Diccionario<Edificio>* edificios){
    this-> datos = datos;
    this-> edificios = edificios;
    this-> mapa = NULL;
    this-> jugador_1 = NULL;
    this-> jugador_2 = NULL;
    
}

Juego::Juego(){
    this-> datos = new Datos("edificios.txt", "materiales.txt", "mapa.txt", "ubicaciones.txt");
    this-> mapa = NULL;
    this-> edificios = new Diccionario<Edificio>();
    this-> jugador_1 = new Jugador();
    this-> jugador_2 = new Jugador();
    this-> objetivos = new Vect<string>();

}

Juego::~Juego(){
    delete datos;
    delete edificios;
    delete jugador_1;
    delete jugador_2;
    delete objetivos;
    if(mapa)
        delete mapa;
}

void Juego::inicializarCargadoDatos(){
    this-> datos->cargarDatosEdificios(edificios);
    this-> datos->cargarDatosMateriales(jugador_1->obtener_inventario(), jugador_2->obtener_inventario());
    this-> datos->cargarDatosMapa(&mapa);
    this-> jugador_1->establecer_grafo(mapa, 1);
    this-> jugador_2->establecer_grafo(mapa, 2);
    this-> datos->cargarDatosUbicaciones(mapa, edificios, jugador_1->obtener_coordenadasDeEdificiosConstruidos(), jugador_2->obtener_coordenadasDeEdificiosConstruidos());
    cargar_objetivos();
    establecer_objetivos_jugadores();
}

void Juego::modificar_edificio_por_nombre(){

    string nombre_edificio;

    cout << "Indique el nombre del edificio que desea modificar:" << endl;
    getline(cin.ignore(), nombre_edificio);
    if(edificios->buscar(nombre_edificio) != NULL){
        if(nombre_edificio == "obelisco"){
            cout << "El obelisco no se puede modificar" << endl;
        }
        else{
            
            int contador_material = 0;
            while(contador_material < 3){

                if(contador_material == 0){

                    modificar_valores_materiales(PIEDRA, nombre_edificio);
                }
                else if(contador_material == 1){
                    modificar_valores_materiales(MADERA, nombre_edificio);
                }
                else if(contador_material == 2){
                    modificar_valores_materiales(METAL, nombre_edificio);
                }

                contador_material ++;
            }
        }
    }
    else{
        cout << "No existe el edificio." << endl;
    }


}

void Juego::listarTodosLosEdificios(){
    
    edificios->mostrarInorder();
}

void Juego::mostrarMapa(){
    this->mapa->mostrar();
}

int Juego::construirEdificioPorNombre(string nombre, Coordenada coordenada, Jugador* jugador){
    

    Vect<Coordenada>* coordenadasDelEdificioConstruido  = NULL;
    Casillero* casillero = NULL;
    Edificio* edificio = NULL;
    Material* piedra = NULL;
    Material* madera = NULL;
    Material* metal = NULL;
    int retorno = 0;

    if(jugador->obtener_cant_energia() > CONSUMO_ENERGIA_CONSTRUIR_EDIFICIO){
        //Verifico que el nombre del edificio exista
        edificio = this->obtenerEdificio(nombre);
        if(edificio){

            //Verifico que la cantidad de materiales sea el adecuado
            piedra = this->obtenerMaterial(PIEDRA, jugador);
            madera = this->obtenerMaterial(MADERA, jugador);
            metal = this->obtenerMaterial(METAL, jugador);

            if(piedra->getCantidad() > edificio->getCantPiedra() && madera->getCantidad() > edificio->getCantMadera() && metal->getCantidad() > edificio->getCantMetal()){
                
                //Verifico que la cantidad de construidos sea el adecuado
                coordenadasDelEdificioConstruido = this->obtenerCoordenadas(edificio->getNombre(), jugador); // al saber las coordenas tengo ya la cantidad de veces que se construyeron asi reutilizo la funcion y no me creo otra igual
                if(coordenadasDelEdificioConstruido->obtenerCantidad() < edificio->getMaxCantPermitidos()){

                    //Verifico que la coordenada sea válida!
                    casillero = this->mapa->getCasillero(coordenada);
                    if(casillero){

                        //Si es exitoso la construccion debo descontar los materiales usados
                        if(casillero->construirEdificio(edificio) == EXITO){
                            piedra->setCantidad(piedra->getCantidad() - edificio->getCantPiedra());
                            madera->setCantidad(madera->getCantidad() - edificio->getCantMadera());
                            metal->setCantidad(metal->getCantidad() - edificio->getCantMetal());

                            //Agrego la coordenada al vector de coordendas del edificio del jugador
                            Coordenada* coordenadaDelEdificioConstruido = new Coordenada(coordenada.getFila(), coordenada.getColumna());
                            jugador->obtener_coordenadasDeEdificiosConstruidos()->agregar(coordenadaDelEdificioConstruido);

                            //Descuento la energia del jugador porque se construyò correctamente el edificio
                            jugador->establecer_energia(jugador->obtener_cant_energia() - CONSUMO_ENERGIA_CONSTRUIR_EDIFICIO);
                            if(nombre == "obelisco"){
                                retorno = 1;
                                cout << "Felicidades, acaba de construir el obelisco, gano el juego." << endl;
                            }
                            

                            
                        } 
                        
                    }else
                        cout << "\n\n ERROR --> NO SE PUEDE CONTRUIR EDIFICIO PORQUE LA COORDENADA ESTÁ FUERA DE RANGO DEL MAPA \n\n" << endl;

                }else
                    cout << "\n\n ERROR --> NO SE PUEDE CONTRUIR EDIFICIO PORQUE NO YA ALCANZÓ SU LÍMITE DE CANTIDAD PERMITIDO \n\n" << endl;

            }else
                cout << "\n\n ERROR --> NO SE PUEDE CONTRUIR EDIFICIO PORQUE NO HAY SUFICIENTE MATERIAL PARA CONSTRUIR EL EDIFICIO \n\n" << endl;

            

        }else
            cout << "\n\n ERROR --> NO SE PUEDE CONTRUIR EDIFICIO PORQUE NO EXISTE EL NOMBRE DEL EDIFICIO \n\n" << endl;
        delete coordenadasDelEdificioConstruido;

    }else
        cout << "\n\n ERROR --> NO TIENE ENERGÌA SUFICIENTE PARA PODER CONSTRUIR UN EDIFICIO" << endl;

        return retorno;

}

void Juego::listarEdificiosConstruidos(Jugador* jugador){


	if(jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerCantidad() == 0){
        cout << "No hay edificios construidos" << endl;
    }
    else{
        cout << "EDIFICIOS CONSTRUIDOS: " << endl;
        cout << endl;
        for(int i = 0; i < jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerCantidad(); i++){

            Coordenada coordenada;
            coordenada.setFila(jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(i)->getFila());
            coordenada.setColumna(jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(i)->getColumna());
            cout <<  mapa->getCasillero(coordenada)->getEdificio()->getNombre() << endl;
            cout << "Coordenada: " << "(" << coordenada.getFila() << " " << coordenada.getColumna() << ")" << endl;
            cout << endl;
        }
    }
}



void Juego::demolerEdificioPorCoordenada(Coordenada coordenada, Jugador* jugador){
    
    Casillero* casillero = NULL;
    Edificio* edificio = NULL;
    Coordenada coordenadaEncontrada;
    if(jugador->obtener_cant_energia() > 15){
        int fila, columna, posEliminar;
        
        for(int i = 0; i < jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerCantidad(); i++){
            fila = jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(i)->getFila();
            columna = jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(i)->getColumna();

            if(coordenada.getFila() == fila && coordenada.getColumna() == columna){
                casillero = this->mapa->getCasillero(coordenada);
                coordenadaEncontrada.setFila(fila);
                coordenadaEncontrada.setColumna(columna);
                posEliminar = i;
            }

        }

        if(casillero){
            edificio = casillero->demolerEdificio();

            //Si es que se demolió correctamente tengo que devolver la mitad de los materiales usado
            if(edificio){
                Material* piedra = this->obtenerMaterial(PIEDRA, jugador);
                Material* madera = this->obtenerMaterial(MADERA, jugador);
                Material* metal = this->obtenerMaterial(METAL, jugador);

                int piedraDeEdificio = edificio->getCantPiedra() / 2;
                int maderaDeEdificio = edificio->getCantMadera() / 2;
                int metalDeEdificio = edificio->getCantMetal() / 2;

                piedra->setCantidad(piedra->getCantidad() + piedraDeEdificio);
                madera->setCantidad(madera->getCantidad() + maderaDeEdificio);
                metal->setCantidad(metal->getCantidad() + metalDeEdificio);

                delete edificio; //TENGO QUE LIBERAR SU MEMORIA YA QUE EL CASILLERO CONSTRUIBLE ME DEVOLVIÓ LA DIRECCION Y ESTE LO INSTANCIÓ EN NULL
                                //ENTONCES CUANDO SE LIBERE CASILLERO CON SU DESTRUCTOR YA NO ESTARÍA ESTE EDIFICIO
            
                //ELIMINO LA COORDENA DEL EDIFICIO DEL JUGADOR
                jugador->obtener_coordenadasDeEdificiosConstruidos()->eliminarDato(posEliminar);
                
                //DESCUENTO LA ENERGÌA
                jugador->establecer_energia(jugador->obtener_cant_energia() - 15);
            }
        }else
            cout << "\n\n ERROR--> COORDENADA FUERA DE RANGO | NO TIENES EDIFICIO EN DICHA COORDENADA" << endl;

    }else
        cout << "\n\n ERROR--> NO TIENE SUFICIENTE ENERGIA PARA DEMOLER UN EDIFICIO";
}

void Juego::reparar_edificio(string nombre_edificio, Jugador* jugador, Coordenada coordenada){


    int cant_piedra_requerida = this->obtenerEdificio(nombre_edificio)->getCantPiedra() * 0.25;
    int cant_madera_requerida = this->obtenerEdificio(nombre_edificio)->getCantMadera() * 0.25;
    int cant_metal_requerido = this->obtenerEdificio(nombre_edificio)->getCantMetal() * 0.25;
    Material* piedra = NULL;
    Material* madera = NULL;
    Material* metal = NULL;

    piedra = this->obtenerMaterial(PIEDRA, jugador);
    madera = this->obtenerMaterial(MADERA, jugador);
    metal = this->obtenerMaterial(METAL, jugador);

    int cant_piedra = this->obtenerMaterial(PIEDRA, jugador)->getCantidad();
    int cant_madera = this->obtenerMaterial(MADERA, jugador)->getCantidad();
    int cant_metal = this->obtenerMaterial(METAL, jugador)->getCantidad();
    if(cant_piedra >= cant_piedra_requerida && cant_madera >= cant_madera_requerida && cant_metal >= cant_metal_requerido){
        
        cout << "Se ha reparado la " << nombre_edificio << " ubiaca en " << "(" << coordenada.getFila() << ", " << coordenada.getColumna() << ")";
        piedra->setCantidad(cant_piedra - cant_piedra_requerida);
        madera->setCantidad(cant_madera - cant_madera_requerida);
        metal->setCantidad(cant_metal - cant_metal_requerido);
        int cant_actual_energia = jugador->obtener_cant_energia();
        jugador->establecer_energia(cant_actual_energia - 25);
        cout << "Se le ha descontado 25 de enrgia." << endl;
        mapa->getCasillero(coordenada)->getEdificio()->setVida();

    }
    else{
        cout << "No cuenta con la cantidad suficiente de materiales para reparar el edificio" << endl;
    }
            


}

void Juego::repararEdificioPorCoordenada(Jugador* jugador){

    if(jugador->obtener_cant_energia() >= 25){

        cout << "Seleccione las coordenadas del edficio a reparar: " << endl;

        mapa->mostrar();

        cout << "Fila: ";
        int fila;
        cin >> fila;

        cout << "Columna: ";
        int columna;
        cin>> columna;

        Coordenada coordenada;
        coordenada.setFila(fila);
        coordenada.setColumna(columna);
        
        if(fila < mapa->getCantFilas() && columna < mapa->getCantColumnas()){

            if(mapa->getCasillero(coordenada)->getTipo() == TERRENO){

                if(mapa->getCasillero(coordenada)->getEdificio()->getNombre() == MINA){

                    reparar_edificio(MINA, jugador, coordenada);
                }
                else if(mapa->getCasillero(coordenada)->getEdificio()->getNombre() == FABRICA){
                   reparar_edificio(FABRICA, jugador, coordenada);
                }
                else{
                    cout << "Ese edificio no es puede reparar." << endl;
                }
            }
            else{
                cout << "Debe seleccionar un edificio." << endl;
            }
        }
        else{
            cout << "Las coordenadas no estan adentro del mapa." << endl;
        }

    }
    else{
        cout << "No tiene energia suficiente para realizar la accion." << endl;
    }

}

void Juego::comprar_bombas(Jugador* jugador){

    if(jugador->obtener_cant_energia() >= 5){

        cout << "Cada bomba cuesta 100 andycoins, indique la cantidad que desea comprar:" << endl;
        cout << "Cantidad: ";
        int cantidad_bombas;
        cin >> cantidad_bombas;
    
        int cantidad_andycoins = obtener_cant_material(ANDYCOINS, jugador);
        int cantidad_actual_bombas = obtener_cant_material(BOMBAS, jugador);

        int total_pagar = 100 * cantidad_bombas;

        if(cantidad_andycoins >= total_pagar){
            if(cantidad_bombas == 1){
               cout << "Se ha agregado " << cantidad_bombas << " bomba a su invnetario." << endl;
            }
            else if(cantidad_bombas > 1){
                cout << "Se han agregado " << cantidad_bombas << " bombas a su invnetario." << endl;
            }
            cout << "Le quedan " << cantidad_andycoins - total_pagar << " de andycoins." << endl;
        
            int posicion = 0;
            bool lo_encontro = false;
            while(posicion < jugador->obtener_inventario()->obtenerCantidad() && lo_encontro == false){

                if(jugador->obtener_inventario()->obtenerDato(posicion)->getNombre() == BOMBAS){
            
                    jugador->obtener_inventario()->obtenerDato(posicion)->setCantidad(cantidad_actual_bombas + cantidad_bombas);

                    lo_encontro = true;
                }

                posicion ++;
            }
        
            lo_encontro = false;
            posicion = 0;
            while(posicion < jugador->obtener_inventario()->obtenerCantidad() && lo_encontro == false){

                if(jugador->obtener_inventario()->obtenerDato(posicion)->getNombre() == ANDYCOINS){
                    int cantidad_actual_anducoins_gastados = jugador->obtener_andycoins_gastados();
                    jugador->establecer_andycoins_gastados(total_pagar + cantidad_actual_anducoins_gastados);
                    jugador->obtener_inventario()->obtenerDato(posicion)->setCantidad(cantidad_andycoins - total_pagar);
                    lo_encontro = true;
                }

                posicion ++;
            }
            

            if(*jugador->obtener_primer_objetivo() == COMPRAR_ANDYPOLIS || *jugador->obtener_segundo_objetivo() == COMPRAR_ANDYPOLIS){
                verificar_objetivo(COMPRAR_ANDYPOLIS, jugador);
            }
            

            int cantidad_actual_energia = jugador->obtener_cant_energia();
            jugador->establecer_energia(cantidad_actual_energia - CONSUMO_ENERGIA_COMPRAR_BOMBAS);
        }
        else{
            cout << "No tene la cantidad suificente de dinero para comprar " << cantidad_bombas << " bombas." << endl;
        }
    }
    else{
        cout << "No tiene energia suficiente para esta opcion." << endl;
    }
        
}

void Juego::consultarCoordenada(Coordenada coordenada){
    Casillero* casillero = this->mapa->getCasillero(coordenada);
    if(casillero){
        casillero->mostrar();
    }else
        cout << "\n\n\n COORDENADA FUERA DEL RANGO" << endl;

}

void Juego::mostrarInventario(Jugador* jugador){ 
    
    jugador->obtener_inventario()->mostrar();
}

void Juego::mostrar_objetivos(Jugador* jugador){
    
    cout << "Sus objetivos son: " << endl;
    cout << endl;
    mostrar_objetivo(jugador->obtener_primer_objetivo());
    mostrar_objetivo(jugador->obtener_segundo_objetivo());
    
}

void Juego::recolectarRecursosProducidos(Jugador* jugador){
    
    if(jugador->obtener_cant_energia() > CONSUMO_ENERGIA_RECOLECTAR_RECUROSOS){
        
        int cant_aserraderos = 0;
        int cant_minas = 0; 
        int cant_plantas_electricas = 0;
        int cant_minas_oro = 0;
        int cant_escuelas = 0;
        int cant_fabricas = 0;

    
        contar_edificios(cant_aserraderos, ASERRADERO, jugador);
        contar_edificios(cant_minas, MINA, jugador);
        contar_edificios(cant_escuelas, ESCUELA, jugador);
        contar_edificios(cant_fabricas, FABRICA, jugador);
        contar_edificios(cant_minas_oro, MINA_ORO, jugador);
        contar_edificios(cant_plantas_electricas, PLANTA_ELECTRICA, jugador);
    
        cout << "Informacion de produccion de los edificios: " << endl;
        cout << endl;
        cout << "Aserradero - 25 maderas c/u - " << "Cantidad: " << cant_aserraderos << " Madera generada: " << cant_aserraderos * RECURSOS_ASERRADERO << endl;
        cout << endl;
        cout << "Mina - 15 piedras c/u - " << "Cantidad: " << cant_minas << " Piedra generada: " << cant_minas * RECURSOS_MINA << endl;
        cout << endl;
        cout << "Fabrica - 40 metales c/u - " << "Cantidad: " << cant_fabricas << " Metal generado: " << cant_fabricas * RECURSOS_FABRICA << endl;
        cout << endl;
        cout << "Escuela - 25 andycoins c/u - " << "Cantidad: " << cant_escuelas << " Andycoin generado: " << cant_escuelas * RECURSOS_ESCUELA << endl;
        cout << endl;
        cout << "Planta electrica - 15 de energia c/u - " << "Cantidad: " << cant_plantas_electricas << " Energia generada: " << cant_plantas_electricas * RECURSOS_PLANTA_ELECTRICA << endl;
        cout << endl;
       cout << "Mina oro - 50 andycoins c/u - " << "Cantidad: " << cant_minas_oro << " Andycoin generado: " << cant_minas_oro * RECURSOS_MINA_ORO << endl;

        recolectar_recurso(cant_aserraderos * RECURSOS_ASERRADERO, jugador, MADERA);
        recolectar_recurso(cant_minas * RECURSOS_MINA, jugador, PIEDRA);
        recolectar_recurso(cant_fabricas * RECURSOS_FABRICA, jugador, FABRICA);
        recolectar_recurso(cant_escuelas * RECURSOS_ESCUELA, jugador, ANDYCOINS);
        recolectar_recurso(cant_plantas_electricas * RECURSOS_PLANTA_ELECTRICA, jugador, ENERGIA);
        recolectar_recurso(cant_minas_oro * RECURSOS_MINA_ORO, jugador, ANDYCOINS);
    
        int cantidad_total_edificios = cant_aserraderos + cant_minas + cant_plantas_electricas + cant_minas_oro + cant_escuelas + cant_fabricas;
    
        if(cantidad_total_edificios == 0){
            cout << "No se descuenta energia porque no recolecto recursos." << endl;
        }
        else{
 
            int cantidad_actual = jugador->obtener_cant_energia();
            jugador->establecer_energia(cantidad_actual - CONSUMO_ENERGIA_RECOLECTAR_RECUROSOS);

        }
    }
    else{
        cout << "No tiene energia suficiente para realizar esta accion." << endl;
    }
}

void Juego::moverJugador(Coordenada puntoFinal, int jugador){
    Casillero * casilleroActual = mapa->getCasillero(puntoFinal);
    Coordenada * caminoRecorrido;
    int topeCamino = 0;
    if( casilleroActual->devolver_jugador_casillero() != 0 || casilleroActual->getEdificio() != nullptr ) {
        cout << "La coordenada dada se encuentra ocupada" << endl;
    }
    else if(jugador == 1)
        caminoRecorrido = jugador_1->jugadorSeMueve(mapa->obtenerPosicionDeJugador(1), puntoFinal, &topeCamino, mapa);
    else caminoRecorrido = jugador_2->jugadorSeMueve(mapa->obtenerPosicionDeJugador(2), puntoFinal, &topeCamino, mapa);

    if(caminoRecorrido) {
        mapa->mostrar_recorrido_jugador(caminoRecorrido, topeCamino, jugador);
        delete[] caminoRecorrido;
    }
}

void Juego::guardarSalir(){
    this->datos->gurdarDatosEdificios(this->edificios);
    this->datos->guardarDatosMateriales(this->jugador_1->obtener_inventario(), this->jugador_2->obtener_inventario());
    this->datos->guardarDatosMapa(this->mapa);
    this->datos->guardarDatosUbicaciones(this->mapa, this->jugador_1->obtener_coordenadasDeEdificiosConstruidos(), this->jugador_2->obtener_coordenadasDeEdificiosConstruidos());

    cout << "\n\n\n SE GUARDÓ CON ÉXITO LOS EDIFICIO, MATERILES, MAPA Y UBICACIONES" << endl;
}


void Juego::lluviaDeRecursos(){
    /*
    Recurso recurso;
    srand((unsigned)time(0));
    
    //Le agregamos el 1 para que sea inclusivo el max
    int cantPiedra = recurso.obtenerNumAleatorio(MIN_CANT_PIEDRA, MAX_CANT_PIEDRA + 1);
    int cantMadera = recurso.obtenerNumAleatorio(MIN_CANT_MADERA, MAX_CANT_MADERA + 1);
    int cantMetal = recurso.obtenerNumAleatorio(MIN_CANT_METAL, MAX_CANT_METAL + 1);
    
    

    Material* piedra = this->obtenerMaterial(PIEDRA);
    Material* madera = this->obtenerMaterial(MADERA);
    Material* metal = this->obtenerMaterial(METAL);

    //Recolectará de ser necesario, osea siempre y cuadno tenga aun caminos.
    this->recolectarMateriales(cantPiedra, piedra);
    this->recolectarMateriales(cantMadera, madera);
    this->recolectarMateriales(cantMetal, metal);
    */
}

void Juego::cumplir_objetivo(string nombre_objetivo, Jugador* jugador){

    if(jugador->obtener_objetivo_cumplido() != nombre_objetivo){
        jugador->aumentar_objetivos_cumplidos();
        jugador->establecer_objetivo_cumplido(nombre_objetivo);
        cout <<" Acaba de completar el objetivo " << nombre_objetivo << endl;
    }


}

int Juego::obtener_cant_edificios(string nombre_edificio, Jugador* jugador){

    int cant_edificio = 0;

    for(int i = 0; i < jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerCantidad(); i++){
        Coordenada coordenada;
        coordenada.setFila(jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(i)->getFila());
        coordenada.setColumna(jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(i)->getColumna());
        if(mapa->getCasillero(coordenada)->getEdificio()->getNombre() == nombre_edificio){
            
            cant_edificio ++;
        }
    }

    return cant_edificio;
}

int Juego::obtener_cant_material(string nombre_material, Jugador* jugador){

    int cant_material;
    int posicion = 0;
    bool lo_encontro = false;

    while(!lo_encontro && posicion != jugador->obtener_inventario()->obtenerCantidad()){

        if(jugador->obtener_inventario()->obtenerDato(posicion)->getNombre() == nombre_material){
                
            cant_material = jugador->obtener_inventario()->obtenerDato(posicion)->getCantidad();
            lo_encontro == true;
        }

        posicion ++;
    }

    return cant_material;
}

void Juego::verificar_objetivo(string nombre_objetivo, Jugador* jugador){

    if(nombre_objetivo == COMPRAR_ANDYPOLIS){
        if(jugador->obtener_andycoins_gastados() >= 100000){
            cumplir_objetivo(COMPRAR_ANDYPOLIS, jugador);    
        }
    }
    else if(nombre_objetivo == EDAD_DE_PIEDRA){

        int cant_piedra = obtener_cant_material(PIEDRA, jugador);

        if(cant_piedra >= 50000){

            cumplir_objetivo(EDAD_DE_PIEDRA, jugador); 
        }
    }
    else if(nombre_objetivo == BOMBARDERO){
        
        cumplir_objetivo(BOMBARDERO, jugador); 
    }
    else if(nombre_objetivo == ENERGETICO){
        
        if(jugador->obtener_cant_energia() == 100){
            cumplir_objetivo(ENERGETICO, jugador); 
        }
        
    }
    else if(nombre_objetivo == LETRADO){
        
        int cant_esceulas = obtener_cant_edificios(ESCUELA, jugador);
        int cant_max_escuelas = edificios->buscar(ESCUELA)->getMaxCantPermitidos();
        if(cant_esceulas == cant_max_escuelas){
            
            cumplir_objetivo(LETRADO, jugador);
        }
    }
    else if(nombre_objetivo == MINERO){
        
        int cant_mina_normal = obtener_cant_edificios(MINA, jugador);
        int cant_mina_oro = obtener_cant_edificios(MINA_ORO, jugador);

        if(cant_mina_normal >= 1 && cant_mina_oro >= 1){
            
            
            cumplir_objetivo(MINERO, jugador);
        }

    }
    else if(nombre_objetivo == CANSADO){
        
        if(jugador->obtener_cant_energia() == 0){
            
            cumplir_objetivo(CANSADO, jugador);
        }
    }
    else if(nombre_objetivo == CONSTRUCTOR){
        
        int cant_aserradero = obtener_cant_edificios(ASERRADERO, jugador);
        int cant_fabrica = obtener_cant_edificios(FABRICA, jugador);
        int cant_escuela = obtener_cant_edificios(ESCUELA, jugador);
        int cant_planta_electrica = obtener_cant_edificios(PLANTA_ELECTRICA, jugador);
        int cant_mina_normal = obtener_cant_edificios(MINA, jugador);
        int cant_mina_oro = obtener_cant_edificios(MINA_ORO, jugador);

        if(cant_mina_normal >= 1 && cant_mina_oro >= 1 && cant_escuela >= 1 && cant_aserradero >= 1 && cant_fabrica >= 1 && cant_planta_electrica >= 1){
            cumplir_objetivo(CONSTRUCTOR, jugador);
        }
    }
    else if(nombre_objetivo == ARMADO){

        int cant_bombas = obtener_cant_material(BOMBAS, jugador);

        if(cant_bombas >= 10){
            
            cumplir_objetivo(ARMADO, jugador);
        }
    }
}


Jugador* Juego::obtener_jugador_1(){

    return this->jugador_1;
}


Jugador* Juego::obtener_jugador_2(){

    return this->jugador_2;
}

Diccionario<Edificio>* Juego::obtener_edificios(){

    return this->edificios;
}

Mapa* Juego::obtener_mapa(){

    return this->mapa;
}

void Juego::Gurdar_datos_edificios(){
    
    this->datos->gurdarDatosEdificios(this->edificios);
    cout << "Se han guardado los datos." << endl;
}

int Juego::obtener_cant_lineas(){

    return datos->obtener_cant_lineas();
}

bool Juego::obtener_esta_ubicaciones(){

    return datos->obtener_esta_ubicaciones();
}

Vect<string>* Juego::obtener_objetivos(){

    return objetivos;
}
