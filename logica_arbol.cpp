#include <iostream>
#include "funciones.hpp"
using namespace std;

super_string::nodo *super_string::crearNodo(int n, char ch) {
    nodo* nuevo_nodo = new nodo(n, ch);
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

string super_string::inOrden(nodo *arbol) {
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

void super_string::EliminarIntervalo(nodo *arbol ,int a, int b){
    while (a <= b) {
        eliminar(arbol, a);
        a += 1;
    } 
}

void super_string::destruirArbol(nodo *&arbol) {
    if (arbol != nullptr) {
        destruirArbol(arbol->left);
        destruirArbol(arbol->right);
        delete arbol;
        arbol = nullptr;
    }
}

void super_string::separar(int i, super_string &a, super_string &b) {
    // Recorta el árbol original para que contenga solo los primeros 'i' caracteres
    b.destruirArbol(b.arbol); // Limpiar el árbol 'b' antes de asignarle nuevos nodos
    
    string s = inOrden(arbol);
    string left_part = s.substr(0, i);
    string right_part = s.substr(i);

    // Modificar el árbol original para contener solo los primeros 'i' caracteres
    destruirArbol(arbol); // Limpiar el árbol original antes de asignarle nuevos nodos
    for (int j = 0; j < left_part.length(); j++) {
        insertarNodo(arbol, j, left_part[j]);
    }

    // Insertar los caracteres restantes en el árbol 'b'
    for (int j = 0; j < right_part.length(); j++) {
        b.insertarNodo(b.arbol, j, right_part[j]);
    }
}

int super_string::obtenerIndiceMaximo(nodo *arbol) {
    if (arbol == nullptr) return -1; // Si el árbol está vacío, devuelve -1

    // Recorre el árbol hacia la derecha para encontrar el nodo con el índice más alto
    while (arbol->right != nullptr) {
        arbol = arbol->right;
    }

    return arbol->index; // Devuelve el índice del nodo más a la derecha
}


void super_string::juntar(super_string &parteRecortada, super_string &parteSobrante) {
    if (parteRecortada.arbol == nullptr) return;
    
    // Obtén el índice más alto del árbol original
    int indiceMaximo = obtenerIndiceMaximo(arbol);
    
    // Obtén el string inorden de la parte sobrante
    string parteSobranteString = parteSobrante.inOrden(parteSobrante.arbol);
    
    // Inserta cada nodo de la parte sobrante en el árbol original
    for (char ch : parteSobranteString) {
        insertarNodo(arbol, ++indiceMaximo, ch); // Incrementa el índice máximo antes de insertar el nodo
    }
}

string invertirString(const string& input) {
    string reversed = input;
    int n = reversed.length();
    for (int i = 0; i < n / 2; ++i) {
        // Intercambiar los caracteres en las posiciones i y n-i-1
        char temp = reversed[i];
        reversed[i] = reversed[n - i - 1];
        reversed[n - i - 1] = temp;
    }
    return reversed;
}

void super_string::reverso() {
    // Llenar una pila con los nodos del árbol original
    cout <<"la palabra a reversar es: "<< inOrden(arbol);
    string palabra_invertida = invertirString(inOrden(arbol));
    cout<<"\nLa palabra invertida es: " <<palabra_invertida;
    destruirArbol(arbol);
    int largo = palabra_invertida.length();
    for (int i = 0; i < largo; i++)
    {
        insertarNodo(arbol, i, palabra_invertida[i]);
    }
    
}

void super_string::recortarArbol() {
    // Crear un vector para almacenar los nodos en inorden
    vector<nodo*> inordenNodes;
    
    // Realizar un recorrido en inorden para obtener todos los nodos
    stack<nodo*> stack;
    nodo* current = arbol;
    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }
        current = stack.top();
        stack.pop();
        inordenNodes.push_back(current);
        current = current->right;
    }
    
    // Limpiar el árbol original antes de reconstruirlo
    destruirArbol(arbol);
    
    // Construir el árbol optimizado de manera iterativa
    int n = inordenNodes.size();
    arbol = Arbol_Optimizado(inordenNodes, 0, n - 1);
}

super_string::nodo* super_string::Arbol_Optimizado(const vector<nodo*>& nodes, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2; // Calcular el índice medio
    nodo* n_Node = nodes[mid];

    // Reconstruir el árbol de manera iterativa
    n_Node->left = Arbol_Optimizado(nodes, start, mid - 1);
    n_Node->right = Arbol_Optimizado(nodes, mid + 1, end);

    return n_Node;
}

void super_string::INSERTAR(nodo *& arbol, string palabra_a_insertar){  
    if(arbol == nullptr){
        for (int i = 0; i < palabra_a_insertar.length(); i++)
        {
            insertarNodo(arbol,i, palabra_a_insertar[i]);
        }
    }
    else{
        string ObtenerIndice = inOrden(arbol);
        int indiceInferior = ObtenerIndice.length() -1;
        int indiceSuperior = indiceInferior + palabra_a_insertar.length();
        int c = 0;
        for (int i = indiceInferior; i < indiceSuperior; i++)
        {
            insertarNodo(arbol,i,palabra_a_insertar[c]);
            c++;
        }
        
    }
}


void super_string::menu(super_string &arbol) {
    int dato, opcion, contador = 0;
    char c;
    super_string s1, s2;
    do {
        cout << "\t.:Menu:." << endl;
        cout << "1. Insertar un nuevo nodo" << endl;
        cout << "2. Mostrar el arbol completo" << endl;
        cout << "3. Buscar un elemento del arbol" << endl;
        cout << "4. Eliminar un nodo del arbol" << endl;
        cout << "5. Recorrer el arbol en In-Orden" << endl;
        cout << "6. Eliminar intervalo" << endl;
        cout << "7. Separar super-string" << endl;
        cout << "8. Juntar super string" << endl;
        cout << "9. Revertir super string" << endl;
        cout << "10. recortar super string" << endl;
        cout << "11. insertar un string" << endl;
        cout << "12. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "\nDigite un numero: ";
            cin >> dato;
            cout << "Digite un caracter: ";
            cin >> c;
            arbol.insertarNodo(arbol.arbol, dato, c); 
            cout << "\n";
            break;
        case 2:
            cout << "\nMostrando el arbol completo:\n\n";
            int Pause;
            arbol.mostrarArbol(arbol.arbol, contador); 
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
        case 3:
            cout << "\nDigite el elemento a buscar: ";
            cin >> dato;
            if (arbol.busqueda(arbol.arbol, dato)) { 
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
            arbol.eliminar(arbol.arbol, dato); 
            cout << "\n";
            break;
        case 5:
            cout <<"\nRecorrido en InOrden: "<< inOrden(arbol.arbol);
            cout<<"\n\n";
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
        case 6:
            int a, b;
            cout<<"\nDigite el primer digito: ";
            cin >> a;
            cout<<"\nDigite el segundo digito: ";
            cin>> b;
            arbol.EliminarIntervalo(arbol.arbol, a, b);        
            break;
        case 7:
            int pos;
            cout << "\nDigite la posicion para separar: ";
            cin >> pos;
            arbol.separar(pos, s1, s2);
            cout << "\nParte izquierda: " << inOrden(arbol.arbol);
            cout << "\nParte derecha: " << inOrden(s2.arbol);
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
        case 8:
            cout << "\nJuntando árboles...\n";
            arbol.juntar(arbol, s2); // Juntar la parte recortada (s1) con la parte sobrante (s2)
            cout << "Árbol resultante:\n";
            arbol.mostrarArbol(arbol.arbol, contador); // Mostrar el árbol completo
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
        case 9:
            cout << "\nReversando el super-string...\n";
            arbol.reverso();
            cout << "Super-string reversado:\n";
            arbol.mostrarArbol(arbol.arbol, contador);
            cout << "\nPresiona cualquier número para volver al menú...";
            cin >> Pause;
            break;
        case 10:
            cout << "\nRecortando el árbol...\n";
            arbol.recortarArbol(); // Llama a la función recortarArbol
            cout << "Árbol recortado:\n";
            arbol.mostrarArbol(arbol.arbol, contador);
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
        case 11:
            string ingresar;
            cout << "\nIngrese la palabra a ingresar el arbol: \n";
            cin >> ingresar;
            INSERTAR(arbol.arbol , ingresar);
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;     
        }
        system("clear");
    } while (opcion != 12);
}