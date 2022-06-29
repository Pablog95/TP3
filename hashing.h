#ifndef TP_3_HASHING_H
#define TP_3_HASHING_H

#include "lista.h"
#include "escritor.h"

#include <list>

const int TAMANIO = 29; //Datoamanio de la lista, dato sacado de calcular t = datosAIngresar / 0.8. y buscando el primer numero primo superior mas cercano.

template <class Dato>
class Hashing {

private:
    Dato* tabla_escritor[TAMANIO];
    bool dato_encontrado[TAMANIO];
    Lista<Escritor*>* lista_escritores;
    list<Escritor*>* lista_escritores_tabla;

public:
    //CONSDatoRUCDatoOR
    Hashing();

    //DESDatoRUCDatoOR
    ~Hashing();
    void agregar_escritor(Dato* escritor, int clave);
    int obtener_posicion_clave(int clave);
    //Dato* mostrar_hashing(int posicion);
    void mostrar_hashing();

};


template <class Dato>


Hashing<Dato>::Hashing(){
    for (int i = 0; i < TAMANIO; i++)
    {
        tabla_escritor[i] = nullptr;
        dato_encontrado[i] = false;
    }
    this->lista_escritores = new Lista <Escritor>[TAMANIO];
    lista_escritores_tabla = new list <Escritor*>[TAMANIO];
}

/*
template<class Dato>
Hashing<Dato>::Hashing(){

	this->lista_escritores = new Lista<Escritor>[TAMANIO];
}*/

/*
template<class Dato>
void Hashing<Dato>::agregar_escritor(Dato* escritor, int clave){
	int posicion = obtener_posicion_clave(clave);
	lista_escritores[posicion].agregar_elemento(escritor,posicion);
	}
*/


template<class Dato>
void Hashing<Dato>::agregar_escritor(Dato* escritor, int clave){
    int posicion = obtener_posicion_clave(clave);

    if(tabla_escritor[posicion] == nullptr)
    {
        tabla_escritor[posicion] = escritor;
        dato_encontrado[posicion] = true;
    }else{
        lista_escritores_tabla[posicion].push_back(*escritor);

    }
    /*lista_escritores[posicion].agregar_elemento(escritor);
    dato_encontrado[posicion] = true;

    if(tabla_escritor[posicion] == nullptr)
    {
        tabla_escritor[posicion] = escritor;
        dato_encontrado[posicion] = true;
    }else{

        tabla_escritor[posicion] = lista_escritores->agregar_elemento(escritor);
    }*/
}


template<class Dato>
int Hashing<Dato>::obtener_posicion_clave(int clave){
    return clave%TAMANIO;
}
/*
template<class Dato>
Dato Hashing<Dato> :: mostrar_hashing(int posicion){
	return lista_escritores[posicion];
}*/
/*
template <class Dato>
Dato* Hashing<Dato> :: mostrar_hashing(int posicion){
	if (dato_encontrado[posicion] == true){
		return tabla_escritores[posicion];
	}else{
		cout << "No hay elementos" << endl;
	}

}*/

template <class Dato>
void Hashing<Dato> :: mostrar_hashing(){
    //if (dato_encontrado[posicion] == true){
    for(int i = 0; i<TAMANIO; i++){
        cout << i << endl;
        for (auto x: lista_escritores_tabla[i]){
            tabla_escritor[i] -> mostrar_datos();
            x->mostrar_datos();
        }
        cout << endl;
        //lista_escritores[i].mostrar_datos();
    }
    /*}else{
        cout << "No hay elementos" << endl;
    }*/

}

template<class Dato>
Hashing<Dato> :: ~Hashing(){
    for(int i = 0; i < TAMANIO; i++)
    {
        delete tabla_escritor[i];
    }

    delete lista_escritores;

}


#endif //TP_3_HASHING_H
