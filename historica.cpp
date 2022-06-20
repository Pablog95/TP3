#include "historica.h"

Historica :: Historica (string _titulo, unsigned int _minutos, int _anio, string _autor,string _genero, string _tema):
        Novela (_titulo, _minutos, _anio, _autor, _genero)
{
    long tamanioTema = _tema.length();
    char* temaDinamico = new char[tamanioTema+1];

    for (int i = 0; i < tamanioTema; i++){
        temaDinamico[i] = _tema[i];
    }

    this -> tema = temaDinamico;
}

Historica::~Historica(){
    delete[] tema;
}

void Historica :: mostrar(){
    cout << "Titulo: " << obtenerTitulo() << endl;
    cout << "Minutos: " << obtenerMinutos() << endl;
    cout << "Anio: " << obtenerAnio() << endl;
    cout << "Autor: " << obtenerAutor() << endl;
    cout << "Genero: " << obtenerGenero() << endl;
    cout << "Tema: " << tema << endl;
}

string Historica :: obtenerGenero(){
    return this -> genero;
}

char* Historica :: obtenerTema(){
    return tema;
}