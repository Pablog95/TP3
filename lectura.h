#ifndef LECTURA_H
#define LECTURA_H
#include <iostream>
#include "escritor.h"

using namespace std;

class Lectura
{
	protected:
		string titulo;
		unsigned int minutos;
		int anio;
		string autor;

	public:
        /*
        Constructor
        PRE: -
        POS: construye una Clase Lectura
        */
		Lectura (string _titulo, unsigned int _minutos, int _anio, string _autor);

        //PRE: -
        //POS: Devuelve el titulo
		string obtenerTitulo();

        //PRE: -
        //POS: Devuelve los minutos
        unsigned int obtenerMinutos();

        //PRE: -
        //POS: Devuelve el anio
		int obtenerAnio();

        //PRE: -
        //POS: Devuelve el autor
		string obtenerAutor();

        //PRE: -
        //POS: Muestra los datos de la clase la clase
		virtual void mostrar() = 0;

        //PRE: -
        //POS: Devuelve el Genero
		virtual string obtenerGenero() = 0;

        // Destructor
		virtual ~Lectura(){};
};

#endif
