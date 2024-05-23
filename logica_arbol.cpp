#include <iostream>
#include "funciones.hpp"
using namespace std;


super_string::nodo *super_string::crearNodo(int n, char ch) {
    nodo* nuevo_nodo = new nodo(n, ch);

    nuevo_nodo->index = n;
    nuevo_nodo->c = ch;
    nuevo_nodo->right = nullptr;
    nuevo_nodo->left = nullptr;

    return  nuevo_nodo;
}

void super_string::insertarNodo(nodo *& arbol, int index, char c) {
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

void super_string::mostrarArbol(nodo *arbol, int cont) {
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

bool super_string::busqueda(nodo *arbol, int index) {
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

void super_string::eliminar(nodo *&arbol, int index) {
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

super_string::nodo *super_string::minimo(nodo *arbol) {
    if (arbol == nullptr) {
        return nullptr;
    }
    if (arbol->left) {
        return minimo(arbol->left);
    } else {
        return arbol;
    }
}
string inOrden(nodo *arbol) {
    string resultado = "";
    if (arbol == nullptr) {
        return resultado;
    } else {
        resultado += inOrden(arbol->left);
        resultado += arbol->c;
        resultado += inOrden(arbol->right);
        return resultado;
    }
}

void EliminarIntervalo(nodo *arbol ,int a, int b){
    while (a <= b)
    {
        eliminar(arbol, a);
        a +=1;
    } 
}

void super_string::menu(super_string &arbol) {
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
            arbol.insertarNodo(arbol.arbol, dato, c); // Cambiar arbol->insertarNodo por arbol.insertarNodo
            cout << "\n";
            break;
        case 2:
            cout << "\nMostrando el arbol completo:\n\n";
            int Pause;
            arbol.mostrarArbol(arbol.arbol, contador); // Cambiar arbol->mostrarArbol por arbol.mostrarArbol
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
        case 3:
            cout << "\nDigite el elemento a buscar: ";
            cin >> dato;
            if (arbol.busqueda(arbol.arbol, dato)) { // Cambiar arbol->busqueda por arbol.busqueda
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
            arbol.eliminar(arbol.arbol, dato); // Cambiar arbol->eliminar por arbol.eliminar
            cout << "\n";
            break;
        case 5:
            cout <<"\nRecorrido en InOrden: "<< inOrden(arbol);
            cout<<"\n\n";
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
        case 6:
            int a, b;
            cout<<"\n digite el primer digito: ";
            cin >> a;
            cout<<"\n digite el segundo digito: ";
            cin>> b;
            EliminarIntervalo(arbol ,a ,b );
        }
        system("clear");
    } while (opcion != 7);
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
        cout << "5. Recorrer el arbol en PreOrden"<<endl;
        cout <<"6. Eliminar Intervalo"<<endl;
        cout << "7. Salir" << endl;
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
        case 5:
            cout <<"\nRecorrido en InOrden: "<< inOrden(arbol);
            cout<<"\n\n";
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
        case 6:
            int a, b;
            cout<<"\n digite el primer digito: ";
            cin >> a;
            cout<<"\n digite el segundo digito: ";
            cin>> b;
            EliminarIntervalo(arbol ,a ,b );
            
        }
        system("clear");
    } while (opcion != 7);
  }