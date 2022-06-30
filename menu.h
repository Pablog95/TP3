#ifndef MENU_H
#define MENU_H

#include "lector2.h"
#include "parser.h"
#include "hashing.h"

class Menu {

private :

    Lista <Escritor*>* escritores;
    Lista <Lectura*>* lecturas;
    Hashing<Escritor*>* escritor_hashing;

    string tipo_lectura = "";
    string titulo = "";
    string caracteristica = "";
    string tema = "";
    string espacio = "";
    string nombre_escritor = "";
    string nacionalidad = "";

    string referencia_al_autor;
    string minutos = "";
    string anio = "";
    string anio_nacimiento = "";
    string anio_fallecimiento = "";
    string anio1 = "";
    string anio2 = "";
    string n_lectura_quitar = "";
    int numero;
    bool salir = false;

public :
    /*
    constructor
    PRE: -
    POS: crea un objeto de tipo parser
    */

    Menu (Lista <Lectura*>*, Lista <Escritor*>*, Hashing<Escritor*>* escritor_hashing);

    /*
    Pre : los atributos y parametros usados son correctos

    Post : devuelve una Lectura* segun el tipo de lectura
    */
    Lectura* procesador_entradaL(Escritor* escritor);

    /*
    Pre : -

    Post : agrega la nueva lectura solicitada por el usuario a la lista de lecturas
    */
    void nueva_lectura();

    /*
    Pre : el usuario debe ingresar el numero de una lectura existente y correcta

    Post : Quita de la lista Lecturas la lectura indicada por le usuario
    */
    void quitar_lectura();

    /*
    Pre : el usuario debe ingresar los datos correctos

    Post : agrega un nuevo escritor indicado por el usuario a la lista de escritores
    */
    void agregar_escritor();

    /*
    Pre : el usuario debe ingresar los datos correctos

    Post : cambia año de fallecimiento de un escritor indicado por el usuario
    */
    void cambiar_dato_escritor();

    /*
    Pre : -

    Post : imprime por pantalla todos los escritores de la lista escritores
    */
    void listar_escritores();

    /*
    Pre : los parametros pasados deben ser correctos

    Post : devuelve un numero aleatorio entre los numeros pasados por parametro
    */
    int random (int min, int max);

    /*
    Pre : -

    Post : imprime por pantalla una lectura aleatoria de la lista
    */
    void lectura_random();

    /*
    Pre : -

    Post : imprime por pantalla todas las lecturas de la lista lecturas
    */
    void listar_lecturas();

    /*
    Pre : el usuario debe ingresar los datos correctos

    Post : imprime por pantalla todas las lecturas escritas entre los años indicados por el usuario
    */
    void listar_lecturas_x_anios();

    /*
    Pre : el usuario debe ingresar los datos correctos

    Post : imprime por pantalla todas las lecturas escritas por un mismo escritor indicado por el usuario
    */
    void listar_lecturas_x_escritor();

    /*
    Pre : el usuario debe ingresar los datos correctos

    Post : imprime por pantalla todas las lecturas de un genero indicado por el usuario
    */
    void listar_novelas_x_genero();

    /*
    Pre : -

    Post : devuelve una cola ordenada de menor (primero) a mayor (ultimo) por tiempo de lectura
    */
    void cola_ordenada();


    void mostrar_hashing();

    /*
    Pre : el numero ingresado es correcto

    Post : lleva a cabo las opciones del menu según el número indicado por el usuario y lo repite hasta que le mismo desee salir
    */
    void implementacion_menu();

        /*
    Pre : -
    Post : devuelve la lista de escritores
    */
    Lista<Escritor*>* obtener_Lescritores();

    /*
    Pre : -
    Post : devuelve la lista de lecturas
    */
    Lista<Lectura*>* obtener_Llecturas();

    /*
    destructor
    PRE: -
    POS: -
    */
    ~Menu();

};
#endif //MENU_H