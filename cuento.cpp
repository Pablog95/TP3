#include "cuento.h"

Cuento::Cuento(string tipo_lectura,string titulo_lectura, unsigned int minutos, unsigned int anio, Escritor* autor,string libro)
    : Lectura(tipo_lectura, titulo_lectura, minutos, anio, autor){
        this->libro = libro;
}

Cuento::~Cuento(){}

string Cuento::obtener_titulo_libro() const{
    return this->libro;
}

void Cuento::mostrar() const{
    cout << "Titulo: " << obtener_titulo() << endl;
    cout << "Minutos: " << obtener_minutos() << endl;
    cout << "Año: " << obtener_anio() << endl;
    
    if(!obtener_autor())
        cout << "Autor : ANONIMO" << endl;
    else
        cout << "Autor: " << obtener_autor()->obtener_nombres() << endl;
    cout << "Libro: " << obtener_titulo_libro() << endl;
}
