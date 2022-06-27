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

enum genero_t {DRAMA, COMEDIA, FICCION, SUSPENSO, TERROR, ROMANTICA, HISTORICA};

extern const char* genero_t_cadena[];



const std :: string ANONIMO_ = "anonimo";
const std :: string NOVELA_ = "novela";
const std :: string CUENTO_ = "cuento";
const std :: string POEMA_ = "poema";
const std :: string HISTORICA_ = "historica";

#endif //H_P_CONSTANTES_H