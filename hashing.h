#ifndef TP_3_HASHING_H
#define TP_3_HASHING_H

#include "Lista.h"
#include "Escritor.h"
#include "ListaG.h"

#include <list>


template <class Dato>
class Hashing {

private:
    bool dato_encontrado[TAMANIO];

    ListaG<Escritor>* lista_escritores_tabla;

public:
    //CONSDatoRUCDatoOR
    Hashing();

    //DESDatoRUCDatoOR
    ~Hashing();
    void agregar_escritor(Dato* escritor, int clave);
    void baja_escritor(Dato* escritor);
    int obtener_posicion_clave(int clave);
    //Dato* mostrar_hashing(int posicion);
    void mostrar_hashing();

};


template <class Dato>


Hashing<Dato>::Hashing(){
    for (int i = 0; i < TAMANIO; i++)
    {
        lista_escritores_tabla = new ListaG <Escritor>[i];
        dato_encontrado[i] = false;
    }
    
}


template<class Dato>
void Hashing<Dato>::agregar_escritor(Dato* escritor, int clave){
    int posicion = obtener_posicion_clave(clave);
	
	lista_escritores_tabla[posicion].agregar(escritor);
	dato_encontrado[posicion] = true;
}


template<class Dato>
int Hashing<Dato>::obtener_posicion_clave(int clave){
    return clave%TAMANIO;
}


template <class Dato>
void Hashing<Dato> :: mostrar_hashing(){
	for(int i = 0; i < TAMANIO; i++)
	{
		
		if(dato_encontrado[i]){
			cout << "<-------------------------------->" << endl;
			cout << i << ") ";
			auto x= lista_escritores_tabla[i];
		
			int tamanio_lista = x.obtenerCantidadDeElementos();
			
			x.obtenerDato(i)->mostrar();
			for(int j = 1; j < tamanio_lista ; j++){
				cout << "<-------------------------------->"<< endl;
				cout << "| C | O | L | I | S | I | O | N |"<< endl;
				cout << "<-------------------------------->"<< endl;
				x.obtenerDato(j)->mostrar();
			}
		}
	}
}

template <class Dato>
void Hashing<Dato> :: baja_escritor(Dato* escritor){
	
	for (int i = 0; i < TAMANIO; i++)
	{
		auto x = lista_escritores_tabla[i];
		
		int tamanio_lista = x.obtenerCantidadDeElementos();
		/*if (x.obtenerDato(i) == escritor->obtener_nombres())
			x.*/
	}
	
}

template<class Dato>
Hashing<Dato> :: ~Hashing(){

}
