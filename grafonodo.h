#ifndef TP_3_GRAFONODO_H
#define TP_3_GRAFONODO_H
#include <iostream>
using namespace std;

template <class T>
class GrafoNodo {
private:
    T* elemento;
    GrafoNodo<T>* siguiente;

public:

    GrafoNodo(string nombre);
    GrafoNodo<T>* obtenerSiguiente();
    string obtenerNombre();
    void cambiarSiguiente(GrafoNodo<T> * siguiente);
    ~GrafoNodo();


};

template <class T>
GrafoNodo<T> ::GrafoNodo(string nombre) {
    elemento = new T(nombre);
    siguiente = nullptr;
}

template <class T>
GrafoNodo<T>* GrafoNodo<T> ::obtenerSiguiente() {
    return siguiente;
}

template <class T>
string GrafoNodo<T> ::obtenerNombre() {
    return elemento->obtenerNombre();
}

template <class T>
void GrafoNodo<T> ::cambiarSiguiente(GrafoNodo<T> *siguiente) {
    this->siguiente = siguiente;
}

template <class T>
GrafoNodo<T> :: ~GrafoNodo() {
    delete elemento;
}

#endif //TP_3_GRAFONODO_H
