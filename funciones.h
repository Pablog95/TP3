#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <iostream>
#include <fstream> 

#include "lectura.h"
#include "escritor.h"
#include "lectura.h"
#include "cuento.h"
#include "novela.h"
#include "poema.h"
#include "historica.h"
#include "lista.h"
#include "nodo.h"
#include "constantes.h"
 

/*
Pre : - 
Post : recibe un string y lo convierte devolviendo un int
*/
int  string_a_int( string string);

/*
Pre : los valores pasados por parametro son correctos
Post : devuelve un tipo de genero_t
*/
genero_t string_a_genero_t(string genero);

/*
PRE:  los valores pasados por parametros son correctos
      la cadena referencia_al_autor debe contener una posicion de la lista de escritores
      1 <= pos <= escritores.obtener_cantidad() o la palabra ANONIMO 
POS:  Devuelve la posicion, en la lista de escritores, del escritor. En caso de ser anonimo
      retorna -1
*/
int  autor_anonimo( string referencia_al_autor);

#endif