#ifndef AFIN_H
#define AFIN_H

#include<iostream>
#include<string>
#include <ctime>
using namespace std ;


class afin{

    public:
        afin();
        afin(int,int);
        int clave_a();
        int clave_b();
        int inversa();
        string cifrado(string);
        string descifrado(string);
    private:
        int tam_array;
        string alf="abcdefghijklmnopqrstuvwxyz";
        int inversa_int;
        int a;
        int b;

};



#endif // AFIN_H
