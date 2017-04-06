//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
char outputString[30];
static int i = 0;
class Opel;
class Car {
public:
    Car(){outputString[i++]='1';}
    ~Car(){outputString[i++]='A';}
};
const Opel& returnCar(const Opel& p) {return p;}
class Opel : public Car {
public:
    Opel() {outputString[i++]='2';}
    ~Opel() {outputString[i++]='B';cout << "Opel " << endl;}
};
Opel returnOpel(Opel s){ return s;}
class Astra : public Opel {
public:
    Astra(){outputString[i++]='3';}
    ~Astra(){outputString[i++]='C';cout << "Astra " << endl;}
};
Opel returnAstra(Opel s) { return s;}
class Vectra : public Astra {
public:
    Vectra(){outputString[i++]='4';}
    ~Vectra(){outputString[i++]='D';cout << "Vectra " << endl;}
};
Car returnVectra(Car d) { return d;}
int main(int argc, char* argv[])
{
    Vectra laza;
    Vectra* pLaza;
    pLaza = &laza;
    returnVectra(returnAstra(returnOpel(returnCar(*pLaza))));
    cout << outputString << i << endl;
    return 0;
}