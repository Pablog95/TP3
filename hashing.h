#ifndef TP_3_HASHING_H
#define TP_3_HASHING_H

#include "lista.h"
#include "escritor.h"

const int TAMANIO = 29; //Tamanio de la lista, dato sacado de calcular t = datosAIngresar / 0.8. y buscando el primer numero primo superior mas cercano.

template <class T>
class Hashing {
	
private:
	T* tablaEscritor[TAMANIO];
	bool datoEncontrado[TAMANIO];
	Lista<Escritor>* listaEscritores;
	
public:
	//CONSTRUCTOR
	Hashing();
	
	//DESTRUCTOR
	~Hashing();
	void agregarEscritor(T* escritor, int clave);
	int obtenerPosicionClave(clave);
	


};


template <class T>
Hashing<T>::Hashing(){
	for (int i = 0; i < TAMANIO; i++)
	{
		escritor[TAMANIO] = nullptr;
		datoEncontrado[TAMANIO] = false;
	}
	this->listaLectura = new Lista<Escritor>
}

template<class T>
void Hashing<T>::agregarEscritor(T* escritor, int clave){
	int posicion = obtenerPosicionClave(clave);
	
	if(tablaEscritor[posicion] == nullptr)
	{
		tablaEscritor[posicion] = escritor;
	}else{
		
		tablaEscritor[posicion] = listaLectura->agregarElemento(escritor);
	}
}


template<class T> 
int Hashing<T>::obtenerPosicionClave(int clave){
	return clave%TAMANIO;
}

template<class T>
Hashing<T> :: ~Hashing(){
	for(int i = 0; i < TAMANIO; i++)
	{
		delete tablaEscritor[i];
	}
	
}


#endif //TP_3_HASHING_H
