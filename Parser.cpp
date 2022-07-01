#include "Parser.h"

void imprimir_menu() {

    cout << "----------------------------------------------------------------------------------------------------------"
         << endl;
    cout << "          				--->>> MENU <<<---   " << endl;
    cout << "----------------------------------------------------------------------------------------------------------"
         << endl;
    cout << "Elija una opcion: \n" << endl;
    cout << "1- Agregar una nueva lectura a la lista." << endl;
    cout << "2- Quitar una lectura de la lista." << endl;
    cout << "3- Agregar un escritor." << endl;
    cout << "4- Cambiar la fecha de fallecimiento de un escritor(Antes de cambiar vea el orden de la lista -Opcion 5-)"
         << endl;
    cout << "5- Listar los escritores." << endl;
    cout << "6- Sortear una lectura random para leer." << endl;
    cout << "7- Listar todas las lecturas." << endl;
    cout << "8- Listar las lecturas entre determinados anios." << endl;
    cout << "9- Listar las lecturas de un determinado escritor" << endl;
    cout << "10- Listar las novelas de determinado genero." << endl;
    cout << "11- Armar una cola ordenada." << endl;
    cout << "12 - Hashing. " << endl;
    cout << "13- Salir." << endl;
    cout << "----------------------------------------------------------------------------------------------------------"
         << endl;
    cout << "----------------------------------------------------------------------------------------------------------"
         << endl;
}

void ingresar_numero(int *numero){
    cout << "Ingresa la opción solicitada : " << endl;

    cin >> (*numero);
    cin.ignore();

    //cout << numero << endl;

    cout << endl << endl;
}

void menu_1(string * tipo_lectura, string * titulo, string * minutos, string * anio, string * caracteristica, string * tema, string * referencia_al_autor){
    cout << "Ingrese el tipo de lectura : (N - Novela, P - Poema, C - Cuento)" << endl;
    cin >> *tipo_lectura;
    cin.ignore();

    cout << "Ingrese el titulo de la lectura : " << endl;
    getline(cin, *titulo);

    cout << "Ingrese los minutos estimados que demandaría la lectura : " << endl;
    cin >> *minutos;
    cin.ignore();

    cout << "Ingrese el año de publicación : " << endl;
    cin >> *anio;
    cin.ignore();

    if (*tipo_lectura == "N") {

        cout << "Ingrese el genero de su novela (DRAMA, COMEDIA, FICCION, SUSPENSO, TERROR, ROMANTICA, HISTORICA) : "
             << endl;
        cin >> *caracteristica;
        cin.ignore();

        if (*caracteristica == "HISTORICA") {

            cout << "Ingrese el tema de su novela histórica : " << endl;
            getline(cin, *tema);

        }
    } else if (*tipo_lectura == "C") {

        cout << "Ingrese el título del libro en el que está publicado el cuento : " << endl;
        getline(cin, *caracteristica);

    } else {

        cout << "Ingrese la cantidad de versos que tiene el poema : " << endl;
        getline(cin, *caracteristica);

    }

    cout << "Ingrese la posición del escritor de la lectura en la lista (contando desde arriba hacia abajo) : " << endl;
    cin >> *referencia_al_autor;
    cin.ignore();
}

void menu_2(string * n_lectura_quitar){
    cout << "Que número de lectura desea quitar de la lista (contando desde arriba hacia abajo) : " << endl;
    cin >> *n_lectura_quitar;
    cin.ignore();
}

void menu_3(string * referencia_al_autor, string * nombre_escritor, string * nacionalidad, string * anio_nacimiento, string * anio_fallecimiento){
    cout << "Ingrese el ISNI del escritor : " << endl;
    cin >> *referencia_al_autor;
    cin.ignore();

    cout << "Ingrese el nombre del escritor : " << endl;
    cin >> *nombre_escritor;
    cin.ignore();

    cout << "Ingrese la nacionalidad del escritor : " << endl;
    cin >> *nacionalidad;
    cin.ignore();

    cout << "Ingrese el año de nacimiento del escritor (en caso de desconocerlo, ingrese -1): " << endl;
    cin >> *anio_nacimiento;
    cin.ignore();

    cout << "Ingrese el año de fallecimiento del escritor (en caso de no haber fallecido, ingrese -1)" << endl;
    cin >> *anio_fallecimiento;
    cin.ignore();
}

void menu_4(string * referencia_al_autor, string * anio_fallecimiento){
    cout << "Ingrese el numero del escritor al que le desea cambiar la fecha de fallecimiento () contando desde arriba hacia abajo: " << endl;
    cin >> *referencia_al_autor;
    cin.ignore();

    cout << "Ingrese el año de fallecimiento actualizado : " << endl;
    cin >> *anio_fallecimiento;
    cin.ignore();
}

void menu_8(string * anio1, string * anio2){
    cout << "Ingrese desde que año desea listar las lecturas : " << endl;
    cin >> *anio1;
    cin.ignore();

    cout << "Ingrese hasta que año desea listar las lecturas : " << endl;
    cin >> *anio2;
    cin.ignore();
}

void menu_9(string * nombre_escritor){
    cout << "Ingrese el escritor deseado para listar todas sus lecturas : " << endl;
    getline(cin, *nombre_escritor);
}

void menu_10(string * caracteristica){
    cout << "Ingrese el genero deseado para listar las novelas : " << endl;
    getline(cin, *caracteristica);
}
