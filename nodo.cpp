#include "nodo.h"
template <class T>
Nodo<T> :: Nodo(T _dato){
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
T Nodo<T>::obtenerDato(){
	return dato;
}


