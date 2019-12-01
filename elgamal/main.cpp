#include <iostream>
#include"elgamal.h"

using namespace std;

int main(){

  int opcion;
  string mensaje="hola como";
  ZZ e1,e2,p;
  string c2;
  int bits=20;
  gamal receptor(bits);
  while(true){
      cout<<"1 para decifrar : "<<endl;
      cout<<"2 para cifrar  : "<<endl;
      cin>>opcion;
      if(opcion==1){
          cout<<" c2: "<<endl;
          cin>>c2;
          cout<<"Mensaje decifrado: "<<receptor.decifrar(c2)<<endl;
      }
      if(opcion==2){
          cout<<" e1: "<<endl;
          cin>>e1;
          cout<<" e2: "<<endl;
          cin>>e2;
          cout<<" p: "<<endl;
          cin>>p;
          gamal emisor(e1,e2,p,bits);
          emisor.cifrar(mensaje);

      }
  }

    return 0;
}
