#include "RC4.h"
#include "matlibrc4.h"


RC4::RC4(int x){
    bits=x;
}

void RC4::swap(ZZ a, ZZ b)
{
    long a1, b1;
    conv(a1, a);
    conv(b1, b);
    ZZ temp = Si[a1];
    Si[a1] = Si[b1];
    Si[b1] = temp;
}

vector<string> RC4::generacion_de_numeros(int bits)
{
    vector<string> res;
    for (int i = 0; i < bits; ++i)
    {
        Si.push_back(conv<ZZ>(i));
        Ki.push_back(getCPUCicles());
    }

    ZZ f;
    ZZ c;
    f = 0;
    c = 0;
    for (int i = 0; i < bits; ++i)
    {
        f = Modulo(c + Si[i] + Ki[i], conv<ZZ>(bits));
        swap(f, c);
        ++c;
    }
    c = 0;
    f = 0;
    long indice;
    ZZ t;
    for (int i = 0; i < bits; ++i)
    {
        c = Modulo(c + 1, conv<ZZ>(bits));
        f = Modulo(f + Si[i], conv<ZZ>(bits));
        conv(indice, f);
        swap(c, f);
        t = Modulo(Si[i] + Si[indice], conv<ZZ>(bits));
        conv(indice, t);
        res.push_back(zToString(Si[indice]));
    }
    Si.clear();
    Ki.clear();

    return res;
}

ZZ RC4::get_numero()
{

    vector<string> a = generacion_de_numeros(bits);
    convetirBits(a);
    bitset<1024> n(binario);
    string temp = zToString(convertBinaryToZZ(binario));

    string tem;
    for (int i = 0; i < binario.size(); i++)
    {
        tem = corta_string_1(binario, bits);
        tem[tem.size()] = '1';
        // if(fermatTest(8,convertBinaryToZZ(tem))){
        if (ProbPrime(convertBinaryToZZ(tem), 10))
        {
            return convertBinaryToZZ(tem);
        }
    }

    return get_numero();
}
