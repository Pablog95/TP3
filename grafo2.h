#ifndef TP_3_GRAFO2_H
#define TP_3_GRAFO2_H
#include <iostream>
#include "listagrafo.h"
#include "vertice2.h"
#include "lectura.h"

const char* vector_tipos[4] = {"P","C","N","H"};

using namespace std;


template <class Dato>
class Grafo2 {

private:
    Dato* matrizAdyacencia;
    ListaGrafo<Dato>* vertices;

    void agrandarMatrizAdyacencia();
    void copiarMatrizAdyacencia(int **nuevaAdyacente);
    void agregarNuevoVertice(int **nuevaAdyacente);
    void liberarMatrizAdyacencia();

public:
    Grafo2();
    void agregarVertice(Dato* verticeNuevo);
    void agregarArista(Dato* origen, Dato* destino, int peso);
    int devolver_peso(int i, int j);
    int posiciones_matriz_peso(char* dato);
    void mostrarGrafo();

};


template <class Dato>
Grafo2<Dato> ::Grafo2() {
    matrizAdyacencia = nullptr;
    vertices = new ListaGrafo<Dato>();
}


template <class Dato>
void Grafo2<Dato> :: agrandarMatrizAdyacencia(){
    int ** auxMatrix;
    int nuevaCantidadVertice = vertices->obtenerCantidadElementos() + 1;

    auxMatrix = new int*[nuevaCantidadVertice];
    for(int i = 0; i < nuevaCantidadVertice; i++){
        auxMatrix[i] = new int[nuevaCantidadVertice];
    }
    copiarMatrizAdyacencia(auxMatrix);
    agregarNuevoVertice(auxMatrix);
    liberarMatrizAdyacencia();
    matrizAdyacencia = auxMatrix;
}


template <class Dato>
void Grafo2<Dato> :: copiarMatrizAdyacencia(int **nuevaAdyacente){
    for(int i = 0; i<vertices->obtenerCantidadElementos(); i++){
        for (int j = 0; j < vertices->obtenerCantidadElementos(); j++)
            nuevaAdyacente[i][j] = matrizAdyacencia[i][j];
    }
}


template <class Dato>
void Grafo2<Dato> ::agregarNuevoVertice(int **nuevaAdyacente){
    for(int i = 0; i<vertices->obtenerCantidadElementos(); i++){
        nuevaAdyacente[vertices->obtenerCantidadElementos()][i] = 99999999;
        nuevaAdyacente[i][vertices->obtenerCantidadElementos()] = 99999999;
    }
    nuevaAdyacente[vertices->obtenerCantidadElementos()][vertices->obtenerCantidadElementos()] = 0;
}


template <class Dato>
void Grafo2<Dato> :: liberarMatrizAdyacencia(){
    for(int i = 0; i < vertices->obtenerCantidadElementos(); i++){
        delete[] matrizAdyacencia[i];
    }
    delete[] matrizAdyacencia;
}


template <class Dato>
void Grafo2<Dato> :: agregarVertice(Dato* verticeNuevo){
    agrandarMatrizAdyacencia();
    vertices->agregarElementos(verticeNuevo);
}


template <class Dato>
void Grafo2<Dato> :: agregarArista(Dato* origen, Dato* destino, int peso){
    int posicionOrigen = vertices->obtenerPosicion(origen);
    int posicionDestino = vertices->obtenerPosicion(destino);

    if(posicionOrigen == -1){
        cout << "El vertice " << origen << " no existe." << endl;
    }
    if(posicionDestino == -1){
        cout << "El vertice " << destino << " no existe." << endl;
    }

    if(!(posicionDestino == -1 || posicionOrigen == -1))
    {
        matrizAdyacencia[posicionOrigen][posicionDestino] = peso;
    }

}

template <class Dato>
int Grafo2<Dato> :: devolver_peso(int i, int j){

    return matriz_pesos[i][j];
}

template <class Dato>
int Grafo2<Dato> :: posiciones_matriz_peso(char* dato){

    for (int i = 0; i < 4; i++){
        if (vector_tipos[i] == dato){
            return i;
        }
    }
}


template <class Dato>
void Grafo2<Dato> :: mostrarGrafo(){
    return;
}


#endif //TP_3_GRAFO2_H
