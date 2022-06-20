#ifndef COLA_H
#define COLA_H
#include "nodo.h"

template <class T>
class Cola
{
	public:
		Cola();
		~Cola();
		bool colaVacia();
		void agregarCola(T* dato);
		T* obtenerDatoCola();
		T* bajaCola();
	private:
		T* dato;
		Nodo<T>* primero;
		Nodo<T>* ultimo;
		
};

template <class T>
Cola<T> :: Cola(){
	primero = 0;
	ultimo = 0;
}

template <class T>
Cola<T> :: ~Cola(){
	while(!(colaVacia())){
		bajaCola();
	}
}

template <class T>
bool Cola<T> :: colaVacia(){
	return (primero == 0);
}

template <class T>
void Cola<T> :: agregarCola(T* dato){
	T* dato= new T*(dato);
	Nodo<T>* nodo = new Nodo<T>(dato);
	if(this->colaVacia()){
		primero = nodo;
	}
	else{
		ultimo->cambiarSiguiente(nodo);
	}
	ultimo = nodo;
}

template <class T>
T* Cola<T> :: obtenerDatoCola(){
	return primero->obtenerDato();/*
	T* dato = this->primero->obtenerDato();
	return dato->obtenerDato();*/
}
template <class T>
T* Cola<T> :: bajaCola(){
	if(primero == ultimo)
		ultimo = 0;
	Nodo<T>* pAux = primero;
	T* aux= (primero->obtenerDato());
	primero = pAux->obtenerSiguiente();
	delete pAux;
	return aux;
}

#endif
