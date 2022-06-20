#ifndef ESCRITOR_H
#define ESCRITOR_H
#include <iostream>

using namespace std;

class Escritor
{
    private:

        string referencia;
        string nombreApellido;
        string nacionalidad;
        int anioNacimiento;
        int anioFallecimiento;

	public:
		//Constructor.
		//PRE: -
		//POST: Inicializa Escritor con sus atributos.
		Escritor(string referencia,string _nombreApellido, string _nacionalidad, int _anioNacimiento, int _anioFallecimiento);

		//PRE: -
		//POST: Muestra por pantalla los atributos.
		void mostrarDatos();
		
		//PRE: - 
		//POST: Devuelve nombre y apellido.
		string obtenerNombreApellido();

		//PRE: Recibe anio valido.
		//POST: Cambia el anio de Fallecimiento.
		void cambiarFallecimiento();
	
		//PRE:-
		//POST: Devuelve la referencia.
        	string obtenerReferencia();
	
		//Destructor.
		//PRE: -
		//POST: Libera los recursos.
		~Escritor(){};

};

#endif
