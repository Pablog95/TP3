#ifndef CUENTO_H
#define CUENTO_H

#include "Lectura.h"

class Cuento : public Lectura{
public:

    /*
    constructor con parametros
    PRE: minutos > 0, anio > 0
    POS: crea un cuento inicializada con sus atributos
    */
    Cuento(string tipo_lectura, string titulo_lectura, unsigned int minutos, unsigned int anio, Escritor* autor, string libro);
    
    /*
    Destructor
    Pre : 
    Post : 
    */
    ~Cuento();

    /*
    Pre : 
    Post : borra la memoria dinamica asociada
    */
    void borrar(){};

    /*
    Pre : -
    Post : devuelve el titulo del libro donde se encuentra el cuento solicitado
    */
    string obtener_titulo_libro() const;

    /*
    Pre :  -
    Post : imprime por pantalla el titulo, minutos, año, autor (si se lo conoce) y el nombre del libro del cuento
    */
    void mostrar() const;

    /*
    Pre : -
    Post : -
    */
    void mostrar(string genero) const{};

private:
    string libro;    
};           


#endif //CUENTO_H