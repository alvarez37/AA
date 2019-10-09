#include "protocolo.h"



string protocolo::get_alfabeto(){
    return  alfabeto1_rojo_get;
}

string protocolo::get_vigenere(){
    return  clave_Vigenere;
}

int protocolo::clave_a(){
    return a_;
}

int protocolo::clave_b(){
    return b_;
}

void cortara (string &alfabeto1,  int posicion1){

  string temp;

  temp=alfabeto1.substr(posicion1 ,alfabeto1.size()-posicion1);
  alfabeto1.resize(posicion1);
  alfabeto1=temp+alfabeto1;


}

string alfabeto_aleatorios () {

  string alfabeto1 ="abcdefghijklmnopqrstuvwxyz";

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


protocolo::protocolo(string xx_){
  clave_anigma=xx_;
}


string protocolo::encriptaProtocolo (string mensaje){

  string rotor1;
  string rotor2;
  string rotor3;
  std::cout << "******************************************************************" << '\n';
  std::cout <<"mensaje "<< mensaje << '\n' ;
  std::cout << "******************************************************************" << '\n'<< '\n';

  string alfabeto_aleatorio=alfabeto_aleatorios();
  alfabeto1_rojo_get=alfabeto_aleatorio;
  scitala s1(2,13);
  rotor1 = s1.Encriptar(alfabeto_aleatorio);
  rotor2 = rotor1;
  cortara(rotor2,1);
  rotor2 = s1.Encriptar(rotor2);

  rotor3 = rotor2;
  cortara(rotor3,1);
  rotor3 = s1.Encriptar(rotor3);



 cifrado a("");
 std::cout << "                               vigenere" << '\n'<< '\n';

 std::cout << "******************************************************************" << '\n'<< '\n';
 string encriptado=a.Encriptar(mensaje);
 std::cout << "******************************************************************" << '\n'<< '\n';



 clave_Vigenere=a.get_clav();
 std::cout << '\n';
 std::cout << '\n';
 std::cout << "                               enigma" << '\n'<< '\n';

 std::cout << "******************************************************************" << '\n'<< '\n';
turing turing1(clave_anigma);

 //turing1.set("abc");
 encriptado=turing1.Encriptar(rotor1,rotor2,rotor3,encriptado);

 std::cout << "******************************************************************" << '\n'<< '\n';

 // cout<<"desencriptado:"<< a.Desencriptar(encriptado, a.get_clav() )<<endl;

 std::cout << "                               afin" << '\n'<< '\n';

 std::cout << "******************************************************************" << '\n'<< '\n';
   afin p1;

   a_=p1.clave_a();
   b_=p1.clave_b();
   std::cout << a_ << '\n';
   std::cout << b_ << '\n';
   string tex=encriptado;
   tex = p1.cifrado(tex);
   std::cout << "******************************************************************" << '\n'<< '\n';
   std::cout << "salida  " << tex<< '\n';
  return tex;

}



string protocolo::desencriptaProtocolo (string alf , string vigenre_sms,string mensaje , int afin_a, int afin_b){

  string rotor1;
  string rotor2;
  string rotor3;

  std::cout << "******************************************************************" << '\n';
  std::cout <<"mensaje "<< mensaje << '\n' ;
  std::cout << "******************************************************************" << '\n'<< '\n';

  string alfabeto_aleatorio=alf;
  alfabeto1_rojo_get=alfabeto_aleatorio;
  scitala s1(2,13);
  rotor1 = s1.Encriptar(alfabeto_aleatorio);
  rotor2 = rotor1;
  cortara(rotor2,1);
  rotor2 = s1.Encriptar(rotor2);

  rotor3 = rotor2;
  cortara(rotor3,1);
  rotor3 = s1.Encriptar(rotor3);



  string txt;

   std::cout << "                               afin" << '\n'<< '\n';

   std::cout << "******************************************************************" << '\n'<< '\n';
   afin p2(afin_a,afin_b);
   txt = p2.descifrado(mensaje) ;
   std::cout << "******************************************************************" << '\n'<< '\n';
   std::cout << "                               enigma" << '\n'<< '\n';

   std::cout << "******************************************************************" << '\n'<< '\n';
   turing turing1(clave_anigma);
   txt=turing1.Desencriptar(rotor1,rotor2,rotor3,txt );
   std::cout << "******************************************************************" << '\n'<< '\n';




   std::cout << "                               vigenere" << '\n'<< '\n';

   cifrado a("");
   std::cout << "******************************************************************" << '\n'<< '\n';
   txt=a.Desencriptar(txt, vigenre_sms );
   cout<<"desencriptado: "<<txt<<endl;
   std::cout << "******************************************************************" << '\n'<< '\n';






  return txt;

}
