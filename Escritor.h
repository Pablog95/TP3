#ifndef ESCRITOR_H
#define ESCRITOR_H

#include "Lista.h"

class Escritor{

public:
    /*
    Constructor
    Pre : En caso de no conocerse anio_nacimiento es -1, anio_defuncion es -1 en caso de no haber muerto
          o no conocerse
    Post : Crea la clase Escritor
    */
    Escritor(string nombres, string nacionalidad, int anio_nacimiento, int anio_defuncion, int isni);
    
    /*
    Destructor
    Pre : -
    Post : -
    */
    ~Escritor();
    
    /*
    Constructor
    Pre : -
    Post : Borra toda la memoria dinamica asociada
    */
    void borrar(){};

    /*
    Pre : -
    Post : imprime por pantalla el nombre y apellido del escritor
    */
    void mostrar();

    /*
    Pre : -
    Post : imprime por pantalla según corresponda la nacionalidad
        el anio de nacimiento y de fallecimiento del escritor
    */
    void mostrar_anios_y_nacionalidades();

    /*
    Pre : -
    Post : retorna el nombre y apellido del escritor
    */    
    string obtener_nombres() const;

    /*
    Pre : -
    Post : retorna la nacionalidad del escritor
    */ 
    string obtener_nacionalidad() const;

    /*
    Pre : -
    Post : retorna año de nacimiento del escritor, en caso de no conocerse anio_nacimiento = -1
    */ 
    int obtener_anio_nacimiento() const;

    /*
    Pre :  -
    Post : retorna año de defuncion del escritor, en caso de estar vivo o de no conocer el año
           se retorna -1.
    */ 
    int obtener_anio_defuncion() const;

    /*
    Pre :  -
    Post : retorna el ISNI.
    */
    int obtener_isni() const;

    //pre: nuevoAnio > 0
    //post: cambia la fecha de defuncion
    void cambiar_anio_defuncion( int nuevo_anio );

    /*
    Pre : e2 no puede ser NULL
    Post : retorna -1 si el año de nacimiento de e2 es mayor, 1 en caso contrario y 0 si son iguales 
    */ 
    int comparar(const Escritor* e2) const;

private:
    string nombres_y_apellidos;
    string nacionalidad;
    int anio_nacimiento;
    int anio_defuncion;
    int isni;
};

#endif //ESCRITOR_H