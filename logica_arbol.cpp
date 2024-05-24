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
    if(a!=0){
        a = a-1;
        }
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

void super_string::recortarArbol() {
    
    // Crear una lista enlazada para almacenar los nodos en inorden
    NodoLista* head = nullptr;
    NodoLista* tail = nullptr;

    // Realizar un recorrido en inorden para obtener todos los nodos
    inordenRecorrido(arbol, head, tail);

    // Convertir la lista enlazada a un array dinámico
    nodo** inordenNodes;
    int size = listaEnArray(head, inordenNodes);

    // Limpiar el árbol original antes de reconstruirlo
    destruirArbol(arbol);

    // Construir el árbol optimizado de manera iterativa
    arbol = Arbol_Optimizado(inordenNodes, 0, size - 1);

    // Liberar la memoria de la lista enlazada y del array
    destruirLista(head);
    delete[] inordenNodes;
}

void super_string::inordenRecorrido(nodo* current, NodoLista*& head, NodoLista*& tail) {
    if (current == nullptr) return;

    inordenRecorrido(current->left, head, tail);

    NodoLista* nuevoNodo = new NodoLista(current);
    if (tail == nullptr) {
        head = tail = nuevoNodo;
    } else {
        tail->next = nuevoNodo;
        tail = nuevoNodo;
    }

    inordenRecorrido(current->right, head, tail);
}

int super_string::listaEnArray(NodoLista* head, nodo**& array) {
    // Primero, contar el número de nodos en la lista enlazada
    int size = 0;
    NodoLista* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }

    // Crear un array dinámico del tamaño adecuado
    array = new nodo*[size];
    current = head;
    for (int i = 0; i < size; i++) {
        array[i] = current->data;
        current = current->next;
    }

    return size;
}

void super_string::destruirLista(NodoLista* head) {
    while (head != nullptr) {
        NodoLista* temp = head;
        head = head->next;
        delete temp;
    }
}

super_string::nodo* super_string::Arbol_Optimizado(nodo** nodes, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    nodo* n_Node = nodes[mid];

    // Reconstruir el árbol de manera iterativa
    n_Node->left = Arbol_Optimizado(nodes, start, mid - 1);
    n_Node->right = Arbol_Optimizado(nodes, mid + 1, end);

    return n_Node;
}

int super_string::alturaArbolBinario(nodo* arbol) {
  if (arbol == nullptr) {
    return 0;
  } else {
    int alturaIzquierda = alturaArbolBinario(arbol->left);
    int alturaDerecha = alturaArbolBinario(arbol->right);

    if (alturaIzquierda > alturaDerecha) {
      return alturaIzquierda + 1;
    } else {
      return alturaDerecha + 1;
    }
  }
}

void super_string::actualizarAltura() {
        // Implementa la actualización de la altura del árbol
        // Puedes usar una función recursiva para calcular la altura del árbol
        this->height = alturaArbolBinario(this->arbol);
    }

int super_string::RECORTAR() {
        recortarArbol();
        actualizarAltura();
        cout << height << endl;
        return (height);
}

void super_string::ReversarIntervalo(nodo *& arbol, int limite_inferior , int limite_superior) {
    // Obtener la palabra del árbol
    string palabra_reversar = inOrden(arbol);

    // Separar la palabra en tres partes: antes del intervalo, el intervalo y después del intervalo
    string p1 = palabra_reversar.substr(0, limite_inferior);
    string p2 = palabra_reversar.substr(limite_inferior, limite_superior - limite_inferior + 1);
    string p3 = palabra_reversar.substr(limite_superior + 1);

    // Invertir la parte central
    p2 = invertirString(p2);

    // Concatenar las tres partes en orden inverso
    string retorno = p1 + p2 + p3;

    // Destruir el árbol original
    destruirArbol(arbol);

    // Insertar los caracteres en el árbol
    for (int i = 0; i < retorno.length(); i++) {
        insertarNodo(arbol, i, retorno[i]);
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
        cout << "10. recortar arbol super string" << endl;
        cout << "11. insertar un string" << endl;
        cout << "12. RECORTAR un string" << endl;
        cout << "13. Reversar intervalo de un string" << endl;
        cout << "14. Salir" << endl;
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
            {
                string ingresar;
                cout << "\nIngrese la palabra a ingresar el arbol: \n";
                cin >> ingresar;
                INSERTAR(arbol.arbol , ingresar);
                cout << "\nPresiona cualquier numero para volver al menú...";
                cin >> Pause;
                break; 
            } 
        case 12:
            cout << "\nLa Altura nueva es: \n";
            RECORTAR();
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
        case 13:

            cout << "\ningrese indice inferior:\n";
            cin >> a;
            cout << "\ningrese indice superior:\n";
            cin >> b;
            ReversarIntervalo(arbol.arbol, a , b);
            cout << "\nPresiona cualquier numero para volver al menú...";
            cin >> Pause;
            break;
           
        }
        system("clear");
    } while (opcion != 14);
}