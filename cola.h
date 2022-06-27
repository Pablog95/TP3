#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "menu.h"

template < typename Dato >
class Cola {
    // Atributos
private:
    
    Nodo<Dato>* primero;
    Nodo<Dato>* ultimo;
    
    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye una Cola vacia
    */
    Cola();

    /*
    Alta
    PRE: e es un Dato valido
    POS: agrega el elemento al final de la Cola
    */
    void alta(Dato e);

    /*
    Baja
    PRE: la Cola no puede estar vacia
    POS: quita el elemento del principio de la Cola
    */
    void baja();

    /*
    Consulta
    PRE: la Cola no puede estar vacia
    POS: devuelve el elemento del principio de la Cola (pero no modifica)
    */
    Dato consulta();

    /*
    Vacia
    PRE: -
    POS: devuelve true si la Cola esta vacia, false de lo contrario
    */
    bool vacia();

    // Destructor
    ~Cola(){};
    
    /*
    desenganchar_nodo
    PRE: la Cola no puede estar vacia
    POS: Saca el elemento del principio de la Cola
    */
    void desenganchar_nodo();

};

template < typename Dato>
Cola<Dato>::Cola() {
    primero = 0;
    ultimo = 0;
}

// alta
template < typename Dato>
void Cola<Dato>::alta(Dato e) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(e);
    if (primero)
        ultimo->cambiar_siguiente(nuevo);
    else
        primero = nuevo;
    ultimo = nuevo;

}

// baja
template < typename Dato>
void Cola<Dato>::baja() {
    Nodo<Dato>* aux = primero;
    primero = primero->obtener_siguiente();
    if (! primero)
        ultimo = 0;
    delete aux;
    
}

// consulta
template < typename Dato>
Dato Cola<Dato>::consulta() {
    return primero->obtener_dato();
}

// vacia
template < typename Dato>
bool Cola<Dato>::vacia() {
    return (ultimo == 0);
}

template <typename Dato>
void Cola<Dato>::desenganchar_nodo(){
    primero = primero->obtener_siguiente();
    if (! primero)
        ultimo = 0;
}

#endif // COLA_H_INCLUDED