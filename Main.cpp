#include "Menu.h"
#include "Grafo.h"

int main(){

    //Cola<Lectura> colaLectura;

    Grafo* grafo = new Grafo;
    Hashing<Escritor*>* tabla_escritor;

    Lector* escritor = new Lector(tabla_escritor, grafo);
    escritor->lectura_archivo_escritores();
    escritor->leer_lectura();
    grafo->completar_matriz_adyacencia();
    grafo->mostrarGrafo();

   Lista<Escritor*>* escritores = escritor->obtener_Lescritores();
   Lista<Lectura*>* lecturas = escritor->obtener_Llecturas();

   //escritores->listar();
   //lecturas->listar();

   //Archivo a1(& escritor, & lecturas , & colaLectura, & tablaEscritor);
   //Menu m1(& escritor, & lecturas, &colaLectura, & tablaEscritor);
  

   Menu* menu = new Menu(lecturas, escritores, tabla_escritor);
   //menu->implementacion_menu();

   lecturas->destruir();
   escritores->destruir();
   
   
   delete escritor;
   delete menu;


   

   return 0;
}