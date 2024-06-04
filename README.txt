Para compilar el archivo se debe usar lo siguiente:
g++ -c main.cpp -o main.o
g++ -c logica_arbol.cpp -o logica_arbol.o
g++ -c logica_del_txt.cpp -o logica_del_txt.o
g++ main.o logica_arbol.o logica_del_txt.o -o mi_programa

Para correr el programa se debe usar ./mi_programa
