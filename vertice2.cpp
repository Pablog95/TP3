#include "vertice2.h"

template <class T>
Vertice2<T> ::Vertice2(T* nombre) {
    this->nombre = nombre;
}

template <class T>
T* Vertice2<T>::obtenerNombre() {
    return this->nombre;
}

template <class T>
Vertice2<T> :: ~Vertice2() {

}