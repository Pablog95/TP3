#include "grafo.h"

Grafo::Grafo() {
    matrizDeAdyacencia = nullptr;
    vertices = new ListaG<Lectura>();
    //algoritmoCaminoMinimo = nullptr;
}

void Grafo::agregarVertice(Lectura* nuevoVertice) {

    agrandarMatrizDeAdyacencia();
    cout << "Agrande la matriz de adyacencia" << endl;
    vertices -> agregar(nuevoVertice);
    cout << "Agregue 1 vértice" << endl;
}

void Grafo::mostrarGrafo() {
    mostrarVertices();
    mostrarMatrizAdyacencia();
}

int Grafo:: devolver_peso(int entrada, int destino){
    return matriz_pesos[entrada][destino];
}

int Grafo:: posiciones_matriz_peso(string tipo){
    for (int i = 0; i < 4; i++){
        if (vector_tipos[i] == tipo)
            return i;
    }
    return -1;
}

void Grafo::completar_matriz_adyacencia() {
    
    //int i, j = 0;
    string vertice_actual = "";
    string vertice_aux = "";

    vertices_totales = vertices ->obtenerCantidadDeElementos();

    for(int i = 0; i <= vertices_totales; i++) {
        vertice_actual = (vertices ->obtener_elemento(i))->obtener_tipo();

        for (int j = 0; j <= vertices_totales; j++){
            vertice_aux = (vertices ->obtener_elemento(j))->obtener_tipo();
            agregarCamino(vertice_actual, vertice_aux);
        }
    }

    /*
    while(i < vertices_totales){

        vertice_actual = (vertices ->obtener_elemento(i))->obtener_tipo();
        i++;
        
        while (j < vertices_totales){
            vertice_aux = (vertices ->obtener_elemento(j))->obtener_tipo();
            agregarCamino(vertice_actual, vertice_aux);
            j++;
        }
        j = 0;  
    }
     */
}

void Grafo::agregarCamino(string origen, string destino) {
    int posicionOrigen = posiciones_matriz_peso(origen);
    int posicionDestino = posiciones_matriz_peso(destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    if(!(posicionDestino == POSICION_NO_ENCONTRADA || posicionOrigen == POSICION_NO_ENCONTRADA)) {
        matrizDeAdyacencia[posicionDestino][posicionOrigen] = devolver_peso(posicionOrigen, posicionDestino);
    }
}

/*
void Grafo::caminoMinimo(string origen, string destino) {
    int posicionOrigen = vertices ->obtenerPosicion(origen);
    int posicionDestino = vertices ->obtenerPosicion(destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    caminoMinimo(posicionOrigen, posicionDestino);
}
*/

void Grafo::agrandarMatrizDeAdyacencia() {
    int** matrizAuxiliar;
    int nuevaCantidadDeVertices = vertices->obtenerCantidadDeElementos() + 1;

    matrizAuxiliar = new int*[nuevaCantidadDeVertices];
    for(int i = 0; i < nuevaCantidadDeVertices; i++){
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiarMatrizAdyacente(matrizAuxiliar);
    inicializarNuevoVertice(matrizAuxiliar);
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = matrizAuxiliar;
}

void Grafo::copiarMatrizAdyacente(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vertices -> obtenerCantidadDeElementos(); j++){
            nuevaAdyacente[i][j] = matrizDeAdyacencia[i][j];
        }
    }
}

void Grafo::inicializarNuevoVertice(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        nuevaAdyacente[vertices -> obtenerCantidadDeElementos()][i] = INFINITO;
        nuevaAdyacente[i][vertices -> obtenerCantidadDeElementos()] = INFINITO;
    }
    nuevaAdyacente[vertices -> obtenerCantidadDeElementos()][vertices -> obtenerCantidadDeElementos()] = 0;
}

void Grafo::liberarMatrizAdyacencia() {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        delete[] matrizDeAdyacencia[i];
    }
    delete[] matrizDeAdyacencia;
}

Grafo::~Grafo() {
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = nullptr;
    delete vertices;
    //delete algoritmoCaminoMinimo;
}

void Grafo::mostrarVertices() {
    cout << "Lista de vértices: [";
    cout << "La cantidad de vertices es : " << vertices ->obtenerCantidadDeElementos() << endl;
    for(int i = 0; i < (vertices -> obtenerCantidadDeElementos()); i++){
        cout << "ENTRO AL FOR" << endl;
        cout << (vertices -> obtener_elemento(i + 1))->obtener_titulo() <<endl;
        if(i + 1 != vertices -> obtenerCantidadDeElementos()){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Grafo::mostrarMatrizAdyacencia() {
    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vertices -> obtenerCantidadDeElementos() * 2; j++) {
            if(j == vertices -> obtenerCantidadDeElementos() * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matrizDeAdyacencia[i][j/2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matrizDeAdyacencia[i][j/2];
                }
            } else{
                cout << "|";
            }
        }
    }
    cout << endl;
}

/*
 void Grafo::caminoMinimo(int origen, int destino) {
    algoritmoCaminoMinimo -> caminoMinimo(origen, destino);
}

void Grafo::usarFloyd() {
    delete algoritmoCaminoMinimo;
    algoritmoCaminoMinimo = new Floyd(vertices, matrizDeAdyacencia);
}

void Grafo::usarDijkstra() {
    delete algoritmoCaminoMinimo;
    algoritmoCaminoMinimo = new Dijkstra(vertices, matrizDeAdyacencia);
}
 */



