//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
static int b;
class X {
    int *pi;
public:
    int plaza, sladoled, more;
    X() {b=0; plaza=3; more = 5*b++; sladoled=more++;};
    X(const X &x) : pi(new int(*x.pi)){b*=2; plaza=-4; more = -3*b++;
        sladoled=more++;}
    X(int l) : pi(new int(l)), plaza(l), more(l++), sladoled(l++) { b++;}
    X& operator= (const X&);
    ~X() {cout << "b:"<< b << "plaza:"<< plaza << "sladoled:"<<sladoled <<
               "more:"<<more << endl;delete pi;}
};
X& X::operator= (const X& x) {
    if (this != &x) {
        delete pi;
        pi = new int(*x.pi);
    }
    return *this;
}
X funF(X& x)
{
    X Xnew(5);
    x=Xnew;
    Xnew.plaza++; Xnew.more+= ++b; Xnew.sladoled=b;
    return x;
}
void g() {
    X xa=3, xb=1;
    X xc = xa;
    xa = funF(xb);
    xc = xa;
    X a(2);
    a.sladoled++;
    b+=a.sladoled;
}
int main(int argc, char* argv[])
{
    X d();
    g();
    return (int)0;
}