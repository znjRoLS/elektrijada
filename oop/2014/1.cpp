//
// Created by rols on 4/6/17.
//

#include <iostream>
#include <iomanip>
using namespace std;
static int b;
class X {
    int *pi;
public:
    int x;
    virtual int a();
    int bb();
    void operator() (X& x);
    X(){b=0; x=-2;};
    X(int i) : pi(new int(i)) {b++;}
    X(const X &x) : pi(new int(*x.pi)){b*=3;}
    X& operator= (const X&);
};
X& X::operator= (const X& x) {
    if (this != &x) {};
    return *this;
}
int X::a(){cout << "F";this->x;return bb();}
int X::bb(){cout << "1\n";return this->x;}
void X::operator() (X& x){
    this->x = x.a() * x.bb();
    cout << this->x << endl;
}
class Derived: public X{
public:
    int a();
    virtual int bb();
};
int Derived::a(){ cout << "Hungaroring\n";return bb()*10;}
int Derived::bb(){ cout << "Kimi Raikkonen\n";return this->x * 2;}
X funF(X x){X Xnew(5); x=Xnew; return x;}
void g() {
    X xa=4, xb=3;
    X xc = xa;
    xa = funF(xb);
    xc = xa;
}
class Base: public X, public Derived{
public:
    int a();
    int bb();
};
int Base::a(){ cout << "20 years\n";return bb()*10;}
int Base::bb(){ cout << "Ayrton Sena\n";return this->Derived::x * 2;}
int main(int argc, char* argv[]){
    X obj, d();
    X *base = new Derived();
    Derived *derived = new Base();
    obj.a(); base->a(); obj.bb();
    base->bb(); obj(*base); (*base)(obj);
    g();
    obj(*derived);
    cout << b << endl;
    return 0;
    cout << "\nE L E K T R I J A D A\n" << endl;
}