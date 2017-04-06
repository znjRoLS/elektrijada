//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int data = 0;
class A
{
    int x;
    virtual int f( int );
public:
    A(){data++;}
    A( int a ) : x(a) {}
    double f( double );
    A& operator++( ) {cout << "Kop1 " << data-- << endl; A* b= new A; return *b;}
    A operator++(int) {cout << "Kop2 " << data++ << endl; A* b= new A; return *b;}
    A& operator--( ) {cout << "Kop3 " << ++data << endl; A* b= new A; return *b;}
    A operator--(int) {cout << "Kop4 " << --data << endl; A* b= new A; return *b;}
    void operator-(A& b) { data++;}
    ~A( ){data++;}
};
int A::f( int a ){ return a+x;}
double A::f( double a ){ return a*x + f(5);}
class B
{
public:
    virtual void g(int d = 2) = 0;
};
class C : public A, public B
{
public:
    int x;
    int f( int );
public:
    C():x(data){};
    C ( int a, int b ) : A(a), x(b) {};
    double f( double );
    void g(int d = 2) { A a; a++; data+=d--;};
};
int C::f( int a = 5){ A b; b++; data+=a--; return a-x;}
double C::f( double a ){ return a/x+f(5); f(1);}
int main()
{
    A i, j;
    B *c = new C;
    A x(2);
    C y(2,4);
    A* pb = new C(2,4);
    cout << x.f( 2.4 ) << endl;
    cout << y.f( 2.4 ) << endl;
    cout << pb->f( 1.2 ) << endl;
    --++i---++j--;
    y.f(data); y.g(data);
    cout << data;
}