#include "../firmas/Recursos.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Recurso::Recurso(){}
Recurso::~Recurso(){}

string Recurso::convertirAMayuscula(string cadena){
    string cadenaNueva = "";
	for(int pos = 0; pos < (int)cadena.size(); pos++)
		cadenaNueva += (char)toupper(cadena[pos]);
	return cadenaNueva;
}

int Recurso::obtenerNumAleatorio(int rango1, int rango2){
	int numeroAleatorio;
	numeroAleatorio = rango1 + (rand()%(rango2 - rango1));
	return numeroAleatorio;
}
