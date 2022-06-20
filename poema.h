#ifndef POEMA_H
#define POEMA_H
#include "lectura.h"
#include <iostream>

using namespace std;

class Poema : public Lectura
{
    private:
        string cantidadVersos;

    public:
        /*
        Constructor
        PRE: -
        POS: construye una Clase Poema
        */
		Poema(string _titulo, unsigned int _minutos, int _anio,string _autor, string _cantidadVersos);

        //PRE: -
        //POS: Muestralos datos de la clase la clase
		void mostrar();

        //PRE: -
        //POS: Devuelve el Genero
		string obtenerGenero();

        // Destructor
        ~Poema(){};
		
};

#endif
