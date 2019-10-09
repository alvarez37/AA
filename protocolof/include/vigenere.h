#ifndef CIFRADO_H
#define CIFRADO_H


#include<iostream>
#include<string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std ;
class cifrado
{
    public:
        cifrado(string);
        cifrado(string,string);

        string Encriptar(string);
        string Desencriptar(string,string);

        void aleatorios ( int  , string []);
        string clave_a (string[], int);
        string alfabeto ="abcdefghijklmnopqrstuvwxyz";
        string get_clav();

      private:
        string clave_s;

};

#endif // CIFRADO_H
