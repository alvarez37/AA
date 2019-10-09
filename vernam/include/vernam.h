#ifndef VERNAM_H
#define VERNAM_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


using namespace std ;


class vernam{

    public:
        vernam(string);
        void aleatorios ( int  , string []);
        void cadena_de_numero (string[], string);

        string Encriptar(string );
        string Desencriptar(string,string);
        string alfabeto ="abcdefghijklmnopqrstuvwxyz ";
        string get_clave();

        void cortar_binario ( string  , string []);

    private:
      string clave_salida;

};

#endif // VERNAM_H
