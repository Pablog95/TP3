#ifndef ESCRITOR_H
#define ESCRITOR_H
#include <iostream>

using namespace std;

class Escritor
{
	public:
		Escritor();
		Escritor(string _nombreApellido, string _nacionalidad, string _anioNacimiento, string anioFallecimiento);
		void mostrarDatos();
		string obtenerNombreApellido();
		void cambiarFallecimiento();
		~Escritor(){};
		
	private:
		string nombreApellido;
		string nacionalidad;
		string anioNacimiento;
		string anioFallecimiento;
};

#endif
