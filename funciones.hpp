#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <stdio.h>

struct Pieza {

 char simbolo; // Define qué tipo de pieza es y su caracter
 int x, y; // Su posición dentro del tablero [0, 7] x [0, 7]

};

struct Tablero {
 int cantidad_piezas;
 Pieza* piezas_tablero; // Lista de piezas que tiene el tablero

};

struct Coordenada {
    int x;
    int y;
};

int filas(float contador);
int columnas (float contador);
void Marcar_amenazas(const Tablero& t , int x_cambiar , int y_cambiar);
bool Buscar_espacios_libres(const Tablero& t , int x_cambiar , int y_cambiar);
bool Descartar_casos(int x , int y);
bool Verificar_Rey_Ahogado(const Tablero& t);

void peon(const Tablero& t);
void alfil (const Tablero& t);
void torre(const Tablero& t);
void reyna(const Tablero& t);
void caballo(const Tablero& t);
void Rey_S(const Tablero& t);
bool Rey_X(const Tablero& t);

#endif