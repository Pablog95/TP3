#include "archivo.h"
#include "cola.h"
#include <iostream>
#include <string>

//enum genero{DRAMA = 1, COMEDIA, FICCION, SUSPENSO, TERROR, ROMANTICA, HISTORICA};

using namespace std;

Archivo :: Archivo (Lista<Escritor>* escritor,Lista<Lectura>* lectura, Cola<Lectura>* colaLectura) {

	this -> escritor = escritor;
	this -> lectura = lectura;
	this -> colaLectura = colaLectura;

}

void Archivo :: leerArchivoEscritor() {

	Escritor* nuevoEscritor = 0;
	string referencia, nombreApellido, nacionalidad,anioNacimiento,anioFallecimiento, saltoLinea;
	
    archivo.open("textoescritor.txt", ios::in);

    if (archivo.fail()){
        cout << "No se puede abrir el archivo escritor." << endl;
        
    }else{

        while (!archivo.eof()){

		getline(archivo, referencia);
		getline(archivo, nombreApellido);
		getline(archivo, nacionalidad);

		getline(archivo, anioNacimiento);
        int AniodeNacimiento = stoi(anioNacimiento);

		getline(archivo, anioFallecimiento);
        int AniodeFallecimiento = stoi(anioFallecimiento);

		getline(archivo, saltoLinea);

		nuevoEscritor = new Escritor(referencia,nombreApellido,nacionalidad,AniodeNacimiento,AniodeFallecimiento);
		escritor -> agregarElemento(nuevoEscritor);

		}

	}
	archivo.close();	     
}

void Archivo :: leerArchivoLecturas(){

	string narracion, titulo,referenciaAutor;
	string anioPublicacion, minutos, datoSegunNarracion,tema,saltoLinea;
	
	archivoLectura.open("textolectura.txt", ios::in);
	
	if (archivoLectura.fail()){
		cout << "No se puede abrir el archivo lectura." << endl;
		
	}else{
	
		while (!archivoLectura.eof()){

            int tamanio = lectura -> obtenerTamanio();
            int tamanioEscritores = escritor -> obtenerTamanio();

			getline(archivoLectura, narracion);
			getline(archivoLectura,titulo);
			getline(archivoLectura,minutos);

            unsigned int minutosLibro = stoi(minutos);
			getline(archivoLectura,anioPublicacion);

            int anioDePublicacion = stoi(anioPublicacion);
			
			if (narracion == "C"){

				getline(archivoLectura,datoSegunNarracion);
				getline(archivoLectura, referenciaAutor);

                string referencia = compararReferencias(referenciaAutor,tamanioEscritores);

				Lectura* nuevoCuento = new Cuento(titulo,minutosLibro,anioDePublicacion,referencia,datoSegunNarracion);
				int posicion = comparar(nuevoCuento->obtenerAnio(),tamanio);

				lectura -> agregarElemento(nuevoCuento,posicion,tamanio);
			 	colaLectura -> agregarCola(nuevoCuento);
			}
			
			if(narracion == "P"){

				getline(archivoLectura,datoSegunNarracion);
				getline(archivoLectura, referenciaAutor);

                string referencia = compararReferencias(referenciaAutor,tamanioEscritores);

				Lectura* nuevoPoema = new Poema(titulo, minutosLibro, anioDePublicacion, referencia, datoSegunNarracion);
				int posicion = comparar(nuevoPoema->obtenerAnio(),tamanio);

				lectura -> agregarElemento(nuevoPoema,posicion,tamanio);
			 	colaLectura -> agregarCola(nuevoPoema);
			}
			
			if(narracion == "N"){

				getline(archivoLectura,datoSegunNarracion);

				if (datoSegunNarracion == "HISTORICA"){

					getline(archivoLectura,tema);
					getline(archivoLectura, referenciaAutor);

                    string referencia = compararReferencias(referenciaAutor,tamanioEscritores);

					Lectura* nuevaHistorica = new Historica(titulo,minutosLibro,anioDePublicacion,referencia, datoSegunNarracion,tema);
					int posicion = comparar(nuevaHistorica->obtenerAnio(),tamanio);

					lectura -> agregarElemento(nuevaHistorica, posicion, tamanio);
					colaLectura -> agregarCola(nuevaHistorica);

				}else{

					getline(archivoLectura, referenciaAutor);

                    string referencia = compararReferencias(referenciaAutor,tamanioEscritores);

					Lectura* nuevaNovela = new Novela(titulo, minutosLibro, anioDePublicacion, referencia, datoSegunNarracion);
					int posicion = comparar(nuevaNovela->obtenerAnio(),tamanio);

					lectura -> agregarElemento(nuevaNovela,posicion, tamanio);
			 		colaLectura -> agregarCola(nuevaNovela);
			 	}
			 }
			getline(archivoLectura, saltoLinea);
		}
	}
	archivoLectura.close();
}

string Archivo :: compararReferencias(string referencia,int tamanioEscritor){

    string referenciaAutor;

    for(int i = 0 ; i <= tamanioEscritor; i++ ){
        if(escritor->obtenerDato(i)->obtenerReferencia() == referencia) {

            referenciaAutor = escritor->obtenerDato(i)->obtenerNombreApellido();
        }
    }
    if (referencia == "ANONIMO"){
        referenciaAutor = "ANONIMO";
    }
    return referenciaAutor;
}


int Archivo :: comparar(int anioLectura, int tamanio)
{
	int dato = 0;

	for (int i = 1; i <= tamanio; i++)
	{
		if (lectura->obtenerDato(i)->obtenerAnio() > anioLectura && lectura->obtenerDato(i) != NULL){
			dato = 1;
		}
        else if(lectura->obtenerDato(i)->obtenerAnio() < anioLectura && lectura->obtenerDato(i) != NULL){
            dato = -1;
		}
	}
	return dato;
}
