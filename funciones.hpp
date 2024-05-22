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

class super_string {
 private:
 struct nodo {
 nodo *left = nullptr, *right = nullptr;
 int index;
 char c;
 nodo(int index, char c) {}
 nodo(){}
 };
 int height = 0; // Altura del árbol
 int length = 0; // Largo del super-string
 nodo* root = nullptr; // Raíz del super-string
 public:
 super_string() {}
 void juntar(super_string &s);
 void agregar(char c); // Insertar un caracter en la última posición
 // En la izquierda esta el super_string a y en la derecha el super_string b
 void separar(int i, super_string &a, super_string &b);
 void reverso(); // No debe cambiar la altura del árbol
 int recortar(); // Retorna this->height después de recortar
 string stringizar(); // Debe ser O(n)
 void limpiar(); // Se deben borrar todos los nodos del super-string
}; 

#endif