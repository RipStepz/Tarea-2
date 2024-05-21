#include <iostream>
#include <fstream> 
#include <stdio.h>
#include <stdlib.h>

#include "funciones.hpp"
using namespace std;

struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
};