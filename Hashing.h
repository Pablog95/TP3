#ifndef TP_3_HASHING_H
#define TP_3_HASHING_H

#include "lista.h"
#include "escritor.h"

const int TAMANIO = 29; //Tamanio de la lista, dato sacado de calcular t = datosAIngresar / 0.8. y buscando el primer numero primo superior mas cercano.

template <class T>
class Hashing {
	
private:
	//T* tablaEscritor[TAMANIO];
	bool datoEncontrado[TAMANIO];
	Lista<Escritor>* listaEscritores;
	//list<Escritor>* listaEscritoresTabla;
	
public:
	//CONSTRUCTOR
	Hashing();
	
	//DESTRUCTOR
	~Hashing();
	void agregarEscritor(T* escritor, int clave);
	int obtenerPosicionClave(int clave);
	//T* mostrarHashing(int posicion);
	void mostrarHashing();
	void borrarDatoHashing(T* posicion);
	void borrarDatoHashing(int posicion);

};


template <class T>
Hashing<T>::Hashing(){
	for (int i = 0; i < TAMANIO; i++)
	{
		datoEncontrado[i] = false;
		listaEscritores = new Lista<Escritor>[i];
	}
}

template <class T>
void Hashing<T> :: agregarEscritor(T* escritor, int clave){
	int posicion = obtenerPosicionClave(clave);
	
	listaEscritores[posicion].agregarElemento(escritor);
	datoEncontrado[posicion] = true;
	
}

template<class T> 
int Hashing<T>::obtenerPosicionClave(int clave){
	return clave%TAMANIO;
}

template <class T>
void Hashing<T> :: mostrarHashing(){
	for(int i = 0; i < TAMANIO; i++)
	{
		
		if(datoEncontrado[i]){
			cout << "<-------------------------------->" << endl;
			cout << i << ") ";
			auto x= listaEscritores[i];
		
			int t = x.obtenerTamanio();
			
			x.obtenerDato(i)->mostrarDatos();
			for(int j = 1; j<t ; j++){
				cout << "<-------------------------------->"<< endl;
				cout << "| C | O | L | I | S | I | O | N |"<< endl;
				cout << "<-------------------------------->"<< endl;
				x.obtenerDato(j)->mostrarDatos();
			}
		}
	}
}

template<class T>
Hashing<T> :: ~Hashing(){

}
#endif //TP_3_HASHING_H