#include "rsa.h"
#include "matlib.h"
#include "criba.h"
#include "RC4.h"
#include <math.h>

rsa::rsa(int bits)
{

  RC4 r(bits);

  for (size_t i = 0; i < 10; i++)
  {
    cout <<" "<< r.get_numero() << endl<< endl;
  }

  tam_array = alf.size();
  q = r.get_numero();
  p = r.get_numero();
  n = p * q;
  phi_n = (p - 1) * (q - 1);

  e = r.get_numero();
  while (!(mcd(e, phi_n)== 1))
  {
     e = r.get_numero();
  }





/* 
  criba c1(pow(2,bits););
  tam_array=alf.size();
  q=ZZ(c1.retornar(bits);
  p=ZZ(c1.retornar(bits);
  n=p*q;
  phi_n=(p-1)*(q-1);

  e=ZZ(c1.retornar(bits);
  while (true) {
    if (mcd(e,phi_n)==1) {
      break;
    }
    e=ZZ(c1.retornar(bits);
    }

 */



  /*     tam_array=alf.size();
    q=GenPrime_ZZ(bits);
    p=GenPrime_ZZ(bits-1);
    n=p*q;
    phi_n=(p-1)*(q-1);

    e=GenPrime_ZZ(bits);
    while (true) {
    if (mcd(e,phi_n)==1) {
      break;
    }
    e=GenPrime_ZZ(bits);
    } */

  d = mod_inverso(e, phi_n);
  d = modulo(d, phi_n);

  std::cout << "-------------------------" << '\n';
  std::cout << "p: " << p << '\n';
  std::cout << "q: " << q << '\n';
  std::cout << "n: " << n << '\n';
  std::cout << "phi_n: " << phi_n << '\n';
  std::cout << "e: " << e << '\n';
  std::cout << "d: " << d << '\n';
  std::cout << "tam_array: " << tam_array << '\n';
  std::cout << "-------------------------" << '\n';
}

rsa::rsa(string e_, string n_)
{
  e = string_a_zz(e_);
  n = string_a_zz(n_);
  std::cout << "-------------------------" << '\n';
  std::cout << "n: " << n << '\n';
  std::cout << "e: " << e << '\n';
  std::cout << "-------------------------" << '\n';
}

string rsa::cifrado(string txt)
{
  //TODO: capturar los digitos de n
  n_string = zz_a_string(n);
  n_string_tam = n_string.size();
  mensaje_con_0 = completar_ceros_string(txt, alf);

  string txt_cifrado_retorno;
  ZZ base;
  ZZ base_por_exponete;

  std::cout << "---------------------------------------------" << '\n';
  std::cout << txt << '\n';
  std::cout << mensaje_con_0 << '\n';
  std::cout << "---------------------------------------------" << '\n';
  for (int i = 0; i < mensaje_con_0.size(); i++)
  {
    base = string_a_zz(corta_string(mensaje_con_0, n_string_tam - 1));
    base_por_exponete = elevar_a_la_potencia_n(base, e, n);
    std::cout << "base " << base << " palabra_array [" << i << "] " << base_por_exponete << '\n';
    txt_cifrado_retorno += completar_ceros(zz_a_string(base_por_exponete), n_string_tam);
  }

  std::cout << "---------------------------------------------" << '\n';

  return txt_cifrado_retorno;
}

string rsa::descifrado(string txt)
{
  string txt_descifrado_retorno;
  string txt_descifrado;

  ZZ base;
  ZZ base_por_exponete;

  for (int i = 0; txt.size() > 0; i++)
  {
    base = string_a_zz(corta_string(txt, n_string_tam));
    base_por_exponete = elevar_a_la_potencia_n(base, d, n);
    std::cout << "base " << base << " palabra_array [" << i << "] " << base_por_exponete << '\n';
    txt_descifrado += completar_ceros(zz_a_string(base_por_exponete), n_string_tam - 1);
    //txt_cifrado_retorno.insert(0,zz_a_string(base_por_exponete));
  }

  std::cout << "mensaje desifrado " << txt_descifrado << '\n';
  std::cout << "mensaje de salida  " << string_2_block(txt_descifrado, alf) << '\n';

  return string_2_block(txt_descifrado, alf);
}

ZZ rsa::get_p() { return p; }
ZZ rsa::get_q() { return q; }
string rsa::get_n() { return zz_a_string(n); }
string rsa::get_e() { return zz_a_string(e); }
