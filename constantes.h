#ifndef H_P_CONSTANTES_H
#define H_P_CONSTANTES_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ANONIMO = -1;
const int CANTIDAD_GENEROS = 7;
const char EOL = '\0';

const int TAMANIO = 29; //Datoamanio de la lista, dato sacado de calcular t = datosAIngresar / 0.8. y buscando el primer numero primo superior mas cercano.


enum genero_t {DRAMA, COMEDIA, FICCION, SUSPENSO, TERROR, ROMANTICA, HISTORICA};

extern const char* genero_t_cadena[];

const  string ANONIMO_ = "anonimo";
const  string NOVELA_ = "novela";
const  string CUENTO_ = "cuento";
const  string POEMA_ = "poema";
const  string HISTORICA_ = "historica";

const  char * const P = "P";
const  char * const C = "C";
const  char * const N = "N";
const  char * const H = "H";

const string vector_tipos [4] = {P, C, N, H};

const int matriz_pesos[4][4]{

    {1,0,10,15},
    {0,8,5,20},
    {10,5,30,60},
    {15,20,60,80}
};

#endif //H_P_CONSTANTES_H