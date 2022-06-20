#include "menu.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>


using namespace std;

Menu :: Menu (Lista<Escritor>* escritores,Lista<Lectura>* lecturas, Cola<Lectura>* colaLectura){
	this -> escritores = escritores;
	this -> lecturas = lecturas;
	this -> colaLectura = colaLectura;
	
}

void Menu :: mostrarMenu(){
	
	do{
        system("cls");

		cout << "----------------------------------------------------------------------------------------------------------" << endl;
		cout << "          				--->>> MENU <<<---   "<< endl;
		cout << "----------------------------------------------------------------------------------------------------------" << endl;
		cout << "Elija una opcion: \n" << endl;
		cout << "1- Agregar una nueva lectura a la lista."<< endl;
		cout << "2- Quitar una lectura de la lista."<< endl;
		cout << "3- Agregar un escritor."<< endl;
		cout << "4- Cambiar la fecha de fallecimiento de un escritor(Antes de cambiar vea el orden de la lista -Opcion 5-)"<< endl;
		cout << "5- Listar los escritores."<< endl;
		cout << "6- Sortear una lectura random para leer."<< endl;
		cout << "7- Listar todas las lecturas."<< endl;
		cout << "8- Listar las lecturas entre determinados anios."<< endl;
		cout << "9- Listar las lecturas de un determinado escritor"<< endl;
		cout << "10- Listar las novelas de determinado genero."<< endl;
		cout << "11- Armar una cola ordenada."<< endl;
		cout << "12- Salir."<< endl;
		cout << "----------------------------------------------------------------------------------------------------------" << endl;
		cout << "----------------------------------------------------------------------------------------------------------" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		
		switch(opcion){
			
			case 1: agregarLectura();break;//agregarElemento(T* dato),
			case 2: borrarLectura ();break;//borrarDato(int posicion)
			case 3: agregarEscritores();break;//agregarElemento(T* escritor)
			case 4: cambiarFallecimiento();break;//cambiarDatoEscritor()
			case 5: listaEscritores(); break;
			case 6: sortearLectura(); break;//sortearLectura()
			case 7: listaLectura(); break; // listarLectura()
			case 8: listarLecturaAnio();break;//listarLecturaAnios()
			case 9: listarLecturaEscritor() ;break;//listarlecturaEscritor()
			case 10:listarNovelaGenero();break;//listarNovelaGenero()
			case 11: mostrarCola(); break;//armarCola()
			case 12:break;
				
		}		
		
	}while (opcion != 12);
}


void Menu :: mostrarCola(){

    system("cls");
    string salida;


	while(salida != "s" && !colaLectura -> colaVacia()){

		colaLectura -> obtenerDatoCola() -> mostrar();
        cout << "Presione (s) si quiere dejar de eliminar lecturas."  << endl;
        colaLectura -> bajaCola();
        cin >> salida;
	}
}

void Menu :: listaEscritores(){

    system("cls");
    string salida;

    do {
        int tamanio = escritores -> obtenerTamanio();

        for (int i = 1; i <= tamanio; i++) {
            cout << i << ") ";
            escritores -> obtenerDato(i) -> mostrarDatos();
            cout << "-------" << endl;
        }

        cout << "Presione (s) para salir" << endl;
        cin >> salida;

    }while((salida != "s"));
}

void Menu :: listaLectura(){

    system("cls");
    string salida;

    do {
        if (lecturas -> listaVacia()) {
            cout << "La lista esta vacia." << endl;
        }
        int tamanio = lecturas->obtenerTamanio();

        for (int i = 1; i <= tamanio; i++) {
            cout << i << ") ";
            lecturas -> obtenerDato(i) -> mostrar();
            cout << "-------" << endl;
        }
        cout << "Presione (s) para salir" << endl;
        cin >> salida;

    }while((salida != "s"));
}

void Menu :: listarNovelaGenero(){

    system("cls");
    string salida;

    do {
        int tamanio = lecturas->obtenerTamanio();
        string genero;

        cout << "Ingrese el genero de novela que quiere listar (Mayuscula): " << endl;
        cin >> genero;

        int contador = 0;
        for (int i = 1; i <= tamanio; i++) {
            if (genero == lecturas->obtenerDato(i)->obtenerGenero()) {
                lecturas->obtenerDato(i)->mostrar();
                contador++;
            }
        }
        if (contador == 0) {
            cout << "No se encontro ninguna novela del genero elegido." << endl;
        }

        cout << "Presione (s) para salir" << endl;
        cin >> salida;

    }while((salida != "s"));
}

void Menu :: agregarEscritores(){

    system("cls");
    string salida;

	Escritor* nuevoEscritor = 0;

	string nombreApellido, nacionalidad;
    int anioNacimiento, anioFallecimiento;

    do {
        cout << "Ingrese nombre y apellido: " << endl;
        cin.ignore();
        getline(cin,nombreApellido);
        cout << "Ingrese nacionalidad: " << endl;
        cin >> nacionalidad;
        cout << "Ingrese anio de nacimiento; " << endl;
        cin >> anioNacimiento;
        cout << "Ingrese anio de fallecimiento: " << endl;
        cin >> anioFallecimiento;

        nuevoEscritor = new Escritor("nuevo",nombreApellido, nacionalidad, anioNacimiento, anioFallecimiento);
        escritores -> agregarElemento(nuevoEscritor);

        cout << "Presione (s) para salir" << endl;
        cin >> salida;

    } while (salida != "s");
}

void Menu :: agregarLectura(){

    system("cls");

	Lectura* nuevaLectura = 0;
	string tipo,titulo, autor,salida;
    unsigned int minutos;
    int anio;

    do {
        cout << "Ingrese el tipo de lectura. (cuento, novela , historica, poema)" << endl;
        cin >> tipo;
        cout << "Ingrese el titulo de la lectura:" << endl;
        cin >> titulo;
        cout << "Ingrese cuantos minutos dura: " << endl;
        cin >> minutos;
        cout << "Ingrese en que anio fue escrita: " << endl;
        cin >> anio;
        cout << "Ingrese el autor: " << endl;
        cin.ignore();
        getline(cin,autor);

        if (tipo != "cuento" && tipo != "novela" && tipo != "poema" && tipo != "historica") {
            cout << "La lectura no es valida." << endl;

            cout << "Presione (s) para salir: ";
            cin >> salida;
        }
        if (tipo == "cuento") {

            string tituloCuento;

            cout << "Ingrese el titulo del libro: " << endl;
            cin >> titulo;

            nuevaLectura = new Cuento(titulo, minutos, anio, autor, tituloCuento);
        }
        if (tipo == "novela") {

            string genero;

            cout << "Ingrese el genero: " << endl;
            cin >> genero;

            if (genero == "historica") {
                string tema;

                cout << "Escriba de que trata la novela historica: " << endl;
                cin >> tema;

                nuevaLectura = new Historica(titulo, minutos, anio, autor, genero, tema);
            } else {
                nuevaLectura = new Novela(titulo, minutos, anio, autor, genero);
            }

        }
        if (tipo == "poema") {

            string cantidadVersos;

            cout << "Ingrese la cantidad de versos del poema: " << endl;
            cin >> cantidadVersos;

            nuevaLectura = new Poema(titulo, minutos, anio, autor, cantidadVersos);
        }
        lecturas->agregarElemento(nuevaLectura);

        cout << "Se agrego la Lectura" << endl;
        cout << "Presione (s) para salir: ";
        cin >> salida;

    }while (salida != "s");
}

void Menu :: borrarLectura(){

    system("cls");
    string salida;

    do {
        lecturas->borrarDato(1);
        cout << "Una lectura fue borrada de la lista." << endl;

        cout << "Presione (s) para salir" << endl;
        cin >> salida;

    }while (salida != "s");
}

void Menu :: sortearLectura(){

    system("cls");
    string salida;

    do {
        int tamanio = lecturas->obtenerTamanio();
        srand((unsigned) time(0));
        int lecturaAleatoria = rand() % (tamanio);
        lecturas->obtenerDato(lecturaAleatoria)->mostrar();

        cout << "Presione (s) para salir" << endl;
        cin >> salida;

    }while (salida != "s");
}

void Menu :: listarLecturaAnio(){

    system("cls");
    string salida;

	int anioUno, anioDos;
	int tamanio = lecturas->obtenerTamanio();

    do {
        cout << "Ingrese dos anios: " << endl;
        cout << "anio 1: " << endl;
        cin >> anioUno;
        cout << "anio 2: " << endl;
        cin >> anioDos;

        if (anioUno < anioDos) {

            for (int i = 0; i < tamanio; i++) {


                int anioLectura = lecturas->obtenerDato(i)->obtenerAnio();
                if (anioUno < anioLectura && anioLectura < anioDos) {

                    cout << "---------------------------"<< endl;
                    lecturas -> obtenerDato(i) -> mostrar();
                    cout << "---------------------------"<< endl;
                }

            }
        }

        cout << "Presione (s) para salir" << endl;
        cin >> salida;

    }while (salida != "s");
	
}

void Menu :: listarLecturaEscritor(){

    system("cls");
    string salida;

    do {
        string ingresoAutor;
        int tamanio = escritores -> obtenerTamanio();

        cout << "Ingrese un autor: " << endl;
        cin.ignore();
        getline(cin,ingresoAutor);

        for (int i = 1; i <= tamanio + 1; i++) {
            if (ingresoAutor == lecturas -> obtenerDato(i) -> obtenerAutor()) {

                cout << "---------------------------"<< endl;
                lecturas -> obtenerDato(i) -> mostrar();
                cout << "---------------------------"<< endl;
            }
        }
        cout << "Presione (s) para salir" << endl;
        cin >> salida;

    }while(salida != "s");
}

void Menu :: cambiarFallecimiento (){

    system("cls");
    string salida;

    do {
        int opcion;
        cout << "Cambiar Fallecimiento: " << endl;
        cout << "Ingrese posicion del cambio de fecha: ";
        cin >> opcion;

        escritores -> obtenerDato(opcion) -> cambiarFallecimiento();

        cout << "Presione (s) para salir" << endl;
        cin >> salida;

    }while(salida !="s");
}
