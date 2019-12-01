#ifndef matlibrc4
#define matlibrc4

#include <NTL/ZZ.h>
#include <iostream>
#include <vector>

#include <string>

using namespace std;
using namespace NTL;


string corta_string_1 (string & texto, int  n_caracteres) {
  string cadena_de_salida;
  int tam=texto.size();
  if (tam>=n_caracteres) {
    cadena_de_salida = texto.substr(0,n_caracteres);
    texto=texto.substr(n_caracteres,texto.size());
    tam=texto.size();
    if (tam<n_caracteres)
    {
      texto.resize(0);
    }
    

    return cadena_de_salida;
  }

  cadena_de_salida=texto;
  texto.resize(0);
  return cadena_de_salida;
}


ZZ getMod(ZZ d, ZZ a){
    ZZ q,r;
    q = d/a;
    r = d-(q*a);
    if(r<0){
        r+=a;
    }
    return r;
}

ZZ algEuclides(ZZ a, ZZ b){
    ZZ m;
    m = getMod(a,b);
    while(m!=0){
        a=b;
        b=m;
        m=getMod(a,b);
    }
    return b;
}

ZZ algEuclidesExt(ZZ a, ZZ b){
    ZZ x,y,x2,x1,y2,y1,q,r;
    if(b==0){
        x2=1;
    }else{
        x=0;
        y=0;
        x1=0;
        x2=1;
        y2=0;
        y1=1;
        q=0;
        r=0;
        while(b!=0){
            q = a/b;
            r=getMod(a,b);
            x=x2-q*x1;
            y=y2-q*y1;
            a=b;
            b=r;
            x2=x1;
            x1=x;
            y2=y1;
            y1=y;
        }
    }
    return x2;

}

ZZ Inversa(ZZ a,ZZ l){
    a = algEuclidesExt(a,l);
    if(a<0){
        a = a+l;
    }else if(a>=l){
        a=getMod(a,l);
    }
    //cout<<"Inversa: "<<a<<endl;
    return a;
}
int getModInt(int d,int a){
    int q = d/a;
    int r = d-(q*a);
    if(r<0){
        r+=a;
    }
    return r;
}
void shiftLeft(vector<bool> &a,int inicio,int fin){
    bool val;
    val = a[inicio];
    a.erase(a.begin());
    a.insert(a.begin()+fin,val);
}
void shiftRight(vector<bool> &a,int inicio,int fin){
    bool val;
    val = a[fin];
    a.erase(a.begin()+fin);
    a.insert(a.begin()+inicio,val);
}











ZZ genetareRandom(int sizeSeed,int sizeNumber,int numPar,int loops){
    vector<bool> seed;
    bool control = 1;
    int ini,increment,fin;
    ZZ res;
    ini = 0;
    long n = 0;
    res = 0;
    int l = 2;
    increment = sizeNumber/numPar;
    if(getModInt(sizeNumber,numPar)!=0){
        increment+=1;
    }
    fin = increment-1;

    for(int i = 0;i<sizeSeed;i++){
        int * foo;
        foo = new  int [1];
        int val = getModInt((*foo)+(time(0)),2);
        seed.push_back(val);
        delete[] foo;

    }
    for(int i = 0;i<sizeNumber;i++){
        int temp;
        temp = seed[i]+seed[i+1];
        if(temp>=2){
            temp = getModInt(temp,l);
        }
        seed.push_back(temp);
    }
    for(int j = 0;j<numPar;j++){
        for(int k = 0 ;k<loops;k++){
            if(control){
                shiftLeft(seed,ini,fin);
            }else{
                shiftRight(seed,ini,fin);
            }
            control = !control;
        }

        ini+=increment;
        fin+=increment;
        if(fin>=seed.size()){
            fin = seed.size()-1;
        }
    }
    seed[sizeNumber-1]=1;
    for (int i = sizeNumber;i>=1;i--){
        if (seed[i-1]){
            res+=power2_ZZ(n);
        }
        n = n + 1;
    }
    //cout<<res<<endl;
    return res;

}
ZZ MulMod(ZZ a, ZZ b, ZZ mod){
    ZZ x,y,c;
    c=2;
    x = 0;
    y = getMod(a,mod);
    while (b > 0)
    {
        if (getMod(b,c) == 1)
        {
            x = getMod((x + y),mod);
        }
        y = getMod((y * c),mod);
        b = b/c;
    }
    return getMod(x,mod);
}

ZZ modularExpo(ZZ a,ZZ b, ZZ m){
    ZZ ans,c;
    ans =1;
    c=2;
    while(b !=0 ) {
        if(getMod(b,c) == 1) {
            ans = getMod(ans*a,m);
        }
        a = getMod(a*a,m);
        b = b/2;
    }
    return ans;
}

ZZ fingGen(ZZ p){
    ZZ g,c,q;
    q=(p-1)/2;
    c=2;
    for(int i=1;i<p-1;i++){
        g=i;
        if((modularExpo(g,c,p)!=1)&&(modularExpo(g,q,p)!=1)){
            return g;
        }
    }
    return g;
}



bool fermatTest(int numTests,ZZ pseudoPrime){
    ZZ a,c;
    c=1;
    if(pseudoPrime==2){
        return 1;
    }
    for(int i = 0;i< numTests;i++){
        a = genetareRandom(16,1024,16,8);
        if(a>=pseudoPrime){
            a=getMod(a,pseudoPrime);
        }
        if(modularExpo(a,(pseudoPrime-c),pseudoPrime)==1){
            return 1;
        }
    }
    return 0;
}


ZZ pow_zz(ZZ a ){
  ZZ tam(2);
  for (ZZ i (1); i < a; i++) {
    tam*=2;
  }
  return tam;
}

string binario_convertir(ZZ numero){

 ZZ dividendo, resto, divisor(2);
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



 return binario;
}





string binario;
void convetirBits(vector <string> a)
{
    int num;
    for(int i=0;i<a.size();i++)
    {
        num = stoi(a[i]);
        string cad;
        if(num > 0)
        {
            while(num>0)
            {
               if(num%2 == 0)
                    cad = "0" + cad;
                else
                    cad = "1" + cad;
                    num = num/2;
            }
            binario+=cad;
        }
    }
    //binario = binario.substr(0,256);
}

ZZ convertBinaryToZZ(string binary){
    ZZ res;
    ZZ base;
    base = 2;
    res = 0;
    for(long i = 0; i<binary.size();++i){
        if(binary[i]=='1'){
            res += power(base,i);
        }
    }

    return res;
}

string zToString(const ZZ &z) {
        std::stringstream buffer;
        buffer << z;
        return buffer.str();
}


ZZ Modulo(ZZ a, ZZ b)
{
    ZZ res,q,r;
    q = a / b;
    r = a - q * b;
    if (r < 0) {
        r += b;
    }
    return r;
}

ZZ getCPUCicles() {
    ZZ n(__rdtsc());
    return n;
}


#endif // matlibrc4
