#include "Menu.h"
#include "Grafo.h"
#include "Prim.h"

int main(){

    //Cola<Lectura> colaLectura;

    Grafo* grafo = new Grafo;
    Hashing<Escritor*>* tabla_escritor;

    Lector* escritor = new Lector(tabla_escritor, grafo);
    escritor->lectura_archivo_escritores();
    escritor->leer_lectura();
    grafo->completar_matriz_adyacencia();
    //grafo->mostrarGrafo();//

   Lista<Escritor*>* escritores = escritor->obtener_Lescritores();
   Lista<Lectura*>* lecturas = escritor->obtener_Llecturas();
   Hashing<Escritor>* tabla_hashing = escritor->obtener_tabla();
   //escritores->listar();
   //lecturas->listar();

   //Archivo a1(& escritor, & lecturas , & colaLectura, & tablaEscritor);
   //Menu m1(& escritor, & lecturas, &colaLectura, & tablaEscritor);
  

   Menu* menu = new Menu(escritores, tabla_escritor, grafo);
   //menu->implementacion_menu();

    //Prim* prim = new Prim(grafo->obtener_matriz_adyacencia(), grafo->obtener_vertices_totales());
   //prim->tiempo_lectura_minimo();
   //grafo->tiempo_lectura_minimo();//

   //Escritor* escritor_ = new Escritor("nombre_escritor", "nacionalidad", 2000 , 3000, 1234);
   //Lectura* lectura_ = new Cuento("C", "titulo", 3, 2001, escritor_, "TERROR");
   //grafo->alta(lectura_);
   grafo->mostrarGrafo();
   grafo->tiempo_lectura_minimo();

   grafo->baja("Una columna de fuego");
   grafo->mostrarGrafo();
   grafo->tiempo_lectura_minimo();

   lecturas->destruir();
   escritores->destruir();
   
   
   delete escritor;
   delete menu;
   delete grafo;


   return 0;
}
