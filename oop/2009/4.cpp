//
// Created by rols on 4/6/17.
//

#include "iostream.h"
static int b;
class X {
    int *pi;
public:
    int osa, buba, mis;
    X() {b=0; osa=3; mis = 5*b++; buba=mis++;};
    X(const X &x) : pi(new int(*x.pi)){b*=2; osa=-2; mis = -4*b++; buba=mis--;}
    X(int l) : pi(new int(l)), osa(l), mis(l++), buba(l++) { b++;}
    X& operator= (const X&);
    ~X() {cout << "b:"<< b << "osa:"<< osa << "buba:"<<buba << "mis:"<<mis << endl;delete
                pi;}
};
X& X::operator= (const X& x) {
    if (this != &x) {
        delete pi;
        pi = new int(*x.pi);
    }
    return *this;
}
X funF(X x)
{
    X Xnew(5);
    x=Xnew;
    Xnew.osa++; Xnew.mis+= ++b; Xnew.buba=b;
    return x;
}
void g() {
    X xa=3, xb=1;
    X xc = xa;
    xa = funF(xb);
    xc = xa;
    X a(2);
    a.buba++;
    b+=a.buba;
}
void main(int argc, char* argv[])
{
    X d();
    g();
}