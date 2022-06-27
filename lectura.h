#ifndef LECTURA_H
#define LECTURA_H

#include "escritor.h"

class Lectura{

public:
    /*
    constructor con parametros
    PRE: minutos > 0, anio > 0
    POS: Construye una lectura con sus respectivos atributos
    */
    Lectura(string titulo_lectura, unsigned int minutos, unsigned int anio, Escritor* autor);
    
    /*
    Destructor
    PRE: -
    POS: -
    */
    virtual ~Lectura(){};

    /*
    PRE: -
    POS: llama al metodo borrar se sus clases hijas
    */
    virtual void borrar(){};

    /*
    PRE: -
    POS: llama al metodo mostrar se sus clases hijas
    */
    virtual void mostrar() const = 0;
    
    /*
    PRE: genero debe contener un genero existente
    POS: llama al metodo mostrar se sus clases hijas
    */
    virtual void mostrar(string genero) const = 0;
    
    /*
    PRE: lectura2 no puede ser NULL;
    POS: Compara los años de las lecturas. Devuelve 0 si son iguales, – 1 si la lectura que llama es menor a la que se pasa por parámetro
        y 1 en caso contrario
    */
    int comparar(const Lectura* lectura2) const;
    
    /*
    PRE: -
    POS: Compara los minutos de las lecturas. Devuelve 0 si son iguales, – 1 si minutos de la lectura que llama es menor al de la 
         que se pasa por parámetro y 1 en caso contrario
    */
    int comparar(unsigned int minutos2) const;

    /*
    PRE: Lectura debe estar creada;
    POS: devuelve el titulo de la lectura,
    */
    string obtener_titulo() const;
    
    /*
    PRE: Lectura debe estar creada;
    POS: devuelve los minutos la lectura,
    */
    unsigned int obtener_minutos() const;

    /*
    PRE: Lectura debe estar creada;
    POS: devuelve el año de la lectura,
    */
    unsigned int obtener_anio() const;

    /*
    PRE: Lectura debe estar creada;
    POS: devuelve un puntero al escritor de la misma
    */
    Escritor* obtener_autor() const;

protected:
    
    string titulo;
    unsigned int minutos;
    unsigned int anio;
    Escritor* autor;

};

#endif //LECTURA_H