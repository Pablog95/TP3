#ifndef TP_3_HASHING_H
#define TP_3_HASHING_H

#include "lista.h"
#include "escritor.h"
#include <list>

const int TAMANIO = 29; //Tamanio de la lista, dato sacado de calcular t = datosAIngresar / 0.8. y buscando el primer numero primo superior mas cercano.

template <class T>
class Hashing {
	
private:
	T* tablaEscritor[TAMANIO];
	bool datoEncontrado[TAMANIO];
	Lista<Escritor>* listaEscritores;
	list<Escritor>* listaEscritoresTabla;
	
public:
	//CONSTRUCTOR
	Hashing();
	
	//DESTRUCTOR
	~Hashing();
	void agregarEscritor(T* escritor, int clave);
	int obtenerPosicionClave(int clave);
	//T* mostrarHashing(int posicion);
	void mostrarHashing();

};


template <class T>


Hashing<T>::Hashing(){
	for (int i = 0; i < TAMANIO; i++)
	{
		tablaEscritor[i] = nullptr;
		datoEncontrado[i] = false;
	}
	this->listaEscritores = new Lista<Escritor>[TAMANIO];
	listaEscritoresTabla = new list<Escritor>[TAMANIO];
}

/*
template<class T>
Hashing<T>::Hashing(){
	
	this->listaEscritores = new Lista<Escritor>[TAMANIO];
}*/

/*
template<class T>
void Hashing<T>::agregarEscritor(T* escritor, int clave){
	int posicion = obtenerPosicionClave(clave);

	listaEscritores[posicion].agregarElemento(escritor,posicion);
	}
*/


template<class T>
void Hashing<T>::agregarEscritor(T* escritor, int clave){
	int posicion = obtenerPosicionClave(clave);
	
	if(tablaEscritor[posicion] == nullptr)
		{
		tablaEscritor[posicion] = escritor;
		datoEncontrado[posicion] = true;
	}else{
		listaEscritoresTabla[posicion].push_back(*escritor);
	
	}
	/*listaEscritores[posicion].agregarElemento(escritor);
	datoEncontrado[posicion] = true;
	
	if(tablaEscritor[posicion] == nullptr)
	{
		tablaEscritor[posicion] = escritor;
		datoEncontrado[posicion] = true;
	}else{
		
		tablaEscritor[posicion] = listaEscritores->agregarElemento(escritor);
	}*/
}


template<class T> 
int Hashing<T>::obtenerPosicionClave(int clave){
	return clave%TAMANIO;
}
/*
template<class T>
T Hashing<T> :: mostrarHashing(int posicion){
	return listaEscritores[posicion];

}*/
/*
template <class T>
T* Hashing<T> :: mostrarHashing(int posicion){
	if (datoEncontrado[posicion] == true){
		return tablaEscritores[posicion];
	}else{
		cout << "No hay elementos" << endl;
	}
	
}*/

template <class T>
void Hashing<T> :: mostrarHashing(){
	for(int i = 0; i < TAMANIO; i++){
		cout << i << ")";
		if(datoEncontrado[i] == true){
			tablaEscritor[i]->mostrarDatos();
		}
		//tablaEscritor[i]->mostrarDatos();
		for (auto x: listaEscritoresTabla[i]){
			//tablaEscritor[i]->mostrarDatos();
			cout << endl;
			x.mostrarDatos();
		}
		cout << endl;
	}
		//listaEscritores[i].mostrarDatos();
}
	/*}else{
		cout << "No hay elementos" << endl;
}*/

template<class T>
Hashing<T> :: ~Hashing(){
	for(int i = 0; i < TAMANIO; i++)
	{
		delete tablaEscritor[i];
	}
	
	delete listaEscritores;
	
}


#endif //TP_3_HASHING_H
