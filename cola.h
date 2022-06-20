#ifndef COLA_H
#define COLA_H
#include "nodo.h"
#include "lista.h"

template <class T>
class Cola
{
    private:
        T* dato;
        Nodo<T>* primero; //Primer elemento de la cola.
        Nodo<T>* ultimo; //Ultimo elemento de la cola.

    public:
		//Constructor
		//PRE: -
		//POST: Inicia la cola.
		Cola();
		
		//Destructor.
		//PRE:
		//POST:
		~Cola();
		
		//PRE: Cola creada.
		//POST: Devuelve TRUE si la cola no es vacia.
		bool colaVacia();
	
		//PRE: Cola creada.
		//POST: Agrega dato puntero al final de la cola.
		void agregarCola(T* dato);
	
		//PRE: Cola creada y no vacia.
		//POST:	Devuelve el dato que es primero en la cola.
		T* obtenerDatoCola();

		//PRE: Cola creada y no vacia.
		//POST: Da de baja el dato primero.
		T* bajaCola();
};

template <class T>
Cola<T> :: Cola(){

	primero = 0;
	ultimo = 0;
}

template <class T>
Cola<T> :: ~Cola(){

	while(!(colaVacia())){
		bajaCola();
	}
}

template <class T>
bool Cola<T> :: colaVacia(){
	return (primero == 0);
}

template <class T>
T* Cola<T> :: obtenerDatoCola(){
	return primero->obtenerDato();

}
template <class T>
T* Cola<T> :: bajaCola(){

	if(primero == ultimo) {
        ultimo = 0;
    }

	Nodo<T>* pAux = primero;
	T* aux= (primero->obtenerDato());
	primero = pAux->obtenerSiguiente();

	delete pAux;
	return aux;
}


template <class T>

void Cola<T>::agregarCola(T *dato) {

    Nodo<T>* nuevo = new Nodo<T>(dato);

    if (primero)
        ultimo->cambiarSiguiente(nuevo);
    else
        primero = nuevo;

    ultimo = nuevo;
}

#endif
