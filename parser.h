#ifndef PARSER_H
#define PARSER_H

#include "constantes.h"

void imprimir_menu();

void ingresar_numero(int *numero);

void menu_1(string * tipo_lectura, string * titulo, string * minutos, string * anio, string * caracteristica, string * tema, string * referencia_al_autor);

void menu_2(string * n_lectura_quitar);

void menu_3(string * referencia_al_autor, string * nombre_escritor, string * nacionalidad, string * anio_nacimiento, string * anio_fallecimiento);

void menu_4(string * referencia_al_autor, string * anio_fallecimiento);

void menu_8(string * anio1, string * anio2);

void menu_9(string * nombre_escritor);

void menu_10(string * caracteristica);


#endif //PARSER_H
