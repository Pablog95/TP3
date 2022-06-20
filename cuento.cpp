#include "cuento.h"

Cuento :: Cuento(string _titulo, unsigned int _minutos, int _anio, string _autor, string _tituloLibro) :
																	Lectura (_titulo, _minutos, _anio, _autor)
																	
{
	this->tituloLibro = _tituloLibro;
}
string Cuento :: obtenerGenero(){
	return "";
}

void Cuento:: mostrar(){
	cout << "Titulo: " << obtenerTitulo() <<endl;
	cout << "Minutos: " << obtenerMinutos() << endl;
	cout << "Anio: " << obtenerAnio() << endl;
	cout << "Autor: " << obtenerAutor() << endl;
	cout <<"Titulo del libro: " <<tituloLibro << endl;
}
