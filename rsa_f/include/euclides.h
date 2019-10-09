#ifndef euclides
#define euclides

#include <NTL/ZZ.h>
#include <iostream>
#include<vector>

#include <string>

using namespace std;
using namespace NTL;


string entero_a_string(int x) {

    if (x==0) {
      return "000";
    }
    if (x<10) {
      return "00"+static_cast<std::ostringstream*>(&(std::ostringstream() << x))->str();
    }
    if (x<100) {
      return "0"+static_cast<std::ostringstream*>(&(std::ostringstream() << x))->str();
    }
      return static_cast<std::ostringstream*>(&(std::ostringstream() << x))->str();
  }

string copletar_ceros_ascii(string texto){
  string cadena_de_salida;
  int ValeurASCII;
  for (int i = 0; i < texto.size(); i++) {
    ValeurASCII = static_cast<int>(texto[i]);
    cadena_de_salida+=entero_a_string(ValeurASCII);
     std::cout<< entero_a_string(ValeurASCII) << '\n';
  }


  return cadena_de_salida;
}




string string_a_ascii(string texto){

  string cadena_de_salida;
  int ValeurASCII;
  for (int i = 0; i < texto.size(); i++) {
    ValeurASCII =  static_cast<int>(texto[i]);
    cadena_de_salida+= static_cast<std::ostringstream*>(&(std::ostringstream() << ValeurASCII))->str();
  }


  return cadena_de_salida;
}


bool par (ZZ x){

    return ((x&1) == 1) ? 0:1;
}

ZZ mcd(ZZ m, ZZ n)
{
    ZZ cero = conv<ZZ>("0");
if (m == cero || n == cero)
return cero;

int s = 0;

while (par(m) && par(n))
{
m >>= 1;
n >>= 1;
s++;
}

while (par(n))
{
n >>= 1;
}

while (m != 0)
{
while (par(m))
{
m >>= 1;
}

if (m < n)
swap(m, n);

m -= n;
m >>= 1;
}
int dos = 2;

if (s == 0)
dos >>= 1;

for (int i = 0; i < s - 1; ++i)
{
dos <<= 1;
}


return dos * n;
}



ZZ modulo(ZZ a,ZZ tam_array){
  ZZ residuo;
  if (a<0) {
    residuo=a-((a/tam_array)-1)*tam_array;
  }

  else{
    residuo=a-(a/tam_array)*tam_array;
  }
  return residuo;
}

// ZZ mcd(ZZ dividendo,ZZ divisor){
//     ZZ residuo=modulo(dividendo,divisor);
//     while(residuo>0){
//         dividendo=divisor;
//         divisor=residuo;
//         residuo=modulo(dividendo,divisor);
//     }
//     return divisor;
// }

ZZ mod_inverso(ZZ a,ZZ b){
    ZZ p0,p1(1),pn(0),q,cont(0),total;
    ZZ uno(1),cero(0);
	ZZ r=a,modin=b;
    if(modulo(a,b)==uno)
        return uno;
	if((modulo(b,a))==cero){return cero;}

	else{
        r=modulo(a,b);
        while(r>uno){
            cont=cont+uno;
            total=b;
            b=r;
            q=(total/b);
            r=modulo(total,b);
            pn=modulo((p0-p1*q),modin);
            p0=p1;
            p1=pn;
        }
        if(r!=uno){return cero;}
	}
	return pn;
}

ZZ euclidesExtendido(ZZ a, ZZ b) {
	ZZ r1 = a;
	ZZ r2 = b;
	ZZ s1 (0);
	ZZ s2 (0);
	ZZ t1 (0);
	ZZ t2 (1);
	ZZ s (0) ;
	ZZ t (0) ;
	while (r2 > 0) {
		ZZ q = r1 / r2;
		ZZ r = r1 - q * r2;
		r1 = r2;
		r2 = r;
		s = s1 - q * s2;
		s1 = s2;
		s2 = s;
		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	s = s1;
	t = t1;
	return s;
}

int zz_a_entero(ZZ number)
{
    int n;
    conv(n,number);
    return n;
}

int string_a_entero (string tex_numero){
  int numero;
  numero = atoi(tex_numero.c_str());
  return numero;
}
ZZ elevar_a_la_potencia_n(ZZ x, ZZ n,ZZ mod){
  ZZ n_result=n/2;
  ZZ x_result=x;

  ZZ result_cuadro;
  ZZ result_mod;

  ZZ zz_n=x;
  int x_mod2;

  while (n_result>0) {

      result_cuadro=modulo(zz_n*zz_n,mod);
      zz_n=result_cuadro;

      if (n_result%2==1) {
        result_mod=modulo(result_cuadro*x_result,mod);
        x_result=result_mod;
      }

      n_result=n_result/2;

  }

  return x_result;
}
ZZ Phi(ZZ X){
    if(X==to_ZZ(1)){
        return to_ZZ(0);
    }
    if(ProbPrime(X)==true){
        return X-to_ZZ(1);
    }
    else{
        ZZ res=to_ZZ(1);
        for(ZZ i=to_ZZ("2");i<=X;i++){
            ZZ aux_num=to_ZZ(0);
            ZZ aux_res;
            long aux_pot=0;
                while(modulo(X,i)==to_ZZ(0)){
                aux_num=i;
                aux_pot++;
                X/=i;
                }
            if(aux_num!=0){
                aux_res=power(aux_num,aux_pot)-power(aux_num,aux_pot-1);
                res*=aux_res;
            }
        }
    return res;
    }
}
ZZ exp_eucliFerm(ZZ A,ZZ B,ZZ P){
    if(ProbPrime(P)==true&&modulo(A,P)!=0){///aplicando teorema pequeño de fermat primera version
        if((P-1)<B){
        ZZ aux=modulo(B,P-1);
            return elevar_a_la_potencia_n(A,aux,P);
        }
        if(modulo(B,P-1)==to_ZZ(0)){
            return to_ZZ(1);
        }
    }
    if(A<P){///aplicando teorema de euler segunda version
        ZZ Phi_P=Phi(P)+to_ZZ(1);
        if(Phi_P<B){
            ZZ aux=modulo(B,Phi_P);
            return modulo(A*elevar_a_la_potencia_n(A,aux,P),P);
        }
        if(Phi_P==B)return A;
    }
    return elevar_a_la_potencia_n(A,B,P);
}
ZZ inv_eucliferm(ZZ A,ZZ P){
    if(ProbPrime(P)==true&&modulo(A,P)!=0){///aplicando teorema pequeño de fermat
        return exp_eucliFerm(A,P-to_ZZ(2),P);
    }
    if(mcd(P,A)==to_ZZ(1)){///aplicando teorema de euler
        return exp_eucliFerm(A,Phi(P)-to_ZZ(1),P);
    }
    return mod_inverso(A,P);
}
ZZ restito(ZZ mensaje,ZZ DP,ZZ DQ,ZZ P,ZZ Q){
    ZZ P_1,P_2,P_1_aux,P_2_aux,Q_1,Q_2,A_1,A_2,D_0;
    ZZ P_aux=P*Q;
    P_1=P_aux/P;
    P_2=P_aux/Q;

        P_1_aux=modulo(P_1,P);
        P_2_aux=modulo(P_2,Q);

    Q_1=inv_eucliferm(P_1_aux,P);
    Q_2=inv_eucliferm(P_2_aux,Q);

    A_1=exp_eucliFerm(mensaje,DP,P);
    A_2=exp_eucliFerm(mensaje,DQ,Q);

    D_0=modulo((A_1*P_1*Q_1)+(A_2*P_2*Q_2),P_aux);

    return D_0;
}

string completar_ceros_string(string digitos,int y,int x) {
    string salida=digitos;
    for (int i = y; i < x; i++) {
        salida="0"+salida;
    }
    std::cout  <<"*************************************************************" <<salida;
    return salida;
  }



string string_a_string_numerico(string texto , string alf){
  string salida;

  for (size_t i = 0; texto[i] != '\0'; i++) {
    salida+=entero_a_string(alf.find(texto[i])+10);
  }

  return salida;
}

string zz_a_string(const ZZ &z) {
      std::stringstream buffer;
      buffer << z;
      return buffer.str();
  }



  ZZ string_a_zz(string message){
     NTL::ZZ number(NTL::INIT_VAL, message.c_str());
     return number;
   }



ZZ bloques_de_enteros(string &tex,ZZ n){
  ZZ numero;
  ZZ numero_de_salida;
  string numero_zz;
  string respaldo=tex;
  bool cambiar=true;

  for (int i=0 ; tex.size()>0 ; i++) {
      numero_zz+=tex.substr(0,2);
      numero=string_a_zz(numero_zz);

      respaldo=tex;
      tex=tex.substr(2,tex.size());

      if (numero > n) {
        tex=respaldo;
        break;
      }
      else{
        numero_de_salida=numero;

      }

      if(tex.size()==0 ) {
        break;

      }
      // if(tex.size()==0 and cambiar ) {
      //   cambiar=false;
      //   numero_de_salida=numero;
      // }

    }


    // std::cout << "-------------------------" << '\n';
    // std::cout<< "numero de salida "<< numero_de_salida <<'\n';
    // std::cout << "-------------------------" << '\n';
    // std::cout  << " cortado " << tex <<'\n';


  return numero_de_salida;
}


// TODO: rsa com blockes de uno a uno
ZZ bloques_de_enteros_atras(string &tex,ZZ n){
  string n_string=zz_a_string(n);
  int n_string_tam=n_string.size();
  // std::cout << n_string_tam << '\n';

  int tamanio=tex.size()-1;
  string numero_zz;
  string temp;

  ZZ numero;
  ZZ numero_de_salida;
  int cortar;
  int i;

  if (n_string_tam  < tex.size() ) {
    for ( i=0 ; numero < n  ; i++) {
      temp= tex[tamanio];
      numero_zz.insert(0,temp);
      tamanio--;
      std::cout << "numero  " << numero_zz << '\n';

      numero=string_a_zz(numero_zz);
      if (numero < n) {
        std::cout << "numero  " << numero_zz << '\n';

        numero_de_salida=numero;
      }
    }
     cortar=tex.size()-zz_a_string(numero_de_salida).size();
  }
  else{

    if (tex[tamanio-1] == '0' and tex[tamanio] == '0' ) {
      numero_de_salida=ZZ(0);
      cortar=tamanio;
    }
    else{

      numero_de_salida=string_a_zz(tex);
      cortar=0;
    }

  }

std::cout << "---------------------------------------------" << '\n';
std::cout  << "sin  cortar " << tex <<'\n';

   cortar=fabsf  (cortar);
   tex=tex.substr(0,cortar);
  std::cout<< "numero de salida "<< numero_de_salida <<'\n';

  std::cout  << " cortado " << tex <<'\n';
  std::cout << "---------------------------------------------" << '\n';


  return numero_de_salida;
}

string texto_de_salida_ascii(string texto){

  string cad1=texto;
  int tam=cad1.size();
  string cad2;
  string cadena_de_salida;

  string a;

  for (int i = 0;  ; i++) {

    if ( cad1.size() < 3) {
      a=string_a_entero(cad1);
      // std::cout << "a fin " << a << '\n';
      cadena_de_salida.insert(0,a);
      break;
    }
    else{

      cad2=cad1.substr(cad1.size()-3,cad1.size());
      a=string_a_entero(cad2);
      // std::cout << "a  " << a << '\n';

      cad1=cad1.substr(0,cad1.size()-3);
      cadena_de_salida.insert(0,a);

    }

  }

  return cadena_de_salida;
}


#endif // euclides










//TODO: rsa com blockes de uno a uno
//

// ZZ bloques_de_enteros(string &tex,ZZ n){
//   ZZ numero;
//   ZZ numero_de_salida;
//   string numero_zz;
//   int i;
//   for ( i=0 ; numero < n and tex[i] != '\0' ; i++) {
//     numero_zz+=tex[i];
//     numero=string_a_zz(numero_zz);
//     if (numero < n) {
//       numero_de_salida=numero;
//     }
//   }
//   std::cout << "-------------------------" << '\n';
//   std::cout << " sin cortar " << tex <<'\n';
//
//   if (i>0) {
//     i--;
//   }
//   tex=tex.substr(i,tex.size());
//   std::cout<< "numero de salida "<< numero_de_salida <<'\n';
//   std::cout  << " cortado " << tex <<'\n';
//   std::cout << "-------------------------" << '\n';
//
//
//   return numero_de_salida;
// }
//
//
//




// #include "rsa.h"
// #include "euclides.h"
//
// rsa::rsa(){
//   tam_array=alf.size();
//   bits=500;
//   RandomPrime(p,bits);
//   RandomPrime(q,bits);
//   n=p*q;
//   phi_n=(p-1)*(q-1);
//   RandomPrime(e,bits);
//
//   while (mcd(e,phi_n)!=1) {
//     RandomPrime(e,bits);
//     }
//
//   d= mod_inverso(e,phi_n);
//
//   std::cout << "-------------------------"  << '\n';
//   std::cout << "p: " << p << '\n';
//   std::cout << "q: " << q << '\n';
//   std::cout << "n: " << n << '\n';
//   std::cout << "phi_n: " << phi_n << '\n';
//   std::cout << "e: " << e << '\n';
//   std::cout << "d: " << d << '\n';
//   std::cout << "tam_array: " << tam_array << '\n';
//   std::cout << "-------------------------" << '\n';
//
// }
//
// rsa::rsa(string e_, string n_){
//   e=string_a_zz(e_);
//   n=string_a_zz(n_);
//   std::cout << "-------------------------"  << '\n';
//   std::cout << "n: " << n << '\n';
//   std::cout << "e: " << e << '\n';
//   std::cout << "-------------------------" << '\n';
//
// }
// string rsa::cifrado(string txt){
//   //TODO: capturar los digitos de n
//   n_string=zz_a_string(n);
//   n_string_tam=n_string.size();
//
//   mensaje_con_0=string_a_string_numerico(txt,alf);
//
//   string txt_cifrado_retorno;
//   int tam_array_entrada = txt.size();
//   ZZ base;
//   ZZ base_por_exponete;
//   std::cout << mensaje_con_0 << '\n';
//   for (int i = 0; tam_array_entrada >i ; i++) {
//     base= bloques_de_enteros(mensaje_con_0,ZZ(n));
//     base_por_exponete=elevar_a_la_potencia_n(base, e ,n);
//     std::cout  << " palabra_array [" << i << "] "<< base_por_exponete <<'\n';
//
//     txt_cifrado_retorno+=zz_a_string(base_por_exponete);
//
//   }
//   return txt_cifrado_retorno;
// }
//
//
// string rsa::descifrado(string txt){
//   string txt_descifrado_retorno;
//   string txt_descifrado;
//
//   int tam_array_entrada = txt.size();
//   ZZ base;
//   ZZ base_por_exponete;
//
//   for (int i = 0;txt [i] != '\0'; i++) {
//     base= bloques_de_enteros(txt,ZZ(n));
//     base_por_exponete=elevar_a_la_potencia_n(base, d,n);
//     std::cout  << " palabra_array [" << i << "] "<< base_por_exponete <<'\n';
//     txt_descifrado_retorno+=zz_a_string(base_por_exponete);
//   }
//   std::cout << "numero  " << txt_descifrado_retorno<< '\n';
//   for (int i = 0; i < txt_descifrado_retorno.size()-1; i+=2) {
//     int j = txt_descifrado_retorno[i] - '0';
//     j*=10;
//     int e = txt_descifrado_retorno[i+1] - '0';
//     int f=j+e-10;
//     std::cout << i<<" " <<alf[f] << '\n';
//     txt_descifrado +=alf[f];
//   }
//   return txt_descifrado;
// }
//
// ZZ rsa::get_p(){return p;}
// ZZ rsa::get_q(){return q;}
