#include <iostream>
#include <cstdlib>
#include <fstream> 
#include <stdio.h>
#include <stdlib.h>

#include "funciones.hpp"

using namespace std;

ifstream fich("prueba.txt");

/*****
* void super_string::archivo
******
* Procesa un archivo de entrada que contiene una serie de instrucciones para manipular un árbol binario.
******
* Input:
* super_string& root : Referencia al objeto `super_string` que representa el árbol binario principal.
* super_string& b : Referencia al objeto `super_string` que puede ser utilizado para operaciones adicionales si es necesario.
******
* Returns:
* void, no retorna ningún valor.
*****/

void super_string::archivo(super_string &root , super_string &b){
    if(!fich.is_open()) { 
    cout << "No se pudo abrir el archivo." << endl;
    }
    else{
    cout << "se abrio el archivo"<< endl;
    }
    string palabra;
    while (fich >> palabra) {
        if (palabra == "INSERTAR") {
            string palabra_a_insertar; 
            fich >> palabra_a_insertar;
            fich >> palabra_a_insertar;
                
            INSERTAR(root.root, palabra_a_insertar); 
        }

        else if (palabra == "ELIMINAR"){
            int a, b;

            fich >> a;
           
            fich >> b;
            
            EliminarIntervalo(root.root, a,b);

        }
        else if (palabra == "MOSTRAR"){
            cout <<stringizar(root.root)<<endl;
        }
        
        else if(palabra == "RECORTAR"){
              RECORTAR();
           }

        else if(palabra == "REVERSO"){
            int a, b;
            string ObtenerIndice = stringizar(root.root);
            fich >> a;
           
            fich >> b;
            if ((a == 0) && (b == (ObtenerIndice.length() -1)) ){
                reverso();
            }
            
            else{
                ReversarIntervalo(root.root, a,b);
            }
        }
        else if (palabra == "FIN")
        {
            fich.close();
            limpiar(root.root);
            b.limpiar(b.root);
            break;
        }
        
    }
}