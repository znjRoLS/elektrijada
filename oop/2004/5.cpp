//
// Created by rols on 4/6/17.
//

#include "iostream"
using namespace std;
static int b;
class X {
    int *pi;
public:
    X(){b=0;};
    X(int i) : pi(new int(i)) {b++;}
    X(const X &x) : pi(new int(*x.pi)){b*=2;}
    X& operator= (const X&);
    ~X() {delete pi;}
};
X& X::operator= (const X& x) {
    if (this != &x) {
        delete pi;
        pi = new int(*x.pi);
    };
    return *this;
}
X funF(X x){X Xnew(5); x=Xnew; return x;}
void g() {
    X xa=3, xb=1;
    X xc = xa;
    xa = funF(xb);
    xc = xa;
}
int main(int argc, char* argv[]){
    X d();
    g();
    cout << b << endl;
    return 0;
}