#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H

#include <string>
#include "NodoG.h"

const int INFINITO = 9999999;

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
//const string NOMBRE_NO_ENCONTRADO = " ";

template < typename Tipo >
class ListaG{

private:

    int cantidadDeElementos;
    NodoG<Tipo>* primero;
    NodoG<Tipo>* ultimo;

    NodoG<Tipo>* obtener_nodo(int pos);

public:
    ListaG();

    //post: devuelve la cantidad de elementos que tiene la lista
    int obtenerCantidadDeElementos();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtenerPosicion(Tipo* nombre);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    Tipo* obtener_elemento(int posicion);
    
    Tipo* obtenerDato(int posicion);

    //post: agrega un nuevo elemento a la lista
    void agregar(Tipo* nuevoElemento);

    bool vacia();


    void baja(int pos);

    ~ListaG();
};

template < typename Tipo >
ListaG<Tipo>::ListaG(){
    cantidadDeElementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

template < typename Tipo >
int ListaG<Tipo>::obtenerCantidadDeElementos(){
    return cantidadDeElementos;
}

template < typename Tipo >
int ListaG<Tipo>::obtenerPosicion(Tipo* nombre) {
    bool elementoEncontrado = false;
    int i = 0;
    NodoG<Tipo>* auxiliar = primero;

    while(!elementoEncontrado && i < cantidadDeElementos){
        if(auxiliar -> obtenerNombre() == nombre){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtenerSiguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void ListaG<Tipo>::agregar(Tipo* nuevoElemento) {
    NodoG<Tipo>* nuevoNodo = new NodoG<Tipo>(nuevoElemento);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = primero;
    } else {
        ultimo -> asignarSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    cantidadDeElementos++;
}

template<typename Tipo>
ListaG<Tipo>::~ListaG() {
    NodoG<Tipo>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtenerSiguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
Tipo* ListaG<Tipo>::obtener_elemento(int posicion) {
    int i = 0;
    NodoG<Tipo>* auxiliar = primero;

/*
    if(posicion > cantidadDeElementos){
        return NOMBRE_NO_ENCONTRADO;
    }
*/
    while(i != posicion){
        auxiliar = auxiliar -> obtenerSiguiente();
        i++;
    }
    return (auxiliar->obtener_dato());

}

template <class Tipo>
Tipo* ListaG<Tipo> :: obtenerDato(int posicion){

	NodoG<Tipo>* aux = primero;
	int contador = 1;

	while (contador < posicion && aux->obtenerSiguiente()){
		aux = aux->obtenerSiguiente();
		contador++;
	}
	return aux->obtener_dato();
}

template < class Tipo >
bool ListaG<Tipo>::vacia(){
    return (cantidadDeElementos == 0);
}

template < class Tipo >
NodoG<Tipo>* ListaG<Tipo>::obtener_nodo(int pos){
    NodoG<Tipo>* aux = primero;
    int contador = 1;

    while (contador < pos) {
        aux = aux->obtenerSiguiente();
        contador++;
    }

    return aux;
}

template < class Tipo >
void ListaG<Tipo>::baja(int pos){
    NodoG<Tipo>* aux = primero;
    if (pos == 1) {
        primero = primero->obtenerSiguiente();
    }
    else {
        NodoG<Tipo>* anterior = obtener_nodo(pos - 1);
        aux = anterior->obtenerSiguiente();
        anterior->cambiar_siguiente(aux->obtenerSiguiente());
    }
    cantidadDeElementos--;

    aux->borrar();
    delete aux;
}

#endif //GRAFOS_LISTA_H
