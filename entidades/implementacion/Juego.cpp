#include "../firmas/Juego.h"
#include "../../recursos/firmas/Recursos.h"
#include <iostream>


const string ASERRADERO = "aserradero";
const string FABRICA = "fabrica";
const string MINA = "mina";

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

const int VACIO = 0;
const int INICIO = 0;

const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";


//----------------------------IMPLEMENTACIÓN DE FUNCIONES PRIVADAS---------------------------------------

Vect<Coordenada>* Juego::obtenerCoordenadas(string nombreEdificio){
    Vect<Coordenada>* coordenadasDelEdificioConstruido = new Vect<Coordenada>;
    Coordenada* coordenada = NULL;
    Edificio* edificio = NULL;

    for(int fil = 0; fil < this->mapa->getCantFilas(); fil++){
        for(int col = 0; col < this->mapa->getCantColumnas(); col++){
            coordenada = new Coordenada(fil,col);
            edificio = this->mapa->getCasillero(*coordenada)->getEdificio();
            if(edificio && edificio->getNombre() == nombreEdificio){
                coordenadasDelEdificioConstruido->agregar(coordenada);
            }else{
                delete coordenada; // libero porque no lo guardaré en mi Vect de coordenadas, sino perdería memoria
            }
        }
    }
    return coordenadasDelEdificioConstruido;
}

Material* Juego::obtenerMaterial(string nombreMaterial, Jugador* jugador){
    int pos = 0;
    bool seEncontro = false;
    Material* material = NULL;
    while(!seEncontro && pos < jugador->obtener_inventario()->obtenerCantidad()){
        material = jugador->obtener_inventario()->obtenerDato(pos);
        if(material->getNombre() == nombreMaterial)
            seEncontro = true;
        pos++;
    }

    return material;
    
}

Edificio* Juego::obtenerEdificio(string nombreEdificio){

    Edificio* edificio = NULL;
    edificio = this->edificios->buscar(nombreEdificio);
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

//----------------------------------------------------------------------------------------------------------------

                                                          //No va

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

}

Juego::~Juego(){
    delete datos;
    delete edificios;
    delete jugador_1;
    delete jugador_2;
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
}


void Juego::mostrarInventario(Jugador* jugador){ 
    
    cout << "		INVENTARIO" << endl;
    jugador->obtener_inventario()->mostrar();
}

void Juego::listarEdificiosConstruidos(Jugador* jugador){
    Recurso recursos;
    Vect<Coordenada>* coordenadasDelEdificioConstruido = NULL;
    string nombre;

	cout << "\n\n\n\n LISTADO DE TODOS LOS EDIFICIOS CONSTRUIDOS";
    for(int pos = 0; pos < jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerCantidad(); pos++){

        nombre = this->mapa->getCasillero(*(jugador->obtener_coordenadasDeEdificiosConstruidos()->obtenerDato(pos)))->getEdificio()->getNombre();
        coordenadasDelEdificioConstruido = this->obtenerCoordenadas(nombre);
        //TODO--> SE VAN A REPETIR LOS EDIFICIOS, LUEGO VERIFICAR QUE NO SUCEDA ESO.
        if(coordenadasDelEdificioConstruido->obtenerCantidad() != VACIO){

            cout << "\n\n"; 
            cout << "|---------------------------------------------|" << endl;
            cout << "		"<< recursos.convertirAMayuscula(nombre) << endl;
            cout << "	CANTIDAD CONSTRUIDOS :" << coordenadasDelEdificioConstruido->obtenerCantidad() << endl;
            cout << " COORDENADAS DE DONDE ESTÁN CONSTRUIDOS" << endl;
            coordenadasDelEdificioConstruido->mostrar();
            cout << "|---------------------------------------------|" << endl;
            cout << "\n"; 
        }
        delete coordenadasDelEdificioConstruido; //Libero así a la siguiente iteración no pierdo memoria
        coordenadasDelEdificioConstruido = NULL;
    }
}


void Juego::listarTodosLosEdificios(){
    /*
    Edificio* edificio = NULL;
    Vect<Coordenada>* coordenadasDelEdificioConstruido = NULL;
    cout << "       lISTADO DE TODOS LOS EDIFICIOS \n\n" ;
    for(int pos = 0; pos < this->edificios->obtenerCantidad(); pos++){
        edificio = this->edificios->obtenerDato(pos);
        coordenadasDelEdificioConstruido = this->obtenerCoordenadas(edificio->getNombre());
        edificio->mostrar();
        cout << "        CANTIDAD CONSTRUIDOS : " << coordenadasDelEdificioConstruido->obtenerCantidad() << endl;
        cout << "        FALTAN CONSTRUIR : " << edificio->getMaxCantPermitidos() - coordenadasDelEdificioConstruido->obtenerCantidad() << endl;
        cout << "|---------------------------------------------|" << endl;

        delete coordenadasDelEdificioConstruido;
        coordenadasDelEdificioConstruido = NULL;
    }*/
    edificios->mostrarInorder();
    //TODO--> falta los criterior de cantid construidos y faltan construir, ¿se puede saber a priori? 
    //porque si es general cuanto hay permitidos es para los dos?, si se tiene 5 aserrador, como maximo entre j1 yj2 solo pueden crear 5 aserraderos?
    

}


void Juego::construirEdificioPorNombre(string nombre, Coordenada coordenada, Jugador* jugador){
    

    Vect<Coordenada>* coordenadasDelEdificioConstruido  = NULL;
    Casillero* casillero = NULL;
    Edificio* edificio = NULL;
    Material* piedra = NULL;
    Material* madera = NULL;
    Material* metal = NULL;

    //Verifico que el nombre del edificio exista
    edificio = this->obtenerEdificio(nombre);
    if(edificio){

        //Verifico que la cantidad de materiales sea el adecuado
        piedra = this->obtenerMaterial(PIEDRA, jugador);
        madera = this->obtenerMaterial(MADERA, jugador);
        metal = this->obtenerMaterial(METAL, jugador);

        if(piedra->getCantidad() > edificio->getCantPiedra() && madera->getCantidad() > edificio->getCantMadera() && metal->getCantidad() > edificio->getCantMetal()){
            
            //Verifico que la cantidad de construidos sea el adecuado
            coordenadasDelEdificioConstruido = this->obtenerCoordenadas(edificio->getNombre()); // al saber las coordenas tengo ya la cantidad de veces que se construyeron asi reutilizo la funcion y no me creo otra igual
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
    
}

void Juego::demolerEdificioPorCoordenada(Coordenada coordenada, Jugador* jugador){
    /*
    Casillero* casillero = this->mapa->getCasillero(coordenada);
    Edificio* edificio = NULL;
    if(casillero){
        edificio = casillero->demolerEdificio();

        //Si es que se demolió correctamente tengo que devolver la mitad de los materiales usado
        if(edificio){
            Material* piedra = this->obtenerMaterial(PIEDRA);
            Material* madera = this->obtenerMaterial(MADERA);
            Material* metal = this->obtenerMaterial(METAL);

            int piedraDeEdificio = edificio->getCantPiedra() / 2;
            int maderaDeEdificio = edificio->getCantMadera() / 2;
            int metalDeEdificio = edificio->getCantMetal() / 2;

            piedra->setCantidad(piedra->getCantidad() + piedraDeEdificio);
            madera->setCantidad(madera->getCantidad() + maderaDeEdificio);
            metal->setCantidad(metal->getCantidad() + metalDeEdificio);

            delete edificio; //TENGO QUE LIBERAR SU MEMORIA YA QUE EL CASILLERO CONSTRUIBLE ME DEVOLVIÓ LA DIRECCION Y ESTE LO INSTANCIÓ EN NULL
                            //ENTONCES CUANDO SE LIBERE CASILLERO CON SU DESTRUCTOR YA NO ESTARÍA ESTE EDIFICIO
        }

    }else
        cout << "\n\n ERROR--> COORDENADA FUERA DE RANGO DEL MAPA" << endl;
    */

}

void Juego::consultarCoordenada(Coordenada coordenada){
    Casillero* casillero = this->mapa->getCasillero(coordenada);
    if(casillero){
        casillero->mostrar();
    }else
        cout << "\n\n\n COORDENADA FUERA DEL RANGO" << endl;

}

void Juego::recolectarRecursosProducidos(Jugador* jugador){
    /*
    Material* piedra = NULL;
    Material* madera = NULL;
    Material* metal = NULL;
    
    Edificio* edificio = NULL;
    for(int fil = 0; fil < this->mapa->getCantFilas(); fil++){
        for(int col = 0; col < this->mapa->getCantColumnas(); col++){

            Coordenada coordena(fil,col);
            edificio = this->mapa->getCasillero(coordena)->getEdificio();

            if(edificio){

                //Dependiendo del edificio que brinda una cantidad de material, actualizo el material según corresponda
                if(edificio->getNombre() == MINA){
                    piedra = this->obtenerMaterial(PIEDRA);
                    piedra->setCantidad(piedra->getCantidad() + CANT_PIEDRA_BRINDADA);

                }else if(edificio->getNombre() == ASERRADERO){
                    madera = this->obtenerMaterial(MADERA);
                    madera->setCantidad(madera->getCantidad() + CANT_MADERA_BRINDADA);

                }else if(edificio->getNombre() == FABRICA){
                    metal = this->obtenerMaterial(METAL);
                    metal->setCantidad(metal->getCantidad() + CANT_METALES_BRINDADA);
                }

            }
        }
    }

    cout << "\n\n\nSE RECOLECTARON LOS RECURSOS EN CASO HAYA EXISITDO UN EDIFICIO QUE BRINDE RECURSOS" << endl;
    */
}

void Juego::moverJugador(Coordenada puntoFinal, int jugador){
    Casillero * casilleroActual = mapa->getCasillero(puntoFinal);
    Coordenada * caminoRecorrido;
    int topeCamino = 0;
    if( casilleroActual->devolver_jugador_casillero() != 0 || casilleroActual->getEdificio() != nullptr ) {
        cout << "La coordenada dada se encuentra ocupada" << endl;
    }
    else if( jugador == 1)
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

void Juego::modificar_valor_material(string material, int cant_material, string nombre_edificio){

    if(material == "piedra"){

        edificios->buscar(nombre_edificio)->setCantPiedra(cant_material);
    }
    else if(material == "madera"){

        edificios->buscar(nombre_edificio)->setCantMadera(cant_material);
    }
    else if(material == "metal"){

        edificios->buscar(nombre_edificio)->setCantMetal(cant_material);
    }
}

void Juego::modificar_valores_materiales(string material, string nombre_edificio){
    
    string decision;

    cout << "Desea modificar los valores de " <<  material << "?" << endl;
    cin >> decision;
    if(decision == "si"){
        cout << "Indique los nuevos valores de " <<  material << " entre 0 y 50000: " << endl;
        int cant_material;
        cin >> cant_material;

        if(cant_material > 0 && cant_material < 50000){
            
            modificar_valor_material(material, cant_material, nombre_edificio);
            
            cout << "Ahora el " << nombre_edificio << " se construye con " << cant_material << " de "<< material <<  "." << endl;
        }
        else{
            cout << "No cumple con los limites establecidos." << endl;
        }
                        
    }
    else{
        cout << "No se modificaron los valores de " << material << "." << endl;
        cout << endl;
    }


}

void Juego::modificar_edificio_por_nombre(){

    string nombre_edificio;

    cout << "Indique el nombre del edificio que desea modificar:" << endl;
    cin >> nombre_edificio;
    if(edificios->buscar(nombre_edificio) != NULL){
        if(nombre_edificio == "obelisco"){
            cout << "El obelisco no se puede modificar" << endl;
        }
        else{
            
            int contador_material = 0;
            while(contador_material < 3){

                if(contador_material == 0){

                    modificar_valores_materiales("piedra", nombre_edificio);
                }
                else if(contador_material == 1){
                    modificar_valores_materiales("madera", nombre_edificio);
                }
                else if(contador_material == 2){
                    modificar_valores_materiales("metal", nombre_edificio);
                }

                contador_material ++;
            }
        }
    }
    else{
        cout << "No existe el edificio." << endl;
    }


}

void Juego::comprar_bombas(Jugador* jugador){

    cout << "Cada bomba cuesta 100 andycoins, indique la cantidad que desea comprar:" << endl;
    cout << "Cantidad: ";
    int cantidad_bombas;
    cin >> cantidad_bombas;
    
    int posicion = 0;
    bool lo_encontro = false;
    int cantidad_andycoins;
    int cantidad_actual_bombas;
    
    while(posicion < jugador->obtener_inventario()->obtenerCantidad() && lo_encontro == false){

        if(jugador->obtener_inventario()->obtenerDato(posicion)->getNombre() == "andycoins"){
            
            cantidad_andycoins = jugador->obtener_inventario()->obtenerDato(posicion)->getCantidad();
            lo_encontro == true;
        }

        posicion ++;
    }

    int total_pagar = 100 * cantidad_bombas;

    if(cantidad_andycoins >= total_pagar){
        if(cantidad_bombas == 1){
            cout << "Se ha agregado " << cantidad_bombas << " bomba a su invnetario." << endl;
        }
        else if(cantidad_bombas > 1){
            cout << "Se han agregado " << cantidad_bombas << " bombas a su invnetario." << endl;
        }
        
        lo_encontro = false;
        posicion = 0;
        while(posicion < jugador->obtener_inventario()->obtenerCantidad() && lo_encontro == false){

            if(jugador->obtener_inventario()->obtenerDato(posicion)->getNombre() == "bombas"){
            
                cantidad_actual_bombas = jugador->obtener_inventario()->obtenerDato(posicion)->getCantidad();
                jugador->obtener_inventario()->obtenerDato(posicion)->setCantidad(cantidad_actual_bombas + cantidad_bombas);

                lo_encontro = true;
            }

            posicion ++;
        }
        
        lo_encontro = false;
        posicion = 0;
        while(posicion < jugador->obtener_inventario()->obtenerCantidad() && lo_encontro == false){

            if(jugador->obtener_inventario()->obtenerDato(posicion)->getNombre() == "andycoins"){
            
                jugador->obtener_inventario()->obtenerDato(posicion)->setCantidad(cantidad_andycoins - total_pagar);
                lo_encontro = true;
            }

            posicion ++;
        }
    }
    else{
        cout << "No tene la cantidad suificente de dinero para comprar " << cantidad_bombas << " bombas." << endl;
    }
        


}

void Juego::mostrar_primer_edificios(){

    edificios->mostrarInorder();
}

void Juego::mostrarMapa(){
    this->mapa->mostrar();
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