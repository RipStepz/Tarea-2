#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <stdio.h>
#include <string>
using namespace std;


void menu();
// void insertarNodo(nodo *&, int, char);
// void mostrarArbol(nodo *, int);
// bool busqueda(nodo *, int);
// void eliminar(nodo *&, int);
// void eliminarNodo(nodo *);
// nodo *minimo(nodo *);
// void reemplazar(nodo *, nodo *);
// void destruirNodo(nodo *);

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
 nodo* arbol = nullptr; // Raíz del super-string (nodo* root)
 
 nodo *crearNodo(int n, char ch) {
    nodo* nuevo_nodo = new nodo(n, ch);

    nuevo_nodo->index = n;
    nuevo_nodo->c = ch;
    nuevo_nodo->right = nullptr;
    nuevo_nodo->left = nullptr;

    return  nuevo_nodo;
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
            cout << "      ";
        }
        cout <<"(" <<arbol->index <<", " <<arbol->c << ")" << endl;
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
    }

    if (index < arbol->index) {
        eliminar(arbol->left, index);
    } else if (index > arbol->index) {
        eliminar(arbol->right, index);
    } else {
        if (arbol->left == nullptr) {
            nodo *temp = arbol->right;
            delete arbol;
            arbol = temp;
        } else if (arbol->right == nullptr) {
            nodo *temp = arbol->left;
            delete arbol;
            arbol = temp;
        } else {
            nodo *sucesor = minimo(arbol->right);
            arbol->index = sucesor->index;
            arbol->c = sucesor->c;
            eliminar(arbol->right, sucesor->index);
        }
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
 public:
 super_string() {}
 void insertar (char c){
    insertarNodo(arbol, height++, c);
 }
 void mostrar(){
    mostrarArbol(arbol,0);
    cout<<endl;
 }
 void eliminar_n(int index){
    eliminar(arbol, index);
 }
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
 //void juntar(super_string &s);
 //void agregar(char c); // Insertar un caracter en la última posición
 // En la izquierda esta el super_string a y en la derecha el super_string b
 //void separar(int i, super_string &a, super_string &b);
 //void reverso(); // No debe cambiar la altura del árbol
 //int recortar(); // Retorna this->height después de recortar
 //string stringizar(); // Debe ser O(n)
 //void limpiar(); // Se deben borrar todos los nodos del super-string
}; 

#endif