//
// Created by rols on 4/6/17.
//

#include <iostream.h>
class A {
public:
    int i, j, k;
    A(int l) : k(l), j(k+1), i(j+2) {}
};
class B: public A {
public:
    B( ) : A(2) { }
};
class C: virtual public A {
public:
    C( ) : A(3) { }
};
void main() {
    C yy;
    B xx ;
    A zz = yy;
    A tt = xx;
    int s = 0;
    for(int i=0;i<10;i++)
    {
        if (xx.i == (xx.j + 1)){
            s+=2;
        }
        else { s+=3; }
        if (yy.i == (yy.j + 1)){
            s+=20;
        }
        else { s+=30; }
        if (zz.i == (zz.j + 1)){
            s+=200;
        }
        else { s+=300; }
        if (tt.i == (tt.j + 1)){
            s+=-3;
        }
        else { s+=-2; }
        xx.i = yy.i;
        yy.i = zz.i;
        zz.i = tt.i;
        xx.j = yy.j;
        yy.j = zz.j;
        zz.j = tt.j;
        cout << " " << s << endl; }
}