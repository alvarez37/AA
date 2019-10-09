#include "vernam.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>


string leertxtparrafos(string nombre){
  string cadena;
  string lectura;
  ifstream fe(nombre.c_str());
  while (!fe.eof()) {
    getline (fe,lectura);
      cadena +=  lectura+'\n';
  }
  cadena.resize(cadena.size()-2);
  return cadena;
  fe.close();
}

string leertxt(string documento){

  string cadena;
  ifstream fe(documento.c_str());
  while (!fe.eof()) {
    fe >> cadena;
    cout << cadena << endl;
  }
  return cadena;
  fe.close();
}


void escribir_txt(string txt,string documento){

  ofstream fs(documento.c_str(), ios::out);
  fs << txt << endl;
  fs.close();
}





using namespace std;

int main()
{

  string documento1="doc1.txt";
  string documento2="doc2.txt";
  string documento3="doc3.txt";
  string documento4="doc4.txt";
  string texto;
  int intercambio;

    string mensaje;
    vernam v1("");

    while (true) {
      std::cout << "1 para cifrar" << '\n';
      std::cout << "2 para descifrado emisor" << '\n';
      std::cin >> intercambio;

      switch (intercambio) {
        case 1: {

                texto=v1.Encriptar(leertxtparrafos(documento1));
                escribir_txt(texto, documento2);
                escribir_txt(v1.get_clave(), documento3 );
                std::cout << "-------gardado----------" << '\n';
                break;
              }

        case 2:  {
              texto=v1.Desencriptar( leertxtparrafos(documento2) , leertxtparrafos(documento3) );
              escribir_txt(texto, documento4);

               break;
               }
      }
    }


    return 0;
}
