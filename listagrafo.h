#ifndef TP_3_LISTAGRAFO_H
#define TP_3_LISTAGRAFO_H
#include <iostream>
#include "grafonodo.h"
#include "vertice2.h"

using namespace std;

//const int POSICION_NO_ENCONTRADA = -1;
//const string NOMBRE_NO_ENCONTRADO = "";

template <class T>
class ListaGrafo {
private:
    int cantidadElementos;
    GrafoNodo<T>* primero;
    GrafoNodo<T>* ultimo;

public:

    ListaGrafo();
    int obtenerCantidadElementos();
    int obtenerPosicion(T* nombre);
    T* obtenerNombre(int posicion);
    void agregarElementos(T* nuevoElemento);

};

template <class T>
ListaGrafo<T> :: ListaGrafo (){
    cantidadElementos = 0;
    primero = nullptr;
    ultimo = nullptr;
}

template <class T>
int ListaGrafo<T> ::obtenerCantidadElementos() {
    return this->cantidadElementos;
}

template <class T>
int ListaGrafo<T> :: obtenerPosicion(T* nombre) {
    bool elementoEncontrado = false;
    int i = 0;
    GrafoNodo<T>* aux = primero;

    while(!elementoEncontrado && i<cantidadElementos){
        if(aux->obtenerNombre() == nombre) {
            elementoEncontrado = true;
        }
        i++;
        aux = aux->obtenerSiguiente();
    }

    if(!elementoEncontrado){
        return -1;
    }
    return i - 1;

}

template <class T>
void ListaGrafo<T> ::agregarElementos(T* elementoNuevo) {
    GrafoNodo<T>* nodoNuevo = new GrafoNodo<T>(elementoNuevo);
    if(primero == nullptr){
        primero = nodoNuevo;
        ultimo = primero;
    }
    else
    {
        ultimo->cambiarSiguiente(nodoNuevo);
        ultimo = nodoNuevo;
    }
    cantidadElementos++;
}

template <class T>
T* ListaGrafo<T> ::obtenerNombre(int posicion) {
    int i = 0;
    GrafoNodo<T>* aux = primero;

    if(posicion > cantidadElementos){
        return "";
    }

    while(i != posicion - 1){
        aux = aux->obtenerSiguiente();
    }
    return aux->obtenerNombre();
}

#endif //TP_3_LISTAGRAFO_H
