#ifndef HISTORICA_H
#define HISTORICA_H
#include <iostream>
#include "novela.h"
#include "lectura.h"

using namespace std;


class Historica : public Novela
{
	private:
		string tema;
	public:
		Historica(string _titulo, string _minutos, string _anio, string _autor, string _genero, string _tema);
		void mostrar();
		string obtenerGenero();
		
		
};

#endif
