#ifndef TP_3_HASHING_H
#define TP_3_HASHING_H

#include "escritor.h"

const int TAMANIO = 29; //Tamanio de la lista, dato sacado de calcular t = datosAIngresar / 0.8. y buscando el primer numero primo superior mas cercano.

template <class Dato>
class Hashing {
	
private:
	Dato* tablaEscritor[TAMANIO];
	bool datoEncontrado[TAMANIO];
	Lista<Escritor>* listaEscritores;
	
public:
	//CONSTRUCTOR
	Hashing();
	
	//DESTRUCTOR
	~Hashing();
	void agregarEscritor(Dato* escritor, int clave);
	Dato* mostrarHashing(int posicion);
	int obtenerPosicionClave(int clave);

};

template <class Dato>
Hashing<Dato>::Hashing(){
	for (int i = 0; i < TAMANIO; i++)
	{
		tablaEscritor[i] = nullptr;
		datoEncontrado[i] = false;
	}
	this->listaEscritores = new Lista<Escritor>;
}

template<class Dato>
void Hashing<Dato>::agregarEscritor(Dato* escritor, int clave){
	int posicion = obtenerPosicionClave(clave);
	
	if(tablaEscritor[posicion] == nullptr)
	{
		tablaEscritor[posicion] = escritor;
	}/*else{
		
		tablaEscritor[posicion] = listaEscritores->agregarElemento(escritor);
	}*/
}


template<class Dato>
int Hashing<Dato>::obtenerPosicionClave(int clave){
	return clave%TAMANIO;
}

template <class Dato>
Dato* Hashing<Dato> :: mostrarHashing(int posicion){
	if (datoEncontrado[posicion] == true){
		return tablaEscritor[posicion];
	}else{
		cout << "No hay elementos" << endl;
	}
	
}

template<class Dato>
Hashing<Dato> :: ~Hashing(){
	for(int i = 0; i < TAMANIO; i++)
	{
		delete tablaEscritor[i];
	}
	
	delete listaEscritores;
}


#endif //TP_3_HASHING_H
