//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
class Base {
    int x;
    virtual int f( int );
public:
    Base() {}
    Base( int a ) : x(a) {cout << "Base" << endl;}
    double f( double );
};
int Base::f( int a ) { return a+x;}
double Base::f( double a ) { return a*x + f(5);}
class Derived : virtual public Base{
    int x;
    int f( int );
public:
    Derived ( int a, int b ) : Base(a), x(b) {cout << "Derived" << endl;}
    double f( double );
};
int Derived::f( int a ) { return a-x;}
double Derived::f( double a ) { return a/x+f(5);}
class NewDerivedA : virtual public Base{
    int x;
public: NewDerivedA ( int a, int b ) : Base(a), x(b) {cout << "NewDerivedA" << endl;}
};
class NewDerivedB : virtual public Base{
    int x;
public: NewDerivedB ( int a, int b ) : Base(a), x(b) {cout << "NewDerivedB" << endl;}
};
class All : public NewDerivedA, public NewDerivedB {
public:
    All(int a, int b) : NewDerivedA(a,b) , NewDerivedB(b,a){ cout<< "All" << endl;}
    double g(double a, double b , double f) { return a-2*b-f;}
};
int main() {
    Base b(4);
    Derived d(4,8);
    All pa(4, 8);
    Base* pb = new Derived(4,8);
    cout<< pa.g(b.f( 1.2 ) ,d.f( 1.2 ), pb->f( 1.2 )) << endl;
}