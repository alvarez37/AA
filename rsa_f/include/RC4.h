#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdint.h>
#include <NTL/ZZ.h>
#include <x86intrin.h>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using namespace NTL;


class RC4{
private:
    vector<ZZ> Si;
    vector<ZZ> Ki;
    int bits;
    

public:

    RC4(int);
    void swap(ZZ a, ZZ b);
    vector<string> generacion_de_numeros(int bitNumber);
    ZZ get_numero();


};
