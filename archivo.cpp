#include "archivo.h"
#include "cola.h"
#include <iostream>
#include <string>

//enum genero{DRAMA = 1, COMEDIA, FICCION, SUSPENSO, TERROR, ROMANTICA, HISTORICA};

using namespace std;

Archivo :: Archivo (Lista<Escritor>* escritor,Lista<Lectura>* lectura) {
	this->escritor = escritor;
	this->lectura = lectura;
	colaLectura = new Cola<Lectura>;

}

void Archivo :: leerArchivoEscritor() {
	Escritor* nuevoEscritor = 0;
	string primero, nombreApellido, nacionalidad,anioNacimiento,anioFallecimiento, saltoLinea;
	//int anioNacimiento, anioFallecimiento;
	
    archivo.open("C:\\Users\\Pablo\\OneDrive\\Documentos\\Algoritmo y Programacion II\\tp2\\textoescritor.txt", ios::in);

    if (archivo.fail()){
        cout << "No se puede abrir el archivo escritor." << endl;
        
    }else{
	
	while (!archivo.eof()){

		getline(archivo, primero);
		getline(archivo, nombreApellido);
		getline(archivo, nacionalidad);
		getline(archivo, anioNacimiento);
		//anioNacimiento = anioNacimientoStr;
		getline(archivo, anioFallecimiento);
		//anioFallecimiento = anioFallecimientoStr;
		getline(archivo, saltoLinea);
		
		nuevoEscritor = new Escritor(nombreApellido,nacionalidad, anioNacimiento, anioFallecimiento);
		escritor-> agregarElemento(nuevoEscritor);
		}
	}
		
	archivo.close();	     
}

void Archivo :: leerArchivoLecturas(){
	string narracion, titulo,referenciaAutor = "anonimo";
	string anioPublicacion, minutos, datoSegunNarracion,tema,saltoLinea;
	
	archivoLectura.open("C:\\Users\\Pablo\\OneDrive\\Documentos\\Algoritmo y Programacion II\\tp2\\textolectura.txt", ios::in);
	
	if (archivoLectura.fail()){
		cout << "No se puede abrir el archivo lectura." << endl;
		
	}else{
	
		while (!archivoLectura.eof()){
			getline(archivoLectura, narracion);
			getline(archivoLectura,titulo);
			getline(archivoLectura,minutos);
			getline(archivoLectura,anioPublicacion);

			
			
			if (narracion == "C"){
				getline(archivoLectura,datoSegunNarracion);
				getline(archivoLectura, referenciaAutor);
				Lectura* nuevoCuento = new Cuento(titulo,minutos,anioPublicacion,referenciaAutor,datoSegunNarracion);
			 	lectura->agregarElemento(nuevoCuento);
			 	colaLectura->agregarCola(nuevoCuento);
			}
			
			if(narracion == "P"){
				getline(archivoLectura,datoSegunNarracion);
				getline(archivoLectura, referenciaAutor);
				Lectura* nuevoPoema = new Poema(titulo, minutos, anioPublicacion, referenciaAutor, datoSegunNarracion);
			 	lectura->agregarElemento(nuevoPoema);
			 	colaLectura->agregarCola(nuevoPoema);
			}
			
			if(narracion == "N"){
				getline(archivoLectura,datoSegunNarracion);
				cout << datoSegunNarracion<< endl;
				if (datoSegunNarracion == "HISTORICA"){
					getline(archivoLectura,tema);
					cout << tema << endl;
					getline(archivoLectura, referenciaAutor);
					cout << referenciaAutor << endl;
					Lectura* nuevaHistorica = new Historica(titulo,minutos,anioPublicacion,referenciaAutor, datoSegunNarracion,tema);
					lectura->agregarElemento(nuevaHistorica);
					colaLectura->agregarCola(nuevaHistorica);
				}else{
					getline(archivoLectura, referenciaAutor);
					Lectura* nuevaNovela = new Novela(titulo, minutos, anioPublicacion, referenciaAutor, datoSegunNarracion);
			 		lectura->agregarElemento(nuevaNovela);
			 		colaLectura->agregarCola(nuevaNovela);
			 	}
			 }
			getline(archivoLectura, saltoLinea);
			
		}
	}
	archivoLectura.close();
}
