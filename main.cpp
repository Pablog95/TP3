#include "menu.h"

int main(){
   
   Lector* escritor = new Lector;

   escritor->lectura_archivo_escritores();
   escritor->leer_lectura();

   Lista<Escritor*>* escritores = escritor->obtener_Lescritores();
   Lista<Lectura*>* lecturas = escritor->obtener_Llecturas();
   
   //escritores->listar();
   //lecturas->listar();
  

   Menu* menu = new Menu(lecturas, escritores);
   menu->implementacion_menu();

   lecturas->destruir();
   escritores->destruir();
   
   
   delete escritor;
   delete menu;
   

   

   return 0;
}