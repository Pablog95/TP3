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
		T* dato;
		Nodo<T>* siguiente;
	public:
		
		Nodo(T* _dato);
		void cambiarSiguiente(Nodo* _siguiente);
		Nodo<T>* obtenerSiguiente();
		T* obtenerDato();
};

template <class T>
Nodo<T> :: Nodo(T* _dato){
	dato = _dato;
	siguiente = 0;
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
