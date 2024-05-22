#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <stdio.h>
#include <string>
using namespace std;

//struct Nodo {
//    int dato;
//    Nodo *der;
//    Nodo *izq;
//    Nodo *padre;
//};
struct nodo {
 nodo *left = nullptr, *right = nullptr;
 int index;
 char c;
 nodo(int index, char c) {}
 nodo(){}
 };

void menu();
void insertarNodo(nodo *&, int, char);
void mostrarArbol(nodo *, int);
bool busqueda(nodo *, int);
void eliminar(nodo *&, int);
void eliminarNodo(nodo *);
nodo *minimo(nodo *);
void reemplazar(nodo *, nodo *);
void destruirNodo(nodo *);

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