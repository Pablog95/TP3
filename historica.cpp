#include "historica.h"
#include "novela.h"
#include <iostream>

//PRE: Recibe una cadena.
//POS: Devuelve un char* en memoria dinamica, al finalizar debe liberarse la memoria.

char* string_to_pchar(string string){
    size_t tamagno = string.length();
    char* nuevo = new char[tamagno + 1];
    
    for(size_t i = 0; i < tamagno; i++)
        nuevo[i] = string[i];

    nuevo[tamagno] = EOL;

    return nuevo;
}

Historica::Historica(string titulo_lectura, unsigned int minutos, unsigned int anio, Escritor* autor, genero_t genero,string tema)
    : Novela( titulo_lectura, minutos, anio, autor, genero){        
        this->tema = string_to_pchar(tema);
}

Historica::~Historica(){};

void Historica::borrar(){
    delete []tema;
}

char* Historica::obtener_tema(){
    return this->tema;
}

void Historica::mostrar(){
    Novela::mostrar();
    cout << "Tema: " << obtener_tema() << endl;
} 

    

    




