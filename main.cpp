#include <iostream>
#include <cstdlib>
#include <fstream> 
#include <stdio.h>
#include <stdlib.h>

#include "funciones.hpp"
using namespace std;

int main() {
    ifstream fich("prueba.txt");
    super_string arbol; // Creamos una instancia de la clase super_string

    if (!fich.is_open()) { // Verifica si el archivo se abrió correctamente
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    string palabra;
    while (fich >> palabra) { // Lee el archivo palabra por palabra
        // Procesa cada palabra
        cout << palabra << endl; // Ejemplo: Imprimir cada palabra
        if (palabra == "INSERTAR")
        {

        }

    }

    fich.close(); // Cierra el archivo
    return 0;
    // Llamamos a la función menu para comenzar la interacción con el usuario
    //arbol.menu(arbol);
    return 0;
    // Llamamos a la función menu para comenzar la interacción con el usuario
    arbol.menu(arbol);

    return 0;
}