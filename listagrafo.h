#ifndef TP_3_LISTAGRAFO_H
#define TP_3_LISTAGRAFO_H
#include <iostream>
#include "grafonodo.h"
#include "vertice2.h"

using namespace std;

//const int POSICION_NO_ENCONTRADA = -1;
//const string NOMBRE_NO_ENCONTRADO = "";

template <class Dato>
class ListaGrafo {
private:
    int cantidadElementos;
    GrafoNodo<Dato>* primero;
    GrafoNodo<Dato>* ultimo;

public:

    ListaGrafo();
    int obtenerCantidadElementos();
    int obtenerPosicion(Dato* nombre);
    Dato* obtenerNombre(int posicion);
    void agregarElementos(Dato* nuevoElemento);

};

template <class Dato>
ListaGrafo<Dato> :: ListaGrafo (){
    cantidadElementos = 0;
    primero = nullptr;
    ultimo = nullptr;
}

template <class Dato>
int ListaGrafo<Dato> ::obtenerCantidadElementos() {
    return this->cantidadElementos;
}

template <class Dato>
int ListaGrafo<Dato> :: obtenerPosicion(Dato* nombre) {
    bool elementoEncontrado = false;
    int i = 0;
    GrafoNodo<Dato>* aux = primero;

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

template <class Dato>
void ListaGrafo<Dato> ::agregarElementos(Dato* elementoNuevo) {
    GrafoNodo<Dato>* nodoNuevo = new GrafoNodo<Dato>(elementoNuevo);
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

template <class Dato>
Dato* ListaGrafo<Dato> ::obtenerNombre(int posicion) {
    int i = 0;
    GrafoNodo<Dato>* aux = primero;

    if(posicion > cantidadElementos){
        return "";
    }

    while(i != posicion - 1){
        aux = aux->obtenerSiguiente();
    }
    return aux->obtenerNombre();
}

#endif //TP_3_LISTAGRAFO_H
