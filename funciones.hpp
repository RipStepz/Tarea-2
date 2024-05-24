#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

string invertirString(const string& input);

class super_string {
private:
    struct nodo {
        nodo *left = nullptr, *right = nullptr;
        int index;
        char c;
        nodo(int index, char c) : index(index), c(c), left(nullptr), right(nullptr) {}
        nodo() {}
    };

    struct NodoLista {
    nodo* data;
    NodoLista* next;
    NodoLista(nodo* dataPtr) : data(dataPtr), next(nullptr) {}
    };

    int height = 0; // Altura del árbol
    int length = 0; // Largo del super-string
    nodo* arbol = nullptr; // Raíz del super-string (nodo* root)

public:
    super_string() {}
    void menu(super_string &arbol);
    nodo *crearNodo(int n, char ch);
    void insertarNodo(nodo *& arbol, int index, char c);
    void mostrarArbol(nodo *arbol, int cont);
    bool busqueda(nodo *arbol, int index);
    void eliminar(nodo *&arbol, int index);
    nodo *minimo(nodo *arbol);
    string inOrden(nodo *arbol);
    void EliminarIntervalo(nodo *arbol ,int a, int b);
    void destruirArbol(nodo *&arbol);
    void separar(int i, super_string &a, super_string &b); // Nueva función separar
    void juntar(super_string &a, super_string &b);
    int obtenerIndiceMaximo(nodo *arbol);
    void reverso();
    void recortarArbol();
    nodo* Arbol_Optimizado(nodo** nodes, int start, int end);
    void inordenRecorrido(nodo* current, NodoLista*& head, NodoLista*& tail);
    int listaEnArray(NodoLista* head, nodo**& array);
    void destruirLista(NodoLista* head);
    void INSERTAR(nodo *& arbol, string palabra_a_insertar);
    int alturaArbolBinario(nodo* arbol);
    void actualizarAltura();
    int RECORTAR();
    void ReversarIntervalo(nodo *& arbol, int limite_inferior , int limite_superior);
    void archivo(super_string &arbol, super_string &b);
};
#endif
