#ifndef LECTOR_H
#define LECTOR_H

#include "Historica.h"
#include "Poema.h"
#include "Cuento.h"
#include "Grafo.h"
#include "Hashing.h"

class Lector{

private :

    ifstream archivo_lecturas;
    ifstream archivo_escritores;

    Lista <Escritor*>* lista_escritores;
    Lista <Lectura*>* lista_lecturas;
    Hashing<Escritor>* escritor_hashing;
    
    string tipo_lectura = "";
    string titulo = "";
    string minutos = "";
    string anio = "";
    string caracteristica = "";
    string referencia_al_autor = "";
    string espacio = "";
    string tema = "";
    string nombre_escritor = "";
    string nacionalidad = "";
    string anio_nacimiento = "";
    string anio_fallecimiento = "";
    string n_escritor = "";

    Grafo* grafo;
    Hashing<Escritor*>* escritor_hashing;

public :

    /*
    Constructor
    Pre : -
    Post : Crea la clase Lector y pide memoria para los punteros a las lecturas
    */
    Lector(Grafo* grafo);

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
    PRE:  los valores pasados por parametros son correctos
      la cadena referencia_al_autor debe contener una posicion de la lista de escritores
      1 <= pos <= escritores.obtener_cantidad() o la palabra ANONIMO
    POS:  Devuelve la posicion, en la lista de escritores, del escritor. En caso de ser anonimo
      retorna -1
*/
    int  autor_anonimo( string referencia_al_autor);

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
    Post: Devuelve un puntero a la tabla hashing
    */
    Hashing<Escritor>* obtener_tabla();

    /*
    Pre : - 
    Post : Cierra los archivos y elimina toda memoria dinamica asociada a Lector
    */
   ~Lector();
};

#endif //LECTOR_H
