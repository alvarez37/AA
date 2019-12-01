#ifndef CRIBA_H
#define CRIBA_H


#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class criba
{
    public:
      vector<int> lista;
      void imprimir ();
      criba(int tam);
      bool emcontrar(int x);
      int retornar(int x);


};

#endif // CRIBA_H
