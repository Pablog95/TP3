#ifndef GRAFO_H
#define GRAFO_H


#include "ListaG.h"
#include "VerticeG.h"
#include "Constantes.h"


using namespace std;

class Grafo {
/*ATRIBUTOS*/
private:
    int ** matriz_de_adyacencia;
    ListaG<Lectura> * vertices;
    int vertices_totales;
    //CaminoMinimo * algoritmoCaminoMinimo;
    int tiempo_total = 0;

/*MÉTODOS*/

    //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    //void caminoMinimo(int origen, int destino);

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandarMatrizDeAdyacencia();

    void achicarMatrizDeAdyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiarMatrizAdyacente(int** nuevaAdyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializarNuevoVertice(int** nuevaAdyacente);

    void inicializarMatrizAchicada(int **nuevaAdyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberarMatrizAdyacencia();

    //post: imprime por pantalla los vertices del grafo
    void mostrarVertices();

    //post: imprime por pantalla la matriz de adyacencia
    void mostrarMatrizAdyacencia();

public:

    Grafo();

    int obtener_vertices_totales();

    int ** obtener_matriz_adyacencia();

    void agregarVertice(Lectura* nuevoVertice);

    //post: imprime por pantalla el grafo
    void mostrarGrafo();

    int devolver_peso(int entrada, int destino);

    int posiciones_matriz_peso(string dato);

    string obtener_tipo_lectura (int i);

    string obtener_titulo (int i);

    void completar_matriz_adyacencia();

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregarCamino(string origen, string destino, int i, int j);

    void tiempo_lectura_minimo();

    void alta(Lectura* lectura);

    void baja(string titulo);

    bool grafo_vacio();

    ~Grafo();
};

#endif //GRAFO_H
