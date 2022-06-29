#ifndef MENU_H
#define MENU_H
#include "lista.h"
#include "escritor.h"
#include "lectura.h"
#include "cuento.h"
#include "poema.h"
#include "historica.h"
#include "novela.h"
#include "cola.h"
#include "grafo2.h"
#include "listagrafo.h"
#include "vertice2.h"
#include "hashing.h"
#include <iostream>

using namespace std;

class Menu
{

    private:
        Lista<Escritor>* escritores;
        Lista<Lectura>* lecturas;
        Cola<Lectura>* colaLectura;
        Hashing<Escritor>* escritorHashing;
        int opcion;

    public:
		Menu(Lista<Escritor>* escritores,Lista<Lectura>* lecturas,Cola<Lectura>* colaLectura,Hashing<Escritor>* escritorHashing);

        //PRE: -
        //POS: Imprime en pantalla el menu de opciones
		void mostrarMenu();

        //PRE: La lista no puede estar vacia
        //POS: Imprime la lista de escritores
		void listaEscritores();

        //PRE: La lista no puede estar vacia
        //POS: Elimina una lectura al azar de la lista
		void borrarLectura ();

        //PRE: -
        //POS: Agrega un nuevo escritor a la lista de escritores
		void agregarEscritores();

        //PRE: -
        //POS: Agrega una nueva lectura a la lista de lecturas
		void agregarLectura();

        //PRE: La lista no puede estar vacia
        //POS: Devuelve una lectura al azar
		void sortearLectura();

        //PRE: La lista no puede estar vacia
        //POS: Imprime la lista de lectura
		void listaLectura();

        //PRE: La lista no puede estar vacia
        //POS: Imprime las lecturas que se encuentran entre dos años determinados
		void listarLecturaAnio();

        //PRE: La lista no puede estar vacia
        //POS: Devuelve las lecturas de un escritor determinado
		void listarLecturaEscritor();

        //PRE: La lista no puede estar vacia
        //POS: Cambia la fecha de fallecimiento de un escritor en la lista
		void cambiarFallecimiento();

        //PRE: La lista no puede estar vacia
        //POS: Muestra las novelas de un genero determinado
		void listarNovelaGenero();

        //PRE: La cola no puede estar vacia
        //POS: Musta cola de lectura
		void mostrarCola();
		
		void mostrarHashing();
		
		void armarGrafo();

};

#endif
