#include "funciones.h"

using namespace std;

int  string_a_int( string string) {
    return ( stoi(string));
}

genero_t string_a_genero_t(string genero){
            
    if(genero == genero_t_cadena[DRAMA])
            return DRAMA;
    else if(genero == genero_t_cadena[COMEDIA])
            return COMEDIA;
    else if(genero == genero_t_cadena[FICCION])
            return FICCION;
    else if(genero == genero_t_cadena[SUSPENSO])
            return SUSPENSO;
    else if(genero == genero_t_cadena[TERROR])
            return TERROR;
    else if(genero == genero_t_cadena[ROMANTICA])
            return ROMANTICA;
    
    return HISTORICA;   
            
}

int  autor_anonimo( string referencia_al_autor) {
    
    if (referencia_al_autor == "ANONIMO"){
        return (ANONIMO);
    }
    else{
        return (string_a_int(referencia_al_autor));
    }
}
