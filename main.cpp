#include <iostream>
#include <fstream> 
#include <stdio.h>
#include <stdlib.h>

#include "funciones.hpp"
using namespace std;

struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

void menu();
Nodo *crearNodo(int,Nodo *);
void insertarNodo(Nodo *&, int,Nodo *);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo * , int);
void eliminar(Nodo *, int);
void eliminarNodo(Nodo*);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);

Nodo *arbol = NULL;

int main(){
    menu();
    cin.get();
    return 0;
}

void menu(){
    int dato, opcion, contador=0;
    do{
        cout<<"\t.:Menu:." << endl;
        cout<<"1. Insertar un nuevo nodo" << endl;
        cout<<"2. Mostrar el arbol completo" << endl;
        cout<<"3. Buscar un elemento del arbol" << endl;
        cout<<"4. Eliminar un nodo del arbol" << endl;
        cout<<"5. Salir" << endl;
        cout<<"Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1: cout<<"\nDigite un numero:";
                cin>> dato;
                insertarNodo(arbol, dato, NULL);
                cout <<"\n";
                system("pause");
                break;
        
        case 2: cout <<"\nMostrando el arbol completo:\n\n";
                mostrarArbol(arbol,contador);
                cout<< "\n";
                system("pause");
                break;
        case 3: cout <<"\nDigite el elemento a buscar: ";
                cin >> dato;
                if(busqueda(arbol , dato) == true){
                    cout<<"\nElemento "<< dato <<" a sudi encontrado en el arbol";
                }
                else{
                    cout << "\nElemento no encontrado \n";
                }
                cout<< "\n";
                system("pause");
                break;
        case 4: cout <<"\nDigite el numero a eliminar: ";
                cin>>dato;
                eliminar(arbol , dato);
                cout<<"\n";
                system("pause");
                break;
        }
        system("cls");
    } while(opcion != 5);
}

Nodo *crearNodo(int n, Nodo *padre){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo-> dato = n;
    nuevo_nodo-> der = NULL;
    nuevo_nodo -> izq = NULL;
    nuevo_nodo -> padre = padre;
    return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
    if(arbol = NULL){
        Nodo *nuevo_nodo = crearNodo(n, padre);
        arbol = nuevo_nodo;
    }
    else{
        int valorRaiz = arbol->dato;
        if(n < valorRaiz){
            insertarNodo(arbol->izq,n, arbol);
        }
        else{
            insertarNodo(arbol->der,n, arbol);
        }
    }
}

void eliminar(Nodo *arbol, int n){
    if(arbol == NULL){
        return;
    }
    else if(n < arbol-> dato){
        eliminar(arbol -> izq,n);
    }
    else if(n > arbol-> dato){
        eliminar(arbol -> der,n);
    }
    else{
        eliminarNodo(arbol);
    }
}

Nodo *minimo(Nodo *arbol){
    if(arbol ==NULL){
        return NULL;
    }
    if(arbol -> izq){
        return minimo(arbol -> izq);
    }
    else{
        return arbol;
    }
}

void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
    if(arbol->padre){
        if(arbol->dato == arbol->padre->izq->dato){
            arbol->padre->izq - nuevoNodo;
        }
        else if(arbol->dato == arbol->padre->der->dato){
            arbol->padre->der = nuevoNodo;
        }  
    }
    if(nuevoNodo){
        nuevoNodo->padre = arbol->padre;
    }
}

void destruirNodo(Nodo *nodo){
    nodo->izq = NULL;
    nodo->der = NULL;

    delete nodo;
}


void eliminarNodo(Nodo *nodoEliminar){
    if(nodoEliminar->izq && nodoEliminar->der){
        Nodo *menor = minimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if(nodoEliminar->izq){
        reemplazar(nodoEliminar,nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }
    else if(nodoEliminar->der){
        reemplazar(nodoEliminar,nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else{
        reemplazar(nodoEliminar,NULL);
        destruirNodo(nodoEliminar);
    }
} 