//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
class A
{
public:
    int no;
public:
    A( ) { no = 4;};
    void f(A* x) {
        no += x->no;
    };
    A* get( ) { return this;}
};
class B : public A
{
public:
    B( ) {
        no++;
        A::f(this);
    };
    virtual void f(A* x) {
        no += x->no;
    };
};
class C : public A
{
public:
    C( ) {
        B* b = new B;
        b->f(b);
        no += b->no;
    }
    void f(A* x) { no -= x->no + 3; };
};
class D : private B, public C
{
public:
    D( ) {
        C* c = new C;
        f(c);
    };
    void f(A* x) {
        C::f(C::get());
        C::no += (x->no + B::no);
        cout << C::no;
    };
};
void main( ) {
    C* d = new D;
    d->f(d);
}