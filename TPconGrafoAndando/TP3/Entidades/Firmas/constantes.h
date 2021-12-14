#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED
#include <string>

const std::string PATH_MATERIALES = "./Archivos/materiales.txt";
const std::string PATH_EDIFICIOS = "./Archivos/edificios.txt";
const std::string PATH_MAPA = "./Archivos/mapa.txt";
const std::string PATH_UBICACIONES = "./Archivos/ubicaciones.txt";

const int NULO = 0;
const std::string VACIO = "-";

const int OPCION_0 = 0;
const int OPCION_1 = 1;
const int OPCION_2 = 2;
const int OPCION_3 = 3;
const int OPCION_4 = 4;
const int OPCION_5 = 5;
const int OPCION_6 = 6;
const int OPCION_7 = 7;
const int OPCION_8 = 8;
const int OPCION_9 = 9;
const int OPCION_10 = 10;

const std::string PIEDRA = "piedra";
const std::string MADERA = "madera";
const std::string METAL = "metal";

const std::string ASERRADERO = "aserradero";
const std::string MINA = "mina";
const std::string MINA_ORO = "mina_oro";
const std::string FABRICA = "fabrica";
const std::string PLANTA_ELECTRICA = "planta_electrica";
const std::string OBELISCO = "obelisco";
const std::string ESCUELA = "escuela";

const char CARACTER_ASERRADERO = 'A';
const char CARACTER_MINA = 'M';
const char CARACTER_MINA_ORO = 'G';
const char CARACTER_FABRICA = 'F';
const char CARACTER_PLANTA_ELECTRICA = 'P';
const char CARACTER_OBELISCO = 'O';
const char CARACTER_ESCUELA = 'E';

const char CARACTER_PIEDRA = 'S';
const char CARACTER_MADERA = 'W';
const char CARACTER_METAL = 'I';

const char LAGO = 'L';
const char CAMINO = 'C';
const char TERRENO = 'T';
const char BETUN = 'B';
const char MUELLE = 'M';


#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__

#endif //CONSTANTES_H_INCLUDED