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
        nodo(int index, char c) : index(index), c(c), left(nullptr), right(nullptr) {} //Agregamos este constructor, para inicializar los valores de los nodos de una forma predeterminada cada vez que creamos alguno/{}
        nodo() {}
    };
    // Agregamos el struct NodoLista, para tener una lista enlazada con los nodos del root, esto nos sirve para poder trabajar con el root de forma mas facil.
    struct NodoLista {
    nodo* data;  
    NodoLista* next; 
    NodoLista(nodo* dataPtr) : data(dataPtr), next(nullptr) {}
    };

    int height = 0; 
    int length = 0; 
    nodo* root = nullptr; // Raíz del super-string (nodo* root)

public:
    super_string() {}
    void menu(super_string &root);
    nodo *crearNodo(int n, char ch);
    void insertar(nodo *& root, int index, char c);
    void mostrararbol(nodo *root, int cont);
    bool busqueda(nodo *root, int index);
    void eliminar(nodo *&root, int index);
    nodo *minimo(nodo *root);
    string stringizar(nodo *root);
    void EliminarIntervalo(nodo *root ,int a, int b);
    void limpiar(nodo *&root);
    void separar(int i, super_string &a, super_string &b); 
    void juntar(super_string &a, super_string &b);
    int obtenerIndiceMaximo(nodo *root);
    void reverso();
    void recortararbol();
    nodo* Arbol_Optimizado(nodo** nodes, int start, int end);
    void InOrdenRecorrido(nodo* current, NodoLista*& head, NodoLista*& tail);
    int listaEnArray(NodoLista* head, nodo**& array);
    void destruirLista(NodoLista* head);
    void INSERTAR(nodo *& root, string palabra_a_insertar);
    int altura_arbolBinario(nodo* root);
    void actualizarAltura();
    int RECORTAR();
    void ReversarIntervalo(nodo *& root, int limite_inferior , int limite_superior);
    void agregar(char c);
    void archivo(super_string &root, super_string &b);
};
#endif
