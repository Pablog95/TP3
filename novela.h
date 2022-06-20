#ifndef NOVELA_H
#define NOVELA_H
#include <iostream>
#include "lectura.h"

using namespace std;

class Novela : public Lectura
{
	public:
		Novela(string _titulo, string _minutos, string _anio, string _autor, string _genero);
		void mostrar();
		string obtenerGenero();
		virtual ~Novela(){};
	protected:
		string genero;
};

#endif
