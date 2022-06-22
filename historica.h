#ifndef HISTORICA_H
#define HISTORICA_H

#include "novela.h"

class Historica : public Novela{
public:
    /*
    constructor con parametros
    PRE: minutos > 0, anio > 0, genero debe ser un genero_t valido.
    POS: Construye una lectura con sus respectivos atributos y reserva memoria dinamica para el tema
    */
    Historica (string titulo_lectura, unsigned int minutos, unsigned int anio, Escritor* autor, genero_t genero, string tema);
    
    /*
    Destructor
    PRE: -
    POS: -
    */
    ~Historica();
    
    /*
    PRE: Historica debe estar creada
    POS: devuelve un puntero al tema
    */
    char* obtener_tema();

    /*
    PRE: Historica debe estar creada
    POS: imprime por pantalla todos los atributos
    */
    void mostrar();
    /*
    PRE: Historica debe estar creada
    POS: elimina toda la memoria dinamica asociada
    */
    void borrar();

private:    
    char* tema;
};


#endif //HISTORICA_H