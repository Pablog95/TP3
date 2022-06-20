#include "poema.h"

Poema :: Poema(string _titulo, unsigned int _minutos, int _anio,string _autor, string _cantidadVersos) : Lectura(_titulo, _minutos, _anio, _autor){
	this->cantidadVersos = _cantidadVersos;
}

void Poema :: mostrar(){

	cout << "Titulo: " << obtenerTitulo() <<endl;
	cout << "Minutos: " << obtenerMinutos() << endl;
	cout << "Anio: " << obtenerAnio() << endl;
	cout << "Autor: " << obtenerAutor() << endl;
	cout << "Cantidad de versos: " << cantidadVersos << endl;
}

string Poema :: obtenerGenero(){
	return "" ;
}
