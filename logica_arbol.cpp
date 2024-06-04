#include <iostream>
#include "funciones.hpp"
using namespace std;

/*****
* super_string::nodo* super_string::crearNodo
******
* Crea un nuevo nodo del árbol binario con el valor y el carácter especificados.
******
* Input:
* int n : Valor del nodo.
* char ch : Carácter del nodo.
******
* Returns:
* super_string::nodo* : Puntero al nuevo nodo creado.
*****/

super_string::nodo *super_string::crearNodo(int n, char ch) {
    nodo* nuevo_nodo = new nodo(n, ch);
    return  nuevo_nodo;
}

/*****
* void super_string::insertar
******
* Inserta un nuevo nodo en un árbol binario ordenado según el índice, donde los valores menores están a la izquierda y los mayores a la derecha.
******
* Input:
* nodo*& root : Referencia al puntero al nodo raíz del árbol binario en el que se va a insertar el nuevo nodo.
* int index : Índice del nuevo nodo a insertar.
* char c : Carácter del nuevo nodo a insertar.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::insertar(nodo *& root, int index, char c) {
    if (root == nullptr) {
        nodo *nuevo_nodo = crearNodo(index, c);
        root = nuevo_nodo;
    } else {
        if (index < root->index) {
            insertar(root->left, index, c);
        } else {
            insertar(root->right, index, c);
        }
    }
}

/*****
* void super_string::mostrararbol
******
* Muestra el árbol binario de forma visual, con los nodos ordenados según el índice.
******
* Input:
* nodo* root : Puntero al nodo raíz del árbol binario que se va a mostrar.
* int cont : Variable que lleva la cuenta de la profundidad del nodo actual en el árbol (utilizada para la indentación).
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::mostrararbol(nodo *root, int cont) {
    if (root == nullptr) {
        return;
    } else {
        mostrararbol(root->right, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout << "      ";
        }
        cout <<"(" <<root->index <<", " <<root->c << ")" << endl;
        mostrararbol(root->left, cont + 1);
    }
}

// bool super_string::busqueda(nodo *root, int index) {
//     if (root == nullptr) {
//         return false;
//     } else if (root->index == index) {
//         return true;
//     } else if (index < root->index) {
//         return busqueda(root->left, index);
//     } else {
//         return busqueda(root->right, index);
//     }
// }

/*****
* void super_string::eliminar
******
* Elimina un nodo con un índice específico de un árbol binario ordenado manteniendo la estructura del árbol.
******
* Input:
* nodo*& root : Referencia al puntero al nodo raíz del árbol binario del cual se eliminará el nodo.
* int index : Índice del nodo que se desea eliminar del árbol.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::eliminar(nodo *&root, int index) {
    if (root == nullptr) {
        return;
    }
    if (index < root->index) {
        eliminar(root->left, index);
    } else if (index > root->index) {
        eliminar(root->right, index);
    } else {
        if (root->left == nullptr) {
            nodo *temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == nullptr) {
            nodo *temp = root->left;
            delete root;
            root = temp;
        } else {
            nodo *sucesor = minimo(root->right);
            root->index = sucesor->index;
            root->c = sucesor->c;
            eliminar(root->right, sucesor->index);
        }
    }
}

/*****
* super_string::nodo* super_string::minimo
******
* Encuentra el nodo con el índice mínimo en un subárbol dado.
******
* Input:
* nodo* root : Puntero al nodo raíz del subárbol en el que se va a buscar el nodo con el índice mínimo.
******
* Returns:
* super_string::nodo* : Puntero al nodo con el índice mínimo encontrado en el subárbol. Si el subárbol está vacío, devuelve nullptr.
*****/

super_string::nodo *super_string::minimo(nodo *root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->left) {
        return minimo(root->left);
    } else {
        return root;
    }
}

/*****
* string super_string::stringizar
******
* Realiza un recorrido en orden (inorden) de un árbol binario, concatenando los caracteres de los nodos en un string.
******
* Input:
* nodo* root : Puntero al nodo raíz del árbol binario que se va a recorrer.
******
* Returns:
* string : String que contiene los caracteres concatenados en el orden stringizar del árbol binario.
*****/

string super_string::stringizar(nodo *root) {
    string resultado = "";
    if (root == nullptr) {
        return resultado;
    } else {
        resultado += stringizar(root->left);
        resultado += root->c;
        resultado += stringizar(root->right);
        return resultado;
    }
}

/*****
* void super_string::EliminarIntervalo
******
* Elimina los nodos con índices dentro de un intervalo [a, b] en un árbol binario.
******
* Input:
* nodo* root : Puntero al nodo raíz del árbol binario del cual se eliminarán los nodos.
* int a : Índice inicial del intervalo.
* int b : Índice final del intervalo.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::EliminarIntervalo(nodo *root ,int a, int b){
    if(a!=0){
        a = a-1;
        }
    while (a <= b) {
        eliminar(root, a);
        a += 1;
    } 
}

/*****
* void super_string::limpiar
******
* Libera la memoria ocupada por todos los nodos de un árbol binario, realizando un recorrido en postorden.
******
* Input:
* nodo*& root : Referencia al puntero al nodo raíz del árbol binario que se va a destruir.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::limpiar(nodo *&root) {
    if (root != nullptr) {
        limpiar(root->left);
        limpiar(root->right);
        delete root;
        root = nullptr;
    }
}

/*****
* void super_string::separar
******
* Separa el árbol binario en dos árboles diferentes en función del índice especificado 'i'.
******
* Input:
* int i : Índice en el cual se separará el árbol original para crear dos árboles diferentes.
* super_string& a : Referencia a un objeto `super_string` que almacenará los primeros 'i' caracteres del árbol original.
* super_string& b : Referencia a un objeto `super_string` que almacenará los caracteres restantes del árbol original después del índice 'i'.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::separar(int i, super_string &a, super_string &b) {
    b.limpiar(b.root); 
    
    string s = stringizar(root);
    string left_part = s.substr(0, i);
    string right_part = s.substr(i);

    limpiar(root); 
    for (int j = 0; j < left_part.length(); j++) {
        insertar(root, j, left_part[j]);
    }

    for (int j = 0; j < right_part.length(); j++) {
        b.insertar(b.root, j, right_part[j]);
    }
}

/*****
* int super_string::obtenerIndiceMaximo
******
* Obtiene el índice máximo almacenado en un árbol binario. Si el árbol está vacío, devuelve -1.
******
* Input:
* nodo* root : Puntero al nodo raíz del árbol binario del cual se va a obtener el índice máximo.
******
* Returns:
* int : El índice máximo encontrado en el árbol binario. Si el árbol está vacío, devuelve -1.
*****/

int super_string::obtenerIndiceMaximo(nodo *root) {
    if (root == nullptr) return -1; 

    while (root->right != nullptr) {
        root = root->right;
    }

    return root->index; 
}

/*****
* void super_string::juntar
******
* Une dos árboles binarios en uno solo. Inserta los nodos de la parte sobrante en el árbol original después del último índice.
******
* Input:
* super_string& parteRecortada : Referencia a un objeto `super_string` que representa la parte recortada del árbol original. No se realiza ninguna acción si la parte recortada está vacía.
* super_string& parteSobrante : Referencia a un objeto `super_string` que representa la parte sobrante que se unirá al árbol original.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::juntar(super_string &parteRecortada, super_string &parteSobrante) {
    if (parteRecortada.root == nullptr) return;
    
    int indiceMaximo = obtenerIndiceMaximo(root);
    
    string parteSobranteString = parteSobrante.stringizar(parteSobrante.root);
    
    for (char ch : parteSobranteString) {
        insertar(root, ++indiceMaximo, ch);
    }
}

/*****
* string invertirString
******
* Invierte el orden de los caracteres en una cadena de texto.
******
* Input:
* const string& input : Cadena de texto que se desea invertir.
******
* Returns:
* string : Cadena de texto con el orden de caracteres invertido.
*****/

string invertirString(const string& input) {
    string reversed = input;
    int n = reversed.length();
    for (int i = 0; i < n / 2; ++i) {
        char temp = reversed[i];
        reversed[i] = reversed[n - i - 1];
        reversed[n - i - 1] = temp;
    }
    return reversed;
}

/*****
* void super_string::reverso
******
* Invierte el orden de los caracteres en el árbol binario.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::reverso() {
    string palabra_invertida = invertirString(stringizar(root));
    limpiar(root);
    int largo = palabra_invertida.length();
    for (int i = 0; i < largo; i++){
        insertar(root, i, palabra_invertida[i]);
    }
}

/*****
* void super_string::INSERTAR
******
* Inserta una palabra en el árbol binario de manera consecutiva, comenzando desde el último índice existente en el árbol.
******
* Input:
* nodo*& root : Referencia al puntero al nodo raíz del árbol binario en el que se insertará la palabra.
* string palabra_a_insertar : Palabra que se insertará en el árbol binario.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::INSERTAR(nodo *& root, string palabra_a_insertar){  
    if(root == nullptr){
        for (int i = 0; i < palabra_a_insertar.length(); i++)
        {
            insertar(root,i, palabra_a_insertar[i]);
        }
    }
    else{
        string ObtenerIndice = stringizar(root);
        int indiceInferior = ObtenerIndice.length() -1;
        int indiceSuperior = indiceInferior + palabra_a_insertar.length();
        int c = 0;
        for (int i = indiceInferior; i < indiceSuperior; i++)
        {
            insertar(root,i,palabra_a_insertar[c]);
            c++;
        }
        
    }
}

/*****
* void super_string::recortararbol
******
* Esta función optimiza un árbol binario existente convirtiéndolo en un árbol balanceado. Primero, realiza un recorrido en stringizar del árbol para almacenar los nodos en una lista enlazada. Luego, convierte esta lista en un array dinámico y construye un nuevo árbol balanceado usando los nodos del array. Finalmente, libera la memoria utilizada por la lista enlazada y el array.
******
* Input:
* Nodo* root : Puntero al nodo raíz del árbol binario que se va a optimizar.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::recortararbol() {
    NodoLista* head = nullptr;
    NodoLista* tail = nullptr;

    InOrdenRecorrido(root, head, tail);

    nodo** stringizarNodes;
    int size = listaEnArray(head, stringizarNodes);

    root = Arbol_Optimizado(stringizarNodes, 0, size - 1);

    destruirLista(head);
    delete[] stringizarNodes;
}

/*****
* void super_string::InOrdenRecorrido
******
* Realiza un recorrido en stringizar de un árbol binario y almacena los nodos en una lista enlazada.
******
* Input:
* nodo* current : Puntero al nodo actual del árbol binario que se está recorriendo.
* NodoLista*& head : Referencia al puntero del primer nodo de la lista enlazada.
* NodoLista*& tail : Referencia al puntero del último nodo de la lista enlazada.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::InOrdenRecorrido(nodo* current, NodoLista*& head, NodoLista*& tail) {
    if (current == nullptr) return;

    InOrdenRecorrido(current->left, head, tail);

    NodoLista* nuevoNodo = new NodoLista(current);
    if (tail == nullptr) {
        head = tail = nuevoNodo;
    } else {
        tail->next = nuevoNodo;
        tail = nuevoNodo;
    }

    InOrdenRecorrido(current->right, head, tail);
}

/*****
* int super_string::listaEnArray
******
* Convierte una lista enlazada de nodos en un array dinámico y devuelve el tamaño del array.
******
* Input:
* NodoLista* head : Puntero al primer nodo de la lista enlazada.
* nodo**& array : Referencia al puntero del array dinámico que se va a crear.
******
* Returns:
* int : El tamaño del array creado, que corresponde al número de nodos en la lista enlazada.
*****/

int super_string::listaEnArray(NodoLista* head, nodo**& array) {
    int size = 0;
    NodoLista* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }

    array = new nodo*[size];
    current = head;
    for (int i = 0; i < size; i++) {
        array[i] = current->data;
        current = current->next;
    }

    return size;
}

/*****
* void super_string::destruirLista
******
* Libera la memoria ocupada por una lista enlazada, eliminando todos sus nodos.
******
* Input:
* NodoLista* head : Puntero al primer nodo de la lista enlazada que se va a destruir.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::destruirLista(NodoLista* head) {
    while (head != nullptr) {
        NodoLista* temp = head;
        head = head->next;
        delete temp;
    }
}

/*****
* super_string::nodo* super_string::Arbol_Optimizado
******
* Construye un árbol binario balanceado a partir de un array de nodos ordenados en stringizar.
******
* Input:
* nodo** nodes : Puntero al array de nodos ordenados en stringizar.
* int start : Índice de inicio del subarray actual.
* int end : Índice de fin del subarray actual.
******
* Returns:
* nodo* : Puntero a la raíz del árbol binario balanceado construido.
*****/

super_string::nodo* super_string::Arbol_Optimizado(nodo** nodes, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    nodo* n_Node = nodes[mid];

    n_Node->left = Arbol_Optimizado(nodes, start, mid - 1);
    n_Node->right = Arbol_Optimizado(nodes, mid + 1, end);

    return n_Node;
}

/*****
* int super_string::altura_arbolBinario
******
* Calcula la altura de un árbol binario de manera recursiva.
******
* Input:
* nodo* root : Puntero al nodo raíz del árbol binario cuya altura se desea calcular.
******
* Returns:
* int : La altura del árbol binario. 
*****/

int super_string::altura_arbolBinario(nodo* root) {
  if (root == nullptr) {
    return 0;
  } else {
    int alturaIzquierda = altura_arbolBinario(root->left);
    int alturaDerecha = altura_arbolBinario(root->right);

    if (alturaIzquierda > alturaDerecha) {
      return alturaIzquierda + 1;
    } else {
      return alturaDerecha + 1;
    }
  }
}

/*****
* void super_string::actualizarAltura
******
* Actualiza la altura del árbol binario almacenado en el objeto `super_string`.
* Utiliza la función recursiva `altura_arbolBinario` para calcular la altura del árbol.
******
* Input: vacio
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::actualizarAltura() {
    this->height = altura_arbolBinario(this->root);
}

/*****
* int super_string::RECORTAR
******
* Recorta el árbol binario almacenado en el objeto `super_string`, optimizándolo para que su altura sea a lo más 𝑂(log 𝑛), donde 𝑛 es la cantidad de nodos.
* Primero, llama a `recortararbol` para optimizar el árbol. Luego, actualiza la altura del árbol con `actualizarAltura`.
******
* Input:
* Ninguno
******
* Returns:
* int : La altura del árbol binario después de recortarlo.
******
* Complejidad:
* La función `recortararbol` realiza un recorrido en stringizar para convertir el árbol en una lista enlazada, luego convierte esta lista en un array y finalmente construye un árbol balanceado. El recorrido stringizar y la conversión de lista a array toman 𝑂(n) tiempo, mientras que la construcción del árbol balanceado tiene una complejidad de 𝑂(n). Por lo tanto, el proceso total tiene una complejidad de 𝑂(n).
* La función `actualizarAltura` calcula la altura del árbol balanceado, lo cual toma 𝑂(log 𝑛) tiempo en un árbol balanceado.
* Por lo tanto, la función `RECORTAR` asegura que la altura del árbol recortado sea a lo más 𝑂(log 𝑛).
*****/

int super_string::RECORTAR() {
        recortararbol();
        actualizarAltura();
        cout << height << endl;
        return (height);
}

/*****
* void super_string::ReversarIntervalo
******
* Invierte el orden de los caracteres en un intervalo específico de un árbol binario.
******
* Input:
* nodo*& root : Referencia al puntero al nodo raíz del árbol binario en el que se realizará la inversión del intervalo.
* int limite_inferior : Índice inferior del intervalo a invertir.
* int limite_superior : Índice superior del intervalo a invertir.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::ReversarIntervalo(nodo *& root, int limite_inferior , int limite_superior) {
    string palabra_reversar = stringizar(root);

    string p1 = palabra_reversar.substr(0, limite_inferior);
    string p2 = palabra_reversar.substr(limite_inferior, limite_superior - limite_inferior);
    string p3 = palabra_reversar.substr(limite_superior);

    p2 = invertirString(p2);

    string retorno = p1 + p2 + p3;

    limpiar(root);

    for (int i = 0; i < retorno.length(); i++) {
        insertar(root, i, retorno[i]);
    }
}

/*****
* void agregar(char c)
******
* Esta función inserta un carácter en la última posición del árbol binario de búsqueda representado
* por el objeto de la clase `super_string`. La función obtiene la secuencia inorden actual del árbol,
* destruye el árbol existente, agrega el nuevo carácter al final de la secuencia y reconstruye el árbol
* a partir de la nueva secuencia.
******
* Input:
* char c : El carácter que se insertará al final del árbol.
******
* Returns:
* void : No retorna ningún valor.
*****/

void super_string::agregar(char c) {
    string secuencia_inorden = stringizar(root);
    
    secuencia_inorden += c;
    
    limpiar(root);
    
    for (int i = 0; i < secuencia_inorden.length(); i++) {
        insertar(root, i, secuencia_inorden[i]);
    }
}

// void super_string::menu(super_string &root) {
//     int dato, opcion, contador = 0;
//     char c;
//     super_string s1, s2;
//     do {
//         cout << "\t.:Menu:." << endl;
//         cout << "1. Insertar un nuevo nodo" << endl;
//         cout << "2. Mostrar el root completo" << endl;
//         cout << "3. Buscar un elemento del root" << endl;
//         cout << "4. Eliminar un nodo del root" << endl;
//         cout << "5. Recorrer el root en In-Orden" << endl;
//         cout << "6. Eliminar intervalo" << endl;
//         cout << "7. Separar super-string" << endl;
//         cout << "8. Juntar super string" << endl;
//         cout << "9. Revertir super string" << endl;
//         cout << "10. recortar root super string" << endl;
//         cout << "11. insertar un string" << endl;
//         cout << "12. RECORTAR un string" << endl;
//         cout << "13. Reversar intervalo de un string" << endl;
//         cout << "14. Salir" << endl;
//         cout << "Opcion: ";
//         cin >> opcion;

//         switch (opcion) {
//         case 1:
//             cout << "\nDigite un numero: ";
//             cin >> dato;
//             cout << "Digite un caracter: ";
//             cin >> c;
//             root.insertar(root.root, dato, c); 
//             cout << "\n";
//             break;
//         case 2:
//             cout << "\nMostrando el root completo:\n\n";
//             int Pause;
//             root.mostrararbol(root.root, contador); 
//             cout << "\nPresiona cualquier numero para volver al menú...";
//             cin >> Pause;
//             break;
//         case 3:
//             cout << "\nDigite el elemento a buscar: ";
//             cin >> dato;
//             if (root.busqueda(root.root, dato)) { 
//                 cout << "\nElemento " << dato << " ha sido encontrado en el root";
//             } else {
//                 cout << "\nElemento no encontrado";
//             }
//             cout << "\nPresiona cualquier numero para volver al menú...";
//             cin >> Pause;
//             break;
//         case 4:
//             cout << "\nDigite el numero a eliminar: ";
//             cin >> dato;
//             root.eliminar(root.root, dato); 
//             cout << "\n";
//             break;
//         case 5:
//             cout <<"\nRecorrido en stringizar: "<< stringizar(root.root);
//             cout<<"\n\n";
//             cout << "\nPresiona cualquier numero para volver al menú...";
//             cin >> Pause;
//             break;
//         case 6:
//             int a, b;
//             cout<<"\nDigite el primer digito: ";
//             cin >> a;
//             cout<<"\nDigite el segundo digito: ";
//             cin>> b;
//             root.EliminarIntervalo(root.root, a, b);        
//             break;
//         case 7:
//             int pos;
//             cout << "\nDigite la posicion para separar: ";
//             cin >> pos;
//             root.separar(pos, s1, s2);
//             cout << "\nParte izquierda: " << stringizar(root.root);
//             cout << "\nParte derecha: " << stringizar(s2.root);
//             cout << "\nPresiona cualquier numero para volver al menú...";
//             cin >> Pause;
//             break;
//         case 8:
//             cout << "\nJuntando árboles...\n";
//             root.juntar(root, s2); // Juntar la parte recortada (s1) con la parte sobrante (s2)
//             cout << "Árbol resultante:\n";
//             root.mostrararbol(root.root, contador); // Mostrar el árbol completo
//             cout << "\nPresiona cualquier numero para volver al menú...";
//             cin >> Pause;
//             break;
//         case 9:
//             cout << "\nReversando el super-string...\n";
//             root.reverso();
//             cout << "Super-string reversado:\n";
//             root.mostrararbol(root.root, contador);
//             cout << "\nPresiona cualquier número para volver al menú...";
//             cin >> Pause;
//             break;
//         case 10:
//             cout << "\nRecortando el árbol...\n";
//             root.recortarroot(); // Llama a la función recortarroot
//             cout << "Árbol recortado:\n";
//             root.mostrararbol(root.root, contador);
//             cout << "\nPresiona cualquier numero para volver al menú...";
//             cin >> Pause;
//             break;
//         case 11:
//             {
//                 string ingresar;
//                 cout << "\nIngrese la palabra a ingresar el root: \n";
//                 cin >> ingresar;
//                 INSERTAR(root.root , ingresar);
//                 cout << "\nPresiona cualquier numero para volver al menú...";
//                 cin >> Pause;
//                 break; 
//             } 
//         case 12:
//             cout << "\nLa Altura nueva es: \n";
//             RECORTAR();
//             cout << "\nPresiona cualquier numero para volver al menú...";
//             cin >> Pause;
//             break;
//         case 13:

//             cout << "\ningrese indice inferior:\n";
//             cin >> a;
//             cout << "\ningrese indice superior:\n";
//             cin >> b;
//             ReversarIntervalo(root.root, a , b);
//             cout << "\nPresiona cualquier numero para volver al menú...";
//             cin >> Pause;
//             break;
           
//         }
//         system("clear");
//     } while (opcion != 14);
// }