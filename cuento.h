#ifndef CUENTO_H
#define CUENTO_H
#include <iostream>
#include "lectura.h"

using namespace std;

class Cuento : public Lectura
{
    private:
        string tituloLibro;

	public:
        /*
        Constructor
        PRE: -
        POS: construye una Clase Cuento
        */
		Cuento(string _titulo, unsigned int _minutos, int _anio, string _autor, string _tituloLibro);

        //PRE: -
        //POS: Muestra los datos de la clase
		void mostrar();

        //PRE: -
        //POS: Devuelve el Genero
		string obtenerGenero();

        // Destructor
        ~Cuento(){};
		
};

#endif
