#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include "afin.h"

using namespace std ;




int main(){

  afin p1;
  int a,b;
  a=p1.clave_a();
  b=p1.clave_b();
  std::cout << a << '\n';
  std::cout << b << '\n';
  string tex="jean-carlos";
  std::cout << p1.cifrado(tex) << '\n';
  tex=p1.cifrado(tex);
  afin p2(a,b);
  std::cout << p2.descifrado(tex) << '\n';
  // std::cout << "j" << '\n';
  return 0;
}
