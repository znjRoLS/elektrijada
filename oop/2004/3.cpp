//
// Created by rols on 4/6/17.
//

#include <iostream.h>
class Base{
    int x;
    virtual int f( int );
public:
    Base( int a ) : x(a) {}
    double f( double );
};
int Base::f( int a ){ return a+x;}
double Base::f( double a ){ return a*x + f(5);}
class Derived : public Base{
    int x;
    3
    int f( int );
public:
    Derived ( int a, int b ) : Base(a), x(b) {}
    ;
    double f( double );
};
int Derived::f( int a ){ return a
                                -x;}
double Derived::f( double a ){ return a/x+f(5); f(1);}
void main() {
    Base b(2);
    Derived d(2,4);
    Base* pb = new Derived(2,4);
    cout << b.f( 1.2 ) << endl;
    cout << d.f( 1.2 ) << endl;
    cout << pb
            ->f( 1.2 ) << endl;
}