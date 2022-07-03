#ifndef TP3_PRIM_H
#define TP3_PRIM_H
#include "Grafo.h"

class Prim {

private :

    int ** matriz_de_adyacencia;
    Lista<Vertice> * vertices;
    int cant_vertices;

public:

    Prim(Lista<Vertice> * vertices, int ** matriz_de_adyacencia);

    virtual void funcion_1() = 0;

    virtual ~Prim() {};

};


#endif //TP3_PRIM_H
