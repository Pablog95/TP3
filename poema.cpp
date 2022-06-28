#include "poema.h"

Poema::Poema(string tipo_lectura, string titulo_lectura, unsigned int minutos, unsigned int anio, Escritor* autor, unsigned int versos)
    : Lectura(tipo_lectura, titulo_lectura, minutos, anio, autor){
        this->versos = versos;
}

unsigned int Poema::obtener_versos() const{
    return this->versos; 
}

void Poema::mostrar() const{
    cout << "Titulo: " << obtener_titulo() << endl;
    cout << "Minutos: " << obtener_minutos() << endl;
    cout << "Año: " << obtener_anio() << endl;
    
    if(!obtener_autor())
        cout << "Autor : ANONIMO" << endl;
    else
        cout << "Autor: " << obtener_autor()->obtener_nombres() << endl;
    cout << "Cantidad de versos: " << obtener_versos() << endl;
}
  

