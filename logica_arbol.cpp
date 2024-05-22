#include <iostream>
#include "funciones.hpp"
using namespace std;

Nodo *arbol = NULL;

void menu() {
    int dato, opcion, contador = 0;
    do {
        cout << "\t.:Menu:." << endl;
        cout << "1. Insertar un nuevo nodo" << endl;
        cout << "2. Mostrar el arbol completo" << endl;
        cout << "3. Buscar un elemento del arbol" << endl;
        cout << "4. Eliminar un nodo del arbol" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: cout << "\nDigite un numero: ";
                cin >> dato;
                insertarNodo(arbol, dato, NULL);
                cout << "\n";
                break;
        case 2: cout << "\nMostrando el arbol completo:\n\n";
                int Pause;
                mostrarArbol(arbol, contador);
                cout << "\nPresiona cualquier numero para volver al menú...";
                cin >> Pause;
                break;

        case 3: cout << "\nDigite el elemento a buscar: ";
                cin >> dato;
                if (busqueda(arbol, dato)) {
                    cout << "\nElemento " << dato << " ha sido encontrado en el arbol";
                } else {
                    cout << "\nElemento no encontrado";
                }
                cout << "\nPresiona cualquier numero para volver al menú...";
                cin >> Pause;
                break;
        case 4: cout << "\nDigite el numero a eliminar: ";
                cin >> dato;
                eliminar(arbol, dato);
                cout << "\n";
                break;
        }
        system("clear");
    } while (opcion != 5);
}

Nodo *crearNodo(int n, Nodo *padre) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;
    return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *padre) {
    if (arbol == NULL) {  // Corrección: comparación en lugar de asignación
        Nodo *nuevo_nodo = crearNodo(n, padre);
        arbol = nuevo_nodo;
    } else {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz) {
            insertarNodo(arbol->izq, n, arbol);
        } else {
            insertarNodo(arbol->der, n, arbol);
        }
    }
}

void mostrarArbol(Nodo *arbol, int cont) {
    if (arbol == NULL) {
        return;
    } else {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont + 1);
    }
}



bool busqueda(Nodo *arbol, int n) {
    if (arbol == NULL) {
        return false;
    } else if (arbol->dato == n) {
        return true;
    } else if (n < arbol->dato) {
        return busqueda(arbol->izq, n);
    } else {
        return busqueda(arbol->der, n);
    }
}

void eliminar(Nodo *&arbol, int n) {
    if (arbol == NULL) {
        return;
    } else if (n < arbol->dato) {
        eliminar(arbol->izq, n);
    } else if (n > arbol->dato) {
        eliminar(arbol->der, n);
    } else {
        eliminarNodo(arbol);
    }
}

Nodo *minimo(Nodo *arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->izq) {
        return minimo(arbol->izq);
    } else {
        return arbol;
    }
}

void reemplazar(Nodo *arbol, Nodo *nuevoNodo) {
    if (arbol->padre) {
        if (arbol->dato == arbol->padre->izq->dato) {
            arbol->padre->izq = nuevoNodo;  // Corrección: asignación correcta
        } else if (arbol->dato == arbol->padre->der->dato) {
            arbol->padre->der = nuevoNodo;  // Corrección: asignación correcta
        }
    }
    if (nuevoNodo) {
        nuevoNodo->padre = arbol->padre;
    }
}

void destruirNodo(Nodo *nodo) {
    nodo->izq = NULL;
    nodo->der = NULL;
    delete nodo;
}

void eliminarNodo(Nodo *nodoEliminar) {
    if (nodoEliminar->izq && nodoEliminar->der) {
        Nodo *menor = minimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    } else if (nodoEliminar->izq) {
        reemplazar(nodoEliminar, nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    } else if (nodoEliminar->der) {
        reemplazar(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    } else {
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}

string stringizar();