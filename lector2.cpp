#include "lector2.h"

Lector :: Lector(){
    lista_escritores = new Lista <Escritor*>;
    lista_lecturas = new Lista <Lectura*>;
    
}

Lector :: ~Lector(){
    lista_lecturas->destruir();
    lista_escritores->destruir();
    
    delete lista_escritores;
    delete lista_lecturas;

    archivo_lecturas.close();
    archivo_escritores.close();
}

void Lector :: completar_informacion_escritura(){
    
    if(getline(archivo_escritores, anio_nacimiento) && anio_nacimiento != ""){
        
        if(getline(archivo_escritores, anio_fallecimiento) && anio_fallecimiento != ""){
            
            if(anio_nacimiento != "-1")
                getline(archivo_escritores, espacio);
            else
                getline(archivo_escritores, espacio);
        }
        else
            anio_fallecimiento = "-1";                
    }
    else{
        anio_nacimiento = "-1";
        anio_fallecimiento = "-1";
    }
}

void Lector :: lectura_archivo_escritores( ){

    archivo_escritores.open("archivoE.h");
    

    if (!archivo_escritores)
        cout << "El archivo no se pudo abrir porque no se encuentra o está dañado" << endl;

    else{
        
        while(getline(archivo_escritores, n_escritor)){

            getline(archivo_escritores, nombre_escritor);
            getline(archivo_escritores, nacionalidad);

            completar_informacion_escritura();
    
            Escritor* escritor = new Escritor(nombre_escritor, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento), stoi(n_escritor));
            
            lista_escritores->alta_ultimo(escritor);  
                     
        }
    }
} 

//tipo_lectura es si o si correcta : NOVELA, CUENTO, POEMA
Lectura* Lector::procesador_entrada_lecturas(Escritor* escritor){


    if(tipo_lectura == "N"){
        if(caracteristica == "HISTORICA") {
            return (new Historica(tipo_lectura,titulo, stoi(minutos), stoi(anio), escritor, string_a_genero_t(caracteristica),tema));
        }
        else

            return (new Novela(tipo_lectura, titulo, stoi(minutos), stoi(anio), escritor, string_a_genero_t(caracteristica)));
    }
    else if(tipo_lectura == "C")        
        return (new Cuento(tipo_lectura, titulo, stoi(minutos), stoi(anio),escritor, caracteristica));
    
    else //POEMA    
        return (new Poema(tipo_lectura, titulo, stoi(minutos), stoi(anio), escritor, stoi(caracteristica)));
}

//no hay archivo vacio
void Lector :: leer_lectura(){
    
    archivo_lecturas.open("archivoL.h");

    if (!archivo_lecturas)
        cout << "El archivo no se pudo abrir porque no se encuentra o está dañado" << endl;

    else{

        Lectura* lectura = 0;

        while(getline(archivo_lecturas, tipo_lectura)){

            getline(archivo_lecturas, titulo);
            getline(archivo_lecturas, minutos);
            getline(archivo_lecturas, anio);
            getline(archivo_lecturas, caracteristica);

            if(caracteristica == "HISTORICA")
                getline(archivo_lecturas, tema);

            getline(archivo_lecturas, referencia_al_autor);

            lectura = procesador_entrada_lecturas(lista_escritores->consulta(autor_anonimo(referencia_al_autor)));

            getline(archivo_lecturas, espacio);

            //lista_lecturas->insercion_ordenada(lectura);
        }
    }
}

int  Lector :: autor_anonimo( string referencia_al_autor) {

    if (referencia_al_autor == "ANONIMO"){
        return (ANONIMO);
    }
    else{
        return (stoi(referencia_al_autor));
    }
}


Lista<Escritor*>* Lector::obtener_Lescritores(){
    return lista_escritores;
}

Lista<Lectura*>* Lector::obtener_Llecturas(){
    return lista_lecturas;
}
