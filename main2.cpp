#include "archivo.h"
#include "menu.h"
#include "grafo2.h"

int main()
{
	Lista<Escritor> escritor;
	Lista<Lectura> lecturas;
	Cola<Lectura> colaLectura;
	Hashing<Escritor> tablaEscritor;

	Archivo a1(& escritor, & lecturas , & colaLectura, & tablaEscritor);
	Menu m1(& escritor, & lecturas, &colaLectura, & tablaEscritor);
	

	a1.leerArchivoEscritor();
	a1.leerArchivoLecturas();
	
	m1.mostrarMenu();

	
    return 0;
    
}
