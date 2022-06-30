#ifndef TP_3_HASHING_H
#define TP_3_HASHING_H

#include "lista.h"
#include "escritor.h"

#include <list>


template <class Dato>
class Hashing {

private:
    Dato* tabla_escritor[TAMANIO];
    bool dato_encontrado[TAMANIO];

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
    lista_escritores_tabla = new list <Escritor*>[TAMANIO];
}


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
}


template<class Dato>
int Hashing<Dato>::obtener_posicion_clave(int clave){
    return clave%TAMANIO;
}


template <class Dato>
void Hashing<Dato> :: mostrar_hashing(){
    for(int i = 0; i < TAMANIO; i++){
        cout << i << ")";
        if(dato_encontrado[i]){
            tabla_escritor[i]->mostrar_datos();
        }
        //tabla_escritor[i]->mostrar_datos();
        for (auto x: lista_escritores_tabla[i]){
            //tabla_escritor[i]->mostrar_datos();
            cout << endl;
            x->mostrar();
        }
        cout << endl;
    }
    //lista_escritores[i].mostrar_datos();
}

template<class Dato>
Hashing<Dato> :: ~Hashing(){
    for(int i = 0; i < TAMANIO; i++)
    {
        delete tabla_escritor[i];
    }
    delete lista_escritores_tabla;
}


#endif //TP_3_HASHING_H
