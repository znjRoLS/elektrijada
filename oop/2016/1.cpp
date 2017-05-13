//
// Created by rols on 5/13/17.
//

#include <iostream>

#include <complex>

using namespace std;

class Base {

protected:

    int x;

public:

    Base( int a ) : x(a) {};

    virtual int f( int );

    virtual double f( double );

    virtual int g( int i = 10 );

};

int Base::f( int a ) { cout << "Base::f(int)" << endl; return a+x; }

double Base::f( double a ) { cout << "Base::f(double)" << endl; return a+x/2; }

int Base::g( int i ) {

    if (i==10) { x = f(2*i);}

    cout << "Base::g() " << i << " " << x << endl;

    return x;

}

class Derived: public Base {

protected:

    int x;

public:

    Derived ( int a, int b ) : Base(a), x(b) {};

    double f( double );

    double f( complex<double> );

    int g( int i = 20 );

};

double Derived::f( double a ) { cout << "Derived::f(double)" << endl; return a+x/4; }

double Derived::f( complex<double> a) { cout << "Derived::f(complex)" << endl; return

            x/8; }

int Derived::g( int i ) {

    if (i==10) { x = f(2*i+1);}

    cout << "Derived::g() " << i << " " << x << endl;

    return x;

}

int f(Base &a) { return a.g(); }

class DerivedRimini : public Derived {

public:

    double f( complex<double> );

    DerivedRimini ( int a, int b ) : Derived(--a, ++b) {};

    int g( int i = 40 );

};

double DerivedRimini::f( complex<double> a) { cout << "Derived::f(complex)" << endl;

    return a.real()+x/16; }

int DerivedRimini::g( int i ) {

    if (i==10) { x = f(2*i+x);}

    if (i==40) { x = f(2*i+x+1);}

    cout << "DerivedRimini::g() " << i << " " << x << endl;

    return x;

}

class DerivedItaly : public DerivedRimini {

public:

    DerivedItaly ( int a, int b ) : DerivedRimini(++a, --b) {};

    int f( int );

    double f( double );

    int g( int i = 80 );

};

int DerivedItaly::f( int a ) { cout << "DerivedItaly::f(int)" << endl; return a+x*2; }

double DerivedItaly::f( double a ) { cout << "DerivedItaly::f(double)" << endl; return

            a+x/8; }

int DerivedItaly::g( int i ) {

    if (i==10) { x = f(2*(i+x));}

    if (i==40) { x = f(2*(i+x)+1);}

    cout << "Derived::g() " << i << " " << x << endl;

    return x;

}

int main()

{

    Base b(2);

    Derived d(1,3);

    Base* pb = new Derived(2,4);

    DerivedRimini dr(3,5);

    DerivedRimini* pr = new DerivedItaly(4,8);

    DerivedItaly i(5,7);

    cout << d.f(b.g()) << endl;

    pb->f(1.0);

    d.g();

    cout << pb->g() << endl;

    cout << dr.f(f(i)) << endl;

    cout << pr->f(pr->g()) << endl;

    delete pb;

    delete pr;

    return 0;

}