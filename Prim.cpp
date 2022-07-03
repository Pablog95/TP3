#include "Prim.h"

Prim :: Prim (Lista<Vertice> * vertices, int ** matriz_de_adyacencia) {
    this-> matriz_de_adyacencia = matriz_de_adyacencia;
    this-> vertices = vertices;
    cant_vertices = vertices->obtener_cantidad();
}



