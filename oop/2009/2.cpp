//
// Created by rols on 4/6/17.
//

#include <iostream>

using namespace std;

class Base
{
    int x;
    virtual int f( int );
public:
    Base( int a ) : x(a) {}
    double f( double );
};
int Base::f( int a )
{
    return a+x;
}
#define KUB(a) a*a*a
double Base::f( double a )
{
    cout << "AA";
    return KUB(a*x-3) + f(5);
}
class Derived : public Base
{
    int x;
    int f( int );
public:
    Derived ( int a, int b ) : Base(a), x(b) {cout << "BB";}
    double f( double );
};
int Derived::f( int a )
{
    cout << "CAB";
    return KUB(a-x);
}
double Derived::f( double a )
{
    cout << "BAC" << f(2);
    return a/x+f(7);
}
int main()
{
    Derived d(3,5);
    cout << d.f( 3.4 ) << endl;
    Base* pb = new Derived(2,4);
    cout << pb->f( 4.5 ) << endl;
    Base b(2);
    cout << b.f( 2.3 ) << endl;
}