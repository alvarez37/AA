#include "scitala.h"

int modulo1(int a,int tam_array){
  int residuo;
  if (a<0) {
    residuo=a-((a/tam_array)-1)*tam_array;
  }

  else{
    residuo=a-(a/tam_array)*tam_array;
  }
  return residuo;
}


 string scitala::Encriptar(string mensaje){

   //std::cout << "tamanio del mensaje: " <<mensaje.size()<< '\n';
   for (size_t i = mensaje.size() ; i < fila*columna; i++) {
     mensaje+="w";
   }
   mensaje.resize(fila*columna);
  // std::cout << "tamanio del mensaje: " <<mensaje.size()<< '\n';


   string cadena_cifrada;
   cadena_cifrada.resize(mensaje.size());
   int contador=0;
   int iterador=0;


   for (size_t i = 0; i <  fila*columna; i++) {

    // std::cout << mensaje[iterador] << " " << iterador<< '\t';
     cadena_cifrada[i] += mensaje[iterador];
     // std::cout << cadena_cifrada[i] << '\n';
     iterador+=columna;
     if (iterador>mensaje.size()-1) {
     //  std::cout  << '\n';
       contador++;
       iterador=contador;
     }


   }

   //std::cout << "tamanio del mensaje cifrado: " <<cadena_cifrada.size()<< '\n';
   //std::cout << "salida: <" << cadena_cifrada <<">"<< '\n';
   return cadena_cifrada;

 }



 string scitala::Desencriptar(string mensaje , int fila , int columna ){

   std::cout << "tamanio del mensaje: " <<mensaje.size()<< '\n';

   string cadena_cifrada;
   cadena_cifrada.resize(mensaje.size());
   int contador=0;
   int iterador=0;


   for (size_t i = 0; i <  fila*columna; i++) {

     std::cout << mensaje[iterador] << " " << iterador<< '\t';
     cadena_cifrada[i] += mensaje[iterador];
     // std::cout << cadena_cifrada[i] << '\n';
     iterador+=columna;
     if (iterador>mensaje.size()-1) {
       std::cout  << '\n';
       contador++;
       iterador=contador;
     }


   }

   std::cout << "tamanio del mensaje cifrado: " <<cadena_cifrada.size()<< '\n';
   std::cout << "salida: " << cadena_cifrada << '\n';
   return cadena_cifrada;

 }


scitala::scitala(int x,int y){
  fila=x;
  columna=y;
}
