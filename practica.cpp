#include<iostream>
#include<string>
#include <sstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std ;

void aleatorios ( int x, int tam_alf , string cadena_cifrada[]) {

  int random;

  for (size_t i = 0; i < x; i++) {
    random=rand()%tam_alf;
    cadena_cifrada[i] = static_cast<std::ostringstream*>(&(std::ostringstream() << random))->str();
  }

  for (size_t i = 0; i < x; i++) {
    std::cout << "num = " << cadena_cifrada[i] << '\n';
  }

}

 string clave_a( string mensaje[], string alfabeto , int a ){
   string clave;
   int posicion;

   for (size_t i = 0; i < a; i++) {
       int b =  atoi(mensaje[i].c_str());

       clave+=alfabeto[b];
   }
      std::cout << '\n';

    std::cout << clave << '\n';

   return clave;
 }

 string mensaje_cifrado(string mensaje, string clave ,string alfabeto ){
   string mensaje_cifrado;
   int suma;
    std::cout << '\n';

   for (size_t i = 0; i < mensaje.size(); i++) {
     suma= (alfabeto.find(mensaje[i]) + alfabeto.find(clave[i])) % alfabeto.size() ;
    std::cout << "suma " << suma << " = " << alfabeto.find(mensaje[i])  << "  " << alfabeto.find(clave[i]) << '\n';
     mensaje_cifrado+= static_cast<std::ostringstream*>(&(std::ostringstream() << suma))->str();
  }

   return mensaje_cifrado;
 }


int main(){

  string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789 ";
  int tam_alf=alfabeto.size();

  string mensaje;
  getline(cin,mensaje);
  string cadena_cifrada[mensaje.size()];
  aleatorios(mensaje.size(),tam_alf , cadena_cifrada);


 string clave_s = clave_a( cadena_cifrada ,alfabeto ,mensaje.size());
 //std::cout << "clave: " << clave_s << '\n';

   string mensaje_c = mensaje_cifrado(mensaje, clave_s ,alfabeto);
       std::cout << '\n';

   std::cout << "mensaje_cifrado: " << mensaje_c << '\n';


 return 0;
}
