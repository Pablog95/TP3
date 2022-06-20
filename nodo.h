#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "escritor.h"
#include "lectura.h"

using namespace std;

template <class T>
class Nodo
{
	private:
		T* dato; // Dato.
		Nodo<T>* siguiente; // Puntero a siguiente nodo.

	public:
		
		//Constructor.
		//PRE: Puntero que apunta a algun dato.
		//POST:	Crea nodo con el dato.
		Nodo(T* _dato);
	
		//PRE: Nodo creado.
		//POST: Modifica el nodo al siguiente.
		void cambiarSiguiente(Nodo* _siguiente);
		
		//PRE: Nodo creado.
		//POST: Devuelve el puntero del siguiente nodo. Si es el ultimo devuelve NULL.
		Nodo<T>* obtenerSiguiente();

		//PRE: Nodo creado
		//POST: Devuelve el dato del nodo.
		T* obtenerDato();
	
		//Destructor.
		//PRE: Nodo creado
		//POST: Libera recursos.
		~Nodo();
};



template <class T>
Nodo<T> :: Nodo(T* _dato){
	dato = _dato;
	siguiente = 0;
}

template <class T>
Nodo<T> :: ~Nodo(){
	delete dato;
}

template <class T>
void Nodo<T> :: cambiarSiguiente (Nodo* _siguiente){
	siguiente = _siguiente;
}

template <class T>
Nodo<T>* Nodo<T> :: obtenerSiguiente(){
	return siguiente;
}

template <class T>
T* Nodo<T>::obtenerDato(){
	return dato;
}

#endif
