#include "Menu.h"

Menu :: Menu(Lista <Lectura*>* lista_lectura, Lista <Escritor*>* lista_escritor, Hashing<Escritor*>* escritor_hashing){
    escritores = lista_escritor;
    lecturas = lista_lectura;
    this->escritor_hashing = escritor_hashing;
}

Menu:: ~Menu(){}

Lectura* Menu::procesador_entradaL(Escritor* escritor){

    if(tipo_lectura == "N"){
        if(caracteristica == "HISTORICA")
            return (new Historica(tipo_lectura, titulo, stoi(minutos), stoi(anio), escritor, string_a_genero_t(caracteristica), tema));
        else
            return (new Novela(tipo_lectura, titulo, stoi(minutos), stoi(anio), escritor, string_a_genero_t(caracteristica)));
    }
    else if(tipo_lectura == "C")
        return (new Cuento(tipo_lectura, titulo, stoi(minutos), stoi(anio),escritor, caracteristica));

    else //POEMA
        return (new Poema(tipo_lectura, titulo, stoi(minutos), stoi(anio), escritor, stoi(caracteristica)));
}

void Menu :: nueva_lectura(){

    menu_1(&tipo_lectura, &titulo, &minutos, &anio, &caracteristica, &tema, &referencia_al_autor);

    Lectura* lectura = 0;

    if ( stoi(referencia_al_autor) == ANONIMO)
        lectura = procesador_entradaL(NULL); // Como x no es una posicion valida, el escritor es anonimo(Puntero a null)
    else
        lectura = procesador_entradaL(escritores->consulta(stoi(referencia_al_autor)));

    lecturas->insercion_ordenada(lectura);

}

void Menu :: quitar_lectura( ){
    if(!lecturas->vacia()){
        menu_2(&n_lectura_quitar);

        lecturas->baja(stoi(n_lectura_quitar));
    }
    else
        cout << "La lista ya se encuentra vacia." << endl;

}

void Menu :: agregar_escritor( ){

    menu_3(&referencia_al_autor, &nombre_escritor, &nacionalidad, &anio_nacimiento, &anio_fallecimiento);

    Escritor* escritor = 0;
    escritor = new Escritor(nombre_escritor, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento), stoi(referencia_al_autor));

    escritores->alta_ultimo(escritor);
}

void Menu :: cambiar_dato_escritor( ){

    menu_4(&referencia_al_autor, &anio_fallecimiento);

    Escritor* escritor = escritores->consulta(stoi(referencia_al_autor));
    escritor->cambiar_anio_defuncion(stoi(anio_fallecimiento));
}

void Menu :: listar_escritores(){
    escritores->listar();
}

int Menu :: random (int min, int max) {
    if (min > max)
        return max;
    return min + (rand() % (max - min + 1));
}

void Menu :: lectura_random( ){

    int n_lectura =  (random(0, lecturas->obtener_cantidad()));

    Lectura* lectura = lecturas->consulta(n_lectura);
    cout << "La lectura a leer en las terturlias será : " << lectura->obtener_titulo() << endl;
}

void Menu :: listar_lecturas( ){
    lecturas->listar();
}

void Menu :: listar_lecturas_x_anios( ){

    menu_8(&anio1, &anio2);

    lecturas->listar(stoi(anio1), stoi(anio2));
}

void Menu :: listar_lecturas_x_escritor( ){

    menu_9(&nombre_escritor);

    lecturas->listar(nombre_escritor);
}

void Menu :: listar_novelas_x_genero( ){

    menu_10(&caracteristica);

    genero_t gen = string_a_genero_t(tema);
    lecturas->listar(gen);
}

void Menu :: cola_ordenada(){

}

void Menu :: mostrar_hashing() {
    /*
    for (int i = 0; i <= TAMANIO; i++){
        cout << i << ")";
        escritorHashing->mostrarHashing(i)->mostrarDatos();
    }*/
    //escritor_hashing->mostrar_hashing();
}

void Menu :: implementacion_menu(){

    imprimir_menu();
    ingresar_numero(&numero);

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

        case 12: mostrar_hashing();
            break;

        case 13: salir = true;
            break;

        default: cout << "Usted a ingresado una opción incorrecta" << endl;

    }
    if(!salir)
        implementacion_menu();
}

Lista<Escritor*>* Menu::obtener_Lescritores(){
    return escritores;
}

Lista<Lectura*>* Menu::obtener_Llecturas(){
    return lecturas;
}