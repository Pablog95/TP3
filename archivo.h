#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <iostream>
#include "lista.h"
#include "escritor.h"
#include "lectura.h"
#include "cuento.h"
#include "novela.h"
#include "poema.h"
#include "historica.h"
#include "cola.h"
#include "grafo2.h"
#include "hashing.h"

using namespace std;

class Archivo
{
	private:
		Lista<Escritor>* escritor;
		Lista<Lectura>* lectura;
		Cola<Lectura>* colaLectura;
		Grafo2<Lectura>* grafo;
		Hashing<Escritor>* escritorHashing;
			
		string datoSegunNarracion;
	public:
		Archivo(Lista<Escritor>* escritor,Lista<Lectura>* lectura, Cola<Lectura>* colaLectura, Hashing<Escritor>* escritorHashing);
		ifstream archivo;
		ifstream archivoLectura;
		void leerArchivoEscritor();
		void leerArchivoLecturas();
        string compararReferencias(string,int);
		int comparar(int,int);
        ~Archivo(){};
};

#endif
