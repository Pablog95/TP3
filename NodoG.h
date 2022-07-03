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
    NodoG<Tipo>* anterior;

/*MÉTODOS*/
public:
    NodoG(Tipo* nombre);

    //post: devuelve el nodo siguiente.
    NodoG<Tipo>* obtenerSiguiente();

    //post: devuelve el nombre del nodo
    Tipo* obtener_dato();

    //post: le asigna como siguiente el nodo recibido
    void asignarSiguiente(NodoG<Tipo>* siguiente);

    void cambiar_siguiente(NodoG* n);

    void cambiar_anterior(NodoG* b);

    void borrar();

    ~NodoG();
};

template <class Tipo>
NodoG<Tipo> ::NodoG(Tipo* dato) {
    elemento = dato;//new T(nombre);
    siguiente = nullptr;
    anterior = nullptr;
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

template < class Tipo >
void NodoG<Tipo>::cambiar_siguiente(NodoG* n) {
    siguiente = n;
}

template < class Tipo >
void NodoG<Tipo>::cambiar_anterior(NodoG* b){
    anterior = b;
}

template < class Tipo >
void NodoG<Tipo>::borrar(){
    elemento->borrar();
}

template<typename Tipo>
NodoG<Tipo>::~NodoG() {
    delete elemento;
}


#endif //NODO_GRAFO_H
