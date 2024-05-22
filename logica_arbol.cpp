#include <iostream>
#include "funciones.hpp"
using namespace std;

//Nodo *arbol = NULL;
 
nodo *arbol = nullptr;

void menu() {
    int dato, opcion, contador = 0;
    char c;
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
        case 1:
            cout << "\nDigite un numero: ";
            cin >> dato;
            cout << "Digite un caracter: ";
            cin >> c;
            insertarNodo(arbol, dato, c);
            cout << "\n";
            break;
        case 2:
            cout << "\nMostrando el arbol completo:\n\n";
            int Pause;
            mostrarArbol(arbol, contador);
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
        case 3:
            cout << "\nDigite el elemento a buscar: ";
            cin >> dato;
            if (busqueda(arbol, dato)) {
                cout << "\nElemento " << dato << " ha sido encontrado en el arbol";
            } else {
                cout << "\nElemento no encontrado";
            }
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
        case 4:
            cout << "\nDigite el numero a eliminar: ";
            cin >> dato;
            eliminar(arbol, dato);
            cout << "\n";
            break;
        }
        system("clear");
    } while (opcion != 5);
}


nodo *crearNodo(int index, char c) {
    return new nodo(index, c);
}

void insertarNodo(nodo *& arbol, int index, char c) {
    if (arbol == nullptr) {
        nodo *nuevo_nodo = crearNodo(index, c);
        arbol = nuevo_nodo;
    } else {
        if (index < arbol->index) {
            insertarNodo(arbol->left, index, c);
        } else {
            insertarNodo(arbol->right, index, c);
        }
    }
}

void mostrarArbol(nodo *arbol, int cont) {
    if (arbol == nullptr) {
        return;
    } else {
        mostrarArbol(arbol->right, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout << "   ";
        }
        cout << arbol->index << " (" << arbol->c << ")" << endl;
        mostrarArbol(arbol->left, cont + 1);
    }
}

bool busqueda(nodo *arbol, int index) {
    if (arbol == nullptr) {
        return false;
    } else if (arbol->index == index) {
        return true;
    } else if (index < arbol->index) {
        return busqueda(arbol->left, index);
    } else {
        return busqueda(arbol->right, index);
    }
}

void eliminar(nodo *&arbol, int index) {
    if (arbol == nullptr) {
        return;
    } else if (index < arbol->index) {
        eliminar(arbol->left, index);
    } else if (index > arbol->index) {
        eliminar(arbol->right, index);
    } else {
        eliminarNodo(arbol);
    }
}

nodo *minimo(nodo *arbol) {
    if (arbol == nullptr) {
        return nullptr;
    }
    if (arbol->left) {
        return minimo(arbol->left);
    } else {
        return arbol;
    }
}

void reemplazar(nodo *arbol, nodo *nuevoNodo) {
    if (arbol->left == nuevoNodo) {
        arbol->left = nuevoNodo;
    } else if (arbol->right == nuevoNodo) {
        arbol->right = nuevoNodo;
    }
    if (nuevoNodo) {
        nuevoNodo->left = arbol->left;
        nuevoNodo->right = arbol->right;
    }
}

void destruirNodo(nodo *nodo) {
    nodo->left = nullptr;
    nodo->right = nullptr;
    delete nodo;
}

void eliminarNodo(nodo *nodoEliminar) {
    if (nodoEliminar->left && nodoEliminar->right) {
        nodo *menor = minimo(nodoEliminar->right);
        nodoEliminar->index = menor->index;
        nodoEliminar->c = menor->c;
        eliminarNodo(menor);
    } else if (nodoEliminar->left) {
        reemplazar(nodoEliminar, nodoEliminar->left);
        destruirNodo(nodoEliminar);
    } else if (nodoEliminar->right) {
        reemplazar(nodoEliminar, nodoEliminar->right);
        destruirNodo(nodoEliminar);
    } else {
        reemplazar(nodoEliminar, nullptr);
        destruirNodo(nodoEliminar);
    }
}