#include<iostream>
#include <time.h>
#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;


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



ZZ algoritmo2(ZZ a1, ZZ b1){

ZZ a = a1;
ZZ b = b1;
ZZ r;
ZZ  pasos (1);
cout<<"a "<<a<<" "<<"b "<<b<<endl;

r = a / b;
r = a - (b * r);
if (r == 0){
return b;
}
else if (r > b / 2)
{
r = b - r;
pasos += 1;;
}
a = b;
b = r;
algoritmo2(a, b);
}



ZZ  euclideanO(ZZ  m,ZZ  n){

    int i=0;
    ZZ  a=m;
    ZZ  b=n;

    ZZ  r=modulo(a,b);

   while(r!=0){
    cout<<"a "<<a<<" "<<"b "<<b<<" "<<"mod (a,b) "<<"= "<< r <<endl;
       i++;
       a=b;
       b=r;
       r=modulo(a,b);
   }


    std::cout <<"vueltas " << i << '\n';

    return b;
}




ZZ  Euclidesmcd(ZZ  a,ZZ  b,ZZ  i){
  i++;
  cout<<"a "<<a<<" "<<"b "<<b<<endl;
  std::cout <<"vueltas " << i << '\n';
  if (b==0){
    return a;
  }
  return Euclidesmcd(b,modulo(a,b),i);

}

  ZZ valor_absoluto( ZZ a){
  if (a>0) {
    return a;
  }
  return a*-1;
}


ZZ  BinaryGcd(ZZ  a, ZZ  b, int cont){
    //unsigned t0, t1;
  //  t0=clock();
    cont++;
     cout<<"a= "<<a<<"  b= "<<b<<endl;
    if(b>a){
        return BinaryGcd(b,a,cont);
    }
    if(b==0){
      //  t1 = clock();
    //    double time = (double(t1-t0)/CLOCKS_PER_SEC);
//        cout << "Execution Time: " << time << endl;
        cout << "Numero de vueltas: " << cont << endl;
        return a;
    }
    if((a&1)==0 && (b&1)==0){
        return (BinaryGcd((a>>1),(b>>1),cont))<<1;
    }
    if((a&1)==0 &&(b&1)==1){
        return BinaryGcd((a>>1),b,cont);
    }
    if((a&1)==1&&(b&1)==0){
        if(a<0){
            a*=-1;
        }
        if(b<0){
            a*=-1;
        }
        return BinaryGcd(a,(b>>1),cont);
    }
    else{
        return BinaryGcd((a-b)>>1,b,cont);
    }
}

ZZ menorResto(ZZ a, ZZ b){
    ZZ r;
    ZZ d,r1,r2;
    while(b!=0){
        cout<<"a "<<a<<" "<<"b "<<b<<endl;
        d=a/b;
        r1=a-b*d;
        r2=b*(d+1)-a;
        r=r1<r2?r1:r2;
        //cout<<" d:"<<d;
        //cout<<" r1:"<<r1;
        //cout<<" r2:"<<r2;
        //r=abs(a-b*((double)(a)/(double)(b)+0.5));
        //cout<<" r:"<<r<<endl;
        a=b;
        b=r;
    }
    return a;
}


ZZ Min(ZZ a, ZZ b){
    ZZ m;
    m = a;
    if(a>b){
        m=b;
    }
    return m;
}

ZZ   lsbgcd(ZZ u, ZZ v){
    ZZ t, aux;
    int s;
    while(v!=0){
        cout<<"a "<<u<<" "<<"b "<<v<<endl;

        s=0;
        while((v<< s)<= u){
        cout<<"a "<<u<<" "<<"b "<<v<<endl;
        s++;
    }
       s=s-1;
       t=Min(u-(v<<s),(v<<(s+1))-u);
          u=v;
          v=t;
          if(u<v){
              aux=u;
              u=v;
              v=aux;
          }
        }
    return u;
}


int main(){


    ZZ a ;
    ZZ b ;
    // cin>>a;
    // cin>>b;




    a = conv<ZZ>("260");
    b = conv<ZZ>("412");




    unsigned t0, t1;

    t0=clock();
    menorResto(a,b);
    t1 = clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;


    // a = conv<ZZ>("9821258765");
    // b = conv<ZZ>("4671258797");


    // t0=clock();
    // euclideanO(a,b);
    // t1 = clock();

    //  time = (double(t1-t0)/CLOCKS_PER_SEC);
    // cout << "Execution Time: " << time << endl;

    // a = conv<ZZ>("982125873546234");
    // b = conv<ZZ>("767125873540937");



    // t0=clock();
    // euclideanO(a,b);
    // t1 = clock();

    //  time = (double(t1-t0)/CLOCKS_PER_SEC);
    // cout << "Execution Time: " << time << endl;










    return 0;
}
