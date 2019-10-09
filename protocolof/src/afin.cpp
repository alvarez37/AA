#include "afin.h"

int afin::clave_a(){
    return a;
}

int afin::clave_b(){
    return b;
}

int afin::inversa(){
    return inversa_int;
}

int modulo(int a, int tam_array){
    int residuo;
    if (a<0) {
      residuo=a-((a/tam_array)-1)*tam_array;
    }

    else{
      residuo=a-(a/tam_array)*tam_array;
    }
    return residuo;
}

int euclides(int a,int b){
   while(b!=0)
   {
       int t=b;
       b=a%b;
       a=t;
   }
   return a;
}

int euclidesExtendido(int a, int b) {
	int r1 = a;
	int r2 = b;
	int s1 = 1;
	int s2 = 0;
	int t1 = 0;
	int t2 = 1;
	int s = 0;
	int t = 0;
	while (r2 > 0) {
		int q = r1 / r2;
		int r = r1 - q * r2;
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

afin::afin(){

  tam_array=alf.size();
  srand(time(0));
	a = rand() % tam_array;
	b = rand() % tam_array;
	while (true) {
		if (euclides(a, tam_array) == 1) {
      break;
		}
		a = rand() % tam_array;
		}
}

afin::afin(int m, int n) {
  tam_array=alf.size();

	a = m;
	b = n;

  
	inversa_int=modulo(euclidesExtendido(m,tam_array), tam_array);

  std::cout << "a " << a << '\n';
  std::cout << "b " << b << '\n';
  std::cout << "inversa_int " << inversa_int << '\n';

}



string afin::cifrado(string txt){
    string mensaje;
    int capturar;
    for(int i=0; i<txt.size(); i++) {
        capturar = modulo(alf.find(txt[i])*clave_a()+clave_b(),tam_array);
        mensaje += alf[capturar];
    }
    return mensaje;
}

string afin::descifrado(string txt) {

	string mensaje;
  int capturar;
    for(int i=0; i<txt.size(); i++) {
        capturar = modulo(inversa_int*(alf.find(txt[i])-b),tam_array);
        std::cout << "capturar :" << alf[capturar] << " " << capturar<< '\n';
        mensaje += alf[capturar];
    }
    return mensaje;

}
