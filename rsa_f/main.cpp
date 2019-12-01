#include <fstream>
#include <NTL/ZZ.h>
#include <iostream>
#include "rsa.h"
#include <stdlib.h>
#include <string>

#include <ctime>


// HOLA NEL
using namespace std;
using namespace NTL;


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

  string documento1="doc1.txt";
  string documento2="doc2.txt";
  string documento3="doc3.txt";
  string documento4="doc4.txt";
  string texto;
  int intercambio;

  rsa emisor(1024);

      texto = leertxtparrafos(documento1);
      string cifrado=emisor.cifrado(texto);
      escribir_txt(cifrado,documento2);
      std::cout << "-------gardado----------" << '\n';
      std::cout << "-------------------------" << '\n';


      string descifrado=emisor.descifrado(cifrado);
      escribir_txt(descifrado,documento4);


  escribir_txt("n: "+emisor.get_n()+" e: "+emisor.get_e(),documento3);

  while (true) {
    std::cout << '\n'<< "1 para cifrar emisor" << '\n';
    std::cout << "2 para descifrado emisor" << '\n';
    std::cout << "3 cifrar para reseptor" << '\n';
    std::cin >> intercambio;

    switch (intercambio) {
      case 1: {
               // std::cout << "que mensaje" << '\n';
               // cin.ignore();
               // getline(cin, texto);
              texto = leertxtparrafos(documento1);
              string cifrado=emisor.cifrado(texto);
              escribir_txt(cifrado,documento2);
              std::cout << "-------gardado----------" << '\n';
              break;}
      case 2:  {

               string descifrado=emisor.descifrado(leertxtparrafos(documento2));
               escribir_txt(descifrado,documento1);
               break;
             }
      case 3:   {
                string e=leertxtparrafos(documento3);
                string n=leertxtparrafos(documento4);

                rsa reseptor(e,n);
                // std::cout << "que mensaje" << '\n';
                // cin.ignore();
                // std::getline (std::cin,texto);
                texto=leertxtparrafos(documento1);

                string descifrado_reseptor=reseptor.cifrado(texto);
                escribir_txt(descifrado_reseptor,documento2);

                break;
              }
    }
  }

  return 0;
}
