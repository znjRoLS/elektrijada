//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
class OOP
{
    virtual int f( int );
public:
    int x;
    OOP( int a ) : x(a) { cout<<"-";}
    double f( double );
};
int OOP::f( int a )
{
    return a+x;
}
#define KUB(a) a*a*a*a
#define swap(a, b) a=a*b;b=a/b;a=a/b;
double OOP::f( double a )
{
    cout << "X-X";
    return KUB(a*x-4) + f(5);
}
class Delphi : public OOP
{
    int x;
    int f( int );
public:
    Delphi ( int a, int b ) : OOP(a), x(b) {cout << "-ZZ-";}
    double f( double );
};
int Delphi::f( int a )
{
    cout << "WXZ-";
    return KUB(a-x);
}
double Delphi::f( double a )
{
    cout << f(3) << "-ZXW";
    swap(a,x);
    return a/x+f(5);
}
int main()
{
    OOP* pb = new Delphi(3,7);
    cout << pb->f( 3.4 ) << endl;
    Delphi d(2,4);
    cout << d.f( 2.5 ) << endl;
    OOP b(3);
    cout << b.f( 1.6 ) << endl;
    cout << KUB(2.5-4);
    return (int)0;
}