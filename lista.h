#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

template <class T>
class Lista
{
	private:
		T* dato;
		Nodo<T>* primero;
		Nodo<T>* cursor;
		int cantidad;
		Nodo<T>* obtenerNodo(int posicion);
	public:
		Lista();
		~Lista();
		void agregarElemento(T* dato);//, int posicion
		bool listaVacia();
		void borrarDato(int posicion);
		void mostrarLista();
		int obtenerTamanio();
		T* obtenerDato(int posicion);
		
};



template<class T>
Lista<T> :: Lista(){
	primero = 0;
	cantidad = 0;
}

template<class T>
Lista<T>::~Lista(){
	while (!listaVacia()){
		this->borrarDato(1);
	}
}

template<class T>
bool Lista<T> :: listaVacia(){
	return (cantidad == 0);
}

template<class T>
void Lista<T> :: agregarElemento(T* dato){
	Nodo<T>* nuevo = new Nodo<T>(dato);
	if (!(this->listaVacia())){
		nuevo->cambiarSiguiente(primero);
		primero = nuevo;
	}/*
	else{
		Nodo<T>* anterior = obtenerNodo(posicion - 1);
		nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
		anterior->cambiarSiguiente(nuevo);
	}*/
	cantidad++;
}

template <class T>
T* Lista<T> :: obtenerDato(int posicion){
	Nodo<T>* aux = primero;
	int contador = 1;
	while (contador < posicion && aux->obtenerSiguiente()){
		aux = aux->obtenerSiguiente();
		contador++;
	}
	return aux->obtenerDato();
}


template<class T>
Nodo<T>* Lista<T>::obtenerNodo(int posicion){
	Nodo<T>* aux = primero;
	int contador = 1;
	while (contador < posicion){
		aux = aux->obtenerSiguiente();
		contador++;
	}
	return aux;
}

template <class T>
void Lista<T> :: borrarDato(int posicion){
	Nodo<T>* auxBorrar = primero;
	if(!listaVacia()){
		if (posicion == 1){
			primero = primero->obtenerSiguiente();
		}
		else{
			Nodo<T>* anterior = obtenerNodo(posicion - 1);
			auxBorrar = anterior->obtenerSiguiente();
			anterior->cambiarSiguiente(auxBorrar->obtenerSiguiente());
		}
		cantidad--;
		delete auxBorrar;
	}
}
template <class T>
void Lista<T> :: mostrarLista(){
	
	Nodo<T>* actual = new Nodo<T>();
	actual = primero;
	
	while(actual != NULL){
		cout << actual->obtenerDato() << endl;
		actual = actual->obtenerSiguiente();
	}
}
template <class T>
int Lista<T> :: obtenerTamanio(){
	return cantidad;
}
#endif
