#include "vertice2.h"

template <class Dato>
Vertice2<Dato> ::Vertice2(Dato* nombre) {
    this->nombre = nombre;
}

template <class Dato>
Dato* Vertice2<Dato>::obtenerNombre() {
    return this->nombre;
}

template <class Dato>
Vertice2<Dato> :: ~Vertice2() {

}