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
        cout<<"4. Salir" << endl;
        cout<<"Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1: cout<<"\nDigite un numero:";
                cin>> dato;
                insertarNodo(arbol, dato);
                cout <<"\n";
                system("pause");
                break;
        
        case 2: cout <<"\nMostrando el arbol completo:\n\n";
                mostrarArbol(arbol,contador);
                cout<< "\n";
                system("pause");
                break;
        
        }
    }
}