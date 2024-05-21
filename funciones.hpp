#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <stdio.h>

struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

int filas(float contador);
int columnas (float contador);

#endif