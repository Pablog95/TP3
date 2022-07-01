#ifndef NOVELA_H
#define NOVELA_H

#include "Lectura.h"

class Novela : public Lectura{

public:
    /*
    constructor con parametros
    PRE: minutos > 0, anio > 0, versos > 0, genero debe ser valido
    POS: crea una Novela inicializada con sus atributos
    */
    Novela(string tipo_lectura, string titulo_lectura, unsigned int minutos, unsigned int anio, Escritor* autor, genero_t genero);
    /*    
    PRE: -
    POS: devuelve el genero de la novela
    */
    genero_t obtener_genero() const;
    /*    
    PRE: -
    POS: imprime los atributos de novela
    */
    void mostrar() const;
    /*    
    PRE: novela no puede ser NULL
    POS: borra la memoria dinamica asociada a novela
    */
    void borrar(){};
    /*
    PRE: genero_t genero debe ser valido
    POS: devuelve true si los generos son iguales, false en caso contrario
    */
    bool comparar(genero_t genero) const;
    /*    
    PRE: genero debe ser un existente
    POS: imprime los atributos de novela en caso ser del mismo genero
    */
    void mostrar(string genero) const;
    
protected:
    genero_t genero;
};

#endif //NOVELA_H