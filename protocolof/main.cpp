#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "protocolo.h"


using namespace std;

  int string_a_entero (string tex_numero){
  int numero;
  numero = atoi(tex_numero.c_str());
  return numero;
}


string entero_a_string(int x) {
      return static_cast<std::ostringstream*>(&(std::ostringstream() << x))->str();
  }


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


  string clave_anigma="abc";
  protocolo p1(clave_anigma);


  string documento1="doc1.txt";
  string documento2="doc2.txt";
  string documento3="doc3.txt";
  string documento4="doc4.txt";
  string documento5="doc5.txt";



  string texto;
  int intercambio;

  while (true) {
    std::cout << "1 para cifrar" << '\n';
    std::cout << "2 para descifrado emisor" << '\n';
    std::cin >> intercambio;

    switch (intercambio) {
      case 1: {
              std::cout << "mensaje  " << '\n';
              std::cin >> texto;
              texto=p1.encriptaProtocolo(texto);;
              escribir_txt(p1.get_alfabeto(), documento1);
              escribir_txt(p1.get_vigenere(), documento2);
              escribir_txt(texto, documento3);
              escribir_txt(entero_a_string(p1.clave_a()), documento4);
              escribir_txt(entero_a_string(p1.clave_b()), documento5);

              std::cout << "-------gardado----------" << '\n';
              break;
            }

      case 2:  {
//qxbyupcoavsdltrgjmiefznwkh,qxy,,4,1,23

               texto=p1.desencriptaProtocolo(leertxt(documento1),leertxt(documento2),leertxt(documento3),string_a_entero(leertxt(documento4)),string_a_entero(leertxt(documento5)));
              // texto=p1.desencriptar("obltzqfnxvmiesjkcharuywdgp","znvq","xjxw",11,1);;

               break;
             }
    }
  }







    return 0;
}
