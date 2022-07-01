#ifndef NODO_GRAFO_H
#define NODO_GRAFO_H
#include <string>

using namespace std;

template < typename Tipo >
class NodoG {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    NodoG<Tipo>* siguiente;

/*MÉTODOS*/
public:
    NodoG(Tipo* nombre);

    //post: devuelve el nodo siguiente.
    NodoG<Tipo>* obtenerSiguiente();

    //post: devuelve el nombre del nodo
    Tipo* obtener_dato();

    //post: le asigna como siguiente el nodo recibido
    void asignarSiguiente(NodoG<Tipo>* siguiente);

    ~NodoG();
};

template <class Tipo>
NodoG<Tipo> ::NodoG(Tipo* dato) {
    elemento = dato;//new T(nombre);
    siguiente = nullptr;
}

template<typename Tipo>
NodoG<Tipo> *NodoG<Tipo>::obtenerSiguiente() {
    return siguiente;
}

template<typename Tipo>
Tipo* NodoG<Tipo>::obtener_dato() {
    return elemento;
}

template<typename Tipo>
void NodoG<Tipo>::asignarSiguiente(NodoG<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
NodoG<Tipo>::~NodoG() {
    delete elemento;
}


#endif //NODO_GRAFO_H
