#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

template < typename Dato >

class Lista {
    // Atributos
private:
    Nodo<Dato>* primero;
    int cantidad;
    Nodo<Dato>* ultimo;
    Nodo<Dato>* obtener_nodo(int pos);
    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye una Lista vacia
    */
    Lista();

    /*
    Alta
    PRE: e es un Dato valido
    POS: agrega el elemento en la ultima posicion de la lista
    */
    void alta_ultimo(Dato dato);

    /*
    PRE: e es un dato valido
    POS: agrega el elemento ordenadamente segun el metodo comparar que tenga el tipo Dato
    */
    void insercion_ordenada(Dato e);

    //void insercion_ordenada2(Dato e);

    
    /*
    Baja
    PRE: 1 <= pos <= obtener_cantidad(), la lista no puede estar vacia
    POS: Se da de baja el elemento que esta en la posicion pos, ademas se llama al metodo borrar()
         que tiene cada nodo de tipo Dato
    */
    void baja(int pos);

    /*
    Consulta
    PRE: 1 <= pos <= obtener_cantidad()
    POS: devuelve el elemento que esta en pos, se empieza por 1
    */
    Dato consulta(int pos);


    /*
    Vacia
    PRE: -
    POS: devuelve true si la Lista esta vacia, false de lo contrario
    */
    bool vacia();

    /*
    PRE: - 
    POS: imprime todos los elementos de la lista segun el metodo mostrar() que tiene cada tipo de dato
    */
    void listar();

    /*
    PRE: anio1 <= anio2 , ademas los años deberan ser enteros positivos.
    POS: imprime todos los elementos de la lista de tipo Lectura, escritas entre anio1 y anio2 
    */
    void listar(unsigned int anio1, unsigned int anio2);

    /*
    PRE: -
    POS: lista todas las lecturas escritas por escritor
    */
    void listar(string escritor);

    /*
    PRE: genero debe ser un genero valido
    POS: lista todas las lecturas pertenecientes al genero 
    */    
    void listar(genero_t genero);

    /*
    PRE: - 
    POS: devuelve la cantidad de elementos de la lista
    */
    int obtener_cantidad();
    
    /*    
    PRE: -
    POS: destruye la lista eliminando toda memoria dinamica asociada a ella
    */
    void destruir();

    // Destructor
    ~Lista(){};
    
};

template < class Dato >
Lista<Dato>::Lista() {
    primero = 0;
    ultimo = 0;
    cantidad = 0;
}

template < class Dato>
void Lista<Dato>::destruir(){
    while(!vacia())
        baja(1);    
}

template < class Dato >
bool Lista<Dato>::vacia() {
    return (cantidad == 0);
}

template < class Dato >
int Lista<Dato>::obtener_cantidad() {
    return cantidad;
}

template < class Dato >
void Lista<Dato>::listar(){
    
    int cantidad = obtener_cantidad();
    for(int i = 1; i <= cantidad; i++){

        cout << i << ")" << endl;
        consulta(i)->mostrar();
        
        cout << endl;
    }
}

template < class Dato >
void Lista<Dato>::listar(unsigned int anio1, unsigned int anio2){
    Nodo<Dato>* iterador = primero;
    Dato actual = iterador->obtener_dato();
        
    while(iterador != 0 && (actual->obtener_anio()) < anio1){
        
        iterador = iterador->obtener_siguiente();
    
        if(iterador)
            actual = iterador->obtener_dato();
           
    }

    while(iterador != 0 && actual->obtener_anio() <= anio2){
        actual->mostrar();
        cout << endl;
        iterador = iterador->obtener_siguiente();

        if(iterador){
            actual = iterador->obtener_dato();
        }
    }

}

// Consulta
template < class Dato >
Dato Lista<Dato>::consulta(int pos) {
    Nodo<Dato>* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

template < class Dato >
void Lista<Dato>::alta_ultimo(Dato e) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(e);
    if (cantidad == 0) {
        primero = nuevo;
        ultimo = nuevo;
    }
   
    else {
              
       nuevo->cambiar_anterior(ultimo);
       ultimo->cambiar_siguiente(nuevo);
       ultimo = nuevo;
       
    }
    cantidad++;
}

template < class Dato >
void Lista<Dato> :: insercion_ordenada(Dato e){

    Nodo<Dato>* nuevo = new Nodo<Dato>(e);
    Nodo<Dato>* siguiente = primero;
    Nodo<Dato>* anterior = primero;
    Dato dato_nuevo = nuevo->obtener_dato();

    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
    }
    
    else if(siguiente->obtener_dato()->comparar(dato_nuevo) == 1 ){
        nuevo->cambiar_siguiente(primero);
        primero->cambiar_anterior(nuevo);
        primero = nuevo;
    }
    
    else {
        Dato dato_siguiente = siguiente->obtener_dato();        
        
        while(siguiente && dato_siguiente->comparar(dato_nuevo) != 1){
            anterior = siguiente;
            siguiente = siguiente->obtener_siguiente();
            
            if (siguiente != 0)
                dato_siguiente = siguiente->obtener_dato();            
        }
       
        nuevo->cambiar_siguiente(siguiente);        
        
        nuevo->cambiar_anterior(anterior);        
        
        anterior->cambiar_siguiente(nuevo);
        
        if (siguiente)
            siguiente->cambiar_anterior(nuevo);
        
    }
    cantidad++;
}

//No puede estar vacia
template < class Dato >
void Lista<Dato>::baja(int pos) {
    Nodo<Dato>* aux = primero;
    if (pos == 1) {
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<Dato>* anterior = obtener_nodo(pos - 1);
        aux = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(aux->obtener_siguiente());
    }
    cantidad--;
    
    //Chequear cuando funciones si hay que hacer una funcion de borrado
    aux->borrar();
    delete aux;
}

// obtener_nodo
template < class Dato >
Nodo<Dato>* Lista<Dato>::obtener_nodo(int pos) {
    Nodo<Dato>* aux = primero;
    int contador = 1;
    
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    
    return aux;
}

template < class Dato >
void Lista<Dato>::listar(string escritor){
    Nodo<Dato>* iterador = primero;
    
    
    while(iterador){
        string autor = iterador->obtener_dato()->obtener_autor()->obtener_nombres();
        if (autor.compare(escritor) == 0){
            iterador->obtener_dato()->mostrar();
            cout << endl;
        }
        iterador = iterador->obtener_siguiente();
    }
}

template < class Dato >
void Lista<Dato>::listar(genero_t genero){
    Nodo<Dato>* iterador = primero;
    string gen = genero_t_cadena[genero];

    while(iterador){
        iterador->obtener_dato()->mostrar(gen);
        iterador = iterador->obtener_siguiente();
    }
}


#endif //LISTA_H_INCLUDED
