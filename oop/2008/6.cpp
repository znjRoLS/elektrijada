//
// Created by rols on 4/6/17.
//

#include "iostream.h"
int data = 0;
class Y;
class X {
public:
    X(){cout << "cX" << endl; data++;}
    ~X(){cout << "dX" << endl; data--;}
    X& operator++( ) { cout << "1 " << data-- << endl; X* b = new X; return *b;}
    X operator++(int) { cout << "2 " << data++ << endl; X* b = new X; return *b;}
    X& operator--( ) { cout << "3 " << ++data << endl; X* b = new X; return *b;}
    X operator--(int) { cout << "4 " << --data << endl; X* b = new X; return *b;}
    void operator+(X& b) { data++;}
};
class B
{
public:
    virtual void f(int d = 3) = 0;
};
class Y : public X, public B {
public:
    Y(){cout << "cY" << endl;}
    ~Y(){cout << "dY" << endl;}
    void f(int d = 5) { X a; a++; data+=d--;};
};
class Z : public Y {
public:
    Z(){cout << "cZ" << endl;}
    ~Z(){cout << "dZ" << endl;}
};
Y retZ(Y s){ return s; }
const Y& retX(const Y& p){return p;}
Y retY(Y s){ return s;}
int main(int argc, char* argv[])
{
    Z Teslic;
    X i, j;
    retZ(retY(retX(Teslic)));
    B *b = new Y;
    ++--j++--+j++;
    b->f(data);
    return 0;
}