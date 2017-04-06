//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
#define jada "Kopaonik"
#define ComplexADD(a,b,c) a+b*c
static int c=2;
static int b;
class X {
    int *pi;
public:
    int x;
    int y;
    int z;
    X():pi(new int(3)), x(c++), y(c++), z(ComplexADD(2,3,++c+1)){b=0;};
    X(int i) : pi(new int(i)), x(c++), z(c++), y(ComplexADD(3,2,++c+1)) {b++;}
    X(const X &ob) : pi(new int(*ob.pi)){
        cout << "kop" << endl; b*=2; x=ComplexADD(c, y+z, z+b);
    }
    X& operator= (const X&);
    ~X() {delete pi;}
};
X& X::operator= (const X& x) {
    if (this != &x) {
        delete pi;
        pi = new int(*x.pi);
        cout << "ELE" << endl;
    };
    return *this;
}
X funF(X x){X Xnew(5); x=Xnew; return x;}
void g() {
    X xa=3, xb=5;
    X xc = xa;
    xa = funF(xb);
    xc = xa;
}
int main(int argc, char* argv[]){
    X d;
    g();
    cout << b << c << endl;
    cout << d.x << d.y << d.z << endl;
    return 0;
}