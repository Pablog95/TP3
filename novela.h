#ifndef NOVELA_H
#define NOVELA_H
#include <iostream>
#include "lectura.h"

using namespace std;

class Novela : public Lectura
{
    protected:
        string genero;

	public:
        /*
        Constructor
        PRE: -
        POS: construye una Clase Novela
        */
		Novela(string _titulo, unsigned int _minutos, int _anio, string _autor, string _genero);

        //PRE: -
        //POS: Muestra los datos de la clase
		void mostrar();

        //PRE: -
        //POS: Devuelve el Genero
		string obtenerGenero();

        // Destructor
		virtual ~Novela(){};
};

#endif
