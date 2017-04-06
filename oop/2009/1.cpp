//
// Created by rols on 4/6/17.
//

#include "iostream"
using namespace std;
int dat=1;
class KlasaB;
class B {
public:
    virtual void f(int d=5)=0;
};
class A {
    unsigned i;
public:
    int pod;
    A& operator++() { cout << "A " << pod-- << dat++ << endl; A* b = new A; return *b;}
    A operator++(int) { cout << "B " << pod++ << dat-- << endl; A* b = new A; return *b;}
    A& operator--() { cout << "C " << dat++ << ++pod << endl; A* b = new A; return *b;}
    A operator--(int) { cout << "D " << dat--<< --pod << endl; A* b = new A; return *b;}
    void operator+(A b) { pod++;}
    friend void B::f(int);
    A() : i(0), pod(dat) {pod++; cout << "CA" << endl;}
    ~A(){pod++; cout << "DC" << endl;}
};
const KlasaB& returnKlasaA(const KlasaB& p){return p;}
class KlasaB : public A, public B {
public:
    void f(int d=2){ A c; c++; pod*=d--;}
    KlasaB(){cout << "CB" << endl;}
    ~KlasaB(){cout << "DB" << endl;}
};
KlasaB returnKlasaB(KlasaB s){ return s;}
class KlasaC : public KlasaB {
public:
    KlasaC(){cout << "CC" << endl;}
    ~KlasaC(){cout << "DC" << endl;}
};
KlasaB returnKlasaC(KlasaB s)
{
    return s;
}
int main(int argc, char* argv[])
{
    KlasaC x;
    A v,w;
    B *c = new KlasaB;
    --++v--+++w--;
    returnKlasaC(returnKlasaB(returnKlasaA(x)));
}