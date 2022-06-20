#include "historica.h"

Historica :: Historica (string _titulo, string _minutos, string _anio, string _autor,string _genero, string _tema):
									Novela (_titulo, _minutos, _anio, _autor, _genero)
{
	this->tema = _tema;
}

void Historica :: mostrar(){
	cout << "Titulo: " << obtenerTitulo() <<endl;
	cout << "Minutos: " << obtenerMinutos() << endl;
	cout << "Anio: " << obtenerAnio() << endl;
	cout << "Autor: " << obtenerAutor() << endl;
	cout << "Genero: " << obtenerGenero() << endl;
	cout << "Tema: " << tema << endl;
}

string Historica :: obtenerGenero(){
	return this->genero;
} 
