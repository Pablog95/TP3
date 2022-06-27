#ifndef NODO_H
#define NODO_H

#include "funciones.h"

template < typename Dato >

class Nodo {
    // Atributos
private:
    Dato dato;
    Nodo* siguiente;
    Nodo* anterior;
    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye un Nodo con d como dato anterior en nullptr
    */
    Nodo(Dato d);
    
    /*
    Destructor
    PRE: - 
    POS: -
    */
    ~Nodo(){};
    
    /*    
    PRE: Nodo no puede ser NULL
    POS: llama al metodo borrar del tipo de dato que este guardando
    */    
    void borrar();
    
    /*    
    PRE: -
    POS: el puntero al siguiente ahora apuntara al nodo n
    */
    void cambiar_siguiente(Nodo* n);
    
    /*    
    PRE: -
    POS: el puntero al anterior ahora apuntara al nodo b
    */
    void cambiar_anterior(Nodo* b);
    
    /*    
    PRE: Nodo no puede ser NULL
    POS: devuelve el dato que esta almacenado
    */
    Dato obtener_dato();

    /*    
    PRE: Nodo no puede ser NULL
    POS: devuelve un puntero al Nodo siguiente
    */
    Nodo* obtener_siguiente();

    /*    
    PRE: Nodo no puede ser NULL
    POS: devuelve un puntero al Nodo siguiente
    */
    Nodo* obtener_anterior();    
           
};


template < class Dato >
Nodo<Dato>::Nodo(Dato d) {
    dato = d;
    siguiente = 0;
    anterior = 0;
}

template < class Dato >
void Nodo<Dato>::borrar(){
    dato->borrar();
}


template < class Dato >
void Nodo<Dato>::cambiar_siguiente(Nodo* n) {
    siguiente = n;
}

template < class Dato >
void Nodo<Dato>::cambiar_anterior(Nodo* b){
    anterior = b;
}


template < class Dato >
Dato Nodo<Dato>::obtener_dato() {
    return dato;
}

template < class Dato >
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){
    return siguiente;
}


template < class Dato >
Nodo<Dato>* Nodo<Dato>::obtener_anterior(){
    return anterior;
}


#endif // NODO_H
