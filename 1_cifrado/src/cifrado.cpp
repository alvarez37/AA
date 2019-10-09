#include "cifrado.h"
int modulo(int a,int tam_array){
  int residuo;
  if (a<0) {
    residuo=a-((a/tam_array)-1)*tam_array;
  }

  else{
    residuo=a-(a/tam_array)*tam_array;
  }
  return residuo;
}

void cifrado::aleatorios ( int x , string cadena_cifrada[]) {

  int random;

  for (size_t i = 0; i < x; i++) {
    random=rand()%alfabeto.size();
    cadena_cifrada[i] = static_cast<std::ostringstream*>(&(std::ostringstream() << random))->str();
  }

  for (size_t i = 0; i < x; i++) {
    std::cout << cadena_cifrada[i] << '\t';
  }

}

 string cifrado::clave_a( string mensaje[] , int a){

   string clave;
   int posicion;

   for (size_t i = 0; i < a; i++) {
       int b =  atoi(mensaje[i].c_str());

       clave+=alfabeto[b];
   }
      std::cout << '\n';

    std::cout <<"clave : "<< clave << '\n';

   return clave;
 }

 string cifrado::Encriptar(string mensaje ){
   int tam_alf=alfabeto.size();

   string cadena_cifrada_a[mensaje.size()];
   aleatorios(mensaje.size() , cadena_cifrada_a);

   string mensaje_cifrado;
   int suma;
   std::cout << '\n';

   clave_s=clave_a( cadena_cifrada_a , mensaje.size());
   for (size_t i = 0; i < mensaje.size(); i++) {
     suma= modulo( (alfabeto.find(mensaje[i]) + alfabeto.find(clave_s[i])) , alfabeto.size() );
     std::cout << "suma " << suma << " = " << alfabeto.find(mensaje[i])  << " + " << alfabeto.find(clave_s[i]) << " % " << alfabeto.size() << '\n';
     mensaje_cifrado+=  alfabeto[suma];
  }

    std::cout << mensaje_cifrado << '\n';
   return mensaje_cifrado;
 }

 string cifrado::get_clav(){

   return clave_s;
 }

string cifrado::Desencriptar(string mensaje,string clave){
   int tam_alf=alfabeto.size();

   string cadena_cifrada_a[mensaje.size()];
   aleatorios(mensaje.size() , cadena_cifrada_a);

   string mensaje_cifrado;
   int suma;
   std::cout << '\n';

   string clave_s=clave;
   for (size_t i = 0; i < mensaje.size(); i++) {
     suma= modulo( (alfabeto.find(mensaje[i]) - alfabeto.find(clave_s[i])) , alfabeto.size() );
     std::cout << "suma " << suma << " = " << alfabeto.find(mensaje[i])  << " - " << alfabeto.find(clave[i]) << '\n';
     mensaje_cifrado+=  alfabeto[suma];
  }

    std::cout << mensaje_cifrado << '\n';
   return mensaje_cifrado;
 }



cifrado::cifrado(string x){
  std::cout << x<< '\n';
}
