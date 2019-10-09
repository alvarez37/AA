#include <string>
#include "scitala.h"
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

    string documento1="doc1.txt";
    string documento2="doc2.txt";
    string documento3="doc3.txt";
    string documento4="doc4.txt";
    string texto;
    int intercambio;
    std::cout << "el mensaje : " << '\n';
    string mensaje;
    int fila=0;
    int columna=0;

    getline(cin,mensaje);

    while(fila*columna<mensaje.size()){
    std::cout << "el tamanio de la clave: " << '\n';
    std::cin >> fila;
    std::cout << "otra " << '\n';
    std::cin >> columna;

    }


    scitala a(fila,columna);

    while (true) {
      std::cout << "1 para cifrar" << '\n';
      std::cout << "2 para descifrado emisor" << '\n';
      std::cin >> intercambio;

      switch (intercambio) {
        case 1: {

                string mensajecifrado = a.Encriptar(mensaje);
                escribir_txt(mensajecifrado, documento3);
                std::cout << "-------gardado----------" << '\n';
                break;
              }

        case 2:  {

              // a.Desencriptar(mensajecifrado, columna, fila);
              // std::cout  << '\n';

              std::cout << "fila: " << '\n';
              std::cin >> fila;
              std::cout << "columna " << '\n';
              std::cin >> columna;
              texto=a.Desencriptar(leertxtparrafos(documento3), columna, fila);
              std::cout  << '\n';

              // texto=a.Desencriptar( leertxtparrafos(documento2) , leertxtparrafos(documento3) );
              escribir_txt(texto, documento4);



               break;
               }
      }
    }








    // a.Desencriptar("hroqueaoytwioi ue  y ee*ldeenty tyi*aos tuobuoi*  tma  i ui*qcaesveeiui*uos  isnhui*em cddt a i*",8 ,12);
    //a.Desencriptar("", columna, fila);
    //a.Desencriptar("", columna, fila);
    //  a.Desencriptar("", columna, fila);
   // a.Desencriptar("", columna, fila);


    return 0;
}
