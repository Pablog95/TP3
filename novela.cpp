#include "novela.h"

const char* genero_t_cadena[] = {"DRAMA","COMEDIA","FICCION","SUSPENSO","TERROR","ROMANTICA","HISTORICA"};

Novela::Novela(string tipo_lectura, string titulo_lectura, unsigned int minutos, unsigned int anio, Escritor* autor, genero_t genero)
    : Lectura(tipo_lectura, titulo_lectura, minutos, anio, autor){
        this->genero = genero;
}

genero_t Novela::obtener_genero() const{
    return this->genero;
}

bool Novela::comparar(genero_t genero) const{
    if(this->genero == genero)
        return 1;
    
    return 0;
}

void Novela::mostrar() const{
    cout << "Tipo de Lectura: " << obtener_tipo() << endl;
    cout << "Titulo: " << obtener_titulo() << endl;
    cout << "Minutos: " << obtener_minutos() << endl;
    cout << "Año: " << obtener_anio() << endl;

    if(!obtener_autor())
        cout << "Autor : ANONIMO" << endl;
    else
        cout << "Autor: " << obtener_autor()->obtener_nombres() << endl;

    cout << "Genero: " << genero_t_cadena[obtener_genero()] << endl;
}

void Novela::mostrar(string genero) const{
    genero_t gen = string_a_genero_t(genero);
    if (comparar(gen)){
        mostrar();
        cout << endl;
    }
}





