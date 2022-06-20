#include "parser.h"

using namespace std;

Parser :: Parser(Lista <Lectura*>* lista_lectura, Lista <Escritor*>* lista_escritor){
    escritores = lista_escritor;
    lecturas = lista_lectura;
}

Parser:: ~Parser(){}

int Parser :: imprimir_menu(){
    
    int numero;

    cout << endl << endl;

    cout << "1 " << "Agregar una nueva lectura a la lista" << endl << endl;
    cout << "2 " << "Quitar una lectura de la lista" << endl << endl;
    cout << "3 " << "Agregar un escritor" << endl << endl;
    cout << "4 " << "Cambiar dato de un escritor (solo fecha de fallecimiento)" << endl << endl;
    cout << "5 " << "Listar escritores" << endl << endl;
    cout << "6 " << "Sortear una lectura random para leer en una de las tertulias" << endl << endl;
    cout << "7 " << "Listar todas las lecturas" << endl << endl;
    cout << "8 " << "Listar las lecturas entre determinados años. Los años los ingresa el usuario" << endl << endl;
    cout << "9 " << "Listar las lecturas de un determinado escritor que ingresa el usuario" << endl << endl;
    cout << "10 " << "Listar las novelas de determinado género" << endl << endl;
    cout << "11 " << "Armar una cola ordenada por tiempo de lectura, de menor (van al principio) a mayor (van al final)" << endl << endl;
    cout << "12 " << "Salir" << endl << endl;

    cout << "Ingresa la opción solicitada : " << endl;
    
    cin >> numero;
        
    cout << endl << endl;

    return numero;
    
}

void Parser :: usuario_nueva_lectura(){
    
    cout << "Ingrese el tipo de lectura : (N - Novela, P - Poema, C - Cuento)" << endl;
    cin >> tipo_lectura;
    cin.ignore();

    cout << "Ingrese el titulo de la lectura : " << endl;
    getline(cin,caracteristica);

    cout << "Ingrese los minutos estimados que demandaría la lectura : " << endl;
    cin >> minutos;

    cout << "Ingrese el año de publicación : " << endl;
    cin >> anio;
    cin.ignore();

    if(tipo_lectura == "N"){
        cout << "Ingrese el genero de su novela (DRAMA, COMEDIA, FICCION, SUSPENSO, TERROR, ROMANTICA, HISTORICA) : " << endl;
        if(genero == "HISTORICA"){
            cout << "Ingrese el tema de su novela histórica : " << endl;
            getline(cin,caracteristica);;
        }    
    }
    else if(tipo_lectura == "C"){
        cout << "Ingrese el título del libro en el que está publicado el cuento : " << endl;
    }
    else{
        cout << "Ingrese la cantidad de versos que tiene el poema : " << endl;
    }
    getline(cin,caracteristica);

    cout << "Ingrese la posición del escritor de la lectura en la lista (contando desde arriba hacia abajo) : " << endl;
    cin >> referencia_al_autor;

}

Lectura* Parser::procesador_entradaL(Escritor* escritor){
   
    if(tipo_lectura == "N"){
        if(caracteristica == "HISTORICA")
            return (new Historica(titulo, string_a_int(minutos), string_a_int(anio), escritor, string_a_genero_t(caracteristica), tema));
        else
            return (new Novela(titulo, string_a_int(minutos), string_a_int(anio), escritor, string_a_genero_t(caracteristica)));
    }
    else if(tipo_lectura == "C")        
        return (new Cuento(titulo, string_a_int(minutos), string_a_int(anio),escritor, caracteristica));
    
    else //POEMA    
        return (new Poema(titulo, string_a_int(minutos), string_a_int(anio), escritor, string_a_int(caracteristica)));
}

void Parser :: nueva_lectura(){

    usuario_nueva_lectura ();

    Lectura* lectura = 0;
    
    //Obtengo la posicion del autor en la lista, en caso de existir
    int x = autor_anonimo(referencia_al_autor);

    if ( x == ANONIMO)
        lectura = procesador_entradaL(NULL); // Como x no es una posicion valida, el escritor es anonimo(Puntero a null)
    else
        lectura = procesador_entradaL(escritores->consulta(x));

    lecturas->insercion_ordenada(lectura);
    
}

void Parser :: quitar_lectura( ){
    if(!lecturas->vacia()){
        cout << "Que número de lectura desea quitar de la lista (contando desde arriba hacia abajo) : " << endl;
        cin >> n_lectura_quitar;

        lecturas->baja(string_a_int(n_lectura_quitar));
    }
    else
        cout << "La lista ya se encuentra vacia." << endl;
    
}

void Parser :: agregar_escritor( ){
    
    cout << "Ingrese el nombre del escritor : " << endl;
    cin >> nombre_escritor;

    cout << "Ingrese la nacionalidad del escritor : " << endl;
    cin >> nacionalidad;

    cout << "Ingrese el año de nacimiento del escritor (en caso de desconocerlo, ingrese -1): " << endl;
    cin >> anio_nacimiento;

    cout << "Ingrese el año de fallecimiento del escritor (en caso de no haber fallecido, ingrese -1)" << endl;
    cin >> anio_fallecimiento;

    Escritor* escritor = 0;
    escritor = new Escritor(nombre_escritor, nacionalidad, string_a_int(anio_nacimiento), string_a_int(anio_fallecimiento));

    escritores->alta_ultimo(escritor);
}

void Parser :: cambiar_dato_escritor( ){

    cout << "Ingrese el numero del escritor al que le desea cambiar la fecha de fallecimiento () contando desde arriba hacia abajo: " << endl;
    cin >> referencia_al_autor;

    cout << "Ingrese el año de fallecimiento actualizado : " << endl;
    cin >> anio_fallecimiento;

    Escritor* escritor = escritores->consulta(string_a_int(referencia_al_autor));
    escritor->cambiar_anio_defuncion(string_a_int(anio_fallecimiento));
}

void Parser :: listar_escritores(){
    escritores->listar();
}

int Parser :: random (int min, int max) {
    if (min > max)
        return max;
    return min + (rand() % (max - min + 1));
}

void Parser :: lectura_random( ){
    
    int n_lectura =  (random(0, lecturas->obtener_cantidad()));

    Lectura* lectura = lecturas->consulta(n_lectura);
    cout << "La lectura a leer en las terturlias será : " << lectura->obtener_titulo() << endl;
}

void Parser :: listar_lecturas( ){
    lecturas->listar();
}

void Parser :: listar_lecturas_x_anios( ){

    cout << "Ingrese desde que año desea listar las lecturas : " << endl;
    cin >> anio1;

    cout << "Ingrese hasta que año desea listar las lecturas : " << endl;
    cin >> anio2;

    lecturas->listar(string_a_int(anio1), string_a_int(anio2));
}

void Parser :: listar_lecturas_x_escritor( ){

    cout << "Ingrese el escritor deseado para listar todas sus lecturas : " << endl;
    cin.ignore();
    getline(cin, nombre_escritor);
    

    lecturas->listar(nombre_escritor);
}

void Parser :: listar_novelas_x_genero( ){

    cout << "Ingrese el genero deseado para listar las novelas : " << endl;
    cin.ignore();
    getline(cin, genero);

    genero_t gen = string_a_genero_t(genero);
    lecturas->listar(gen);
}

void Parser :: cola_ordenada(){

}

void Parser :: opcion_seleccionada( ){
    
    bool salir = false;
    int numero = imprimir_menu();
    
    switch(numero){
        case 1: nueva_lectura();
        break;

        case 2: quitar_lectura();
        break;
        
        case 3: agregar_escritor();
        break;
        
        case 4: cambiar_dato_escritor();
        break;
    
        case 5: listar_escritores();
        break;
        
        case 6: lectura_random();
        break;
        
        case 7: listar_lecturas(); 
        break;
        
        case 8: listar_lecturas_x_anios();
        break;
        
        case 9: listar_lecturas_x_escritor();
        break;
        
        case 10: listar_novelas_x_genero();
        break;
        
        case 11: ;//cola_ordenada();
        break;
        
        case 12: 
        salir = true;
        break;

        default: cout << "Usted a ingresado una opción incorrecta" << endl; 
        
    }
    if(!salir)
        opcion_seleccionada();
}

Lista<Escritor*>* Parser::obtener_Lescritores(){
    return escritores;
}

Lista<Lectura*>* Parser::obtener_Llecturas(){
    return lecturas;
}
