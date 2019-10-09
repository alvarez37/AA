#ifndef TURING_H
#define TURING_H


#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std ;

class turing
{
    public:

        turing(string );

        string Encriptar(string);
        string Desencriptar(string);
        string alfabeto_aleatorios();
        string GetAlfabeto();
        string GetClave();

        string alfabeto1 ="abcdefghijklmnopqrstuvwxyz ";
        string alfabeto2 ="abcdefghijklmnopqrstuvwxyz ";
        string alfabeto3 ="abcdefghijklmnopqrstuvwxyz ";

      private:
        string clave;
        string alfabeto1_rojo;
        string alfabeto2_rojo;
        string alfabeto3_rojo;

};



#endif // TURING_H
