#ifndef VERTICE_GRAFO_H
#define VERTICE_GRAFO_H

#include <string>
#include "lectura.h"

using namespace std;

class Vertice {
/*ATRIBUTOS*/
private:
    Lectura* nombre;

/*MÉTODOS*/
public:
    Vertice(Lectura* nombre);

    //post: obtiene el nombre del vertice
    Lectura* obtenerNombre();

    ~Vertice();
};


#endif //VERTICE_GRAFO_H
