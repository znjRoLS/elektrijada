//
// Created by rols on 4/6/17.
//

#include "iostream.h"
static int b;
class X {
    int *pi;
public:
    int x;
    virtual int a();
    int bb();
    void operator() (X& x);
    X(){b=0; x=5;};
    X(int i) : pi(new int(i)) {b++;}
    X(const X &x) : pi(new int(*x.pi)){b*=2;}
    X& operator= (const X&);
};
X& X::operator= (const X& x) {
    if (this != &x) {
        delete pi;
        pi = new int(*x.pi);
    };
    return *this;
}
int X::a(){cout << "X A\n";this->x;return bb();}
int X::bb(){cout << "X B\n";return this->x;}
void X::operator() (X& x){
    this->x = x.a() * x.bb();
    cout << this->x << endl;
}
class Derived: public X{
public:
    int a();
    int bb();
};
int Derived::a(){ cout << "Derived A\n";return bb()*10;}
int Derived::bb(){ cout << "Derived B\n";return this->x * 2;}
X funF(X x){X Xnew(5); x=Xnew; return x;}
void g() {
    X xa=4, xb=3;
    X xc = xa;
    xa = funF(xb);
    xc = xa;
}
int main(int argc, char* argv[]){
    X d();
    X obj;
    X *dd = new Derived();
    obj.a(); dd->a(); obj.bb();
    dd->bb(); obj(*dd); (*dd)(obj);
    g();
    cout << b << endl;
    return 0;
}