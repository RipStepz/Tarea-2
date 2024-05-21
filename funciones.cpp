#include <iostream>
#include <stdexcept>
#include "funciones.hpp"

using namespace std;
extern Tablero t;

/*
Tipo de Función entera (retorna un entero)  y su nombre es filas
**
Resumen Función: Esta funcion sirve para calcular las filas, por eleccion las filas coorresponden a y para las coordenadas (x,y)
**
Input:
recibe un parametro contador tipo entero que es el indice que necesitamos del struct, es decir ese contador lo usamos para saber en que posicion llenar el parametro y en el struct
.......
**
Returns:
retorna un entero, el retorno devolvera la coordenada y recordando que la coordenada maxima es (8,8) , para eso sirven las operaciones
*/
int filas(float contador) {
    if (contador/8 <= 1){
        return 1;
    }

    else if (contador/8 <= 2){
        return 2;
    }
    
    else if (contador/8 <= 3){
        return 3;
    }

    else if (contador/8 <= 4){
        return 4;
    }

    else if (contador/8 <= 5){
        return 5;
    }

    else if (contador/8 <= 6){
        return 6;
    }

    else if (contador/8 <= 7){
        return 7;
    }

    else if (contador/8 <= 8){
        return 8;
    }

    else{
        return -1;
    }
}

/*
funcion de tipo entera de Nombre columnas
**
Resumen Función: Esta funcion sirve para calcular las columnas, por eleccion las columnas corresponden a x para las coordenadas (x,y)
**
Input:
recibe un parametro contador tipo entero que es el indice que necesitamos del struct, es decir ese contador lo usamos para saber en que posicion llenar el parametro y en el struct
.......
**
Returns:
retorna un entero, el retorno devolvera la coordenada x recordando que la coordenada maxima es (8,8) , para eso sirven las operaciones
*/
int columnas (float contador){
    if (contador <= 8){  
        return contador;
     }

    else if ((contador > 8) && (contador <16)){  
        int returneable = contador;
        returneable = returneable % 8;

        return (returneable);
     }

     else if (contador == 16){
        return 8;
     }

    else if ((contador > 16) && (contador <=24)){  
        int returneable = contador;
        returneable = returneable % 16;
        return (returneable);
     }

    else if ((contador > 24) && (contador <=32)){  
            int returneable = contador;
            returneable = returneable % 24;
            return (returneable);
        }

        else if ((contador > 32) && (contador <=40)){  
        int returneable = contador;
        returneable = returneable % 32;
        return (returneable);
     }

     else if ((contador > 40) && (contador <=48)){  
        int returneable = contador;
        returneable = returneable % 40;
        return (returneable);
     }

     else if ((contador > 48) && (contador <=56)){  
        int returneable = contador;
        returneable = returneable % 48;
        return (returneable);
     }

     else if ((contador > 56) && (contador <=64)){  
        int returneable = contador;
        returneable = returneable % 56;
        return (returneable);
     }

     else{
        return -1;
     }
}

/*****
* funcion tipo vacia (no retorna nada) de nombre Marcar_amenazas
******
* Resumen Función: cuando encotramos la coordenada que le pasamos es un punto, lo cambiamos por ! que significa amenaza
* cuando encontramos X lo cambiamos por $ para poder diferenciar los jaques mates de rey ahogado mas adelante
******
* Input:
* Ingresa un struct t tipo Tablero un x_cambiar, y_cambiar que no son mas la posicion a la que se mueve una pieza (dato tipo entero)
* .......
******
* Returns:
* retorna void
*****/
void Marcar_amenazas(const Tablero& t , int x_cambiar , int y_cambiar){
    for (int i = 0 ;i<64 ;i++){
        if (t.piezas_tablero[i].x == x_cambiar && t.piezas_tablero[i].y == y_cambiar && t.piezas_tablero[i].simbolo == '.'){
            t.piezas_tablero[i].simbolo = '!';
        } 

        if (t.piezas_tablero[i].x == x_cambiar && t.piezas_tablero[i].y == y_cambiar && t.piezas_tablero[i].simbolo == 'X'){
            t.piezas_tablero[i].simbolo = '$';
        }
    }
}

/*
Funcion tipo bool (retorna un booleano) de nombre Buscar_espacios_libres

Resumen Función: Esta funcion la ocupamos para la logica del rey X, buscamos al rededor del rey si puede moverse a algun lado.
Nuestra forma de afrontar el problema, nos ahorrra tener en cuenta, si el rey puede comer otra pieza, pero no soluciona la situacion de rey ahogado.
ese caso lo controlamos en otra funcion

Input:
Ingresa un struct t tipo Tablero y dos posiciones tipo entero, las posiciones son las coordenadas, donde el rey deberia poder moverse
.......
**
Returns:
retorna un bool que es true lo que significa que hay espacios libres y no hay jaque, si no hay espacios libres retorna false.
*/
bool Buscar_espacios_libres(const Tablero& t , int x_rey , int y_rey){
    for (int i = 0 ;i<64 ;i++){
        if (t.piezas_tablero[i].x == x_rey && t.piezas_tablero[i].y == y_rey && t.piezas_tablero[i].simbolo != '!'){
        return true;
        } 
    }
return false;
}

/*
Funcion tipo booleana(retorna un bool) de nombre Descartar_casos

Resumen Función: Esta funcion verifica si la posicion que se amenza se encuentra alguna pieza
en el caso de encontrar se retorna true y se usa para volver una flag falsa y descartar este caso de la pieza que llame la funcion, ya que no puede seguir avanzando en esa direccion

Input:
Ingresa un struct t tipo Tablero, tambien ingresa un la posicion x,y (datos enteros) de la casilla que se amenaza, su nombre es el nombre elegido en este caso es x_ver y y_ver
.......
**
Returns:
retorna un true en caso de que encuentre una pieza, para descartar el caso , si retorna false porque no encontro una pieza, el caso seguira siendo valido
*/
bool Descartar_casos(int x_ver , int y_ver){ //si es verdadera significa que deberemos parar de usar ese caso
    for (int i = 0 ;i<64 ;i++){
        if (t.piezas_tablero[i].x == x_ver && t.piezas_tablero[i].y == y_ver && t.piezas_tablero[i].simbolo != '.' && t.piezas_tablero[i].simbolo != '!'){
            return true;
        } 
    }
return false;
}

/*****
* funcion tipo bool (retorna un booleano) de nombre Verificar_rey_Ahogado
******
* Resumen Función: Si el rey sigue siendo X, significa que esta ahogado ya que no hay pieza que lo coma, retorna true
* en caso de ser $ significa que si se lo puede comer una pieza y es un jaque, retorna false
******
* Input:
* Ingresa un struct t tipo Tablero
* .......
******
* Returns:
* retorna true en caso de estar ahogado y un false en caso de ser un jaque 
*****/
bool Verificar_Rey_Ahogado(const Tablero& t) {
    for (int i = 0 ;i<64 ;i++){
        if (t.piezas_tablero[i].simbolo == 'X'){ // si encuentro X, como era originalmente retorna verdaro, el caso contrario, es cuando el X se transformo a $ retorna falso
        return true; //este caso es ahogado
        } 
        if (t.piezas_tablero[i].simbolo == '$'){ 
            return false; // este caso es jaque
        }
    }
return false;
}