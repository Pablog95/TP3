#ifndef TP_3_GRAFONODO_H
#define TP_3_GRAFONODO_H
#include <iostream>
using namespace std;

template <class Dato>
class GrafoNodo {
private:
    Dato* elemento;
    GrafoNodo<Dato>* siguiente;

public:

    GrafoNodo(string nombre);
    GrafoNodo<Dato>* obtenerSiguiente();
    string obtenerNombre();
    void cambiarSiguiente(GrafoNodo<Dato> * siguiente);
    ~GrafoNodo();


};

template <class Dato>
GrafoNodo<Dato> ::GrafoNodo(string nombre) {
    elemento = new Dato(nombre);
    siguiente = nullptr;
}

template <class Dato>
GrafoNodo<Dato>* GrafoNodo<Dato> ::obtenerSiguiente() {
    return siguiente;
}

template <class Dato>
string GrafoNodo<Dato> ::obtenerNombre() {
    return elemento->obtenerNombre();
}

template <class Dato>
void GrafoNodo<Dato> ::cambiarSiguiente(GrafoNodo<Dato> *siguiente) {
    this->siguiente = siguiente;
}

template <class Dato>
GrafoNodo<Dato> :: ~GrafoNodo() {
    delete elemento;
}

#endif //TP_3_GRAFONODO_H
