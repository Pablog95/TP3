#include "escritor.h"

Escritor::Escritor( string nombres, string nacionalidad, int anio_nacimiento, int anio_defuncion, int isni){
    this->nombres_y_apellidos = nombres;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_defuncion = anio_defuncion;
    this->isni = isni;
}

Escritor::~Escritor(){}

void Escritor::mostrar_datos(){
    cout << "ISNI :  " << obtener_isni() << endl;
    cout << obtener_nombres() << endl;
    mostrar_anios_y_nacionalidades();
}

void Escritor :: mostrar_anios_y_nacionalidades(){
    if (obtener_anio_defuncion() != -1){
        cout << obtener_nacionalidad() << endl;
        cout << obtener_anio_nacimiento() << endl;
        cout << obtener_anio_defuncion() << endl;
    }
    else if(obtener_anio_defuncion() == -1 && obtener_anio_nacimiento() != -1){
        cout << obtener_nacionalidad() << endl;
        cout << obtener_anio_nacimiento() << endl;
    }
    else if(obtener_anio_defuncion() == -1 && obtener_anio_nacimiento() == -1 && obtener_nacionalidad() != "¿?"){
        cout << obtener_nacionalidad() << endl;
    }
}

std::string Escritor::obtener_nombres() const{
    return this->nombres_y_apellidos;
}

std::string Escritor::obtener_nacionalidad() const{
    return nacionalidad;
}

int Escritor :: obtener_isni() const{
    return this->isni;
}

void Escritor::cambiar_anio_defuncion( int nuevo_anio ){
    anio_defuncion = nuevo_anio;
}

int Escritor::obtener_anio_nacimiento() const{
    return this->anio_nacimiento;
}

int Escritor::obtener_anio_defuncion() const {
    return this->anio_defuncion;
}

int Escritor::comparar(const Escritor* e2) const{
    unsigned int anio1 = obtener_anio_nacimiento();
    unsigned int anio2 = e2->obtener_anio_nacimiento();

    if( anio1 < anio2)
        return -1;
    
    if( anio1 > anio2)
        return 1;
    
    return 0;
}
