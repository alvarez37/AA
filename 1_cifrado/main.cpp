#include <iostream>
#include "cifrado.h"
using namespace std;

int main()
{
    string mensaje;
   cout<<"ingrese mensaje: ";
   getline(cin,mensaje);
   cifrado a("");
   string encriptado=a.Encriptar(mensaje);

   std::cout << '\n';
   std::cout << '\n';

   cout<<"desencriptado:"<< a.Desencriptar(encriptado, a.get_clav() )<<endl;


    return 0;
}
