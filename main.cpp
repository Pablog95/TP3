#include "parser.h"

int main(){
   
   Lector* escritor = new Lector;

   escritor->lectura_archivo_escritores();
   escritor->leer_lectura();

   Lista<Escritor*>* escritores = escritor->obtener_Lescritores();
   Lista<Lectura*>* lecturas = escritor->obtener_Llecturas();
   
   //escritores->listar();
   //lecturas->listar();
  

   Parser* parser = new Parser(lecturas, escritores);
   parser->opcion_seleccionada();

   lecturas->destruir();
   escritores->destruir();
   
   
   delete escritor;
   delete parser;
   

   

   return 0;
}