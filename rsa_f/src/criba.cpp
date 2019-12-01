#include "criba.h"


int modulocriba(int a, int tam_array){
    int residuo;
    if (a<0) {
      residuo=a-((a/tam_array)-1)*tam_array;
    }

    else{
      residuo=a-(a/tam_array)*tam_array;
    }
    return residuo;
}

void criba::imprimir (){
      cout <<'\n' << '\n';
      for(int i = 0; i < lista.size(); i++) {
        std::cout << lista[i] << '\t';
      }
      cout <<'\n' << '\n';
}

bool criba::emcontrar(int x){

  cout <<'\n' << '\n';
  for(int i = 0; i < lista.size(); i++) {
    if (lista[i]==x) {
      std::cout << "si esta " << x << '\n';
      return 1;
    }
  }
  std::cout << "no esta" << '\n';

  return 0;
  cout <<'\n' << '\n';

}

int criba::retornar(int x){
  return lista[x];
}

criba::criba(int tam){

      int suma;
      int cont=2;

      for (size_t i = 2; i < tam; i++) {
        lista.push_back(i);
      }

      // imprimir(lista);

      int n = sqrt(tam);

      for (size_t i = 0; i < n; i++) {
    //    std::cout <<"*******************  "<< cont <<"  *******************"<< '\n';
        for (size_t i = 1; i < lista.size(); i++) {
          if (!(  modulocriba(lista[i], cont ))) {
            if ((lista[i]==cont)) {
            }
            else{
              lista.erase(lista.begin()+i,lista.begin()+i+1);
            }
          }
        }
        cont++;
      //  imprimir(lista);
      }

      // imprimir();
}
