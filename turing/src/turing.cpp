#include "turing.h"


string invertic_cad(string x){
  string salida;

  for (int i =  x.size()-1; i >= 0; i--) {
    salida+=x[i];
  }
  return salida;
}

string turing::alfabeto_aleatorios () {

  string cadena_salida;

  int arreglo[alfabeto1.size()];
  int aux = 0;

  srand(time(0));

  for(int i = 0; i < alfabeto1.size(); i++){
      aux = (rand() % alfabeto1.size());

      int aux2 = 0;

      while(aux2 < i){

          if(aux != arreglo[aux2])
              aux2++;

          else{
                  aux = ( rand() % alfabeto1.size());
                  aux2 = 0;

              }
      }
      arreglo[i] = aux;
      cadena_salida+=alfabeto1[aux];

      // cout << arreglo[i] << "\n";
  }

    return cadena_salida;
}

void cortar (string &alfabeto1,  int posicion1){

  string temp;

  temp=alfabeto1.substr(posicion1 ,alfabeto1.size()-posicion1);
  alfabeto1.resize(posicion1);
  alfabeto1=temp+alfabeto1;
  std::cout  << alfabeto1 << '\n';


}


string turing::Encriptar (string mensaje){

  std::cout << '\n' << mensaje << '\n';





  std::cout << "clave " <<clave<< '\n' << '\n';
  // alfabeto1_rojo=alfabeto_aleatorios();
    alfabeto1_rojo="skwpvyuriblqa hdmctzgefnxjo";

    std::cout <<"<"<< alfabeto1_rojo  <<">"<< '\n';
    std::cout <<" "<< alfabeto1 << '\n' << '\n';

    // alfabeto2_rojo=alfabeto_aleatorios();
    alfabeto2_rojo="phrkg mdqwbeyocxlzafsvnjtui";

    std::cout <<"<"<< alfabeto2_rojo  <<">"<< '\n';
    std::cout <<" "<< alfabeto1 << '\n' << '\n';

    // alfabeto3_rojo=alfabeto_aleatorios();
    alfabeto3_rojo="wrcpgjhozfmvlkyiased xtunqb";
    std::cout <<"<"<< alfabeto3_rojo  <<">"<< '\n';
    std::cout <<" "<< alfabeto1 << '\n' << '\n';
    string tem;

  std::cout << "+++++++++++++++++++++++++++++++++++++" << '\n';
  string alfabetos ="abcdefghijklmnopqrstuvwxyz ";

  tem=clave[0];
  int pos=alfabetos.find(tem);
  cortar( alfabeto1, pos);
  std::cout <<"<"<< alfabeto1_rojo  <<">"<< '\n'<< '\n';

  tem=clave[1];
  pos=alfabetos.find(tem);
  std::cout << tem << '\n';
  cortar( alfabeto2, pos);
  std::cout <<"<"<< alfabeto2_rojo  <<">"<< '\n'<< '\n';


  tem=clave[2];
  pos=alfabetos.find(tem);
  std::cout << tem << '\n';

  cortar( alfabeto3, pos);
  std::cout <<"<"<< alfabeto3_rojo  <<">"<< '\n'<< '\n';
  std::cout << "+++++++++++++++++++++++++++++++++++++" << '\n';


  int iterador;
  int rotar_rotor=0;
  string temporal;
  string mensaje_cifrado;


    for (size_t i = 0; i < mensaje.size(); i++) {

      if (i>=4){
        cortar( alfabeto1,1);
        std::cout << alfabeto1_rojo  << '\n';
      }
      if (i>=8){
        cortar( alfabeto1,1);
        cortar( alfabeto3,1);
        std::cout << alfabeto2_rojo  << '\n';

      }
      if (i>=12){
        cortar( alfabeto1,1);
        cortar( alfabeto2,1);
        cortar( alfabeto3,1);

        std::cout << alfabeto3_rojo  <<'\n';
      }

        iterador=alfabeto1.find(mensaje[i]);
        temporal=alfabeto1_rojo[iterador];
        std::cout << "temporal  " << temporal<< '\n';

        iterador=alfabeto2.find(temporal);
        temporal=alfabeto2_rojo[iterador];
        std::cout << "temporal  " << temporal<< '\n';


        iterador=alfabeto3.find(temporal);
        temporal=alfabeto3_rojo[iterador];
        std::cout << "temporal  " << temporal<< '\n'<< '\n';

        mensaje_cifrado+=temporal;
        rotar_rotor++;

    }

    std::cout << mensaje_cifrado << '\n';

  return mensaje_cifrado;
}



string turing::Desencriptar (string mensaje){

  string alfabeto1 ="abcdefghijklmnopqrstuvwxyz ";
  string alfabeto2 ="abcdefghijklmnopqrstuvwxyz ";
  string alfabeto3 ="abcdefghijklmnopqrstuvwxyz ";

  clave=mensaje.substr(0,3);
  mensaje=mensaje.substr(clave.size(),mensaje.size());

  alfabeto1_rojo=mensaje.substr(0,alfabeto1.size());
  mensaje=mensaje.substr(alfabeto1_rojo.size(),mensaje.size());

  alfabeto2_rojo=mensaje.substr(0,alfabeto1.size());
  mensaje=mensaje.substr(alfabeto1_rojo.size(),mensaje.size());

  alfabeto3_rojo=mensaje.substr(0,alfabeto1.size());
  mensaje=mensaje.substr(alfabeto1_rojo.size(),mensaje.size());

  std::cout << "clave " <<clave<< '\n' << '\n';
  std::cout << "mensaje: " << mensaje<< '\n';


  std::cout << "+++++++++++++++++++++++++++++++++++++" << '\n';
  string alfabetos ="abcdefghijklmnopqrstuvwxyz ";

  cortar( alfabeto1, alfabetos.find(clave[0]));
  std::cout << alfabeto1_rojo  <<'\n'<< '\n',

  cortar( alfabeto2, alfabetos.find(clave[1]));
  std::cout <<alfabeto2_rojo << '\n'<< '\n',

  cortar( alfabeto3, alfabetos.find(clave[2]));
  std::cout << alfabeto3_rojo  << '\n'<< '\n',

  std::cout << "+++++++++++++++++++++++++++++++++++++" << '\n';


  int iterador;
  string temporal;
  string mensaje_cifrado;


  for (size_t i = 0; i < mensaje.size(); i++) {
      std::cout << '\n' << '\n'<< '\n' << '\n';

      if (i>=4){
        cortar( alfabeto1,1);
        std::cout << alfabeto1_rojo  << '\n';
      }
      if (i>=8){
        cortar( alfabeto1,1);
        cortar( alfabeto3,1);
        std::cout << alfabeto2_rojo  << '\n';

      }
      if (i>=12){
        cortar( alfabeto1,1);
        cortar( alfabeto2,1);
        cortar( alfabeto3,1);

        std::cout << alfabeto3_rojo  <<'\n';
      }
        iterador=alfabeto3_rojo.find(mensaje[i]);
        temporal=alfabeto3[iterador];
        std::cout << "temporal  " << temporal<< '\n';

        iterador=alfabeto2_rojo.find(temporal);
        temporal=alfabeto2[iterador];
        std::cout << "temporal  " << temporal<< '\n';

        iterador=alfabeto1_rojo.find(temporal);
        temporal=alfabeto1[iterador];
        std::cout << "temporal  " << temporal<< '\n'<< '\n';

        mensaje_cifrado+=temporal;
    }

    std::cout << mensaje_cifrado << '\n';

  return mensaje_cifrado;
}



turing::turing(string x){clave=x;}
string turing::GetAlfabeto(){ return  alfabeto1_rojo+ alfabeto2_rojo+ alfabeto3_rojo;}
string turing::GetClave(){ return  clave;}
