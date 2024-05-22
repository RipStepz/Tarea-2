#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <stdio.h>

struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

void menu();
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void eliminar(Nodo *&, int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);

#endif