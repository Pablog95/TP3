#include "cuento.h"

Cuento :: Cuento(string _titulo, string _minutos, string _anio, string _autor, string _tituloLibro) :
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
	//mostrarLectura();
	cout <<"Titulo del libro: " <<tituloLibro << endl;
}
