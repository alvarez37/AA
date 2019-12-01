#include"elgamal.h"
string entero_a_string(int x)
{

  if (x == 0)
  {
    return "0";
  }
  return static_cast<std::ostringstream *>(&(std::ostringstream() << x))->str();
}

string completar_ceros_string(string texto, string alf)
{
  string salida;
  int salida_int;


  for (int i = 0; i < texto.size(); i++)
  {
    salida_int = alf.find(texto[i]);
    if (salida_int < 10)
    {
      salida += "0" + entero_a_string(salida_int);
    }
    else
    {
      salida += entero_a_string(salida_int);
    }
  }

  return salida;
}
void gamal::generarClaves(int bits){

    funcions_math m;
    ZZ a,r_0;

    GenPrime(a,bits);
    // a = m.genetareRandom(11,bits,5,10);
    // while(!m.testMiller(a,10)){
        // a = GenPrime(bits);
        // a = m.genetareRandom(11,bits,5,10);
    // }
    p=a;
    e1 = m.fingGen(p);
    GenPrime(d,bits-1);
    // d = m.genetareRandom(11,bits,5,10);
    GenPrime(r_0,bits);
    // r_0 = m.genetareRandom(11,bits,5,10);
    while(d<1 && d>p-2 && r_0<1 && r_0>p-2){
        GenPrime(d,bits-1);
        GenPrime(r_0,bits);
        // d = m.genetareRandom(11,bits,5,10);
        // r_0 = m.genetareRandom(11,bits,5,10);
    }
    r=r_0;
    e2 = m.modularExpo(e1,d,p);
    cout<<"e1: "<<e1<<endl;
    cout<<"e2: "<<e2<<endl;
    cout<<"p: "<<p<<endl;
}

gamal::gamal(int bits_){
    bits=bits_;
    generarClaves(bits);
}

gamal::gamal(ZZ e_1,ZZ e_2, ZZ p_0, int bits_){
    bits=bits_;
    e1 = e_1;
    e2 = e_2;
    p = p_0;
}

string zToString(const ZZ &z) {
    stringstream buffer;
    buffer << z;
    return buffer.str();
}

string numberToString(int numero){
    stringstream ss;
	ss << numero;
	return ss.str();
}

string gamal::cifrar(string mensaje){
    string res,lString,mensajeC,c1_string;
    int c1_temp;
    funcions_math m;
    ZZ c1;
    ZZ N,Km;
    N=p;

    GenPrime(r,bits-2);


    c1= m.modularExpo(e1,r,p);
    Km = m.modularExpo(e2,r,p);
    c1_string =zToString(c1);
    c1_temp = c1_string.length();

    int lenMaxString = numberToString(longitud).length();
    int lenN = zToString(N).length();
    int k = lenN-1;


    res = completar_ceros_string(mensaje, alfabeto);
    string posW = numberToString(alfabeto.find('w'));
    while(m.getModInt(res.length(),k)!=0){
        res.append(posW);
    }
    std::cout <<endl << " ---------------------------------------------------" << std::endl;
    std::cout << "   mensaje " << mensaje<< std::endl;
    std::cout << "   numeros " << res<< '\n';
    std::cout << " ---------------------------------------------------" << std::endl;


    ZZ numGroups;
    numGroups = conv<ZZ>(res.length()/k);
    long long i;
    int ini = 0;
    int fin = k;
    for(i=0;i<numGroups;i++){
        ZZ numCifrar(INIT_VAL,res.substr(ini,fin).c_str());
        std::cout << "   " << i << " base  " << numCifrar;
        // numCifrar = m.modularExpo(numCifrar,clavePublica,N);
        // std::cout << " numCifrar " << numCifrar << '\n';
        numCifrar = m.getMod(numCifrar*Km,p);
        string t = zToString(numCifrar);
        int diff = (lenN)-t.length();
        string actualString = t;
        if(diff!=0){
            string temp(diff,'0');
            temp.append(t);
            actualString = temp;
        }
        mensajeC+=actualString;
        std::cout  << " result:  " <<  actualString << '\n';
        // std::cout << " mensajeC " << mensajeC << '\n';
        ini+=k;
    }
    if(c1_temp<lenN){
        int tempo = lenN-c1_temp;
        string temp(tempo,'0');
        temp+=c1_string;
        temp+=mensajeC;
        mensajeC=temp;
        // std::cout << '\n' << " mensajeC if " << mensajeC << '\n';


    }else{
        c1_string+=mensajeC;
        // mensajeC = c1_temp;
        mensajeC = c1_string;
        // std::cout << '\n' << " mensajeC else " << mensajeC << '\n';

    }

    std::cout <<endl << " ---------------------------------------------------" << std::endl;
    cout<<"   Mensaje Cifrado: "<<mensajeC<<endl;
    std::cout << " ---------------------------------------------------" << std::endl;

    return mensajeC;
}

string gamal::decifrar(string mensaje){
    funcions_math m;
    ZZ Km;
    ZZ N;
    N = p;

    int lenP = zToString(p).length();
    ZZ c1(INIT_VAL,mensaje.substr(0,lenP).c_str());
    Km=m.modularExpo(c1,d,p);
    Km=m.Inversa(Km,p);

    string grupo,res,MensajeDes;
    int numMaxofChars = numberToString(longitud).length();
    ZZ nLen,menLen,numGrupos,dp,dq,D,c,numLetras;
    nLen = conv<ZZ>(zToString(N).length());
    menLen = conv<ZZ>(mensaje.length());
    numGrupos = menLen/nLen;
    long long i;
    int inicio = lenP;
    c=0;
    std::cout <<endl << " ---------------------------------------------------" << std::endl;
    cout<<"   c1: "<<c1<<endl;
    cout<<"   Mensaje Cifrado: "<< mensaje.substr(inicio, mensaje.size()) <<endl;
    std::cout << " ---------------------------------------------------" << std::endl;

    for(i=1;i<numGrupos;i++){

        grupo = mensaje.substr(inicio,conv<int>(nLen));
        std::cout << "   " << i << " base  " << grupo;
        ZZ valGrupo(INIT_VAL,grupo.c_str());
        D=m.getMod(valGrupo*Km,p);

        if(zToString(D).length() < conv<int>(nLen)){
            string temp((conv<int>(nLen)-zToString(D).length())-1,'0');
            temp.append(zToString(D));
            res+=temp;
            std::cout  << " result:  " <<  temp << '\n';

        }else{
           res+=zToString(D);
           std::cout  << " result:  " <<  zToString(D) << '\n';
        }

        c++;
        inicio+=conv<int>(nLen);
    }

    std::cout <<endl << " ---------------------------------------------------" << std::endl;
    std::cout  << " mensaje:  " <<  res << '\n';

    inicio = 0;
    numLetras = conv<ZZ>(res.length())/conv<ZZ>(numberToString(longitud).length());
    for(i=0;i<numLetras;i++){
        ZZ temp(INIT_VAL,res.substr(inicio,numMaxofChars).c_str());
        if(alfabeto[conv<int>(temp)]=='w'){
            break;
        }
        MensajeDes+=alfabeto[conv<int>(temp)];
        inicio+=numMaxofChars;
    }
    
    cout<<"   Mensaje Cifrado: "<<MensajeDes<<endl;
    std::cout << " ---------------------------------------------------" << std::endl;
    return MensajeDes;

}
