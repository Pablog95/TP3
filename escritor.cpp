#include "escritor.h"
#include <iostream>

using namespace std;


Escritor :: Escritor(string _nombreApellido, string _nacionalidad, string _anioNacimiento, string _anioFallecimiento){
	this->nombreApellido = _nombreApellido;
	this->nacionalidad = _nacionalidad;
	this->anioNacimiento = _anioNacimiento;
	this->anioFallecimiento = _anioFallecimiento;
}
void Escritor :: mostrarDatos()
{
	cout <<"Nombre y apellido: " <<nombreApellido<<endl;
	cout <<"Nacionalidad: " << nacionalidad << endl;
	cout <<"Anio de nacimiento: "<< anioNacimiento<<endl;
	cout << "Anio de Fallecimiento: " <<anioFallecimiento<<endl;
};

void Escritor :: cambiarFallecimiento(){
	int anioFallecimientoNuevo;
	cout << "Ingrese el anio nuevo de fallecimiento: " << endl;
	cin >> anioFallecimientoNuevo;
	anioFallecimiento = anioFallecimientoNuevo;
	cout << "Se cambio la fecha de fallecimiento." << endl;
}

string Escritor ::  obtenerNombreApellido(){
	return nombreApellido;
}
