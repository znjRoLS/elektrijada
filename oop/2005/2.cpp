//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
class A {
public:
    int a;
    A() { a = 0; }
    A(int a1) { a = a1; }
    void print() { cout << "A::a = " << a << endl; }
};
class B : virtual public A {
    int b;
public:
    B() : A() { b = 0 ; }
    B(int a1, int b1) : A(a1) { b = b1; }
    void print() { cout << "B::"; A::print(); cout << "B::b = " << b << endl; }
};
class C : virtual public A {
    int c;
public:
    C() : A() { c = 0; }
    C(int a1, int c1) : A(a1) { c = c1; }
    void print() { cout << "C::"; A::print(); cout << "C::c = " << c << endl; }
};
class D : public B, public C {
    int d;
public:
    D() : B(), C() { d = 0 ; }
    D(int a1, int a2, int b1, int c1, int dl) : B(a1, b1), C(a2, c1) { d = dl; }
    void print() { B::print(); C::print(); cout << "D::d = " << d << endl; }
};
class E : public A {
    int e;
public:
    E() : A() { e = 0; }
    E(int a1, int e1) : A(a1) { e = e1; }
    void print() { cout << "E::"; A::print(); cout << "E::e = " << e << endl; }
};
class F : public B, public C, public E {
    int f;
public:
    F() : B(), C(), E() { f = 0; }
    F(int a1, int a2, int a3, int b1, int c1, int e1, int f1) : B(a1, b1), C(a2,
                                                                             c1), E(a3, e1) { f = f1; }
    void print() { B::print(); C::print(); E::print(); cout<< "F::f = " << f <<
                                                           endl; }
};
void main () {
    D x(1, 2, 3, 4, 5);
    x.print(); x.a = 7; x.B::a = 8;
    x.C::a = 9; x.print();
    F y(1, 2, 3, 4, 5, 6, 7);
    y.print(); y.B::a = 1;
    y.E::a = 2; y.print();
}