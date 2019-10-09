#include "turing.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


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





int main(){



  turing a("cba");


  string documento1="doc1.txt";
  string documento2="doc2.txt";
  string documento3="doc3.txt";
  string documento4="doc4.txt";
  string texto;
  int intercambio;

  while (true) {
    std::cout << "1 para cifrar" << '\n';
    std::cout << "2 para descifrado emisor" << '\n';
    std::cin >> intercambio;

    switch (intercambio) {
      case 1: {

              texto=a.Encriptar(leertxtparrafos(documento1));

              escribir_txt(a.GetClave()+a.GetAlfabeto()+texto, documento2);
              std::cout << "-------gardado----------" << '\n';
              break;
            }

      case 2:  {

            texto=a.Desencriptar(leertxtparrafos(documento2));
            std::cout << "mensaje descifrado: " << texto<< '\n';
            escribir_txt(texto, documento4);

               break;
             }
    }
  }

  return 0;
}
