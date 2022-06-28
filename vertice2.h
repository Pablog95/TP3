#ifndef TP_3_VERTICE2_H
#define TP_3_VERTICE2_H
#include <iostream>

using namespace std;


template <class Dato>
class Vertice2 {
private:
    Dato* nombre;

public:
    Vertice2(Dato* nombre);
    Dato* obtenerNombre();

    ~Vertice2();


};


#endif //TP_3_VERTICE2_H
