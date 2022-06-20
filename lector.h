#ifndef LECTOR_H
#define LECTOR_H

#include <string>
#include <iostream>
#include <fstream> 

#include <stdio.h>

#include "lectura.h"
#include "escritor.h"
#include "historica.h"
#include "novela.h"
#include "poema.h"
#include "cuento.h"
#include "lista.h"
#include "parser.h"
#include "funciones.h"

using namespace std;

class Lector{

private :

    ifstream archivo_lecturas;
    ifstream archivo_escritores;

    Lista <Escritor*>* lista_escritores;
    Lista <Lectura*>* lista_lecturas;
    
    string tipo_lectura;
    string titulo;
    string minutos;
    string anio;
    string caracteristica;
    string referencia_al_autor;
    string espacio;
    string tema;
    string nombre_escritor;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento;
    string n_escritor;

public :

    /*
    Constructor
    Pre : -
    Post : Crea la clase Lector y pide memoria para los punteros a las lecturas
    */
    Lector();

    /*
    Pre : los datos tomados del archivo son correctos
    Post : revisa si se conocen o no los años de nacimiento y fallecimiento
    */
    void completar_informacion_escritura();

    /*
    Pre : los datos tomados del archivo son correctos
    Post : completa una lista de escritores basada en un archivo
    */
    void lectura_archivo_escritores( );

        /*
    Pre : los atributos y parametros recibidos son correctos
    Post : devuelve una Lectura* según el tipo de lectura 
    */
    Lectura* procesador_entrada_lecturas(Escritor* escritor);

    /*
    Pre : los datos tomados del archivo son correctos
    Post : completa la lista de lecturas ordeanda por años basada en un archivo
    */
    void leer_lectura();

    /*
    Pre : -
    Post : devuelve un puntero a la lista de escritores
    */
    Lista<Escritor*>* obtener_Lescritores();

    /*
    Pre : -
    Post : devuelve un puntero a la lista de lecturas
    */
    Lista<Lectura*>* obtener_Llecturas();


    /*
    Pre : - 
    Post : Cierra los archivos y elimina toda memoria dinamica asociada a Lector
    */
   ~Lector();
};

#endif