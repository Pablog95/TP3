#ifndef HISTORICA_H
#define HISTORICA_H
#include <iostream>
#include "novela.h"
#include "lectura.h"

using namespace std;


class Historica : public Novela
{
	private:
		char* tema;

	public:
        /*
        Constructor
        PRE: -
        POS: construye una Clase Historica
        */
		Historica(string _titulo, unsigned int _minutos, int _anio, string _autor, string _genero, string _tema);

        //PRE: -
        //POS: Muestra los datos de la clase
		void mostrar();

        //PRE: -
        //POS: Devuelve el Genero
		string obtenerGenero();

        //PRE: -
        //POS: Devuelva el tema de la novela
        char* obtenerTema();

        // Destructor
	//PRE: -
	//POST: Libera memoria del char Tema y recursos.
        ~Historica();
		
		
};

#endif
