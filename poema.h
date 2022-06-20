#ifndef POEMA_H
#define POEMA_H
#include "lectura.h"
#include <iostream>

using namespace std;

class Poema : public Lectura
{
	public:
		Poema(string _titulo, string _minutos, string _anio,string _autor, string _cantidadVersos);
		void mostrar();
		string obtenerGenero();
	private:
		string cantidadVersos;
		
};

#endif
