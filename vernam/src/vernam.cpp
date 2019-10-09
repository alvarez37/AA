#include "vernam.h"

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

int string_a_entero (string tex_numero){
  int numero;
  numero = atoi(tex_numero.c_str());
  return numero;
}

string xor_f(string a , string b){

  string binario;
  int tam=a.size();

  for (size_t i = 0; i < tam; i++) {
    if (a[i]== b[i]) {
      binario+="0";
    }
    else{
      binario+="1";
    }
  }


  return binario;
}

string binario(int numero){

 int dividendo, resto, divisor = 2;
 string binario = "";

 dividendo = numero;
 while(dividendo >= divisor){
 resto = dividendo % 2;
  if(resto == 1)
   binario = "1" + binario;
  else
   binario = "0" + binario;
   dividendo = dividendo/divisor;
 }
  if(dividendo == 1)
   binario = "1" + binario;
  else
   binario = "0" + binario;

  int binario_tam=binario.size();
  for (size_t i = binario_tam; i < 6; i++) {
    binario.insert(0,"0");
  }

 return binario;
}

int binario_a_decimal(string numero){

  int resultado=0;
  int tam=numero.size()-1;
  string a="1";
  int j=0;
  for (int i = tam; i>=0 ; i--,j++) {
    // std::cout << numero[i] << "  " << a[0]<< '\n';
    if (numero[i]== a[0] ) {

      resultado += pow(2, j);
      // std::cout << "result" << resultado<< '\n';
    }
  }

 return resultado;
}


void vernam::aleatorios ( int x , string cadena_cifrada[]) {

  int random;

  for (size_t i = 0; i < x; i++) {
    random=rand()%alfabeto.size();
    // random=rand()%alfabeto.size();
    clave_salida+= alfabeto[random];
    cadena_cifrada[i] = alfabeto[random];
    cadena_cifrada[i] = static_cast<std::ostringstream*>(&(std::ostringstream() << random))->str();

  }

  std::cout << '\n';
  std::cout << "aleatorios" << '\n';
  std::cout <<"<" << clave_salida << ">"<< '\n';


}

 void vernam::cadena_de_numero( string mensaje2[] , string mensaje){

   for (size_t i = 0; i < mensaje.size(); i++) {
        mensaje2[i]=static_cast<std::ostringstream*>(&(std::ostringstream() << alfabeto.find(mensaje[i])  ))->str();
      //  std::cout << "me olvide de ti " << mensaje2[i]<< '\n';
   }
 }






 string vernam::Encriptar(string mensaje ){

   int tam_alf=alfabeto.size();

   for (size_t i = 0; i < tam_alf; i++) {
     std::cout << alfabeto[i] << " [ " << i << " ] " << '\t';
   }

   string cadena_de_aleatorios[mensaje.size()];
   string cadena_de_num_mensaje[mensaje.size()];

   aleatorios(mensaje.size() , cadena_de_aleatorios);
   cadena_de_numero( cadena_de_num_mensaje , mensaje);

   string mensaje_vernam;
   int suma;
   std::cout << '\n';

   for (size_t i = 0; i < mensaje.size(); i++) {
     std::cout << cadena_de_aleatorios[i] << " = " ;
     std::cout << binario(string_a_entero( cadena_de_aleatorios[i] ));
     std::cout << " XOR ";
     std::cout << cadena_de_num_mensaje[i] << " = " ;

     std::cout << binario(string_a_entero( cadena_de_num_mensaje[i] ));
     std::cout << " = ";
     mensaje_vernam+= xor_f( binario(string_a_entero( cadena_de_aleatorios[i] )) , binario(string_a_entero( cadena_de_num_mensaje[i] ))  );
     std::cout << xor_f( binario(string_a_entero( cadena_de_aleatorios[i] )) , binario(string_a_entero( cadena_de_num_mensaje[i] ))  ) ;

     std::cout  << '\n';

  }
    std::cout <<"<"<< mensaje_vernam <<">"<< '\n';
   return mensaje_vernam;
 }


 void vernam::cortar_binario ( string x , string cadena_de_num_mensaje[]) {

   string tem;
   for (size_t i = 0; i < x.size()/6; i++) {
     tem=x.substr(i*6,6);
     cadena_de_num_mensaje[i]=tem;
   }
 }


 string vernam::Desencriptar(string mensaje , string clave ){


   string cadena_de_num_mensaje[mensaje.size()/6];
   string cadena_de_aleatorios[clave.size()];

   cortar_binario(mensaje , cadena_de_num_mensaje);

   for (size_t i = 0; i < clave.size(); i++) {
     cadena_de_aleatorios[i]= static_cast<std::ostringstream*>(&(std::ostringstream() <<  alfabeto.find( clave[i] ) ))->str();
   }


   string mensaje_vernam;
   int suma;
   std::cout << '\n';

   for (size_t i = 0; i < clave.size(); i++) {

     std::cout << cadena_de_aleatorios[i] << " = " ;
     std::cout << binario(string_a_entero( cadena_de_aleatorios[i] ));
     std::cout << " XOR ";
     std::cout <<  cadena_de_num_mensaje[i];
     std::cout << " = ";
     std::cout << xor_f( binario(string_a_entero( cadena_de_aleatorios[i] )) , cadena_de_num_mensaje[i]  ) ;
     std::cout << " => ";
     suma = binario_a_decimal(  xor_f( binario(string_a_entero( cadena_de_aleatorios[i] )) , cadena_de_num_mensaje[i]   ));
     std::cout << suma  << " mod " << alfabeto.size() << " = ";
     suma = modulo(suma, alfabeto.size());
     std::cout << suma << '\n';
     mensaje_vernam+=  alfabeto[suma];


  }
    std::cout << mensaje_vernam << '\n';
   return mensaje_vernam;
 }


string vernam::get_clave(){
  return clave_salida;
}

vernam::vernam(string x){
  std::cout << x<< '\n';
}





//
// #include "vernam.h"
//
// int modulo(int a,int tam_array){
//   int residuo;
//   if (a<0) {
//     residuo=a-((a/tam_array)-1)*tam_array;
//   }
//
//   else{
//     residuo=a-(a/tam_array)*tam_array;
//   }
//   return residuo;
// }
//
// int string_a_entero (string tex_numero){
//   int numero;
//   numero = atoi(tex_numero.c_str());
//   return numero;
// }
//
// string xor_f(string a , string b){
//
//   string binario;
//   int tam=a.size();
//
//   for (size_t i = 0; i < tam; i++) {
//     if (a[i]== b[i]) {
//       binario+="0";
//     }
//     else{
//       binario+="1";
//     }
//   }
//
//
//   return binario;
// }
//
// string binario(int numero){
//
//  int dividendo, resto, divisor = 2;
//  string binario = "";
//
//  dividendo = numero;
//  while(dividendo >= divisor){
//  resto = dividendo % 2;
//   if(resto == 1)
//    binario = "1" + binario;
//   else
//    binario = "0" + binario;
//    dividendo = dividendo/divisor;
//  }
//   if(dividendo == 1)
//    binario = "1" + binario;
//   else
//    binario = "0" + binario;
//
//   int binario_tam=binario.size();
//   for (size_t i = binario_tam; i < 6; i++) {
//     binario.insert(0,"0");
//   }
//  // cout << "En sistema binario " << numero<< " se escribe " << binario << endl;
//
//  return binario;
// }
//
// int binario_a_decimal(string numero){
//
//   int resultado=0;
//   int tam=numero.size()-1;
//   string a="1";
//   int j=0;
//   for (int i = tam; i>=0 ; i--,j++) {
//     // std::cout << numero[i] << "  " << a[0]<< '\n';
//     if (numero[i]== a[0] ) {
//
//       resultado += pow(2, j);
//       // std::cout << "result" << resultado<< '\n';
//     }
//   }
//
//
//  return resultado;
// }
//
//
// void vernam::aleatorios ( int x , string cadena_cifrada[]) {
//
//   int random;
//
//   for (size_t i = 0; i < x; i++) {
//     random=rand()%alfabeto.size();
//     cadena_cifrada[i] = alfabeto[random];
//     //cadena_cifrada[i] = static_cast<std::ostringstream*>(&(std::ostringstream() << random))->str();
//
//   }
//   std::cout << "aleatorios" << '\n';
//   std::cout <<"<";
//   for (size_t i = 0; i < x; i++) {
//     std::cout << cadena_cifrada[i] ;
//   }
//   std::cout <<">"<< '\n';
//
//
// }
//
//  void vernam::cadena_de_numero( string mensaje2[] , string mensaje){
//
//    for (size_t i = 0; i < mensaje.size(); i++) {
//         mensaje2[i]=static_cast<std::ostringstream*>(&(std::ostringstream() << alfabeto.find(mensaje[i])  ))->str();
//    }
//  }
//
//  string vernam::Encriptar(string mensaje ){
//    int tam_alf=alfabeto.size();
//
//    for (size_t i = 0; i < tam_alf; i++) {
//      std::cout << alfabeto[i] << " [ " << i << " ] " << '\t';
//    }
//
//    string cadena_de_aleatorios[mensaje.size()];
//    string cadena_de_num_mensaje[mensaje.size()];
//
//    aleatorios(mensaje.size() , cadena_de_aleatorios);
//    cadena_de_numero( cadena_de_num_mensaje , mensaje);
//
//    for (size_t i = 0; i < mensaje.size(); i++) {
//      string a = cadena_de_aleatorios[i];
//      cadena_de_aleatorios[i]= static_cast<std::ostringstream*>(&(std::ostringstream() <<  alfabeto.find( a ) ))->str();
//      std::cout << cadena_de_aleatorios[i] << '\n';
//    }
//
//
//
//    string mensaje_vernam;
//    int suma;
//    std::cout << '\n';
//
//    for (size_t i = 0; i < mensaje.size(); i++) {
//      std::cout << cadena_de_aleatorios[i] << " = " ;
//      std::cout << binario(string_a_entero( cadena_de_aleatorios[i] ));
//      std::cout << " XOR ";
//      std::cout << cadena_de_num_mensaje[i] << " = " ;
//
//      std::cout << binario(string_a_entero( cadena_de_num_mensaje[i] ));
//      std::cout << " = ";
//      std::cout << xor_f( binario(string_a_entero( cadena_de_aleatorios[i] )) , binario(string_a_entero( cadena_de_num_mensaje[i] ))  ) ;
//      std::cout << " => ";
//      suma = binario_a_decimal(  xor_f( binario(string_a_entero( cadena_de_aleatorios[i] )) , binario(string_a_entero( cadena_de_num_mensaje[i] ))  ) );
//      std::cout << suma  << " mod " << alfabeto.size() << " = ";
//      suma = modulo(suma, alfabeto.size());
//      std::cout << suma << '\n';
//      mensaje_vernam+=  alfabeto[suma];
//   }
//     std::cout <<"<"<< mensaje_vernam <<">"<< '\n';
//    return mensaje_vernam;
//  }
//
//
//
//
//  string vernam::Desencriptar(string mensaje , string clave ){
//    int tam_alf=alfabeto.size();
//
//    string cadena_de_num_mensaje[mensaje.size()];
//    string cadena_de_aleatorios[clave.size()];
//
//    cadena_de_numero( cadena_de_num_mensaje , mensaje);
//
//    for (size_t i = 0; i < mensaje.size(); i++) {
//      cadena_de_aleatorios[i]=mensaje[i];
//      cadena_de_num_mensaje[i]=clave[i];
//    }
//
//    for (size_t i = 0; i < mensaje.size(); i++) {
//      cadena_de_aleatorios[i]= static_cast<std::ostringstream*>(&(std::ostringstream() <<  alfabeto.find( clave[i] ) ))->str();
//      // std::cout << cadena_de_aleatorios[i] << '\n';
//      cadena_de_num_mensaje[i]= static_cast<std::ostringstream*>(&(std::ostringstream() <<  alfabeto.find( mensaje[i] ) ))->str();
//      // std::cout << mensaje[i] << '\n';
//    }
//
//    string mensaje_vernam;
//    int suma;
//    std::cout << '\n';
//
//    for (size_t i = 0; i < mensaje.size(); i++) {
//
//      std::cout << cadena_de_aleatorios[i] << " = " ;
//      std::cout << binario(string_a_entero( cadena_de_aleatorios[i] ));
//      std::cout << " XOR ";
//      std::cout << cadena_de_num_mensaje[i] << " = " ;
//
//      std::cout << binario(string_a_entero( cadena_de_num_mensaje[i] ));
//      std::cout << " = ";
//      std::cout << xor_f( binario(string_a_entero( cadena_de_aleatorios[i] )) , binario(string_a_entero( cadena_de_num_mensaje[i] ))  ) ;
//      std::cout << " => ";
//      suma = binario_a_decimal(  xor_f( binario(string_a_entero( cadena_de_aleatorios[i] )) , binario(string_a_entero( cadena_de_num_mensaje[i] ))  ) );
//      std::cout << suma  << " mod " << alfabeto.size() << " = ";
//      suma = modulo(suma, alfabeto.size());
//      std::cout << suma << '\n';
//      mensaje_vernam+=  alfabeto[suma];
//
//
//   }
//     std::cout << mensaje_vernam << '\n';
//    return mensaje_vernam;
//  }
//
//
// vernam::vernam(string x){
//   std::cout << x<< '\n';
// }
