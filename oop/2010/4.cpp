//
// Created by rols on 4/6/17.
//

#include <iostream>
#include <complex>
using namespace std;
#define MUL(a,b) a*a
class Canj {
public:
    virtual void f( int );
    virtual void f( double );
    virtual void g( int i = 2010 );
};
void Canj::f( int i) { cout << "Canj" << i << endl; }
void Canj::f( double i) { cout << "CrnaGora" << i << endl; }
void Canj::g( int i ) {
    cout << i << endl;
    if (i==2010) { f(MUL(2+i,3-i));}
}
class CrnaGora: public Canj {
public:
    void f( complex<double> );
    void g( int i = 2011 );
};
void CrnaGora::f( complex<double> c) { cout << "Elektrijada" << c.real() << endl; }
void CrnaGora::g( int i ) {
    cout << "50" << i << endl;
    if (i==2010) { f(MUL(2+i,3-i));}
}
void f(Canj &a) { a.g(); }
void main() {
    Canj b;
    CrnaGora d;
    Canj* pb = new CrnaGora;
    b.f(3.0);
    d.f(4.0);
    pb->f(5.0);
    b.g();
    d.g();
    pb->g();
    f(d);
    delete pb;
    exit(0);
}