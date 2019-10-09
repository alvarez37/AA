#ifndef PROTOCOLO_H
#define PROTOCOLO_H

#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>

#include "afin.h"
#include "enigma.h"
#include "scitala.h"
#include "vigenere.h"

using namespace std ;

class protocolo{


    public:

        turing turing1();


        protocolo(string);
        string encriptaProtocolo(string);
        string desencriptaProtocolo(string,string,string , int ,int);




         int clave_a();
         int clave_b();
         int inversa();

         string get_alfabeto();
         string getclave();
         string get_vigenere();


     private:

        string clave_anigma;
         int a_;
         int b_;
         int inversa_int;
         string vigenereclave;
         string alfabeto1_rojo_get;
         string clave_Vigenere;

};

#endif // PROTOCOLO_H
