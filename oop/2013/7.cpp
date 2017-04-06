//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
#define ISTRIANGLE(a,b,c) (a - b)>c ? (a - c)>b ? (b - c)>a ? 1 : 2 : 2 : 2
int noTriangA = 0, noTriangB =0, noTriangC=0;
class A {
public:
    int i, j, k;
    A(int l) : k(l), j(k+2), i(j+4) {}
};
class B: public A {
public:
    B( ) : A(2) { }
};
class C: virtual public A {
public:
    C( ) : A(3) { }
};
int main() {
    C yy;
    B xx ;
    A zz = yy;
    A tt = xx;
    int s = 0;
    for(int i=0;i<10;i++)
    {
        if (xx.i == (xx.j + 1)){
            s+=3;
        }
        else { s+=3; }
        if (yy.i == (yy.j + 1)){
            s+=12;
        }
        else { s+=30; }
        if (zz.i == (zz.j + 1)){
            s+=114;
        }
        else { s+=300; }
        if (tt.i == (tt.j + 1)){
            s+=-5;
        }
        else { s+=-3; }
        noTriangA+= ISTRIANGLE(xx.i+yy.i,xx.j+yy.j,xx.k+yy.k);
        noTriangB+= ISTRIANGLE(xx.i+tt.i,xx.j+tt.j,xx.k+tt.k);
        noTriangC+= ISTRIANGLE(tt.i+yy.i,tt.j+yy.j,tt.k+yy.k);
        xx.i = yy.i;
        yy.i = zz.i;
        zz.i = tt.i;
        xx.j = yy.j;
        yy.j = zz.j;
        zz.j = tt.j;
        cout << " " << s << " tA=" << noTriangA<< " tB=" << noTriangB
             << " tC=" << noTriangC << endl; }
    return (int)0;
}