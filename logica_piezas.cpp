#include <iostream>
#include "funciones.hpp"
using namespace std;
extern Tablero t;

/**
TipoFunción:Es una funcion de tipo void NombreFunción: peon
**
Resumen Función: Esta funcion busca el o los peones recorriendo el tablero, luego usa la funcion Marcar_amenazas para evaluar las posibles amenazas siguiendo la logica de movimento de peon para despues marcar las casillas amenazadas con un (!)
**
Input:
entra un struct t tipo Tablero, que nos entrega el tablero
.......
**
Returns:
TipoRetorno, Descripción retorno: retorna void
*/
void peon(const Tablero& t){
      for (int i = 0 ;i<64 ;i++){
        if (t.piezas_tablero[i].simbolo == 'P'){
          int Pos_x = t.piezas_tablero[i].x , Pos_Y = t.piezas_tablero[i].y;

            Marcar_amenazas(t , Pos_x + 1 , Pos_Y -1 );
            Marcar_amenazas(t , Pos_x - 1 , Pos_Y -1 );

          }
        }
      }

/**
TipoFunción:Es una funcion de tipo void NombreFunción: alfil
**
Resumen Función:Esta funcion busca un alfil recorriendo el tablero, luego utiliza un bucle para evaluar las posibles amenazas diagonales que puede hacer en todas las direcciones, para cada amenaza detectada marca la casilla con un (!) usando la funcion Marcer_amenazas y usa la condicion de control (flag_1, flag_2, flag_3, flag_4) para decidir si debe continuar evaluando la direccion.
**
Input:
Entra un struct t tipo Tablero, que nos entrega el tablero
.......
**
Returns:
TipoRetorno, Descripción retorno: retorna void
*/
void alfil(const Tablero& t){
      for (int i = 0 ;i<64 ;i++){
        if (t.piezas_tablero[i].simbolo == 'A'){
          int Pos_x = t.piezas_tablero[i].x , Pos_Y = t.piezas_tablero[i].y, contador = 1;
          bool flag_1 = true , flag_2 = true , flag_3 = true , flag_4 = true;

          while (contador < 9){
            if (flag_1){
              Marcar_amenazas(t , Pos_x + contador , Pos_Y + contador);

            if (Descartar_casos(Pos_x + contador , Pos_Y + contador)){
                flag_1 = false;
              }
            }

            if (flag_2){
              Marcar_amenazas(t , Pos_x - contador , Pos_Y + contador);
              if (Descartar_casos(Pos_x - contador , Pos_Y + contador)){
                flag_2 = false;
              }
            }

            if (flag_3){
              Marcar_amenazas(t , Pos_x + contador , Pos_Y - contador);
              if (Descartar_casos(Pos_x + contador , Pos_Y - contador)){
                flag_3 = false;
              }
            }

            if (flag_4){
              Marcar_amenazas(t , Pos_x - contador , Pos_Y - contador );
              if (Descartar_casos(Pos_x - contador , Pos_Y - contador)){
                flag_4 = false;
              }
            }
            contador ++;
          }
        }
      }
}

/*
TipoFunción:Es una funcion de tipo void NombreFunción: torre
**
Resumen Función:Esta funcion busca la o las Torres presentes en el tablero recorriendolo, luego utiliza un bucle para poder evaluar las posibles amenazas verticales y horizontales de todas las direcciones posibles para luego usar la funcion Marcar_amenaza para poder maracar las casillas amenazadas por un (!) ademas de usar las codiciones de control (flag_1, flag_2, flag_3, flag_4) para decidir si debe continuar evaluando la direccion
**
Input:
Entra un struct t tipo Tablero, que nos entrega el tablero
.......
**
Returns:
TipoRetorno, Descripción retorno: retorna void
*/
void torre(const Tablero& t){
      for (int i = 0 ;i<64 ;i++) {
        if (t.piezas_tablero[i].simbolo == 'T'){
          int Pos_x = t.piezas_tablero[i].x , Pos_Y = t.piezas_tablero[i].y, contador = 1;
          bool flag_1 = true , flag_2 = true , flag_3 = true , flag_4 = true;

            while (contador < 9){
            if (flag_1){
              Marcar_amenazas(t , Pos_x + contador , Pos_Y);
              if (Descartar_casos(Pos_x + contador , Pos_Y)){
                flag_1 = false;
              }
            }

            if (flag_2){
              Marcar_amenazas(t , Pos_x - contador , Pos_Y);
              if (Descartar_casos(Pos_x - contador , Pos_Y)){
                flag_2 = false;
              }
            }

            if (flag_3){
              Marcar_amenazas(t , Pos_x, Pos_Y + contador);
              if (Descartar_casos(Pos_x, Pos_Y + contador)){
                flag_3 = false;
              }
            }

            if (flag_4){
              Marcar_amenazas(t , Pos_x, Pos_Y - contador );
              if (Descartar_casos(Pos_x, Pos_Y - contador)){
                flag_4 = false;
              }
            }
            contador ++;
          }
        }
      }
}

/*
TipoFunción:Es una funcion de tipo void NombreFunción: reyna
**
Resumen Función:Esta funcion busca a la reina presente en el tablero recorriendolo, luego utiliza dos bucles el primero evalua las posibles amenazas verticales y horizontales de todas las direcciones posible, y el segundo evalua las amenazas diagonales de todas las direcciones posibles para luego usar la funcion Marcar_amenaza para poder maracar las casillas amenazadas por un (!) ademas d que ambos bucles usan las codiciones de control (flag_1, flag_2, flag_3, flag_4) para decidir si debe continuar evaluando la direccion, para poder usar las concuones de control en el segundo bucle se reinician
**
Input:
Entra un struct t tipo Tablero, que nos entrega el tablero
.......
**
Returns:
TipoRetorno, Descripción retorno: retorna void
*/
void reyna(const Tablero& t){
      for (int i = 0 ;i<64 ;i++){
        if (t.piezas_tablero[i].simbolo == 'R'){
          int Pos_x = t.piezas_tablero[i].x , Pos_Y = t.piezas_tablero[i].y, contador = 1;
          bool flag_1 = true , flag_2 = true , flag_3 = true , flag_4 = true;

          while (contador < 9){
            if (flag_1){
              Marcar_amenazas(t , Pos_x - contador , Pos_Y);
              if (Descartar_casos(Pos_x - contador , Pos_Y)){
                flag_1 = false;
              }
            }

            if (flag_2){
              Marcar_amenazas(t , Pos_x + contador , Pos_Y);
              if (Descartar_casos(Pos_x + contador , Pos_Y)){
                flag_2 = false;
              }
            }

            if (flag_3){
              Marcar_amenazas(t , Pos_x, Pos_Y - contador);
              if (Descartar_casos(Pos_x, Pos_Y - contador)){
                flag_3 = false;
              }
            }

            if (flag_4){
              Marcar_amenazas(t , Pos_x, Pos_Y + contador );
              if (Descartar_casos(Pos_x, Pos_Y + contador)){
                flag_4 = false;
              }
            }
            contador ++;
          }

contador =1;
flag_1 = true;
flag_2 =true;
flag_3 =true;
flag_4 =true;

            while (contador < 9){
            if (flag_1){
              Marcar_amenazas(t , Pos_x + contador , Pos_Y + contador);
              if (Descartar_casos(Pos_x + contador , Pos_Y + contador)){
                flag_1 = false;
              }
            }
            if (flag_2){
              Marcar_amenazas(t , Pos_x - contador , Pos_Y + contador);
              if (Descartar_casos(Pos_x - contador , Pos_Y + contador)){
                flag_2 = false;
              }
            }

            if (flag_3){
              Marcar_amenazas(t , Pos_x + contador , Pos_Y - contador);
              if (Descartar_casos(Pos_x + contador , Pos_Y - contador)){
                flag_3 = false;
              }
            }

            if (flag_4){
              Marcar_amenazas(t , Pos_x - contador , Pos_Y - contador );
              if (Descartar_casos(Pos_x - contador , Pos_Y - contador)){
                flag_4 = false;
              }
            }
            contador ++;
          }
          
        }
      }
}

/**
TipoFunción:Es una funcion de tipo void NombreFunción: caballo
**
Resumen Función: Esta funcion busca el o los caballos recorriendo el tablero, luego usa la funcion Marcar_amenazas para evaluar las posibles amenazas siguiendo la logica de movimento del caballo para despues marcar las casillas amenazadas con un (!)
**
Input:
Entra un struct t tipo Tablero, que nos entrega el tablero
.......
**
Returns:
TipoRetorno, Descripción retorno: retorna void
*/
void caballo(const Tablero& t){
      for (int i = 0 ;i<64 ;i++){
        if (t.piezas_tablero[i].simbolo == 'C'){
          int Pos_x = t.piezas_tablero[i].x , Pos_Y = t.piezas_tablero[i].y;

            Marcar_amenazas(t , Pos_x + 2 , Pos_Y + 1 );
            Marcar_amenazas(t , Pos_x - 2 , Pos_Y + 1 );

            Marcar_amenazas(t , Pos_x + 1 , Pos_Y + 2 );
            Marcar_amenazas(t , Pos_x - 1 , Pos_Y + 2 );

            Marcar_amenazas(t , Pos_x + 2 , Pos_Y - 1 );
            Marcar_amenazas(t , Pos_x - 2 , Pos_Y - 1 );

            Marcar_amenazas(t , Pos_x + 1 , Pos_Y - 2 );
            Marcar_amenazas(t , Pos_x - 1 , Pos_Y - 2 );
          }
        }
      }

/*
TipoFunción:Es una funcion de tipo void NombreFunción: Rey_S
**
Resumen Función: Esta funcion busca al rey recorriendo el tablero, luego usa la funcion Marcar_amenazas para evaluar las posibles amenazas siguiendo la logica de movimento del rey para despues marcar las casillas amenazadas con un (!)
**
Input:
Entra un struct t tipo Tablero, que nos entrega el tablero
.......
**
Returns:
TipoRetorno, Descripción retorno: retorna void
*/
void Rey_S(const Tablero& t){
      for (int i = 0 ;i<64 ;i++){
        if (t.piezas_tablero[i].simbolo == 'K'){
          int Pos_x = t.piezas_tablero[i].x , Pos_Y = t.piezas_tablero[i].y;

            Marcar_amenazas(t , Pos_x + 1 , Pos_Y );
            Marcar_amenazas(t , Pos_x - 1 , Pos_Y );

            Marcar_amenazas(t , Pos_x , Pos_Y + 1 );
            Marcar_amenazas(t , Pos_x , Pos_Y - 1 );

            Marcar_amenazas(t , Pos_x + 1 , Pos_Y - 1 );
            Marcar_amenazas(t , Pos_x - 1 , Pos_Y - 1 );

            Marcar_amenazas(t , Pos_x + 1 , Pos_Y + 1 );
            Marcar_amenazas(t , Pos_x - 1 , Pos_Y + 1 );
          }
        }
}

/*
TipoFunción: Es una funcion de tipo bool NombreFunción: Rey_X
**
Resumen Función: Esta funcion se encarga de verificar si el rey tiene al menos un movimiento legal disponible en un tablero. Utiliza un bucle para encontrar la posición del rey y luego evalúa las posibles casillas adyacentes y diagonales para determinar si alguna de ellas está vacía y puede ser ocupada por el rey.
**
Input:
Entra un struct t tipo Tablero, que nos entrega el tablero
.......
**
Returns:
TipoRetorno, Descripción retorno: retorna true si encuentra espacios libres y false si no tiene ningun mavimiento legal
*/ 
bool Rey_X(const Tablero& t){
      for (int i = 0 ;i<64 ;i++){
        if (t.piezas_tablero[i].simbolo == 'X' or t.piezas_tablero[i].simbolo == '$'){
          int Pos_x = t.piezas_tablero[i].x , Pos_Y = t.piezas_tablero[i].y;

            if(Buscar_espacios_libres(t ,Pos_x + 1 , Pos_Y) ){
              return true;
            }
            if (Buscar_espacios_libres(t , Pos_x - 1 , Pos_Y )){
               return true;
            }
        

            if (Buscar_espacios_libres(t , Pos_x , Pos_Y + 1 )){
               return true;
            }
            if (Buscar_espacios_libres(t , Pos_x , Pos_Y - 1)){
               return true;
            }


            if (Buscar_espacios_libres(t , Pos_x + 1 , Pos_Y - 1)){
               return true;
            }
            if (Buscar_espacios_libres(t , Pos_x - 1 , Pos_Y - 1)){
               return true;
            }


            if (Buscar_espacios_libres(t , Pos_x + 1 , Pos_Y + 1)){
               return true;
            }
            if (Buscar_espacios_libres(t , Pos_x - 1 , Pos_Y + 1)){
               return true;
            }
          }
        }
return false;
}