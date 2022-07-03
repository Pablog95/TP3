#include "VerticeG.h"

Vertice::Vertice(Lectura* nombre) {
    this -> nombre = nombre;
}

Lectura* Vertice::obtenerNombre() {
    return nombre;
}

Vertice::~Vertice() {

}

