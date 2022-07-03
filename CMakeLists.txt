cmake_minimum_required(VERSION 3.21)
project(Prueba)

set(CMAKE_CXX_STANDARD 14)

add_executable(Prueba main.cpp
        archivoE.txt archivoL.txt
        cola.h  constantes.h
        cuento.cpp  cuento.h
        escritor.cpp escritor.h
        funciones.cpp   funciones.h
        grafo.cpp   grafo.h
        hashing.h
        historica.h     historica.cpp
        lector2.cpp  lector2.h
        lectura.cpp lectura.h
        lista.h
        lista_grafo.h
        menu.cpp    menu.h
        nodo.h  nodo_grafo.h
        novela.cpp  novela.h
        parser.cpp  parser.h
        poema.cpp   poema.h
        vertice_grafo.cpp   vertice_grafo.h)
