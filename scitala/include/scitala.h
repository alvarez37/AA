#ifndef SCITALA_H
#define SCITALA_H


#include <iostream>
#include <string>
#include <sstream>

using namespace std ;

class scitala{

    public:

        scitala(int,int);
        string Encriptar(string );
        string Desencriptar(string,int , int);
        string alfabeto ="abcdefghijklmnopqrstuvwxyzas ";
        int fila;
        int columna;

};

#endif // SCITALA_H
