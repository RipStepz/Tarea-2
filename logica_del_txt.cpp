#include <iostream>
#include <cstdlib>
#include <fstream> 
#include <stdio.h>
#include <stdlib.h>

#include "funciones.hpp"

using namespace std;

ifstream fich("prueba.txt");
void super_string::archivo(super_string &arbol , super_string &b){

if(!fich.is_open()) { // Verifica si el archivo se abrió correctamente
    cout << "No se pudo abrir el archivo." << endl;
}
else{
    cout << "se abrio el archivo"<< endl;
}
string palabra;
    while (fich >> palabra) {
        // Procesa cada palabra
        //cout << palabra << endl; // Ejemplo: Imprimir cada palabra

        if (palabra == "INSERTAR") {
            string palabra_a_insertar; 
            fich >> palabra_a_insertar;
            fich >> palabra_a_insertar;
                // Llama a la función INSERTAR aquí
                // arbol.INSERTAR(arbol.arbol, palabra_a_insertar);
            //cout << "Insertar: " << palabra_a_insertar << endl; // Ejemplo de procesamiento
            INSERTAR(arbol.arbol, palabra_a_insertar); 
        }

        else if (palabra == "ELIMINAR"){
            int a, b;

            fich >> a;
            //cout << "\n limite inferior a insertar: " << a << endl;
           
            fich >> b;
            //cout << "\n limite superior a insertar: " << b << endl;
            
            EliminarIntervalo(arbol.arbol, a,b);

        }
        else if (palabra == "MOSTRAR"){
            cout <<inOrden(arbol.arbol)<<endl;
        }
        
        else if(palabra == "RECORTAR"){
              RECORTAR();
           }

        else if(palabra == "REVERSO"){
            int a, b;
            string ObtenerIndice = inOrden(arbol.arbol);
            fich >> a;
           
            fich >> b;
            if ((a == 0) && (b == (ObtenerIndice.length() -1)) ){
                reverso();
            }
            
            else{
                ReversarIntervalo(arbol.arbol, a,b);
            }
        }
        else if (palabra == "FIN")
        {
            fich.close();
            destruirArbol(arbol.arbol);
            b.destruirArbol(b.arbol);
            break;
        }
        
    }
}