#include "Lectura.h"

Lectura::Lectura(string tipo_lectura, string titulo_lectura, unsigned int minutos, unsigned int anio, Escritor* autor ){
    this->tipo_lectura = tipo_lectura;
    this->titulo = titulo_lectura;
    this->minutos = minutos;
    this->anio = anio;
    this->autor = autor;
}

int Lectura::comparar(const Lectura* lectura2) const{
    unsigned int anio1 = obtener_anio();
    unsigned int anio2 = lectura2->obtener_anio();

    if( anio1 < anio2)
        return -1;
    
    if( anio1 > anio2)
        return 1;
    
    return 0;
}

int Lectura::comparar(unsigned int minutos2) const{
    unsigned int minutos1 = obtener_minutos();
    
    if( minutos1 < minutos2)
        return -1;
    
    if( minutos1 > minutos2)
        return 1;
    
    return 0;
}

string Lectura::obtener_titulo() const{
    return titulo;
}

unsigned int Lectura::obtener_minutos() const{
    return minutos;
}

unsigned int Lectura::obtener_anio() const{
    return anio;
}

Escritor* Lectura::obtener_autor() const{
    return autor;
}

string Lectura::obtener_tipo() const{
    return tipo_lectura;
}
