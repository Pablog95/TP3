#include "archivolecturas.h"
#include <iostream>
#include <fstream>

using namespace std;

ArchivoLecturas :: ArchivoLecturas(){
	
}

void ArchivoLecturas :: procesarArchivo(){
	string genero, titulo, minutos,anioPublicacion,casoEspecial,referencia;
	ifstream archivo;
	archivo.open("C:\\Users\\Pablo\\OneDrive\\Documentos\\Algoritmo y Programacion II\\Ultimointento\\lecturas.txt", ios::in);
	
	if (archivo.fail()){
		cout<< "Fallo la carga del archivo" << endl;
	}
	
	getline(archivo,genero);
	getline(archivo,titulo);
	getline(archivo,minutos);
	getline(archivo,anioPublicacion);
	getline(archivo,casoEspecial);
	getline(archivo,referencia);
}
