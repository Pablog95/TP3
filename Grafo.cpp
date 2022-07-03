#include "Grafo.h"

Grafo::Grafo() {
    matriz_de_adyacencia = nullptr;
    vertices = new ListaG<Lectura>();
    //algoritmoCaminoMinimo = nullptr;
}

int Grafo :: obtener_vertices_totales(){
    return vertices_totales;
}

int ** Grafo :: obtener_matriz_adyacencia(){
    return matriz_de_adyacencia;
}

void Grafo::agregarVertice(Lectura* nuevoVertice) {

    agrandarMatrizDeAdyacencia();
    vertices -> agregar(nuevoVertice);
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

string Grafo :: obtener_tipo_lectura (int i){
    if ((vertices ->obtener_elemento(i))->obtener_tipo() == N){

        //CAMBIAR A GENERO !!!!!!!!!!!!!!!!!!!!!!!!!!!
        if((vertices->obtener_elemento(i))->obtener_tipo() == "HISTORICA"){
            return "H";
        }
    }
    return ((vertices ->obtener_elemento(i))->obtener_tipo());
}

string Grafo :: obtener_titulo (int i){
    return ((vertices ->obtener_elemento(i))->obtener_titulo());
}

void Grafo::completar_matriz_adyacencia() {
    
    string vertice_actual = "";
    string vertice_aux = "";

    vertices_totales = vertices ->obtenerCantidadDeElementos();

    for(int i = 0; i < vertices_totales; i++) {
        vertice_actual = obtener_tipo_lectura(i);

        for (int j = 0; j < vertices_totales; j++){
            vertice_aux = obtener_tipo_lectura (j);
            agregarCamino(vertice_actual, vertice_aux, i, j);
        }
    }
}

void Grafo::agregarCamino(string origen, string destino, int i, int j) {
    int posicionOrigen = posiciones_matriz_peso(origen);
    int posicionDestino = posiciones_matriz_peso(destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    if(!(posicionDestino == POSICION_NO_ENCONTRADA || posicionOrigen == POSICION_NO_ENCONTRADA)) {
        matriz_de_adyacencia[i][j] = devolver_peso(posicionOrigen, posicionDestino);

    }
}

void Grafo::achicarMatrizDeAdyacencia(){
    int** matrizAuxiliar;

    int nuevaCantidadDeVertices = vertices->obtenerCantidadDeElementos();

    matrizAuxiliar = new int*[nuevaCantidadDeVertices];
    for(int i = 0; i < nuevaCantidadDeVertices; i++){
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiarMatrizAdyacente(matrizAuxiliar);
    inicializarMatrizAchicada(matrizAuxiliar);
    liberarMatrizAdyacencia();
    matriz_de_adyacencia = matrizAuxiliar;
}

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
    matriz_de_adyacencia = matrizAuxiliar;
}

void Grafo::copiarMatrizAdyacente(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vertices -> obtenerCantidadDeElementos(); j++){
            nuevaAdyacente[i][j] = matriz_de_adyacencia[i][j];
        }
    }
}

void Grafo::inicializarMatrizAchicada(int **nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vertices -> obtenerCantidadDeElementos(); j++){

            if(i == j)
                nuevaAdyacente[i][j] = 0;
            else
                nuevaAdyacente[i][j] = INFINITO;
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
        delete[] matriz_de_adyacencia[i];
    }
    delete[] matriz_de_adyacencia;
}

Grafo::~Grafo() {
    liberarMatrizAdyacencia();
    matriz_de_adyacencia = nullptr;
    delete vertices;
    //delete algoritmoCaminoMinimo;
}

void Grafo::mostrarVertices() {
    cout << "Lista de vértices: [";
    cout << "La cantidad de vertices es : " << vertices ->obtenerCantidadDeElementos() << "  -  ";
    for(int i = 0; i < (vertices -> obtenerCantidadDeElementos()); i++){
        cout <<  (vertices -> obtener_elemento(i))->obtener_tipo();
        if(i  != vertices -> obtenerCantidadDeElementos()){
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
                if(matriz_de_adyacencia[i][j/2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matriz_de_adyacencia[i][j/2];
                }
            } else{
                cout << "     |     ";
            }
        }
    }
    cout << endl;
}

void Grafo :: tiempo_lectura_minimo() {

    int vertices_seleccionados[vertices_totales];
    memset(vertices_seleccionados, false, sizeof(vertices_seleccionados));

    vertices_seleccionados[0] = true;

    int minimo = 0;
    int fil = 0;
    int col = 0;

    cout << "Camino" << " : " << "Peso" << endl;
    while (minimo < vertices_totales - 1) {

        int min = INFINITO;

        for (int i = 0; i < vertices_totales; i++) {
            if (vertices_seleccionados[i]) {
                for (int j = 0; j < vertices_totales; j++) {
                    if (!vertices_seleccionados[j] &&
                        matriz_de_adyacencia[i][j]) {  // not in vertices_seleccionados and there is an edge
                        if (min > matriz_de_adyacencia[i][j]) {
                            min = matriz_de_adyacencia[i][j];
                            fil = i;
                            col = j;
                        }
                    }
                }
            }
        }
        cout << fil << " - " << col << " :  " << matriz_de_adyacencia[fil][col] << endl;
        vertices_seleccionados[col] = true;
        minimo++;
        tiempo_total = tiempo_total + matriz_de_adyacencia[fil][col];
    }
    cout << endl << "El tiempo total que tardará Sid en leer será (en minutos) : " << tiempo_total << endl << endl;
    tiempo_total = 0;
}

void Grafo ::alta(Lectura* lectura){
    agrandarMatrizDeAdyacencia();
    agregarVertice(lectura);
    completar_matriz_adyacencia();
}

void Grafo ::baja(string titulo) {

    int i = 0;
    bool encontrado = false;

    while(!(vertices->vacia()) && !encontrado && i < vertices_totales){
        if (vertices->obtener_elemento(i)->obtener_titulo() == titulo){
            encontrado = true;
        }
        else
            i++;
    }

    vertices -> baja(i + 1);
    achicarMatrizDeAdyacencia();
    completar_matriz_adyacencia();
}

bool Grafo :: grafo_vacio(){
    return(vertices->vacia());
}







