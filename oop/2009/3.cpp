//
// Created by rols on 4/6/17.
//

#include <iostream>
#include <complex>
using namespace std;
class Base{
public:
    virtual void f( int );
    virtual void f( double );
    virtual void g( int i = 3 );
};
void Base::g( int i ){ cout << "XXX" << i << endl;}
void Base::f( int ){ cout << "ABC" << endl;}
void Base::f( double ){ cout << "CACA" << endl;}
class Derived: public Base{
public:
    void g( int i = 2 );
    void f( complex<double> );
};
void Derived::f( complex<double> ){ cout << "CBA" << endl;}
void Derived::g( int i ){
    cout << "BABC**" << i << endl;
    Base b = *(new Derived());
    try {
        if (i==2) throw Derived();
        if (i==3) throw 7.6;
        if (i==4) throw 2.4f;
        if (i==5) throw b;
    }
    catch (Base) {cout << "ASS";}
    catch (double) {cout << "ATT";}
    catch (Derived) {cout << "AMM";}
    catch (float) {cout << "AVV";}
}
int main(){
    Base b; Derived d; Base* pb = new Derived;

    d.f(5.0);
    pb->f(6.0);
    b.g();
    b.g(5);
    d.g();
    b.f(4.0);
    pb->g();
    pb->g(4);
    delete pb;
}