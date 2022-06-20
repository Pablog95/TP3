#include "novela.h"

Novela :: Novela(string _titulo, string _minutos, string _anio, string _autor, string _genero):
											Lectura(_titulo, _minutos, _anio, _autor)
{
	this->genero = _genero;
}

void Novela :: mostrar(){
	//mostrarLectura();
	cout << "Titulo: " << obtenerTitulo() <<endl;
	cout << "Minutos: " << obtenerMinutos() << endl;
	cout << "Anio: " << obtenerAnio() << endl;
	cout << "Autor: " << obtenerAutor() << endl;
	cout << "Genero de la novela: " << genero << endl;
}

string Novela :: obtenerGenero(){
	return this->genero;
} 
