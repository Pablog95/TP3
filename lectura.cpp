#include "lectura.h"
#include <iostream>

using namespace std;

Lectura :: Lectura (string _titulo, unsigned int _minutos, int _anio, string _autor)
{
	this -> titulo = _titulo;
	this -> minutos = _minutos;
	this -> anio = _anio;
	this -> autor = _autor;
}

string Lectura :: obtenerTitulo(){
	return titulo;
}

unsigned int Lectura :: obtenerMinutos(){
	return minutos;
}

int Lectura :: obtenerAnio(){
	return anio;
}

string Lectura :: obtenerAutor(){
	return autor;
}
