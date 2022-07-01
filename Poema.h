#ifndef POEMA_H
#define POEMA_H

#include "Lectura.h"

class Poema : public Lectura {
public:
    /*
    constructor con parametros
    PRE: minutos > 0, anio > 0, versos > 0
    POS: inicializa atributos
    */
    Poema(string tipo_lectura, string titulo_lectura, unsigned int minutos, unsigned int anio, Escritor* autor, unsigned int versos);
    
    /*
    Destructor
    PRE: -
    POS: -
    */
    ~Poema(){};
    
    /*
    PRE: -
    POS: borra la memoria dinamica asociada
    */
    void borrar(){};
    
    /*    
    PRE: -
    POS: obtiene la cantidad de versos del poema, cantidad > 0
    */
    unsigned int obtener_versos() const;
    void mostrar() const;
    void mostrar(string genero) const{};
    
private:
    unsigned int versos;
};

#endif //POEMA_H